procedure gen_primes;
var
    primes:array[1..maxn]of boolean;
    i,j,x,count:longint;
begin
    count:=0;
    fillchar(primes,sizeof(primes),true);
    primes[1]:=false;
    x:=trunc(sqrt(maxn));
    for i:=2 to x do
		if primes[i] then
			begin
				inc(count);
				for j:=i to (maxn div i) do
					primes[i]:=false;
			end;
end;{O(n*sqrt(n))}
