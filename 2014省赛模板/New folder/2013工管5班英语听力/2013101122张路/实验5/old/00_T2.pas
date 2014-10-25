var n,kk,i,j,k,q,p,x,y:longint;
    a:array[1..100] of longint;
    f:array[1..50,1..50,0..10] of int64;
    s:string;
    tmp,mx:int64;

begin
assign(input,'0002.in');
reset(input);
assign(output,'0002.out');
rewrite(output);

readln(n,kk);
readln(s);
for i:=1 to n do
 val(s[i],a[i]);

for i:=1 to n do
 for j:=i to n do
  begin
  tmp:=a[i];
  for k:=i+1 to j do
   begin
   tmp:=tmp*10;
   tmp:=tmp+a[k];
   end;
  f[i,j,0]:=tmp;
  end;

for q:=1 to kk do
 begin
 for k:=q to n do
  for i:=1 to n-k do
   begin
   j:=i+k;
   mx:=0;
   for p:=i to j-1 do
    for x:=0 to q-1 do
     begin
     y:=q-1-x;
     if f[i,p,x]*f[p+1,j,y]>mx then
      mx:=f[i,p,x]*f[p+1,j,y];
     end;
   f[i,j,q]:=mx;
   end;
 end;

writeln(f[1,n,kk]);

close(input);
close(output);
end.











