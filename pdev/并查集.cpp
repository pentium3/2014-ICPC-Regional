//例题：找亲戚
//一抓一大把的裸题= =
#include <iostream>
#include <cstring>
using namespace std;
int n,m,p,tx,ty,i,x,y,j;
int f[10000];

int find(int x)
{
    if (f[x]!=x)
        f[x]=find(f[x]);
    return f[x];
}

void iunion(int x,int y)
{
    int fx,fy;
    fx=find(x);
    fy=find(y);
    if (fx!=fy) 
        f[fx]=fy;
}

int main()
{
    cin>>n>>m>>p;
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
        f[i]=i;
        
    for (i=1;i<=m;i++)
    {
        cin>>x>>y;
        iunion(x,y);
            for (j=1;j<=n;j++)  cout<<f[j]<<"  ";
            cout<<endl;
    }
        
    for (i=1;i<=p;i++)
    {
        cin>>x>>y;
        tx=find(x);
        ty=find(y);
        if (tx==ty) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
    }
}