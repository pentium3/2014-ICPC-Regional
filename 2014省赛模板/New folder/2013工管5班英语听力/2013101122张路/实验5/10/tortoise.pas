{
x:=i+j*2+k*3+l*4+1;
f[i,j,k,l]:=max(f[i-1,j,k,l],
                f[i,j-1,k,l],
                f[i,j,k-1,l],
                f[i,j,k,l-1])+score[x];
}

var f:array[-1..40,-1..40,-1..40,-1..40] of longint;
    score:array[0..1000] of longint;
    num:array[1..4] of longint;
    tmp,x,m,n,i,j,k,l:longint;

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
 assign(input,'tortoise.in');
 reset(input);
 assign(output,'tortoise.out');
 rewrite(output);

 fillchar(num,sizeof(num),0);
 fillchar(score,sizeof(score),0);

 readln(n,m);
 for i:=1 to n do read(score[i]);
 for i:=1 to m do
  begin
  read(tmp);
  inc(num[tmp]);
  end;

 for i:=0 to num[1] do
  for j:=0 to num[2] do
   for k:=0 to num[3] do
    for l:=0 to num[4] do
     begin
     x:=i+j*2+k*3+l*4+1;
     f[i,j,k,l]:=max(f[i-1,j,k,l],f[i,j-1,k,l],f[i,j,k-1,l],f[i,j,k,l-1])+score[x];
     end;

writeln(f[num[1],num[2],num[3],num[4]]);
close(input);
close(output);
end.


