var n,k,p,i,j,tmp:longint;
    f:array[0..200000,0..50] of longint;
    c,pre:array[1..200000] of longint;
    a:array[0..200000] of longint;
    ans:int64;

begin
assign(input,'hotel.in');
reset(input);
assign(output,'hotel.out');
rewrite(output);

readln(n,k,p);
fillchar(f,sizeof(f),0);

for i:=1 to n do
 begin
 readln(c[i],a[i]);
 for j:=0 to k do
  f[i,j]:=f[i-1,j];
 inc(f[i,c[i]]);
 end;

fillchar(pre,sizeof(pre),0);
//fillchar(sum,sizeof(sum),0);

for i:=n downto 1 do
 if pre[i]=0 then
 begin
 tmp:=i;
 while (a[tmp]>p) do dec(tmp);
 if tmp<>0 then
  begin
  for j:=tmp to i do
   pre[j]:=tmp;
  end;
 end;
{
for i:=1 to n do
 sum[i]:=f[i,c[i]];
}
{
write('PRE    ');
for i:=1 to n do write(pre[i],' ');
writeln;
write('SUM    ');
for i:=1 to n do write(sum[i],' ');
writeln;
}
ans:=0;
for i:=1 to n do
 begin
 if a[i]>p then
  begin
  if pre[i]>0 then inc(ans,f[pre[i],c[i]]);
  end
 else
  inc(ans,f[i,c[i]]-1);
 end;

writeln(ans);

close(input);
close(output);
end.
