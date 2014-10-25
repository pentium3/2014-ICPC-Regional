var visited,visitedx,visitedy:array[1..9,1..9] of boolean;
    a:array[1..9,1..9] of longint;
    tmp,i,j,max:longint;

procedure answer;
var i,j,ans:longint;
begin
ans:=0;
for i:=1 to 9 do
 for j:=1 to 9 do
  begin
  if (i=1) or (i=9) or (j=1) or (j=9) then
   ans:=ans+a[i,j]*6
  else if (i=2) or (i=8) or (j=2) or (j=8) then
   ans:=ans+a[i,j]*7
  else if (i=3) or (i=7) or (j=3) or (j=7) then
   ans:=ans+a[i,j]*8
  else if (i=4) or (i=6) or (j=4) or (j=6) then
   ans:=ans+a[i,j]*9
  else if (i=5) and (j=5) then
   ans:=ans+a[i,j]*10;
  end;
if ans>max then max:=ans;
{
writeln(ans);
for i:=1 to 9 do
 begin
 for j:=1 to 9 do write(a[i,j],' ');
 writeln;
 end;
writeln;
writeln;
}
end;

procedure dfs(x,y:longint);
var tmp,i:longint;
begin
if a[x,y]<>0 then
 begin
{ tmp:=a[x,y];
 visitedx[x,tmp]:=true;
 visitedy[y,tmp]:=true;
 if (x>=1) and (x<=3) then
  begin
  if (y>=1) and (y<=3) then visited[1,tmp]:=true;
  if (y>=4) and (y<=6) then visited[4,tmp]:=true;
  if (y>=7) and (y<=9) then visited[7,tmp]:=true;
  end
 else if (x>=4) and (x<=6) then
  begin
  if (y>=1) and (y<=3) then visited[2,tmp]:=true;
  if (y>=4) and (y<=6) then visited[5,tmp]:=true;
  if (y>=7) and (y<=9) then visited[8,tmp]:=true;
  end
 else if (x>=7) and (x<=9) then
  begin
  if (y>=1) and (y<=3) then visited[3,tmp]:=true;
  if (y>=4) and (y<=6) then visited[6,tmp]:=true;
  if (y>=7) and (y<=9) then visited[9,tmp]:=true;
  end;}
 if (x=9) and (y<9) then dfs(1,y+1)
  else if (x=9) and (y=9) then answer
  else dfs(x+1,y);
 end

 else

 begin
 if (x>=1) and (x<=3) then
  begin
  if (y>=1) and (y<=3) then tmp:=1;
  if (y>=4) and (y<=6) then tmp:=4;
  if (y>=7) and (y<=9) then tmp:=7;
  end
 else if (x>=4) and (x<=6) then
  begin
  if (y>=1) and (y<=3) then tmp:=2;
  if (y>=4) and (y<=6) then tmp:=5;
  if (y>=7) and (y<=9) then tmp:=8;
  end
 else if (x>=7) and (x<=9) then
  begin
  if (y>=1) and (y<=3) then tmp:=3;
  if (y>=4) and (y<=6) then tmp:=6;
  if (y>=7) and (y<=9) then tmp:=9;
  end;
 for i:=1 to 9 do
  begin
  if (not visitedx[x,i]) and (not visitedy[y,i]) and (not visited[tmp,i]) then
   begin
   a[x,y]:=i;
   visitedx[x,i]:=true;
   visitedy[y,i]:=true;
   visited[tmp,i]:=true;

   if (x=9) and (y<9) then dfs(1,y+1)
   else if (x=9) and (y=9) then answer
   else dfs(x+1,y);

   a[x,y]:=0;
   visitedx[x,i]:=false;
   visitedy[y,i]:=false;
   visited[tmp,i]:=false;
   end;
  end;
 end;
end;



begin
assign(input,'sudoku.in');
reset(input);
assign(output,'sudoku.out');
rewrite(output);

fillchar(visited,sizeof(visited),false);
fillchar(visitedx,sizeof(visitedx),false);
fillchar(visitedy,sizeof(visitedy),false);
max:=0;
fillchar(a,sizeof(a),0);



for i:=1 to 9 do
 for j:=1 to 9 do
  read(a[i,j]);

for i:=1 to 9 do
 for j:=1 to 9 do
  begin
  if a[i,j]<>0 then
  begin
  tmp:=a[i,j];
  visitedx[i,tmp]:=true;
  visitedy[j,tmp]:=true;
  if (i>=1) and (i<=3) then
   begin
   if (j>=1) and (j<=3) then visited[1,tmp]:=true;
   if (j>=4) and (j<=6) then visited[4,tmp]:=true;
   if (j>=7) and (j<=9) then visited[7,tmp]:=true;
   end
  else if (i>=4) and (i<=6) then
   begin
   if (j>=1) and (j<=3) then visited[2,tmp]:=true;
   if (j>=4) and (j<=6) then visited[5,tmp]:=true;
   if (j>=7) and (j<=9) then visited[8,tmp]:=true;
   end
  else if (i>=7) and (i<=9) then
   begin
   if (j>=1) and (j<=3) then visited[3,tmp]:=true;
   if (j>=4) and (j<=6) then visited[6,tmp]:=true;
   if (j>=7) and (j<=9) then visited[9,tmp]:=true;
   end;
  end;
  end;

dfs(1,1);

if max=0 then writeln(-1) else writeln(max);

close(input);
close(output);
end.


