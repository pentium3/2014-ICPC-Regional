#include "iostream"
#include "vector"
#include "cstring"
#include "queue"
using namespace std;
int n,m;
int cap[201][201];
int flow[201][201];
int a[201];
int p[201];
const int inf=100000000;
int Edmonds_Karp()
{
    queue<int> Q;
    memset(flow,0,sizeof(flow));
    memset(p,-1,sizeof(p));
    int f=0,minflow=inf;
    while(1)
    {
        memset(a,0,sizeof(a));
        a[1]=inf;
        Q.push(1);
        while(!Q.empty())
        {
            int u=Q.front();Q.pop();
            for(int v=1;v<=m;v++)
                if(!a[v]&&cap[u][v]>flow[u][v])
            {
                p[v]=u;Q.push(v);
                a[v]=a[u]<cap[u][v]-flow[u][v]?a[u]:cap[u][v]-flow[u][v];
            }
        }
        if(a[m]==0) break;
        for(int u=m;u!=1;u=p[u])
        {
            flow[p[u]][u]+=a[m];
            flow[u][p[u]]-=a[m];
        }
        f+=a[m];
    }
    return f;
}
int main()
{
    int S,E,C;
    while(cin>>n>>m)
    {
        memset(cap,0,sizeof(cap));
        for(int i=1;i<=n;i++)
        {
            cin>>S>>E>>C;
            cap[S][E]+=C; //÷ÿ±ﬂ∫œ≤¢£ø
        }
        cout<<Edmonds_Karp()<<endl;
    }
    return 0;
}
