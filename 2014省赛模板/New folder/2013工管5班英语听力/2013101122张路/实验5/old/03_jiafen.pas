var a:array[1..1000] of longint;
    path,f:array[0..1000,0..1000] of longint;
    n,i,j,k,tmp,max,mx,q:longint;

procedure pre(x,y:longint);
begin
if (x>0) and (y>=x) then
 begin
 write(path[x,y],' ');
 pre(x,path[x,y]-1);
 pre(path[x,y]+1,y)
 end;
end;

begin
readln(n);
for i:=1 to n do read(a[i]);

fillchar(f,sizeof(f),0);
for i:=1 to n do
 begin
 f[i,i]:=a[i];
 path[i,i]:=i;
 end;
for i:=1 to n-1 do
 begin
 f[i,i+1]:=a[i]+a[i+1];
 path[i,i+1]:=i;
 end;

for q:=1 to n do
begin

for i:=1 to n-q do
 begin
 j:=i+q;
 max:=0;
 mx:=0;
 for k:=i to j do
  begin
  tmp:=f[i,k-1]*f[k+1,j]+a[k];
  if tmp>max then
   begin
   max:=tmp;
   mx:=k;
   end;
  end;
 if max>f[i,j] then
  begin
  f[i,j]:=max;
  path[i,j]:=mx;
  end;
 end;

end;

writeln(f[1,n]);

pre(1,n);
writeln;

end.
