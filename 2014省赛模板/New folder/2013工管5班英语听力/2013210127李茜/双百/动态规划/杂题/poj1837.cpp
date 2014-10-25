#include "iostream"
#include "fstream"
using namespace std;
int f[21][15001];
int a[21];
int hook[21];
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    int c,g,left,right;
    int v=0;
    cin>>c>>g;
    for(int i=1;i<=c;i++)
        cin>>hook[i];
    for(int i=1;i<=g;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=c;i++)
    {
        f[1][7500+hook[i]*a[1]]=1;
    }
    f[0][0]=1;
    for(int i=1;i<=g;i++)
    {
        for(int j=0;j<=15000;j++)
        {
               for(int k=1;k<=c;k++)
               {
                    f[i][j]+=f[i-1][j-a[i]*hook[k]]; //¼õ·¨
               }
        }
    }
    cout<<f[g][7500]<<endl;
    return 0;
}
