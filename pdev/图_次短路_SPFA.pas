{
思路：先用SPFA求一遍最短路，并将最短路上的每条边记录下来。
然后枚举删去最短路上的每一条边，再求一遍最短路。
删边之后求得的所有最短路中的的最小值即次短路

求次小生成树？方法同上
先求最小生成树，然后枚举删除其中的每一条边再求一遍。
所有求得的......中的最小值即次小生成树

注意：
因为最短路\最小生成树可能有多个，
所以可能出现求得的次短路=最短路、次小生成树=最小生成树这样的情况
}
var path,q,d:array[1..1000] of longint;
    a:array[1..1000,1..1000] of longint;
    visited:array[1..1000] of boolean;
    tm1,tm2,min,tmp,head,tail,s,t,n,m,dt,i,j:longint;

procedure spfa2;
begin
fillchar(d,sizeof(d),127 div 3);
fillchar(visited,sizeof(visited),false);
fillchar(q,sizeof(q),0);
d[s]:=0;
head:=0;
q[1]:=s;
visited[1]:=true;
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
end;

procedure spfa1;
begin
fillchar(d,sizeof(d),127 div 3);
fillchar(visited,sizeof(visited),false);
fillchar(path,sizeof(path),0);
fillchar(q,sizeof(q),0);
d[s]:=0;
head:=0;
q[1]:=s;
visited[1]:=true;
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
   path[i]:=q[head];
   if not visited[i] then
    begin
    inc(tail);
    q[tail]:=i;
    visited[i]:=true;
    end;
   end;
  end;
 end;
end;

begin
assign(input,'spfa.in');
reset(input);
{
assign(output,'spfa.out');
rewrite(output);
}
fillchar(a,sizeof(a),0);
{readln(s,t);
readln(n);
for i:=1 to n do
 for j:=1 to n do
  begin
  read(dt);
  a[i,j]:=dt;
  a[j,i]:=dt;
  end;
}
readln(n,m,s,t);
for i:=1 to m do
 begin
 readln(tm1,tm2,dt);
 a[tm1,tm2]:=dt;
 a[tm2,tm1]:=dt;
 end;

SPFA1;
dt:=d[t];
writeln(dt);
{
for i:=1 to n do
 write(d[i],' ');
writeln;
}
//for i:=1 to n do
// begin
tmp:=t;
min:=maxlongint;
//write(tmp,' ');
while path[tmp]<>0 do
 begin
 //write(path[tmp],' ');
 //writeln(tmp,'--',path[tmp]);
 tm1:=a[tmp,path[tmp]];
 tm2:=a[path[tmp],tmp];
 a[tmp,path[tmp]]:=0;
 a[path[tmp],tmp]:=0;
 SPFA2;
 if (d[t]>dt) and (d[t]<min) then min:=d[t];
 a[tmp,path[tmp]]:=tm1;
 a[path[tmp],tmp]:=tm2;
 tmp:=path[tmp];
 end;
writeln(min);
// end;

close(input);
{
close(output);
}
end.
