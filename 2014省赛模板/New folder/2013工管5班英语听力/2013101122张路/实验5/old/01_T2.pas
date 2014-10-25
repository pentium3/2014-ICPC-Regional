var ans,n,k:longint;

procedure dfs(s,m,l:longint);
var i,mn,mx:longint;
function min(a,b:longint):longint;
begin
if a<b then exit(a) else exit(b);
end;
begin
if l=0 then
 begin
 if s=k then inc(ans);
 end
else
 begin
 mn:=l div (k-s);
 for i:=mn to m do
  dfs(s+1,min(i,l-i),l-i);
 end;
end;

begin
assign(input,'0102.in');
reset(input);
assign(output,'0102.out');
rewrite(output);

readln(n,k);

ans:=0;
//step,max,last
dfs(0,n,n);

writeln(ans);

close(input);
close(output);
end.
