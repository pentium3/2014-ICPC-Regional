#include "iostream"
#include "cstdio"
#include "stack"
#include "vector"
using namespace std;
vector<int> G[201];
stack<int> S;
int pre[201],lowlink[201],sccno[201],clock,cnt,in[201],out[201];
void dfs(int u)
{
    pre[u]=lowlink[u]=++clock;
    S.push(u);
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!pre[v])
        {
            dfs(v);
            lowlink[u]=min(lowlink[u],lowlink[v]);
        }
        else if(!sccno[v]) lowlink[u]=min(lowlink[u],lowlink[v]);
    }
    if(lowlink[u]==pre[u])
    {
        cnt++;
        while(1)
        {
            int x=S.top();S.pop();
            sccno[x]=cnt;
            if(x==u) break;
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,V;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        while(scanf("%d",&V)&&V)
            G[i].push_back(V);
    for(int i=1;i<=n;i++)
        if(!pre[i]) dfs(i);
    for(int i=1;i<=cnt;i++) in[i]=out[i]=1;
    for(int u=1;u<=n;u++)
        for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(sccno[u]!=sccno[v]) in[sccno[v]]=out[sccno[u]]=0;
    }
    int a=0,b=0;
    for(int i=1;i<=cnt;i++)
    {
        if(in[i]) a++;
        if(out[i]) b++;
    }
    int ans=max(a,b);
    printf("%d\n",a);
    printf("%d\n",ans=(cnt==1?0:ans));
    return 0;

}
