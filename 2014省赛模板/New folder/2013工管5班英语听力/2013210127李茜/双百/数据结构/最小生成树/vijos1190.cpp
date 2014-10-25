#include "iostream"
#include "cstdio"
#include "queue"
using namespace std;
int p[301];
struct edge
{
    int u,v,c;
    bool operator < (const edge &a) const
    {
        return c > a.c;
    }
};
int find(int x) {return x!=p[x]?p[x]=find(p[x]):x;}
int main()
{
    freopen("in.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    edge tmp;
    priority_queue<edge> Q;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&tmp.u,&tmp.v,&tmp.c);
        Q.push(tmp);
    }
    int count=0,u,v,res=0,MAX=0;
    for(int i=1;i<=n;i++) p[i]=i;
    while(count<n-1)
    {
        tmp=Q.top();Q.pop();
        u=find(tmp.u);v=find(tmp.v);
        if(u!=v)
        {
            p[v]=u;
            res+=tmp.c;
            count++;
            if(tmp.c>MAX) MAX=tmp.c;
        }
    }
    printf("%d %d\n",n-1,MAX);

}
