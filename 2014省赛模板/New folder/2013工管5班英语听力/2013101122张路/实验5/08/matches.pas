const count:array[0..9] of integer=(6,2,5,5,4,5,6,3,7,6);
var a:array[0..9999] of longint;
    n,i,j,ans:longint;

begin
assign(input,'matches.in');
reset(input);
assign(output,'matches.out');
rewrite(output);

for i:=0 to 9 do
 a[i]:=count[i];
for i:=10 to 99 do
 a[i]:=count[i div 10]+count[i mod 10];
for i:=100 to 999 do
 a[i]:=count[i div 100]+
       count[i mod 10]+
       count[(i-100*(i div 100)) div 10];
for i:=1000 to 9999 do
 a[i]:=count[i div 1000]+
       count[i mod 10]+
       count[(i-100*(i div 100)) div 10]+
       count[(i-1000*(i div 1000)) div 100];

readln(n);
n:=n-4;
ans:=0;

for i:=0 to 1111 do
 for j:=0 to 1111 do
  if a[i]+a[j]+a[i+j]=n then inc(ans);


writeln(ans);

close(input);
close(output);
end.
