var a,b,k,n,m,ans:int64;
    i,j:longint;
    f:array[0..1000,0..1000] of int64;

begin
assign(input,'factor.in');
reset(input);
assign(output,'factor.out');
rewrite(output);

readln(a,b,k,n,m);

fillchar(f,sizeof(f),0);
for i:=1 to k do
 begin
 f[i,0]:=1;
 f[i,1]:=i;
 f[i,i]:=1;
 f[i,i-1]:=i;
 end;

for i:=1 to k do
 for j:=1 to i do
  if f[i,j]=0 then
   f[i,j]:=(f[i-1,j]+f[i-1,j-1]) mod 10007;

ans:=f[k,n];
a:=a mod 10007;
b:=b mod 10007;
for i:=1 to n do
 begin
 ans:=ans*a;
 ans:=ans mod 10007;
 end;
for i:=1 to k-n do
 begin
 ans:=ans*b;
 ans:=ans mod 10007;
 end;

writeln(ans);

close(input);
close(output);
end.

