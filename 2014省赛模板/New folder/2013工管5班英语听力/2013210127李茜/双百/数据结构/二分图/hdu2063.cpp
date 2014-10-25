#include "iostream"
#include "cstdio"
#include "cstring"
using namespace std;
int G[501][501];
int link[501];
bool vis[501];
int k,m,n,U,V;
bool dfs(int u)
{
    for(int v=1;v<=n;v++)
    {
        if(G[u][v]&&!vis[v])
        {
            vis[v]=true;
            if(!link[v]||dfs(link[v]))
            {
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while(scanf("%d%d%d",&k,&m,&n)!=-1&&k)
    {
    int res=0;
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&U,&V);
        G[U][V]=1;
    }
    for(int u=1;u<=m;u++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(u)) res++;
    }
    printf("%d\n",res);
    memset(G,0,sizeof(G));
    memset(link,0,sizeof(link));
    }
    return 0;
}
