fwrite(a,'d');pause(1);fwrite(a,'j');pause(1);
for i=1:200
    fwrite(a,'l');
    pause(0.02);
end
fwrite(a,'j');
for i=1:200
    fwrite(a,'l');
    pause(0.02);
end
for k=1:10
fwrite(a,'d');pause(1);fwrite(a,'j');pause(1);
for i=1:200
    fwrite(a,'l');pause(0.005);
   
end
fwrite(a,'k');
for i=1:200
    fwrite(a,'l');pause(0.005);
    
end
fwrite(a,'e');
end