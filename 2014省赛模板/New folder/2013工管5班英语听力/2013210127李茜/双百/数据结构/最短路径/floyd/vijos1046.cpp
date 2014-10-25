#include "iostream"
#include "cstdio"
#include "cstring"
using namespace std;
int G[101][101];
int d[101][101];
const int inf=100000000;
int main()
{
    freopen("in.txt","r",stdin);
    int n,m,u,v,w;
    int MIN=inf;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
        {
              G[i][j]=G[j][i]=d[i][j]=d[j][i]=inf;
              if(i==j) G[i][j]=G[j][i]=d[i][j]=d[j][i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            G[u][v]=G[v][u]=d[u][v]=d[v][u]=w;
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<k;i++)
                for(int j=1;j<i;j++)
                  MIN=min(MIN,d[i][j]+G[j][k]+G[k][i]);
            for(int i=1;i<=n;i++)
              for(int j=1;j<=n;j++)
                 d[i][j]=d[j][i]=d[i][j]<d[i][k]+d[k][j]?d[i][j]:d[i][k]+d[k][j];
        }
        if(MIN>=inf) printf("No solution.\n");
        else printf("%d\n",MIN);
        memset(G,0,sizeof(G));
        memset(d,0,sizeof(d));
    }
}
