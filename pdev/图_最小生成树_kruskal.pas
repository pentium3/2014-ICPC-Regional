{
�㷨���裺
1����ͼ�еı߰�Ȩֵ��С��������
2������С�����˳�����������мӱߡ�
      �����ÿһ���ߣ�u��v��ʱ�����u��V�����㶼�������У�һ����ӣ��ͻع��ɻ�·�����Է����ñߣ����������һ���ߡ�
3��ֱ�����n-1���ߡ�
}
type abc=record
     x,y,dat:longint;
     end;

var a:array[1..1000] of abc;
    n,m,i,ans:longint;
    f:array[1..1000] of longint;

function find(x:longint):longint;
begin
if f[x]=0 then exit(x);
if f[x]=x then exit(x);
if f[f[x]]=0 then exit(f[x]);
exit(find(f[x]));
end;

procedure union(s:longint);
var x,y:longint;
begin
x:=find(a[s].x);
f[a[s].x]:=x;
y:=find(a[s].y);
f[a[s].y]:=y;
if x<>y then
 begin
 inc(ans,a[s].dat);
 f[y]:=x;
 end;
end;

    procedure sort(l,r: longint);
      var
         i,j,x: longint;
         y:abc;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2].dat;
         repeat
           while a[i].dat<x do
            inc(i);
           while x<a[j].dat do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;


begin
readln(n,m);
for i:=1 to m do
 readln(a[i].x,a[i].y,a[i].dat);

sort(1,m);

ans:=0;
fillchar(f,sizeof(f),0);
for i:=1 to m do union(i);

writeln(ans);

end.
