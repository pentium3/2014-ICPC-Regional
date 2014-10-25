#include "iostream"
#include "fstream"
using namespace std;
int n,m;
int a[101][101];
int f[101][101];
int res=-1;
int dp(int i,int j)
{
    if(f[i][j]) return f[i][j];
    int x,y,tmp=0,Max=1;
    for(int s=1;s<=4;s++)
    {
        switch(s)
        {
        case 1:
            x=i;y=j-1;
            break;
        case 2:
            x=i;y=j+1;
            break;
        case 3:
            x=i-1;y=j;
            break;
        case 4:
            x=i+1;y=j;
            break;
        }
        if(x>0&&x<=n&&y>0&&y<=m)
        {
            if(a[x][y]<a[i][j]) tmp=dp(x,y)+1;
            if(tmp>Max) Max=tmp;
        }
    }
    return f[i][j]=Max;
}
int main()
{

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
          cin>>a[i][j];
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           dp(i,j);
       }
   }
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           if(f[i][j]>res) res=f[i][j];
       }
   }
   cout<<res<<endl;
   return 0;
}
