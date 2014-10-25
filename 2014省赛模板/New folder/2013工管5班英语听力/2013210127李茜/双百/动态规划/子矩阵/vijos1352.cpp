#include "cstdio"
#include "iostream"
#include "fstream"
using namespace std;
int map[2001][2001];
int l[2001][2001],r[2001][2001],h[2001][2001];
int main()
{
    //freopen("in.txt","r",stdin);
    //#define fin cin
    //ifstream fin("in.txt");
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m)
    {
    int r1=0,r2=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
           cin>>map[i][j];
    for(int i=1;i<=n;i++) //预处理左右第一个障碍点
    {
        int lx=0,rx=m+1;
        l[i][1]=lx;r[i][m]=rx;
        int nei=map[i][1];
        for(int j=2;j<=m;j++) //第一个绝对不是障碍
        {
            if(map[i][j]!=nei) l[i][j]=lx;
            else {lx=j-1;l[i][j]=lx;}
            nei=map[i][j];
        }
        nei=map[i][m];
        for(int j=m-1;j>=1;j--)
        {
            if(map[i][j]!=nei) r[i][j]=rx;
            else {rx=j+1;r[i][j]=rx;}
            nei=map[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1||map[i][j]==map[i-1][j]) h[i][j]=1;
            else
            { h[i][j]=h[i-1][j]+1;
             l[i][j]=max(l[i][j],l[i-1][j]);
             r[i][j]=min(r[i][j],r[i-1][j]);
            }
            if(min(r[i][j]-l[i][j]-1,h[i][j])>r1) r1=min(r[i][j]-l[i][j]-1,h[i][j]);
            if((r[i][j]-l[i][j]-1)*h[i][j]>r2)
            {
               r2=(r[i][j]-l[i][j]-1)*h[i][j];
               //printf("%d %d %d %d\n",r2,l[i][j]+1,r[i][j]-1,h[i][j]);
            }
        }
    }
    cout<<r1*r1<<endl<<r2<<endl;
    }
}
