#include "iostream"
#include "cstdio"
#include "vector"
using namespace std;
int n;
vector<int> G[1501];
int a[1501];
int c[1501];
int f[1501][4];
const int inf=100000000;
int dp(int root,int type)
{
    if(f[root][type]) return f[root][type];
    int sum=0,most=inf,fix=0;
    int t1,t2;
    switch(type)
    {
    case 1:
        for(int i=0;i<G[root].size();i++)
           sum+=min(min(dp(G[root][i],1),dp(G[root][i],2)),dp(G[root][i],3));
        sum+=a[root];
        f[root][type]=sum;
        break;
    case 2:
        for(int i=0;i<G[root].size();i++)
        {
            t1=dp(G[root][i],1);t2=dp(G[root][i],2);
            sum+=min(t1,t2);
            most=min(most,t1-t2);
        }
        f[root][type]=sum;
        if(most>0) f[root][type]+=most;
        break;
    case 3:
        for(int i=0;i<G[root].size();i++)
          sum+=min(dp(G[root][i],1),dp(G[root][i],2));
        f[root][type]=sum;
        break;
    }
    return f[root][type];
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    int num,val,sn,sp,root;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&num,&val,&sn);
        for(int j=1;j<=sn;j++)
        {
            scanf("%d",&sp);
            G[num].push_back(sp);
            c[sp]=true; //ÊÇ×Óµã
        }
        a[num]=val;
    }
    for(int i=1;i<=n;i++)
      if(!c[i]) {root=i;break;}
    int MIN=1000000,tmp;
    printf("%d\n",min(dp(root,1),dp(root,2)));
}
