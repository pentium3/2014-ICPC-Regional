#include "iostream"
#include "cstring"
#include "queue"
#include "fstream"
using namespace std;
int n,m;
int cap[101][101];
int flow[101][101];
int a[101],p[101];
const int inf=100000000;
int s,t;
int Edmonds_Karp()
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
            for(int v=0;v<=2*n+1;v++)
            {
                if(!a[v]&&cap[u][v]-flow[u][v])
                {
                    p[v]=u;Q.push(v);
                    a[v]=a[u]<cap[u][v]-flow[u][v]?a[u]:cap[u][v]-flow[u][v];
                }
            }
        }
        if(a[t+n+1]==0) break;
        for(int u=t+n+1;u!=s;u=p[u])
        {
            flow[p[u]][u]+=a[t+n+1];
            flow[u][p[u]]-=a[t+n+1];
        }
        f+=a[t+n+1];
    }
    return f;
}
int main()
{
    int Case,S,E;
    cin>>Case;
    while(Case--)
    {
        cin>>n>>m;
        memset(cap,0,sizeof(cap));
        for(int i=1;i<=n-1;i++)
        {
            cin>>cap[i][n+i+1];
        }
        cap[0][n+1]=cap[n][2*n+1]=inf;
        for(int i=1;i<=m;i++) //这个吊炸天的拆点
        {
            cin>>S>>E;
            cap[S+n+1][E]=inf;
            cap[E+n+1][S]=inf;//有向图无视这个
        }
        s=0;t=n;
        int res=Edmonds_Karp();
        if(res==0) cout<<"Min!"<<endl;
        else if(res>=inf) cout<<"Max!"<<endl;
        else cout<<res<<endl;
    }
    return 0;
}
