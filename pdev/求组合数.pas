{
NOI专刊    2007.9

算法：
prime(x)：求出1~x之间的质数，并加到b[i].dat中
calcprime(x)：求出1~x之间的质数，并计入f[i]
calc(x)：对x!分解质因数，计算出x!中各质因数的使用次数。
         即Σ((b[i].dat)^(b[i].time))=x!

因为C(n,m):=(n!)/(m!*(n-m)!)
所以对n!分解质因数，计算出n!中各质因数的使用次数，计入a
再分别对m!、(n-m)!也进行类似操作，并在a数组中减去相应的质因数的使用次数
最后将a中的质数按各自的幂相乘即可。
}

type abc=record
     dat,time:longint;
     end;

var f:array[1..10000] of boolean;
    a,b:array[1..10000] of abc;
    ans,fm,i,j,n,nm,m,tn:longint;

procedure prime(x:longint);
begin
i:=2;
nm:=0;
while i<=x do
 begin
 if f[i] then
  begin
  inc(nm);
  b[nm].dat:=i;
  end;
 inc(i);
 end;
end;

procedure calc(x:longint);
var t:longint;
begin
for i:=1 to nm do
 begin 
 t:=x;
 while t<>0 do
  begin
  t:=t div b[i].dat;
  inc(b[i].time,t);
  end;
 end;
end;

procedure calcprime(x:longint);
var tn,i,j:longint;
begin
tn:=trunc(sqrt(n))+1;
fillchar(f,sizeof(f),true);
f[1]:=false;
for i:=1 to n do
 if (i mod 2=0) or (i mod 5=0) then
  f[i]:=false;
f[2]:=true;
f[5]:=true;
for i:=3 to tn do
 if f[i] then
  begin
  j:=i+i;
  while j<=n do
   begin
   f[j]:=false;
   inc(j,i);
   end;
  end;
end;


begin

readln(n,m);
//C(n,m)

fillchar(f,sizeof(f),true);
calcprime(n);
{
f[1]:=false;
tn:=trunc(sqrt(n))+1;
for i:=2 to tn do
 for j:=2 to tn do
  f[i*j]:=false;
}
fillchar(b,sizeof(b),0);
prime(n);
calc(n);
fm:=nm;
a:=b;

fillchar(b,sizeof(b),0);
prime(m);
calc(m);
for i:=1 to nm do
 dec(a[i].time,b[i].time);

fillchar(b,sizeof(b),0);
prime(n-m);
calc(n-m);
for i:=1 to nm do
 dec(a[i].time,b[i].time);

ans:=1;
for i:=1 to fm do
 for j:=1 to a[i].time do
  ans:=ans*a[i].dat;
writeln(ans);
readln;
end.



