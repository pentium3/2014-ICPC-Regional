var tmp,nm,x,i,j,k,p,q,n,m,max:longint;
    dic:array[1..1000] of string;
    s,ss:string;
    ok:boolean;
    sum,f:array[0..1000,0..1000] of longint;

begin
assign(input,'0103.in');
reset(input);
assign(output,'0103.out');
rewrite(output);

{readln(times);
for time:=1 to times do
 begin
}
 readln(p,q);
 s:='';
 for i:=1 to p do
  begin
  readln(ss);
  s:=s+ss;
  end;
 n:=length(s);
 readln(nm);
 for i:=1 to nm do readln(dic[i]);

 for i:=n-1 downto 0 do
  for j:=i to n do
   begin
   tmp:=0;
   ss:=copy(s,i,j-i+1);
   ok:=false;
   for k:=1 to nm do
    begin
//    l:=length(dic[k]);
    x:=0;
    x:=pos(dic[k],ss);
    if x=1 then
     begin
     ok:=true;
     break;
     end;
    end;
   if ok then
    sum[i,j]:=sum[i+1,j]+1
   else sum[i,j]:=sum[i+1,j];
   end;
{
for i:=1 to n do
 begin
 for j:=i to n do
  write(sum[i,j],' ');
 writeln;
 end;
}
 for i:=1 to n do
  f[1,i]:=sum[1,i];

 //f[i,j]:=max(f[i-1,k]+sum[k+1,j])
 for i:=2 to q do
  begin
  for j:=i+1 to n do
   begin
   max:=0;
   for k:=i+1 to j-1 do
    if f[i-1,k]+sum[k+1,j]>max then
     max:=f[i-1,k]+sum[k+1,j];
   f[i,j]:=max;
   end;
  end;

 writeln(f[q,n]);
// end;

close(input);
close(output);
end.


