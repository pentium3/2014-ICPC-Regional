#include "iostream"
#include "vector"
#include "cstring"
#include "queue"
using namespace std;
int n,m;
bool vis[201];
int d[201];
int cur[201];
int p[201];
int num[201];
const int inf=100000000;
struct Edge
{
    int from,to,cap,flow;
};
vector<int> G[201];
vector<Edge> edges;
void AddEdge(int from,int to,int cap)
{
    int m;
    Edge tmp;
    tmp.from=from;tmp.to=to;tmp.cap=cap;tmp.flow=0;
    edges.push_back(tmp);
    tmp.from=to;tmp.to=from;tmp.cap=0;tmp.flow=0;
    edges.push_back(tmp);
    m=edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
}
bool BFS()
{
    memset(vis,0,sizeof(vis));
    queue<int> Q;
    Q.push(m);
    d[m]=0;
    vis[m]=true;
    while(!Q.empty())
    {
        int x=Q.front();Q.pop();
        for(int i=0;i<G[x].size();i++)
        {
            Edge &e=edges[G[x][i]];
            if(!vis[e.to]&&e.cap>e.flow)
            {
                vis[e.to]=1;
                d[e.to]=d[x]+1;
                Q.push(e.to);
            }
        }
    }
    return vis[1];
}
int Augment()
{
    int x=m,a=inf;
    while(x!=1)
    {
        Edge &e=edges[p[x]];
        a=min(a,e.cap-e.flow);
        x=edges[p[x]].from;
    }
    x=m;
    while(x!=1)
    {
        edges[p[x]].flow+=a;
        edges[p[x]^1].flow-=a;
        x=edges[p[x]].from;
    }
    return a;
}
int Maxflow()
{
    int flow=0;
    BFS();
    memset(num,0,sizeof(num));
    for(int i=1;i<=m;i++) num[d[i]]++;
    int x=1;
    memset(cur,0,sizeof(cur));
    while(d[1]<m)
    {
        if(x==m)
        {
            flow+=Augment();
            x=1;
        }
        int ok=0;
        for(int &i=cur[x];i<G[x].size();i++)
        {
            Edge &e=edges[G[x][i]];
            if(e.cap>e.flow&&d[x]==d[e.to]+1)
            {
                ok=1;
                p[e.to]=G[x][i];
                cur[x]=i;
                x=e.to;
                break;
            }
        }
        if(!ok)
        {
            int k=m-1;
            for(int i=0;i<G[x].size();i++)
            {
                Edge &e=edges[G[x][i]];
                if(e.cap>e.flow) k=min(k,d[e.to]);
            }
            if(--num[d[x]]==0) break;
            num[d[x]=k+1]++;
            cur[x]=0;
            if(x!=1) x=edges[p[x]].from;
        }
    }
    return flow;
}
int main()
{
    int S,E,C;
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>S>>E>>C;
            AddEdge(S,E,C);
        }
        cout<<Maxflow()<<endl;
        memset(d,0,sizeof(d));
        memset(p,0,sizeof(p));
        for(int i=1;i<=200;i++) G[i].clear();
        edges.clear();
    }
    return 0;
}
