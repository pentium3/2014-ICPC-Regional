{
NOIר��    2007.9

�㷨��
prime(x)�����1~x֮������������ӵ�b[i].dat��
calcprime(x)�����1~x֮���������������f[i]
calc(x)����x!�ֽ��������������x!�и���������ʹ�ô�����
         ����((b[i].dat)^(b[i].time))=x!

��ΪC(n,m):=(n!)/(m!*(n-m)!)
���Զ�n!�ֽ��������������n!�и���������ʹ�ô���������a
�ٷֱ��m!��(n-m)!Ҳ�������Ʋ���������a�����м�ȥ��Ӧ����������ʹ�ô���
���a�е����������Ե�����˼��ɡ�
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



