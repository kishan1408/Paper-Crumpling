%% This function  finds the centroid of a list Y .
%%It can either be a row or a column vector.(But not a matrix)
function x=centroid(Y)
l=length(Y);

a=1:l;a=uint16(a);Y=uint16(Y);
if iscolumn(Y)==1 && sum(Y)~=0
x=sum(a'.*Y)/sum(Y);
elseif iscolumn(Y)==0 && sum(Y)~=0
x=sum(a.*Y)/sum(Y);
else
    x=1;
end
end
%%
% History:
% 20.03.2014  Written by kishan (kishan1408@gmail.com).
% Modifications:
% ---