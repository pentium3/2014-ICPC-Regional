procedure factor(n:longint);
var
    i,x:longint;
begin
	x:=trunc(sqrt(n))+1;
	for i:=2 to x do
		while n mod i=0 do
			begin
				write(i,'*');
				n = n div i
			end;
	if n>1 then write(n);
end;{k*sqrt(n)}
