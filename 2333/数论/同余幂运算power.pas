Function Power(a,b,n:longint):longint;
begin
	if b=0 then exit(1);
	if b=1 then exit(a mod n);
	if b mod 2=0 then
		exit(power(a*a, b shr 1, n) mod n)
	else
		exit(power(a*a,b shr 1,n)*a mod n); 
end;{a^b mod n}{¶þ·Ö}