#include "iostream"
#include "cstring"
#include "queue"
using namespace std;
int cap[102][102],flow[102][102];
int p[102],a[102];
int n,m,k;
const int inf=10000000000;
int EK()
{
    memset(flow,0,sizeof(flow));
    memset(p,-1,sizeof(p));
    int f=0;
    queue<int> Q;
    while(1)
    {
        memset(a,0,sizeof(a));
        Q.push(1);
        a[1]=inf;
        while(!Q.empty())
        {
            int u=Q.front();Q.pop();
            for(int v=1;v<=n+1;v++)
            {
                if(!a[v]&&cap[u][v]>flow[u][v])
                {
                    Q.push(v);p[v]=u;
                    a[v]=a[u]<cap[u][v]-flow[u][v]?a[u]:cap[u][v]-flow[u][v];
                }
            }
        }
        if(a[n+1]==0) break;
        for(int u=n+1;u!=1;u=p[u])
        {
            flow[p[u]][u]+=a[n+1];
            flow[u][p[u]]-=a[n+1];
        }
        f+=a[n+1];
    }
    return f;
}
int main()
{
    int S,E,V;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>S>>E>>V;
        cap[S][E]=V;
        cap[E][S]=V;
    }
    cin>>k;
    for(int i=1;i<=k;i++) //³¬¼¶»ãµã
    {
        cin>>S;
        cap[S][n+1]=inf;
    }
    cout<<EK()<<endl;
    return 0;
}
