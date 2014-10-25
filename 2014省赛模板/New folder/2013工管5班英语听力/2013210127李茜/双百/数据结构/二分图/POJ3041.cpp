#include "iostream"
#include "cstdio"
using namespace std;
int G[501][501],link[501];
bool vis[501];
int n,k;
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
    int u,v;
    int res=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&u,&v);
        G[u][v]=1;
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) res++;
    }
    printf("%d\n",res);
    return 0;
}
