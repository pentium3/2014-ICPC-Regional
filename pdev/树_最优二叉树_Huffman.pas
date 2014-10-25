//合并果子
//n个结点，构造一棵最优二叉树，输出总权值

var a:array[1..50000] of longint;
    n,x,y,i,j,k,sum:longint;

procedure qsort(l,r: longint);
var i,j,x,y: longint;
begin
 i:=l;
 j:=r;
 x:=a[(l+r) div 2];
 repeat
  while a[i]<x do inc(i);
  while x<a[j] do dec(j);
  if not(i>j) then
   begin
   y:=a[i];
   a[i]:=a[j];
   a[j]:=y;
   inc(i);
   j:=j-1;
   end;
 until i>j;
 if l<j then qsort(l,j);
 if i<r then qsort(i,r);
end;

begin
readln(n);
for i:=1 to n do read(a[i]);

qsort(1,n);

i:=1;

while i<n do
 begin
 x:=a[i];   y:=a[i+1];
 sum:=sum+x+y;
 i:=i+2;
 j:=i;
 while (a[j]<(x+y)) and (j<n+1) do inc(j);
 for k:=n downto j do
  a[k+1]:=a[k];
 a[j]:=x+y;
 inc(n);
 end;

writeln(sum);
readln;
end.