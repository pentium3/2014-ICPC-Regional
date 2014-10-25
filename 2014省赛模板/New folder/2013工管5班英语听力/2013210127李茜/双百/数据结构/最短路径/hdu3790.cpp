#include "iostream"
#include "fstream"
#include "cstring"
#include "cstdio"
using namespace std;
int p[1001],d[1001];
int n,m,s,t;
const int inf=0x6FFFFFFF;
int dd[1001][1001],pp[1001][1001];
bool vis[1001];
/*
struct edge
{
    int u,v,d,p;
}Edge[200001];
void Bellman_Ford() //TLE,ORZ
{
    for(int i=1;i<=n;i++) //Initialize
    {
        d[i]=inf;
        p[i]=inf;
        if(i==s) {d[i]=0;p[i]=0;}
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=2*m;j++)
        {
            if(d[Edge[j].u]+Edge[j].d<d[Edge[j].v]) //Relax
            {
                d[Edge[j].v]=d[Edge[j].u]+Edge[j].d;
                p[Edge[j].v]=p[Edge[j].u]+Edge[j].p;
            }
            else if(d[Edge[j].u]+Edge[j].d==d[Edge[j].v]) //Realx_2
            {
                if(p[Edge[j].u]+Edge[j].p<p[Edge[j].v])
                {
                    p[Edge[j].v]=p[Edge[j].u]+Edge[j].p;
                }
            }
        }
    }
}*/
void Dijkstra()
{
    for(int i=1;i<=n;i++) //Initialize
    {
        d[i]=p[i]=inf;
        if(i==s) {d[i]=p[i]=0;}
    }
    for(int i=1;i<=n;i++)
    {
        int MinC=inf,MinD=inf,k;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&(d[j]<MinC||(d[j]==MinC&&p[j]<MinD)))
            {
                MinC=d[j];
                MinD=p[j];
                k=j;
            }
        }
        vis[k]=true;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&(d[k]+dd[k][j]<d[j]||(d[k]+dd[k][j]==d[j]&&p[k]+pp[k][j]<p[j])))
            {
                d[j]=d[k]+dd[k][j];
                p[j]=p[k]+pp[k][j];
            }
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int A,B,D,P;
    while(scanf("%d%d",&n,&m)&&n!=0&&m!=0)
    {
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        dd[i][j]=inf;
        pp[i][j]=inf;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d%d",&A,&B,&D,&P);
        if(D<dd[A][B]||(dd[A][B]==D&&P<pp[A][B]))
        {
        dd[A][B]=dd[B][A]=D;
        pp[A][B]=pp[B][A]=P;
        }
    }
    scanf("%d%d",&s,&t);
    Dijkstra();
    printf("%d %d\n",d[t],p[t]);
    memset(vis,0,sizeof(vis));
    }
    return 0;
}
