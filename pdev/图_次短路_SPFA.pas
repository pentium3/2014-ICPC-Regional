{
˼·������SPFA��һ�����·���������·�ϵ�ÿ���߼�¼������
Ȼ��ö��ɾȥ���·�ϵ�ÿһ���ߣ�����һ�����·��
ɾ��֮����õ��������·�еĵ���Сֵ���ζ�·

���С������������ͬ��
������С��������Ȼ��ö��ɾ�����е�ÿһ��������һ�顣
������õ�......�е���Сֵ����С������

ע�⣺
��Ϊ���·\��С�����������ж����
���Կ��ܳ�����õĴζ�·=���·����С������=��С���������������
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
