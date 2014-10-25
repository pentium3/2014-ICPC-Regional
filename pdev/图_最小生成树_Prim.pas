const vmax=1000;
var 
w:array[1..vmax,1..vmax] of longint;
i,j,k,v,e:longint;
w:存储邻接矩阵
v:结点数
e:边数

procedure prim(v0:longint);
var flag:array[1..vmax] of boolean; 
      min,prevk,nextk:longint;
begin
 fillchar(flag,sizeof(flag),0);
 flag[v0]:=true;           //STEP2
 for i:=1 to v-1 do          //STEP5
   begin
    min:=maxlongint;

    for k:=1 to v do  
      if flag[k] then  
        for j:=1 to v do          //STEP3
          if (not flag[j]) and (w[k,j]<min) and (w[k,j]<>0) then
            begin
            min:=w[k,j];
            nextk:=j;    
            prevk:=k;    
            end;

    if min<>maxlongint then        
      begin
      flag[nextk]:=true;            //STEP4
      writeln(prevk,‘ ’,nextk,‘ ’,min);          
      end;

   end;
end;

begin
fillchar(w,sizeof(w),0);
readln(v,e);
for k:=1 to e do
 begin
 read(i,j);
 readln(w[i,j]);
 w[j,i]:=w[i,j];
 end;

prim(1);       //STEP1

end.