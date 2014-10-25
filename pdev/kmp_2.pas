//NOIµ¼¿¯  Mar.20th.2009

var t,p:string;
    lp,lt,i,q,k:longint;
    pf:array[1..1000] of longint;
    ok:boolean;

begin
ok:=false;
readln(t);
readln(p);
lt:=length(t);
lp:=length(p);

fillchar(pf,sizeof(pf),0);
pf[1]:=0;
k:=0;
for i:=2 to lp do
 begin
 while (k>0) and (p[k+1]<>p[i]) do
  k:=pf[k];
 if p[k+1]=p[i] then inc(k);
 pf[i]:=k;
 end;

q:=1;
for i:=1 to lt do
 begin
 while (q>0) and (t[i]<>p[q+1]) do
  q:=pf[q];
 if p[q+1]=t[i] then inc(q);
 if q=lp then
  begin
  ok:=true;
  writeln('START:',i-lp);
  end;
 end;

if not ok then writeln('404: NOT FOUND');

readln;
end.




