%% Setup folder for saving sessions
close all;
clear all;
fclose('all');
prompt = {'Enter the Folder Name :'};
dlg_title = '3d scan of crumpled paper';
num_lines = 1;
folder = sprintf('session_%s_%d',date,round(sum(clock)));
def = {folder};
answer = inputdlg(prompt,dlg_title,num_lines,def);
mkdir(answer{1});cd(answer{1}); 

%% Note
prompt = {'Note for this trial'};
dlg_title = 'Note for this trial';
num_lines = 2;
def = {'note'};
options.Resize='on';
answer1 = inputdlg(prompt,dlg_title,num_lines,def,options);
fid =fopen('Note.txt','w');
fprintf(fid,answer1{1});

%% Control Box Setup

prompt = {'control box port'};
dlg_title = 'control box port';
num_lines = 1;
def = {'com4'};
port = inputdlg(prompt,dlg_title,num_lines,def);
a=serial(port{1});
fopen(a);
fwrite(a,'a');pause(4);
fwrite(a,'e');pause(2);
fwrite(a,'n');pause(2);
helpdlg('press any key after setting the paper','paper setup');
pause();

%% Camera1 Setup
vid = videoinput('winvideo', 1,'RGB24_1024x576');
%1024x576 1280x720 1920x1080 2304x1536
vid.ROIPosition=[0 0 1024 200];
set(vid, 'ReturnedColorSpace', 'RGB');
preview(vid);
helpdlg('press any key after setting the camera','camera setup');
pause();


%% Scanning
helpdlg('press any key to start the experiment','Experiment');
pause();
%% snapshot of LED along x direction 
fwrite(a,'l');pause(0.6);
fwrite(a,'o');pause(0.6);
data{11,1}=getsnapshot(vid);pause(0.6);
fwrite(a,'n');pause(0.6);
fwrite(a,'m');pause(0.6);
%imshow(getsnapshot(vid));pause(1);

%% snapshots of paper along x direction 
h1 = waitbar(0, 'scanning along x-direction ...');
steps = 100;

for i = 1:100
fwrite(a,'h');pause(0.6);
for ii=1:5
data{ii,i}=getsnapshot(vid);
end
%imshow(getsnapshot(vid));pause(1);
waitbar(i/steps);
end
close(h1)

fwrite(a,'h');pause(30);fwrite(a,'d');pause(5);

%% snapshot of LED along y direction 
fwrite(a,'l');pause(0.6);
fwrite(a,'o');pause(0.6);
data{11,2}=getsnapshot(vid);pause(0.6);
fwrite(a,'n');pause(0.6);
fwrite(a,'m');pause(0.6);
%imshow(getsnapshot(vid));pause(1);
h2 = waitbar(0, 'scanning along y-direction ...');

%% snapshots of paper along y direction 
for i = 1:100
fwrite(a,'h');pause(0.6);
for jj=6:10
data{jj,i}=getsnapshot(vid);pause(0.1);
end
%imshow(getsnapshot(vid));pause(1);
waitbar(i/steps);
end
close(h2)
fwrite(a,'h');pause(1);
fclose('all');
save data;
cd ..;
%%
% History:
% 08.03.2014  Written by kishan (kishan1408@gmail.com).
% Modifications:
% ---21.03.2014 : 5 images for each step. 
