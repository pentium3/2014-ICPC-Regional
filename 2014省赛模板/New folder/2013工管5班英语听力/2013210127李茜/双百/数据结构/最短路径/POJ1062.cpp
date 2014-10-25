#include "iostream"
#include "vector"
#include "cstring"
#include "queue"
#include "fstream"
using namespace std;
int lev[101];
int value[101];
int d[101];
bool vis[101];
const int inf=100000000;
int m,n,x,t,v;
struct point
{
    int p,w;
};
struct dd
{
    int d,p;
    bool operator < (const dd &a) const
    {
        return d > a.d;
    }
};
vector<point> G[101];
int dijkstra()
{
    for(int i=2;i<=n;i++)
        d[i]=inf;
    d[1]=0;
    priority_queue<dd> Q;
    dd tmp;tmp.d=d[1];tmp.p=1;
    Q.push(tmp);
    while(!Q.empty())
    {
        dd xx=Q.top();Q.pop();
        int x=xx.p;
        if(vis[x]) continue;
        vis[x]=true;
        for(int i=0;i<G[x].size();i++)
        {
            if(d[x]+G[x][i].w<d[G[x][i].p]&&!vis[G[x][i].p])
            {
                d[G[x][i].p]=d[x]+G[x][i].w;
                tmp.d=d[G[x][i].p];tmp.p=G[x][i].p;
                Q.push(tmp);
            }
        }
    }
    int res=inf;
    for(int i=1;i<=n;i++)
        if(d[i]+value[i]<res) res=d[i]+value[i];
    return res;
}
int main()
{

    while(cin>>m>>n)
    {
    for(int i=1;i<=n;i++)
    {
        cin>>value[i]>>lev[i]>>x;
        for(int j=1;j<=x;j++)  //邻接表
        {
            cin>>t>>v;
            point tmp;tmp.p=t;tmp.w=v;
            G[i].push_back(tmp);
        }
    }
    int res=inf;
    for(int i=1;i<=n;i++)  //枚举冒险者的等级，本题最神的化简方式
    {
        memset(vis,false,sizeof(vis));
        int nowLev=lev[i];
        for(int j=1;j<=n;j++)
        {
            if(lev[j]>nowLev||nowLev-lev[j]>m)
                vis[j]=true;
        }
        int tt=dijkstra();
        if(tt<res) res=tt;
    }
    cout<<res<<endl;
    for(int i=1;i<=100;i++) G[i].clear();
    }
}
