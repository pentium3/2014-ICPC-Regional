#include<stdio.h>
#include<math.h>
#define N 10000001
bool prime[N];
int main()
{
   int i, j;
   for(i=2; i<N; i++)
      if(i%2) prime[i]=false;
        else prime[i]=true;
   for(i=3; i<=sqrt(N); i+=2)
   {   if(prime[i])
       for(j=i+i; j<N; j+=i)
            prime[j]=false;
   }
   for(i=2; i<n; i++)
    if( prime[i] )
         printf("%d ",i);
   return 0;
}

//  1.��һ�����bool������prime[]����С����n+1�Ϳ�����.
//  �Ȱ����е��±�Ϊ�����ı�Ϊtrue,�±�Ϊż���ı�Ϊfalse.
//  2.Ȼ��
//    for( i=3; i<=sqrt(n); i+=2 )
//    {   if(prime)
//        for( j=i+i; j<=n; j+=i ) prime[j]=false;
//    }
//  3.������bool�����е�ֵΪtrue�ĵ�Ԫ���±꣬���������n���ڵ������ˡ�
//
//ԭ��ܼ򵥣����ǵ�i����(��)����ʱ��i�����еı�����Ȼ�Ǻ�����
//���i�Ѿ����жϲ��������ˣ���ô���ҵ�i���������������������ı���ɸ����

var a:array[1..100000000] of boolean;
    tmp,i,j,n:longint;

begin
assign(output,'p.out');
rewrite(output);

readln(n);
fillchar(a,sizeof(a),false);
for i:=1 to n do
 if (i mod 2<>0) and (i mod 5<>0) then a[i]:=true;
a[2]:=true;
a[5]:=true;
a[1]:=false;

tmp:=trunc(sqrt(n));
i:=3;
while i<=tmp do
 begin
 j:=2*i;
 while j<=n do
  begin
  a[j]:=false;
  inc(j,i);
  end;
 inc(i,2);
 end;

for i:=1 to n do
 if a[i] then writeln(i);

close(output);
end.


