%% Setup folder for saving sessions
% close all;
% clear all;
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

%%
preview(vid);
helpdlg('press any key after setting the camera','camera setup');
pause();


%% Scanning
helpdlg('press any key to start the experiment','Experiment');
pause();


%% snapshots of paper along x direction 
h1 = waitbar(0, 'scanning along x-direction ...');
steps = 100;
for i = 1:100
fwrite(a,'h');pause(0.6);
data{1,i}=getsnapshot(vid);
waitbar(i/steps);
end
close(h1)
fwrite(a,'h');pause(0.6);
fwrite(a,'h');pause(1);
fclose('all');
save data;
cd ..;
%%
% History:
% 10.03.2014  Written by kishan (kishan1408@gmail.com).
% Modifications:
% ---
