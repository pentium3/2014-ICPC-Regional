Program cat;
//uses sysutils;

Const
  maxn=1010;


Type
    link=^node;
    node=record
        v,w       :integer;
        next      :link;
    end;
    htype=record
        v,d,p     :integer;
    end;


Var
    n,s,hl        :integer;
    heap          :array[0..maxn]of htype;
    hpos          :array[1..maxn]of integer;
    g             :array[1..maxn]of link;
    a             :array[1..maxn,1..maxn]of longint;


Procedure insert(u,v,w:integer);
var
     x:link;
begin
     new(x);
     x^.v:=v; x^.w:=w;
     x^.next:=g[u]; g[u]:=x;
end;


Procedure init;
var
     u,v,w :integer;
     i,j,k,t:longint;
begin
     readln(t,n);
     s:=1;
     for t:=1 to t do
         begin
              readln(u,v,w);
              if (a[u,v]>w)or(a[u,v]=0) then
                 begin
                      a[u,v]:=w;
                      a[v,u]:=w;
                 end;
              insert(u,v,a[u,v]);
              insert(v,u,a[v,u]);
         end;
end;


Procedure swap(a,b:integer);
begin
     heap[0]:=heap[a];
     heap[a]:=heap[b];
     heap[b]:=heap[0];
     hpos[heap[a].v]:=a;
     hpos[heap[b].v]:=b;
end;


procedure decrease(i:integer);
begin
     while (i<>1)and(heap[i].d<heap[i div 2].d) do
        begin
           swap(i,i div 2);
           i:=i div 2;
        end;
end;


procedure heapify;
var
     i:integer;
begin
     i:=2;
     while i<=hl do
        begin
           if(i<hl)and(heap[i+1].d<heap[i].d) then
           inc(i);
           if heap[i].d<heap[i div 2].d then
              begin
                 swap(i,i div 2);
                 i:=i*2;
              end
              else break
        end;
end;


procedure relax(u,v,w:integer);
begin
     if w+heap[hpos[u]].d<heap[hpos[v]].d then
        begin
           heap[hpos[v]].p:=u;
           heap[hpos[v]].d:=w+heap[hpos[u]].d;
           decrease(hpos[v]);
        end;
end;


procedure dijkstra;
var
     u:integer;
     p:link;
begin
     for u:=1 to n do
        begin
           heap[u].v:=u;
           heap[u].d:=maxint;
           hpos[u]:=u;
        end;
     heap[s].p:=s;heap[s].d:=0;swap(1,s);
     hl:=n;
     while hl>0 do
        begin
           u:=heap[1].v;
           swap(1,hl);dec(hl);heapify;
           p:=g[u];
           while p<>nil do
              begin
                 if hpos[p^.v]<=hl then
                 relax(u,p^.v,p^.w);
                 p:=p^.next;
              end;
        end;
end;


procedure path(i:integer);
begin
     if heap[hpos[i]].p<>s then
     path(heap[hpos[i]].p);
     write('->',i);
end;


procedure show;
var
    i:integer;
begin
    {for i:=1 to n do
    if i<>s then
       begin
          write(s,'->',i,': ',heap[hpos[i]].d,': ',s);
          path(i);
          writeln;
       end    }
    writeln(heap[hpos[n]].d);
end;


begin
     {assign(input,'cat.in');
     assign(output,'cat.out');
     reset(input);
     rewrite(output);   }
     //time:=now;
     init;
     dijkstra;
     show;
     //writeln((now-time)*86400000:8:8);
    { close(input);
     close(output);      }
end.
