#include "iostream"
#include "fstream"
#include "queue"
#include "cstring"
using namespace std;
const int inf=10000000;
int n,m,s,t;
int cap[500][500],flow[500][500];
int a[500],p[500];
int EK()
{
    queue<int> Q;
    memset(flow,0,sizeof(flow));
    memset(p,-1,sizeof(p));
    int f=0;
    while(1)
    {
        memset(a,0,sizeof(a));
        a[s]=inf;
        Q.push(s);
        while(!Q.empty())
        {
            int u=Q.front();Q.pop();
            for(int v=1;v<=2*n;v++)
            {
                if(!a[v]&&cap[u][v]-flow[u][v])
                {
                    p[v]=u;Q.push(v);
                    a[v]=a[u]<cap[u][v]-flow[u][v]?a[u]:cap[u][v]-flow[u][v];
                }
            }
        }
        if(a[t+n]==0) break;
        for(int u=t+n;u!=s;u=p[u])
        {
            flow[p[u]][u]+=a[t+n];
            flow[u][p[u]]-=a[t+n];
        }
        f+=a[t+n];
    }
    return f;
}
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    int S,E;
    while(cin>>n>>m)
    {
        cin>>s>>t;
        for(int i=1;i<=n;i++)
        {
            cin>>cap[i][i+n];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>S>>E;
            cap[S+n][E]=inf;
            cap[E+n][S]=inf;
        }
        cout<<EK()<<endl;
        memset(cap,0,sizeof(cap));
    }
    return 0;
}
