var a:array[1..26] of longint;
    tmp,l,i,ans,max,min:longint;
    s:string;

procedure qsort(l,r: longint);
var i,j,x,y: longint;
begin
i:=l; j:=r;
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
assign(input,'word.in');
reset(input);
assign(output,'word.out');
rewrite(output);

readln(s);
l:=length(s);
for i:=1 to l do
 begin
 tmp:=ord(s[i])-96;
 inc(a[tmp]);
 end;

qsort(1,26);

max:=a[26];
min:=0;
for i:=1 to 26 do
 begin
 if a[i]<>0 then
  begin
  min:=a[i];
  break;
  end;
 end;

ans:=max-min;

if (ans=1) or (ans=0) then
 begin
 writeln('No Answer');
 writeln(0);
 close(input);
 close(output);
 halt;
 end;

for i:=2 to ans-1 do
 if ans mod i=0 then
  begin
  writeln('No Answer');
  writeln(0);
  close(input);
  close(output);
  halt;
  end;

writeln('Lucky Word');
writeln(ans);
close(input);
close(output);
end.

