var i,j,k,n,now,t1,t2:longint;
    v,a,b,q1,q2:array[0..1000] of longint;
    g:array[1..1000,1..1000] of boolean;
    ok:boolean;

    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=b[(l+r) div 2];
         repeat
           while b[i]<x do
            inc(i);
           while x<b[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

procedure bfs(x:longint);
var i:longint;
begin
for i:=1 to n do
 if g[x,i] then
  begin
  if v[i]=v[x] then
   begin
   writeln(0);
   close(input);
   close(output);
   halt;
   end
  else if v[i]=0 then
   begin
   v[i]:=3-v[x];
   bfs(i);
   end;
  end;
end;

begin
assign(input,'twostack.in');
reset(input);
assign(output,'twostack.out');
rewrite(output);

readln(n);
for i:=1 to n do
 read(a[i]);

fillchar(g,sizeof(g),false);

for i:=1 to n-1 do                            //1 5 4 6 3 2
 for j:=i+1 to n do
  begin
  ok:=false;
  for k:=j+1 to n do
   if (a[k]<a[i]) and (a[i]<a[j]) then
    begin
    ok:=true;
    break;
    end;
  if ok then
   begin
   g[a[i],a[j]]:=true;
   g[a[j],a[i]]:=true;
   end;
  end;

{
for i:=1 to n do
 begin
 for j:=1 to n do
  if g[i,j] then write(1)
   else write(0);
 writeln;
 end;
}

fillchar(v,sizeof(v),0);
for i:=1 to n do
 if v[i]=0 then
  begin
  v[i]:=1;
  bfs(i);
  end;

//for i:=1 to n do write(v[i]);
//writeln;

t1:=0;
t2:=0;
now:=0;
fillchar(q1,sizeof(q1),0);
fillchar(q2,sizeof(q2),0);

b:=a;
sort(1,n);

for i:=1 to n do
 begin
 if v[a[i]]=1 then
  begin
  inc(t1);
  q1[t1]:=a[i];
  write('a ');
  end
 else if v[a[i]]=2 then
  begin
  inc(t2);
  q2[t2]:=a[i];
  write('c ');
  end;
 while (q1[t1]=b[now+1]) and (q1[t1]<>0) do
  begin
  if v[q1[t1]]=1 then
   write('b ');
 { else if v[q1[t1]]=2 then
   write('d');     }
  dec(t1);
  inc(now);
  if t1=0 then break;
  end;
  while (q2[t2]=b[now+1]) and (q2[t2]<>0) do
  begin
{  if v[q2[t2]]=1 then
   write('b ')
  else }if v[q2[t2]]=2 then
   write('d ');
  dec(t2);
  inc(now);
  if t2=0 then break;
  end;
 end;
  while (q1[t1]=b[now+1]) and (q1[t1]<>0) do
  begin
  if v[q1[t1]]=1 then
   write('b ');
 { else if v[q1[t1]]=2 then
   write('d');     }
  dec(t1);
  inc(now);
  if t1=0 then break;
  end;
  while (q2[t2]=b[now+1]) and (q2[t2]<>0) do
  begin
{  if v[q2[t2]]=1 then
   write('b ')
  else }if v[q2[t2]]=2 then
   write('d ');
  dec(t2);
  inc(now);
  if t2=0 then break;
  end;
writeln;

close(input);
close(output);
end.






