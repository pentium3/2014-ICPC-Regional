#include "iostream"
#include "cstring"
#include "fstream"
using namespace std;
int f[100001];
int c[11],n[11];
int N,V;
void zeroOnePack(int cost)
{
    for(int i=V;i>=cost;i--)
        f[i]=f[i-cost]+cost>f[i]?f[i-cost]+cost:f[i];
}
void completePack(int cost)
{
    for(int i=cost;i<=V;i++)
        f[i]=f[i-cost]+cost>f[i]?f[i-cost]+cost:f[i];
}
void multiPack(int amount,int cost)
{
    if(amount*cost>=V)
    {
        completePack(cost);
        return;
    }
    int k=1;
    while(k<amount)
    {
        zeroOnePack(k*cost);
        amount-=k;
        k<<=1;
    }
    zeroOnePack(amount*cost);
}
int main()
{
    //#define fin cin
    //ifstream fin("in.txt");
    while(cin>>V>>N)
    {
        if (N==0) cout<<"0"<<endl;
        else
        {
            for(int i=1;i<=N;i++)
            {
                cin>>n[i]>>c[i];
            }
            for(int i=1;i<=N;i++)
                multiPack(n[i],c[i]);
            cout<<f[V]<<endl;
            memset(f,0,sizeof(f));
            memset(n,0,sizeof(n));
            memset(c,0,sizeof(c));
        }
    }
    return 0;
}
