#include<iostream>
#include<algorithm>
#include<cstring>
#include "fstream"
using namespace std;
int a[25][1010];
int f[25][1010];
int max(int x,int y)
{
    return x>y? x:y;
}
int main()
{
    int c,i,j,k,n,m,temp;
    cin>>c;
    while(c--)
    {
          cin>>n>>m;
          memset(a,0,sizeof(a));
          for(i=1;i<=n;i++)
             for(j=1;j<=m;j++)
                    cin>>a[i][j];
         f[1][1]=a[1][1];
          for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                   {
                       if(i==1&&j==1) continue;//边界条件 
                       if(i==1) {temp=f[i][j-1]+a[i][j];}
                       else
                         if(j==1) {temp=f[i-1][j]+a[i][j];}
                       else
                         temp=max(f[i-1][j]+a[i][j],f[i][j-1]+a[i][j]);
                       for(k=1;k<j;k++)  //精彩的倒判断倍数 
                       {
                           if(j%k==0)
                           {
                              temp=max(temp,f[i][k]+a[i][j]);
                           }
                       }
                       f[i][j]=temp;
                   }
             cout<<f[n][m]<<endl;
    }
    return 0;
}

