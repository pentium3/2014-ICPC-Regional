#include "iostream"
#include "cstring"
#include "fstream"
using namespace std;
int n,m;
int c[101],N[101];
int f[100001];
void zeroOnePack(int cost)
{
    for(int i=m;i>=cost;i--)
        f[i]=f[i-cost]+cost>f[i]?f[i-cost]+cost:f[i];
}
void completePack(int cost)
{
     for(int i=cost;i<=m;i++)
        f[i]=f[i-cost]+cost>f[i]?f[i-cost]+cost:f[i];
}
void multiPack(int cost,int amount)
{
    if(cost*amount>=m)
    {
        completePack(cost);
        return;
    }
    int m=1;
    while(m<amount)
    {
        zeroOnePack(m*cost);
        amount-=m;
        m<<1;
    }
    zeroOnePack(amount*cost);
}
int main()
{
    //#define fin cin
    //ifstream fin("in.txt");
    while(cin>>n>>m&&n!=0)
    {
        for(int i=1;i<=n;i++)
            cin>>c[i];
        for(int i=1;i<=n;i++)
            cin>>N[i];
        for(int i=1;i<=n;i++)
            multiPack(c[i],N[i]);
        int count=0;
        for(int i=1;i<=m;i++)
            if(f[i]==i) count++;
        cout<<count<<endl;
        memset(f,0,sizeof(f));
    }
}
