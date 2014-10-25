var s,tmp,ans:int64;
    l,r,w,v:array[1..200000] of longint;
    a,b:array[1..200000] of int64;
    al,ar,mn,mx,mid,i,n,m:longint;

function process(x:longint):int64;
var i:longint;
    ta:int64;
begin
ta:=0;
{
for i:=1 to m do
 begin
 tm:=0;
 sm:=0;
 for j:=l[i] to r[i] do
  if w[j]>=x then
   begin
   inc(sm);
   inc(tm,v[j]);
   end;
 inc(ta,tm*sm);
 end;
}

a[0]:=0;  b[0]:=0;
for i:=1 to n do
 begin
 a[i]:=a[i-1];
 b[i]:=b[i-1];
 if w[i]>=x then
  begin
  inc(a[i]);
  inc(b[i],v[i]);
  end;
 end;
for i:=1 to m do
 inc(ta,((a[r[i]]-a[l[i]-1])*(b[r[i]]-b[l[i]-1])));

exit(ta);
end;

function min(a,b:int64):int64;
begin
if a>b then exit(b) else exit(a);
end;

begin
assign(input,'qc.in');
reset(input);
assign(output,'qc.out');
rewrite(output);

mn:=maxlongint;
mx:=0;
readln(n,m,s);
for i:=1 to n do
 begin
 readln(w[i],v[i]);
 if w[i]<mn then mn:=w[i];
 if w[i]>mx then mx:=w[i];
 end;
for i:=1 to m do
 readln(l[i],r[i]);

ans:=maxlongint;
al:=mn; ar:=mx;

{
while al<ar do
 begin
 mid:=(al+ar) div 2;
 tmp:=process(mid);

 if abs(tmp-s)<=ans then
  begin
  ans:=abs(tmp-s);
  if tmp-s>0 then al:=mid+1
   else ar:=mid-1;
  end
 else
  begin
  if tmp-s>0 then ar:=mid
   else al:=mid;
  end;
 end;
}
dec(al);  inc(ar);
while al+1<ar do
 begin
 mid:=(al+ar) shr 1;
 tmp:=process(mid);

 if tmp>s then al:=mid
  else ar:=mid;
 end;

ans:=min(abs(s-process(al)),abs(s-process(ar)));
writeln(ans);

close(input);
close(output);
end.


