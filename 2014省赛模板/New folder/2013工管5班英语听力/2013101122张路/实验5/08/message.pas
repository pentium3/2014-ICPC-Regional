var f:array[0..50,0..50,0..50,0..50] of longint;
    a:array[1..50,1..50] of longint;
    m,n,i,j,x1,x2,y1,y2:longint;

function max(a,b,c,d:longint):longint;
var tmp:longint;
begin
tmp:=a;
if b>tmp then tmp:=b;
if c>tmp then tmp:=c;
if d>tmp then tmp:=d;
exit(tmp);
end;

begin
assign(input,'message.in');
reset(input);
assign(output,'message.out');
rewrite(output);

fillchar(f,sizeof(f),193);
f[1,1,1,1]:=0;
readln(m,n);
for i:=1 to m do
 begin
 for j:=1 to n do read(a[i,j]);
 readln;
 end;

for x1:=1 to m do
 for y1:=1 to n do
  for x2:=1 to m do
   for y2:=1 to n do
    begin
    if ((x1<>x2) and (y1<>y2)) or ((x1=m) and (y1=n)) then
    f[x1,y1,x2,y2]:=max(f[x1-1,y1,x2-1,y2],
                        f[x1-1,y1,x2,y2-1],
                        f[x1,y1-1,x2-1,y2],
                        f[x1,y1-1,x2,y2-1])+a[x1,y1]+a[x2,y2];
    end;

writeln(f[m,n,m,n]);
readln;
close(input);
close(output);
end.
