#include "iostream"
#include "cstdio"
#include "queue"
#include "cstring"
#include "algorithm"
using namespace std;
int p[1001];
bool vis[1001];
int find(int x) {return x!=p[x]?p[x]=find(p[x]):x;}
struct edge
{
    int u,v,c;
}Edge[10001];
bool cmp(edge a,edge b)
{
    return a.c<b.c;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,m,k,U,V,C;
    edge tmp;
    while(scanf("%d%d%d",&n,&m,&k)!=-1)
    {
        for(int i=1;i<=n;i++) p[i]=i;
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&Edge[i].u,&Edge[i].v,&Edge[i].c);
        sort(Edge+1,Edge+m+1,cmp);
        int pos=1;
        int count=0,res=0;
        bool flag=false;
        while(count<n-k)
        {
            if(pos<=m)
            {
                U=find(Edge[pos].u);V=find(Edge[pos].v);
                if(U!=V)
                {
                    p[U]=V;
                    count++;
                    res+=Edge[pos].c;
                }
                pos++;
            }
            else {flag=true;break;}
        }
        if(flag) printf("No Answer\n");
        else printf("%d\n",res);
        memset(p,0,sizeof(p));
    }
    return 0;
}
