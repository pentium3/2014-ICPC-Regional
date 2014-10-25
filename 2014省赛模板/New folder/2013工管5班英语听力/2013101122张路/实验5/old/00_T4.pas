var n,x,y,t,i,j:longint;
    a:array[0..11,0..11] of longint;
    f:array[0..11,0..11,0..11,0..11] of longint;

function max(a,b,c,d,e:longint):longint;
var t:longint;
begin
t:=a;
if b>t then t:=b;
if c>t then t:=c;
if d>t then t:=d;
if e>t then t:=e;
exit(t);
end;

begin
assign(input,'0004.in');
reset(input);
assign(output,'0004.out');
rewrite(output);

fillchar(a,sizeof(a),0);

readln(n);
repeat
 readln(x,y,t);
 if x<>0 then a[x,y]:=t;
until x=0;
{
for i:=1 to n do
 begin
 for j:=1 to n do
  write(a[i,j],' ');
 writeln;
 end;
}
fillchar(f,sizeof(f),0);
f[1,1,1,1]:=a[1,1];
for i:=1 to n do
 for j:=1 to n do
  for x:=1 to n do
   for y:=1 to n do
    begin
    if ((i<>x) or (y<>j)) or
       ((i=x) and (j=y) and (i=n) and (j=n)) then
     begin
     f[i,j,x,y]:=max(f[i-1,j,x-1,y],
                     f[i-1,j,x,y-1],
                     f[i,j-1,x-1,y],
                     f[i,j-1,x,y-1],
                     f[i,j,x,y]);
     f[i,j,x,y]:=f[i,j,x,y]+a[i,j]+a[x,y];
     end;
    end;

writeln(f[n,n,n,n]-a[n,n]);

close(input);
close(output);
end.