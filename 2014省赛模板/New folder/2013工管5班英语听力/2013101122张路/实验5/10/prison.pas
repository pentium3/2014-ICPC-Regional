type abc=record
      x,y:longint;
      t:int64;
      end;
     node=^re;
     re=record
      x,dat:longint;
      nxt:node;
      end;

var t:array[1..20000] of node;
    a:array[1..100000] of abc;
    tx:array[1..20000] of longint;
    ok,sol,yes:boolean;
    i,n,m:longint;
    l,r,mid,mx:int64;

procedure bfs(x,c:longint);
var tm:node;
begin
tm:=t[x];
while yes and (tm<>nil) do
 begin
 if tm^.dat>mid then
  begin
  if tx[tm^.x]=0 then
   begin
   tx[tm^.x]:=3-c;
   bfs(tm^.x,3-c);
   end
  else if tx[tm^.x]=c then
   begin
   yes:=false;
   exit;
   end;
  end;
 tm:=tm^.nxt;
 end;
end;

function process(x:longint):boolean;
var i:longint;
begin
yes:=true;
fillchar(tx,sizeof(tx),0);
for i:=1 to n do
 if yes and (tx[i]=0) and (t[i]<>nil) then
  begin
  tx[i]:=1;
  bfs(i,1);
  end;
exit(yes);
end;

procedure insert(a,b,c:longint);
var p:node;
begin
new(p);
p^.x:=b;
p^.dat:=c;
p^.nxt:=t[a];
t[a]:=p;
end;

begin
assign(input,'prison.in');
reset(input);
assign(output,'prison.out');
rewrite(output);

readln(n,m);
mx:=0;
for i:=1 to n do t[i]:=nil;
for i:=1 to m do
 begin
 readln(a[i].x,a[i].y,a[i].t);
 insert(a[i].x,a[i].y,a[i].t);
 insert(a[i].y,a[i].x,a[i].t);
 if a[i].t>mx then mx:=a[i].t;
 end;

sol:=false;
l:=0;   r:=mx;
while l<r do
 begin
 mid:=(l+r) div 2;
 ok:=process(mid);
 if ok then
  begin
  sol:=true;
  r:=mid;
  end
 else
  begin
  l:=mid+1;
  sol:=true;
  end;
 end;

if not sol then writeln(0)
 else writeln(r);

close(input);
close(output);
end.
