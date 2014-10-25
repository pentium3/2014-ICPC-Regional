function gcd(a,b:longint):longint;
var
    r:longint;
begin
    repeat
		r:=a mod b;
		a:=b;
		b:=r
    until r=0;
    exit(a);
end;{log(n)}
