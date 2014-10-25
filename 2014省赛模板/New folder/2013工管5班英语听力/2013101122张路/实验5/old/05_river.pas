var v:array[0..31] of boolean;
    ta:array[1..1000] of longint;
    a:array[0..10000000] of boolean;
    f:array[0..31] of longint;
    sm,l,tmp,ttmp,min,i,j,s,t,m:longint;

      procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=ta[(l+r) div 2];
         repeat
           while ta[i]<x do
            inc(i);
           while x<ta[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=ta[i];
                ta[i]:=ta[j];
                ta[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

begin
assign(input,'river.in');
reset(input);
assign(output,'river.out');
rewrite(output);

fillchar(a,sizeof(a),false);
fillchar(v,sizeof(v),false);
fillchar(f,sizeof(f),127 div 3);

readln(l);
readln(s,t,m);
sm:=0;
ttmp:=0;

for i:=1 to m do read(ta[i]);
sort(1,m);

for i:=1 to m do
 begin
 tmp:=ta[i];
 tmp:=tmp-sm;
 if tmp-ttmp>3*t then
  begin
  l:=l-(tmp-ttmp+1-3*t-1);
  sm:=sm+(tmp-ttmp+1-3*t-1);
  tmp:=ttmp+3*t;
  end;
 a[tmp]:=true;
 ttmp:=tmp;
 end;

if l-tmp>3*t then
 l:=tmp+3*t+1;

if s=t then
 begin
 min:=0;
 for i:=1 to m do
  if ta[i] mod s=0 then
   inc(min);
 writeln(min);
 close(input);
 close(output);
 halt;
 end;

v[0]:=true;
f[0]:=0;
for i:=s to l+t-1 do
 begin
 min:=maxlongint;
 for j:=s to t do
  if i-j>=0 then
   begin
   tmp:=(i-j) mod 30;
   if (f[tmp]<min) and (v[tmp]) then
    min:=f[tmp];
   end;
 if min<>maxlongint then
  begin
  v[i mod 30]:=true;
  f[i mod 30]:=min;
  if a[i] then inc(f[i mod 30]);
  end;
 end;

{
for i:=1 to l+t-1 do
 write(f[i],' ');
writeln;
}
min:=maxlongint;
for i:=l to l+t-1 do
 if v[i mod 30] and (f[i mod 30]<min) then
  min:=f[i mod 30];

writeln(min);


close(input);
close(output);
end.



