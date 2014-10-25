#include "iostream"
#include "cstdio"
#include "vector"
#include "queue"
#include "cstring"
using namespace std;
struct road
{
    int v,c;
};
vector<road> G[2001];
bool inq[2001];
int d[2001];
const int inf=100000000;
void spfa()
{
    queue<int> Q;
    memset(inq,0,sizeof(inq));
    memset(d,0,sizeof(d));
    d[1]=inf;
    Q.push(1);
    while(!Q.empty())
    {
        int x=Q.front();Q.pop();
        inq[x]=false;
        for(int i=0;i<G[x].size();i++)
        {
            if(d[G[x][i].v]<min(d[x],G[x][i].c))
            {
                d[G[x][i].v]=min(d[x],G[x][i].c);
                if(!inq[G[x][i].v])
                {
                    inq[G[x][i].v]=true;
                    Q.push(G[x][i].v);
                }
            }
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,u,v,c;
    road tmp;
    bool flag=false;
    while(scanf("%d",&n)!=-1)
    {
        while(scanf("%d%d%d",&u,&tmp.v,&tmp.c)&&u!=0)
             G[u].push_back(tmp);
        spfa();
        for(int i=2;i<=n;i++) printf("%d\n",d[i]);
        for(int i=1;i<=2000;i++) G[i].clear();
    }
    return 0;
}
