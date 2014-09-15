
for i=1:100
    newdata{i}(:,1:151)=0;
end

for i=1:100
   for j=1:640
       [x,y]=max(newdata{i}(:,j));
       y=480-y;
       if y>470 
           y=0;
       end
       dat{1,i}(j)=j;
       dat{2,i}(j)=y;
   end
end

 for i=29:72
plot(dat{1,i},480-dat{2,i});ylim([0,480]);pause();i
 end
 %%
 
 for i=1:100
d{i}=(1/5)*(data{1,i}(:,:,1)+data{2,i}(:,:,1)+data{3,i}(:,:,1)+data{4,i}(:,:,1)+data{5,i}(:,:,1))
 end

 
for i=1:100
newdata{i}(:,471:end)=0;
newdata{i}(:,1:151)=0;
newdata{i}(155:end,:)=0;
end;

 for i=1:100
     l=zeros(1,640);
     for j=1:640
     [x,y]=max(newdata{i}(:,j));
     l(j)=y;
     end
     newmat{i}=l;
 end