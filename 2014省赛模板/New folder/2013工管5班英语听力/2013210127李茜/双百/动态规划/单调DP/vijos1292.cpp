#include "iostream"
#include "fstream"
#include "cstdio"
using namespace std;
long long f[10001];
long long dis[10001];
long long L1,L2,L3,C1,C2,C3,n,a,b,tmp;
/*
int dp(int x,int y)
{
    if(dis[y]-dis[x]<=0) return 0;
    if(dis[y]-dis[x]>0&&dis[y]-dis[x]<=L1&&!f[x][y]) return f[x][y]=C1;
    if(dis[y]-dis[x]>L1&&dis[y]-dis[x]<=L2&&!f[x][y]) return f[x][y]=C2;
    if(dis[y]-dis[x]>L2&&dis[y]-dis[x]<=L3&&!f[x][y]) return f[x][y]=C3;
    if(f[x][y]) return f[x][y];
    int tmp,MIN=1000000000;
    for(int k=x+1;k<y;k++)
    {
        tmp=dp(x,k)+dp(k,y);
        if(tmp<MIN) MIN=tmp;
    }
    return f[x][y]=MIN;
}*/
long long cost(int i,int j)
{
    if(dis[j]-dis[i]>0&&dis[j]-dis[i]<=L1) return C1;
    else if(dis[j]-dis[i]>L1&&dis[j]-dis[i]<=L2) return C2;
    else if(dis[j]-dis[i]>L2&&dis[j]-dis[i]<=L3) return C3;
    else return 1300000001;
}
int main()
{
    cin>>L1>>L2>>L3>>C1>>C2>>C3>>n>>a>>b;
    for(int i=2;i<=n;i++) cin>>dis[i];
    long long MIN;
    for(int j=a+1;j<=b;j++)
    {
        MIN=1300000001;
        for(int k=j-1;k>=a;k--)
        {
            if(dis[j]-dis[k]>L3) break;
            if(f[k]+cost(k,j)<MIN) MIN=f[k]+cost(k,j);
        }
        f[j]=MIN;
    }
    cout<<f[b]<<endl;
    return 0;
}
