#include "iostream"
#include "fstream"
#include "cstring"
#include "iomanip"
#include "cstdio"
using namespace std;
double f[10001];
int c[10001];
double p[10001];
int main()
{
    //#define fin cin
    //ifstream fin("in.txt");
    int n,m;
    double t;
    while(cin>>n>>m&&(n+m)!=0)
    {
        for(int i=1;i<=m;i++)
            cin>>c[i]>>p[i];
        for(int i=1;i<=m;i++)
        {
             for(int j=n;j>=c[i];j--)
           {
               f[j]=max(f[j],(1-f[j-c[i]])*p[i]+f[j-c[i]]);
           }
        }
        cout<<setiosflags(ios::fixed)<<showpoint<<setprecision(1)<<f[n]*100<<"%"<<endl;
        //printf("%.1lf%%\n",f[n]*100);
        memset(f,0,sizeof(f));
    }
    return 0;
}
