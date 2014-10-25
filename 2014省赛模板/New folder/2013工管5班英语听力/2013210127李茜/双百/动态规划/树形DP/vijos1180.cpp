#include "iostream"
#include "cstdio"
using namespace std;
int l[301],r[301],a[301],f[301][301];
int n,m,root,x;
int dp(int node,int cap)
{
    if(node==0) return 0;
    if(f[node][cap]) return f[node][cap];
    int MAX=0,tmp;
    for(int k=0;k<cap;k++)
    {
        tmp=dp(l[node],k)+dp(r[node],cap-k-1)+a[node];
        if(tmp>MAX) MAX=tmp;
    }
    return f[node][cap]=max(MAX,dp(r[node],cap));
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&a[i]);
        if(root==0&&x==0) root=i;
        if(l[x]==0) l[x]=i;
        else
        {
            r[i]=r[l[x]];
            r[l[x]]=i;
        }
    }
    printf("%d\n",dp(root,m));
}
