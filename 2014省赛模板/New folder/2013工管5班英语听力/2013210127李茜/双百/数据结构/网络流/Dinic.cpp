#include "iostream"
#include "vector"
#include "cstring"
#include "queue"
using namespace std;
int n,m;
bool vis[201];
int d[201];
int cur[201];
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
    Q.push(1);
    d[1]=0;
    vis[1]=true;
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
    return vis[m];
}
int dfs(int x,int a)
{
    if(x==m||a==0) return a;
    int flow=0,f;
    for(int &i=cur[x];i<G[x].size();i++)
    {
        Edge &e=edges[G[x][i]];
        if(d[e.to]==d[x]+1&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0)
        {
            e.flow+=f;
            edges[G[x][i]^1].flow-=f;
            flow+=f;
            a-=f;
            if(a==0) break;
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
        int flow=0;
        while(BFS())
        {
           memset(cur,0,sizeof(cur));
           flow+=dfs(1,inf);
        }
        cout<<flow<<endl;
        memset(d,0,sizeof(d));
        for(int i=1;i<=200;i++) G[i].clear();
        edges.clear();
    }
    return 0;
}
