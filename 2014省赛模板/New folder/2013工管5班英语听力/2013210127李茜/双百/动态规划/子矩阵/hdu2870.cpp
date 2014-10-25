#include "iostream"
#include "fstream"
#include "string"
#include "cstring"
using namespace std;
char map[1001][1001];
int f[1001][1001],g[1001][1001],h[1001][1001];
int l[1001],r[1001];
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    int n,m;
    string tmp;
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>tmp;
            for(int j=0;j<m;j++)
            {
               map[i][j+1]=tmp[j];
               //用电路的叠加定理来处理a，b，c
               if(map[i][j+1]=='a'||map[i][j+1]=='w'||map[i][j+1]=='y'||map[i][j+1]=='z') //这四个其实是等价的，所以直接连通为矩形就行了，无须考虑不同变换的影响
               {
                   if(map[i-1][j+1]=='a'||map[i-1][j+1]=='w'||map[i-1][j+1]=='y'||map[i-1][j+1]=='z')
                        f[i][j+1]=f[i-1][j+1]+1;
                   else f[i][j+1]=1;
               }
               if(map[i][j+1]=='b'||map[i][j+1]=='w'||map[i][j+1]=='x'||map[i][j+1]=='z')
               {
                   if(map[i-1][j+1]=='b'||map[i-1][j+1]=='w'||map[i-1][j+1]=='x'||map[i-1][j+1]=='z')
                       g[i][j+1]=g[i-1][j+1]+1;
                   else g[i][j+1]=1;
               }
               if(map[i][j+1]=='c'||map[i][j+1]=='x'||map[i][j+1]=='y'||map[i][j+1]=='z')
               {
                   if(map[i-1][j+1]=='c'||map[i-1][j+1]=='x'||map[i-1][j+1]=='y'||map[i-1][j+1]=='z')
                       h[i][j+1]=h[i-1][j+1]+1;
                   else h[i][j+1]=1;
               }
            }
        }
        int MAX=0;
        for(int i=1;i<=n;i++) //转化为HDU 1506
        {
            l[1]=1;r[m]=m;
            for(int j=2;j<=m;j++)
            {
                int t=j;
                while(t>1&&f[i][t-1]>=f[i][j]) t=l[t-1];
                l[j]=t;
            }
            for(int j=m-1;j>=1;j--)
            {
                int t=j;
                while(t<m&&f[i][t+1]>=f[i][j]) t=r[t+1];
                r[j]=t;
            }
            for(int j=1;j<=m;j++)
                if((r[j]-l[j]+1)*f[i][j]>MAX) MAX=(r[j]-l[j]+1)*f[i][j];
            l[1]=1;r[m]=m;
            for(int j=2;j<=m;j++)
            {
                int t=j;
                while(t>1&&g[i][t-1]>=g[i][j]) t=l[t-1];
                l[j]=t;
            }
            for(int j=m-1;j>=1;j--)
            {
                int t=j;
                while(t<m&&g[i][t+1]>=g[i][j]) t=r[t+1];
                r[j]=t;
            }
            for(int j=1;j<=m;j++)
                if((r[j]-l[j]+1)*g[i][j]>MAX) MAX=(r[j]-l[j]+1)*g[i][j];
            l[1]=1;r[m]=m;
            for(int j=2;j<=m;j++)
            {
                int t=j;
                while(t>1&&h[i][t-1]>=h[i][j]) t=l[t-1];
                l[j]=t;
            }
            for(int j=m-1;j>=1;j--)
            {
                int t=j;
                while(t<m&&h[i][t+1]>=h[i][j]) t=r[t+1];
                r[j]=t;
            }
            for(int j=1;j<=m;j++)
                if((r[j]-l[j]+1)*h[i][j]>MAX) MAX=(r[j]-l[j]+1)*h[i][j];
        }
        cout<<MAX<<endl;
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        memset(h,0,sizeof(h));
    }
    return 0;
}
