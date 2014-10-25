type abc=record
     w,c,no,lw,lc,rw,rc:longint;
     end;

var f:array[0..100,0..32010] of longint;
    nm,m,n,i,j,t,x,y,q,nm2:longint;
    //w,c:array[1..100] of longint;
    a:array[1..100] of abc;

begin
assign(input,'budget.in');
reset(input);
assign(output,'budget.out');
rewrite(output);

fillchar(f,sizeof(f),0);

readln(n,m);
{
for i:=1 to m do
 begin
 readln(x,y,q);
 if q=0 then
  begin
  inc(nm);
  a[nm].w:=x;
  a[nm].c:=x*y;
//f[1,a[nm].w]:=a[nm].c;
  end
 else
  begin
  inc(nm2);
  w[nm2]:=x;
  c[nm2]:=x*y;
  if a[q].l=0 then a[q].l:=nm2
   else if a[q].r=0 then a[q].r:=nm2;
  end;
 end;
}
nm:=0;
for i:=1 to m do
 begin
 readln(x,y,q);
 if q=0 then
  begin
  inc(nm);
  a[nm].w:=x;
  a[nm].c:=x*y;
  a[nm].no:=i;
  end
 else
  begin
  j:=1;
  while a[j].no<>q do inc(j);
  if a[j].lw=0 then
   begin
   a[j].lw:=x;
   a[j].lc:=x*y;
   end
  else
   begin
   a[j].rw:=x;
   a[j].rc:=x*y;
   end;
  end;
 end;

for i:=1 to nm do
 for j:=1 to n do
 // if f[i,j]=0 then
  begin
  t:=f[i-1,j];
  if (j-a[i].w>=0) then
   if (f[i-1,j-a[i].w]+a[i].c>t) then         //i
    t:=f[i-1,j-a[i].w]+a[i].c;
  if (a[i].lw<>0) and (j-a[i].w-a[i].lw>=0) then     //i+i.l
   if f[i-1,j-a[i].w-a[i].lw]+a[i].c+a[i].lc>t then
    t:=f[i-1,j-a[i].w-a[i].lw]+a[i].c+a[i].lc;
  if (a[i].rw<>0) and (j-a[i].w-a[i].rw>=0) then     //i+i.r
   if f[i-1,j-a[i].w-a[i].rw]+a[i].c+a[i].rc>t then
    t:=f[i-1,j-a[i].w-a[i].rw]+a[i].c+a[i].rc;
  if (a[i].rw<>0) and (a[i].lw<>0)
   and (j-a[i].w-a[i].lw-a[i].rw>=0) then                    //i+i.r+i.l
   if f[i-1,j-a[i].w-a[i].lw-a[i].rw]+a[i].c+a[i].lc+a[i].rc>t then
    t:=f[i-1,j-a[i].w-a[i].lw-a[i].rw]+a[i].c+a[i].lc+a[i].rc;
  //end;
  f[i,j]:=t;
 // writeln(i,' ',j,' ',t);
  end;

writeln(f[nm,n]);

close(input);
close(output);
end.


