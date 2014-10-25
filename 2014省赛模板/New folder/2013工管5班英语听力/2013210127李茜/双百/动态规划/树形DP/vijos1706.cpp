#include "iostream"
#include "cstdio"
#include "cstring"
using namespace std;
int a[5001],l[5001],r[5001],f[5001];
int dp(int node)
{
    if(node==0) return 0;
    if(f[node]) return f[node];
    int t1=dp(r[node])+a[node]+dp(l[l[node]]),t2=dp(r[node])+dp(l[node]);
    return f[node]=max(t1,t2);
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,x;
    while(scanf("%d",&n)!=-1)
    {
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&x);
        if(l[x]==0) l[x]=i;
        else
        {
            r[i]=r[l[x]];
            r[l[x]]=i;
        }
    }
    printf("%d\n",dp(1));
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    memset(f,0,sizeof(f));
    }
}
