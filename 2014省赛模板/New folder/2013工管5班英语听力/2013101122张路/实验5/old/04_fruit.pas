var a:array[1..10001] of longint;
    j,tmp,ans,n,i:longint;

    procedure qsort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           qsort(l,j);
         if i<r then
           qsort(i,r);
      end;

begin
assign(input,'fruit.in');
reset(input);
assign(output,'fruit.out');
rewrite(output);

readln(n);
for i:=1 to n do read(a[i]);

ans:=0;
qsort(1,n);

while n<>1 do
 begin
 tmp:=a[1]+a[2];
 ans:=ans+tmp;
 j:=1;
 while (a[j]<tmp) and (j<=n) do inc(j);
 dec(j);
 for i:=1 to j-2 do
  a[i]:=a[i+2];
 if j>1 then dec(j);
 a[j]:=tmp;
 for i:=j+2 to n do
  a[i-1]:=a[i];
 n:=n-1;
 end;

writeln(ans);


close(input);
close(output);
end.



