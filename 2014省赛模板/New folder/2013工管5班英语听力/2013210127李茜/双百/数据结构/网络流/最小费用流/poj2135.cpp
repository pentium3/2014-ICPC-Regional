#include "iostream"
#include "cstdio"
#include "vector"
#include "queue"
#include "cstring"
using namespace std;
const int inf=200000000;
struct edge
{
    int u,v,cap,flow,cost;
};
vector<edge> Edge;
vector<int> G[1005];
bool inq[1005];
int d[1005],p[1005],a[1005];
int N,M,U,V,w;
void add(int u,int v,int cap,int cost)
{
    edge tmp;
    tmp.u=u;tmp.v=v;tmp.cap=cap;tmp.flow=0;tmp.cost=cost;
    Edge.push_back(tmp);
    tmp.u=v;tmp.v=u;tmp.cap=0;tmp.cost=-cost;
    Edge.push_back(tmp);
    int m=Edge.size();
    G[u].push_back(m-2);
    G[v].push_back(m-1);
}
bool spfa(int s,int t,int &flow,int &cost)
{
    for(int i=0;i<=t;i++) d[i]=(i==s?0:inf);
    memset(p,0,sizeof(p));
    a[s]=inf;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        inq[u]=false;
        for(int i=0;i<G[u].size();i++)
        {
            edge &e=Edge[G[u][i]];
            if(e.cap>e.flow&&d[e.v]>d[u]+e.cost)
            {
                d[e.v]=d[u]+e.cost;
                p[e.v]=G[u][i];
                a[e.v]=min(a[u],e.cap-e.flow);
                if(!inq[e.v]) {Q.push(e.v);inq[e.v]=true;}
            }
        }
    }
    if(d[t]==inf) return false;
    flow+=a[t];
    cost+=d[t]*a[t];
    int u=t;
    while(u!=s)
    {
        Edge[p[u]].flow+=a[t];
        Edge[p[u]^1].flow-=a[t];
        u=Edge[p[u]].u;
    }
    return true;
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=M;i++)
    {
        scanf("%d%d%d",&U,&V,&w);
        add(U,V,1,w);
        add(V,U,1,w);
    }
    add(0,1,2,0);
    add(N,N+1,2,0);
    int flow=0,cost=0;
    while(spfa(0,N+1,flow,cost));
    printf("%d\n",cost);
}

