var i,n,x,a1,a0,b1,b0,ans:longint;

function gcd(a,b:longint):longint;
begin
if b=0 then exit(a)
else exit(gcd(b,a mod b));
end;

function lcm(a,b:longint):longint;
begin
exit((a*b) div gcd(a,b));
end;


begin
assign(input,'son.in');
reset(input);
assign(output,'son.out');
rewrite(output);

readln(n);
for i:=1 to n do
 begin
 ans:=0;
 readln(a0,a1,b0,b1);
 for x:=a1 to b1 do
  begin
  if (gcd(x,a0)=a1) and (lcm(x,b0)=b1) then
   inc(ans);
  end;

 writeln(ans);
 end;

close(input);
close(output);
end.
