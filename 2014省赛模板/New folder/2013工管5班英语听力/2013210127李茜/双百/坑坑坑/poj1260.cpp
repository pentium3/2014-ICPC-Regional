#include "iostream"
#include "fstream"
#include "cstring"
using namespace std;
int a[101],p[101];
int f[101];
bool s[101];
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    int n,k;
    cin>>n;
    while(n--)
    {
        cin>>k;
        for(int i=1;i<=k;i++)
            cin>>a[i]>>p[i];
        for(int i=k;i>=1;i--)
        {
            int Min=p[i]*(a[i]+10);
            int MinJ=i;
            for(int j=i+1;j<=k;j++)
            {
                if(!s[j])
                {
                if(p[j]*(a[i]+10)<=Min) //转向购买
                {
                    Min=p[j]*(a[i]+10);
                    MinJ=j;
                }
                }
                else
                {
                if(p[j]*a[i]<=Min) //转向购买
                {
                    Min=p[j]*a[i];
                    MinJ=j;
                }
                }
            }
            f[MinJ]+=Min;
            s[MinJ]=true;
        }
        int sum=0;
        for(int i=1;i<=k;i++)
        {
            sum+=f[i];
        }
        cout<<sum<<endl;
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        memset(s,false,sizeof(s));
    }
    return 0;
}
