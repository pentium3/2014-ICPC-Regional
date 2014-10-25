var a:array[1..200000] of longint;
    n,i,num,tmpnum,tmpdat:longint;


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
assign(input,'count.in');
reset(input);
assign(output,'count.out');
rewrite(output);

fillchar(a,sizeof(a),0);

readln(n);
for i:=1 to n do readln(a[i]);

qsort(1,n);

num:=1;
while num<=n do
 begin
 tmpdat:=a[num];
 tmpnum:=num;
 while a[num]=tmpdat do inc(num);
 writeln(tmpdat,' ',num-tmpnum);
// dec(num);
 end;

close(input);
close(output);
end.
