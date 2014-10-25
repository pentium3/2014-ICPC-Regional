#include "iostream"
#include "cstdio"
#include "fstream"
#include "cstring"
using namespace std;
int map[301][301],f[301][301];
int l[301][301],r[301][301],h[301][301];
int s[301][301],sum[301][301];
const int inf=1000000;
int getsum(int x,int y,int cx,int cy)
{
    return sum[cx][cy]-sum[x-1][cy]-sum[cx][y-1]+sum[x-1][y-1];
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
    int MAX=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&map[i][j]);
            //cin>>map[i][j];
            if(!map[i][j]) map[i][j]=-inf;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j]=s[i-1][j]+(map[i][j]>0?map[i][j]:0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j]=sum[i][j-1]+s[i][j];
    //悬线求障碍点
    for(int i=1;i<=n;i++)
    {
        int lx=0,rx=m+1;
        for(int j=1;j<=m;j++)
        {
            if(map[i][j]!=-inf) l[i][j]=lx; //不是障碍，继承前一个点的第一个障碍
            else {lx=j;l[i][j]=lx;}
        }
        for(int j=m;j>=1;j--)
        {
            if(map[i][j]!=-inf) r[i][j]=rx;
            else {rx=j;r[i][j]=rx;}
        }
    }
    //计算极大子矩形
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(map[i-1][j]==-inf||i==1) h[i][j]=1;
            else
            {
                h[i][j]=h[i-1][j]+1;
                l[i][j]=max(l[i][j],l[i-1][j]);
                r[i][j]=min(r[i][j],r[i-1][j]);
            }
            //int tmp=getsum(i-h[i][j]+1,l[i][j]+1,i,r[i][j]-1);
            int tmp=0;
            for(int a=i-h[i][j]+1;a<=i;a++)
            {
                for(int b=l[i][j]+1;b<=r[i][j]-1;b++)
                    tmp+=map[a][b];
            }
            if(tmp>MAX) MAX=tmp;
        }
    }
    cout<<MAX<<endl;
    }
    return 0;
}
