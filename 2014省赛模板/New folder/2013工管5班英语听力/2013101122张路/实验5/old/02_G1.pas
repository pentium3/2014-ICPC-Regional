var n,i,sm,ans:longint;
    a:array[1..1000] of longint;

begin
assign(input,'a.in');
reset(input);
assign(output,'a.out');
rewrite(output);

readln(n);
sm:=0;
for i:=1 to n do
 begin
 read(a[i]);
 sm:=sm+a[i];
 end;
sm:=sm div n;
ans:=0;

for i:=1 to n-1 do
 begin
 if a[i]>sm then
  begin
  a[i+1]:=a[i+1]+a[i]-sm;
  a[i]:=sm;
  inc(ans);
  end
 else if a[i]<sm then
  begin
  a[i+1]:=a[i+1]-(sm-a[i]);
  a[i]:=sm;
  inc(ans);
  end;
 end;

writeln(ans);

close(input);
close(output);
end.
