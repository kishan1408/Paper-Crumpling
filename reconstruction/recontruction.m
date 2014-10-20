clear all;
% load data
load('data.mat');
clearvars -except data;
x1=(0.5*cell2mat(data(2,:))+0.5*cell2mat(data(1,:)));
y1=(0.5*cell2mat(data(3,:))+0.5*cell2mat(data(4,:)));
x2=(0.5*cell2mat(data(5,:))+0.5*cell2mat(data(6,:)));
y2=(0.5*cell2mat(data(7,:))+0.5*cell2mat(data(8,:)));
A=x1;
% Red channel selection
x1(:,:,2:3)=[];
y1(:,:,2:3)=[];
x2(:,:,2:3)=[];
y2(:,:,2:3)=[];
 
% Thresholding
thres=40;
x1(x1<thres)=0;
y1(y1<thres)=0;
x2(x2<thres)=0;
y2(y2<thres)=0;
roi= [1:305,804:1024];

% selcting the maximum value in each column
[~,x1max] = max(x1);
[~,y1max] = max(y1);
[~,x2max] = max(x2);
[~,y2max] = max(y2);

% region of interest selection

for i=0:99
 x1max(:,roi+1024*i)=-10;
 y1max(:,roi+1024*i)=-10;
 x2max(:,roi+1024*i)=-10;
 y2max(:,roi+1024*i)=-10;
end

x1=x1max;y1=y1max;x2=x2max;y2=y2max;
%mapping function
% 
% x1=mapfunc(x1);
% y1=mapfunc(y1);
% x2=mapfunc(x2);
% y2=mapfunc(y2);

%baseline image

Base_x1 = 1 ;
Base_y1 = 24 ;
Base_x2 = 2; 
Base_y2 = 24;

x1b=x1(:,1024*Base_x1:1024*(Base_x1+1)-1);
y1b=y1(:,1024*Base_y1:1024*(Base_y1+1)-1);
x2b=x2(:,1024*Base_x2:1024*(Base_x2+1)-1);
y2b=y2(:,1024*Base_y2:1024*(Base_y2+1)-1);

%baseline sustraction

x1 = x1 - repmat(x1b,[1,100]);
y1 = y1 - repmat(y1b,[1,100]);
x2 = x2 - repmat(x2b,[1,100]);
y2 = y2 - repmat(y2b,[1,100]);

% reconstruction 
x1=reshape(x1,[1024,100])';
y1=reshape(y1,[1024,100])';
x2=reshape(x2,[1024,100])';
y2=reshape(y2,[1024,100])';
x1(:,roi)=[];y1(:,roi)=[];x2(:,roi)=[];y2(:,roi)=[];
x1(x1<-120)=nan;x1(x1>=0)=nan;
x2(x2<-120)=nan;x2(x2>=0)=nan;
y1(y1<-120)=nan;y1(y1>=0)=nan;
y2(y2<-120)=nan;y2(y2>=0)=nan;

ygap = invmapfunc(1000);

final_img = zeros(ygap*100,length(x1));
final_img(1:ygap:end,:)=x1;
for jj =1:ygap:ygap*99
  for i = 1:ygap-1
    diff=i*((final_img(jj+ygap,:)-final_img(jj,:))/ygap);
    final_img(jj+i,:)=diff+final_img(jj,:);
  end 
   jj 
end
% final_img=-((final_img));
 final_img=-(inpaint_nans(final_img));
% final_img(final_img<=0)=nan;
%final_img(final_img<=0)=nan;
surf(final_img(1:4:end,1:4:end))









 






