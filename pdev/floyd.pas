//path[i,j]：用来输出最短路径
//floyd
var path,d:array[1..1000,1..1000] of longint;
    n,k,i,j,st,en,x,y,tmp:longint;

procedure dfs(i,j:longint);
begin
if path[i,j]>0 then
 begin
 dfs(i,path[i,j]);
 write(path[i,j],'->');
 dfs(path[i,j],j);
 end;
end;

begin
assign(input,'floyd.in');
reset(input);

fillchar(d,sizeof(d),127 div 3);

readln(n);

for i:=1 to n do d[i,i]:=0;
for i:=1 to n do
 for j:=1 to n do
  path[i,j]:=-1;

readln(st,en);
while not eof do
 begin
 readln(x,y,tmp);
 d[x,y]:=tmp;
 d[y,x]:=tmp;
 path[x,y]:=0;
 path[y,x]:=0;
 end;

for k:=1 to n do
 for i:=1 to n do
  for j:=1 to n do
   begin
   if d[i,k]+d[k,j]<d[i,j] then
    begin
    d[i,j]:=d[i,k]+d[k,j];
    path[i,j]:=k;
    end;
   end;

writeln(d[st,en]);

write(st,'->');
dfs(st,en);
writeln(en);

close(input);
end.