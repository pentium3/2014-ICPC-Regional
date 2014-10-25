#include "iostream"
#include "fstream"
using namespace std;
const int MX=100001;
long long f[MX],l[MX],r[MX];
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    int n;
    while(cin>>n&&n!=0)
    {
        for(int i=1;i<=n;i++)
            cin>>f[i];
        l[1]=1;r[n]=n;
        /*典型错误，误以为转移方程只是继承相邻的l和r，其实还要继续找比当前矩形高的，范围要扩大
        for(int i=2;i<=n;i++)
        {
            if(f[i-1]>=f[i]) l[i]=l[i-1];
            else l[i]=i;
        }
        for(int i=n-1;i>=1;i--)
        {
            if(f[i+1]>=f[i]) r[i]=r[i+1];
            else r[i]=i;
        }
        */
        for (int i=2; i<=n; ++i)
        {
            int t=i;
            while (t>1 && f[i]<=f[t-1]) t=l[t-1];
            l[i]=t;
        }
        for (int i=n-1; i>=1; --i)
        {
            int t=i;
            while (t<n && f[i]<=f[t+1]) t=r[t+1];
            r[i]=t;
        }
        long long MAX=0,tmp;
        for(int i=1;i<=n;i++)
        {
            tmp=(r[i]-l[i]+1)*f[i];
            if(tmp>MAX) MAX=tmp;
        }
        cout<<MAX<<endl;
    }
    return 0;
}
