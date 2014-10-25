#include "iostream"
#include "cstdio"
#include "cstring"
using namespace std;
int n;
int link[301],LX[301],RX[301],W[301][301],slack[301];
bool S[301],T[301];
const int inf=100000000;
bool dfs(int u)
{
    S[u]=true;
    for(int v=1;v<=n;v++)
    {
        if(T[v]) continue;
        int t=LX[u]+RX[v]-W[u][v];
        if(!t)
        {
            T[v]=true;
            if(!link[v]||dfs(link[v]))
            {
                link[v]=u;
                return true;
            }
        }
        else if(t<slack[v]) slack[v]=t;
    }
    return false;
}
void update()
{
    int a=1<<30;
    for(int i=1;i<=n;i++) //ny 找最小slack
       if(!T[i]&&slack[i]<a) a=slack[i];
    for(int i=1;i<=n;i++)  //nx
        if(S[i]) LX[i]-=a;
    for(int i=1;i<=n;i++) //ny
        if(T[i]) RX[i]+=a;
        else slack[i]-=a;
}
int KM()
{
    memset(link,0,sizeof(link));
    memset(RX,0,sizeof(RX));
    for(int i=1;i<=n;i++) //nx
        for(int j=1;j<=n;j++) //ny
            LX[i]=max(LX[i],W[i][j]);
    for(int i=1;i<=n;i++) //nx
    {
        for(int j=1;j<=n;j++)
            slack[j]=inf;
        while(1)
        {
            memset(S,0,sizeof(S));
            memset(T,0,sizeof(T));
            if(dfs(i)) break;
            else update();
        }
    }
    int res=0;
    for(int i=1;i<=n;i++) //ny
       if(link[i]) res+=W[link[i]][i];
    return res;
}
int main()
{
    freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=-1)
    {
       for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
          scanf("%d",&W[i][j]);
       int ans=KM();
       printf("%d\n",ans);
    }
    return 0;
}
