var tmp,n,i,j,k,x,max,maxk:longint;
    f:array[1..1000,1..1000] of longint;
    a:array[1..1000] of longint;

begin
assign(input,'energy.in');
reset(input);
assign(output,'energy.out');
rewrite(output);

fillchar(f,sizeof(f),0);
//fillchar(fin,sizeof(fin),0);
//fillchar(top,sizeof(top),0);

readln(n);
for i:=1 to n do
 begin
 read(x);
 a[i]:=x; a[i+n]:=x;
 end;
{
for i:=1 to n do
 begin
 read(x);
 top[i]:=x;
 top[i+n]:=x;
 if i=1 then
  begin fin[n]:=x; fin[2*n]:=x; end
  else begin fin[i-1]:=x; fin[i+n-1]:=x; end;
 end;
}

{
for i:=1 to n-1 do
 for j:=i+1 to n do
  begin
  max:=0;
  maxk:=j;
  for k:=i to j-1 do
   begin
   if f[i,k]+f[k+1,j]>max then
    begin
    max:=f[i,k]+f[k+1,j];
    maxk:=k;
    end;
   end;
//f[i,j]:=max+top[i]*top[maxk]*fin[j];
  f[i,j]:=max+a[i]*a[maxk]*a[j];
  end;
}
for x:=2 to n do
 for i:=1 to 2*n-x do
  begin
  j:=i+x;
  for k:=i+1 to j-1 do
   begin
   tmp:=f[i,k]+f[k,j]+a[i]*a[j]*a[k];
   if tmp>f[i,j] then f[i,j]:=tmp;
   end;
  end;

max:=0;
for i:=1 to n do
 if f[i,i+n]>max then max:=f[i,i+n];
writeln(max);

close(input);
close(output);
end.
