type node=^re;
      re=record
       dat:longint;
       nxt:node;
       end;
     abc=record
      x,y,t:longint;
      end;

var tx,i,head,tail,mx,x,y,n,m:longint;
    visited:array[1..100000] of boolean;
    t:array[1..100000] of node;
    q,f,g,a:array[1..100000] of longint;
    tmp:node;
    z:array[1..100000] of abc;

function min(a,b,c:longint):longint;
var t:longint;
begin
t:=a;
if b<t then t:=b;
if c<t then t:=c;
exit(t);
end;

function max(a,b,c:longint):longint;
var t:longint;
begin
t:=a;
if b>t then t:=b;
if c>t then t:=c;
exit(t);
end;

procedure insert(x,y:longint);
var p:node;
begin
new(p);
p^.nxt:=t[x];
p^.dat:=y;
t[x]:=p;
end;

begin
assign(input,'trade.in');
reset(input);
assign(output,'trade.out');
rewrite(output);

readln(n,m);
for i:=1 to n do read(a[i]);
for i:=1 to n do t[i]:=nil;
for i:=1 to m do
 begin
 readln(z[i].x,z[i].y,z[i].t);
 if z[i].t=1 then insert(z[i].x,z[i].y)
  else if z[i].t=2 then
   begin
   insert(z[i].x,z[i].y);
   insert(z[i].y,z[i].x);
   end;
 end;

fillchar(f,sizeof(f),127 div 3);
fillchar(g,sizeof(g),0);
f[1]:=a[1];
g[n]:=a[n];

fillchar(visited,sizeof(visited),false);
fillchar(q,sizeof(q),0);
head:=0;   tail:=1;
visited[1]:=true;
q[1]:=1;

while head<tail do
 begin
 inc(head);
 visited[q[head]]:=false;
 tmp:=t[q[head]];
 while tmp<>nil do
  begin
  tx:=tmp^.dat;
 {
  f[tx]:=min(f[q[head]],f[tx],a[tx]);
  tmp:=tmp^.nxt;

  if not visited[tx] then
   begin
   inc(tail);
   q[tail]:=tx;
   visited[tx]:=true;
   end;
  }
  if (f[q[head]]<f[tx]) or (a[tx]<f[tx]) then
   begin
   f[tx]:=min(f[q[head]],f[tx],a[tx]);
   if not visited[tx] then
    begin
    inc(tail);
    q[tail]:=tx;
    visited[tx]:=true;
    end;
   end;
  tmp:=tmp^.nxt;
  end;
 end;

for i:=1 to n do if t[i]<>nil then dispose(t[i]);
for i:=1 to n do t[i]:=nil;
for i:=1 to m do
 begin
 if z[i].t=1 then insert(z[i].y,z[i].x)
  else if z[i].t=2 then
   begin
   insert(z[i].x,z[i].y);
   insert(z[i].y,z[i].x);
   end;
 end;

fillchar(visited,sizeof(visited),false);
fillchar(q,sizeof(q),0);
head:=0;   tail:=1;
visited[n]:=true;
q[1]:=n;

while head<tail do
 begin
 inc(head);
 visited[q[head]]:=false;
 tmp:=t[q[head]];
 while tmp<>nil do
  begin
  tx:=tmp^.dat;
{
  g[tx]:=max(g[q[head]],g[tx],a[tx]);
  tmp:=tmp^.nxt;

  if not visited[tx] then
   begin
   inc(tail);
   q[tail]:=tx;
   visited[tx]:=true;
   end;
}
  if (g[q[head]]>g[tx]) or (a[tx]>g[tx]) then
   begin
   g[tx]:=max(g[q[head]],g[tx],a[tx]);
   if not visited[tx] then
    begin
    inc(tail);
    q[tail]:=tx;
    visited[tx]:=true;
    end;
   end;
  tmp:=tmp^.nxt;
  end;
 end;

mx:=0;
for i:=1 to n do
 if (g[i]-f[i])>mx then mx:=g[i]-f[i];

writeln(mx);

close(input);
close(output);
end.
