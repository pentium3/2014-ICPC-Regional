var s:string;
    p1,p2,p3,i,j,tmp,tmp1,tmp2,x:longint;
    ok:boolean;

begin

assign(input,'expand.in');
reset(input);
assign(output,'expand.out');
rewrite(output);

readln(p1,p2,p3);
readln(s);

x:=pos('-',s);

while x<>0 do
begin
tmp1:=ord(s[x-1]);
tmp2:=ord(s[x+1]);
if x=1 then tmp1:=0;

ok:=false;
if ((tmp1>=97) and (tmp1<=122) and (tmp2>=97) and (tmp2<=122)) or
   ((tmp1>=48) and (tmp1<=57) and (tmp2>=48) and (tmp2<=57))
then ok:=true;

if (tmp1>=tmp2) or (not ok) then
 begin
 for i:=1 to x do write(s[i]);
 end
else if tmp2=tmp1+1 then
 begin
 for i:=1 to x-1 do write(s[i]);
//write(s[x+1]);
 end
else
 begin
 for i:=1 to x-1 do write(s[i]);
 case p1 of
 1:begin
   case p3 of
    1:begin
      if (tmp1>=65) and (tmp1<=90) then tmp1:=tmp1+32;
      if (tmp2>=65) and (tmp2<=90) then tmp2:=tmp2+32;
      for i:=tmp1+1 to tmp2-1 do
       for j:=1 to p2 do write(chr(i));
      end;
    2:begin
      if (tmp1>=65) and (tmp1<=90) then tmp1:=tmp1+32;
      if (tmp2>=65) and (tmp2<=90) then tmp2:=tmp2+32;
      for i:=tmp2-1 downto tmp1+1 do
       for j:=1 to p2 do write(chr(i));
      end;
   end;
   end;
 2:begin
   case p3 of
    1:begin
      if (tmp1>=97) and (tmp1<=122) then tmp1:=tmp1-32;
      if (tmp2>=97) and (tmp2<=122) then tmp2:=tmp2-32;
      for i:=tmp1+1 to tmp2-1 do
       for j:=1 to p2 do write(chr(i));
      end;
    2:begin
      if (tmp1>=97) and (tmp1<=122) then tmp1:=tmp1-32;
      if (tmp2>=97) and (tmp2<=122) then tmp2:=tmp2-32;
      for i:=tmp2-1 downto tmp1+1 do
       for j:=1 to p2 do write(chr(i));
      end;
   end;
   end;
 3:begin
   for i:=tmp1+1 to tmp2-1 do
    for j:=1 to p2 do write('*');
   end;
 end;
//write(s[x+1]);
 end;

delete(s,1,x);
x:=pos('-',s);
end;

//delete(s,1,1);
writeln(s);

close(input);
close(output);

end.
