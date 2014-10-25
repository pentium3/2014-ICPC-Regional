var q,d:array[1..1000] of longint;
    a:array[1..1000,1..1000] of longint;
    visited:array[1..1000] of boolean;
    head,tail,s,n,dt,i,j:longint;

begin
assign(input,'spfa.in');
reset(input);

fillchar(d,sizeof(d),127 div 3);
fillchar(visited,sizeof(visited),false);
fillchar(a,sizeof(a),0);

readln(s);
d[s]:=0;
readln(n);
for i:=1 to n do
 for j:=1 to n do
  begin
  read(dt);
  a[i,j]:=dt;
  a[j,i]:=dt;
{ if dt<>0 then
   begin
   if i=s then d[j]:=dt;
   if j=s then d[i]:=dt;
   end;
  }
  end;

head:=0;
q[1]:=s;
visited[s]:=true;
tail:=1;
while head<tail do
 begin
 inc(head);
 visited[q[head]]:=false;
 for i:=1 to n do
  begin
  if (a[q[head],i]>0) and (d[q[head]]+a[q[head],i]<d[i]) then
   begin
   d[i]:=d[q[head]]+a[q[head],i];
   if not visited[i] then
    begin
    inc(tail);
    q[tail]:=i;
    visited[i]:=true;
    end;
   end;
  end;
 end;

for i:=1 to n do
 write(d[i],' ');
writeln;

close(input);
end.