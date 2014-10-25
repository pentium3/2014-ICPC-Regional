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

//  1.开一个大的bool型数组prime[]，大小就是n+1就可以了.
//  先把所有的下标为奇数的标为true,下标为偶数的标为false.
//  2.然后：
//    for( i=3; i<=sqrt(n); i+=2 )
//    {   if(prime)
//        for( j=i+i; j<=n; j+=i ) prime[j]=false;
//    }
//  3.最后输出bool数组中的值为true的单元的下标，就是所求的n以内的素数了。
//
//原理很简单，就是当i是质(素)数的时候，i的所有的倍数必然是合数。
//如果i已经被判断不是质数了，那么再找到i后面的质数来把这个质数的倍数筛掉。

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


