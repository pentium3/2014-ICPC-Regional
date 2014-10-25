#include "iostream"
#include "cstdio"
using namespace std;
int a[201];
int d[201][201];
const int inf=10000000;
int main()
{
    int n,m,u,v,c;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=inf;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&c);
        c+=a[v];
        if(c<d[u][v]) d[u][v]=c;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            d[i][j]=d[i][j]<d[i][k]+d[k][j]?d[i][j]:d[i][k]+d[k][j];
    if(d[1][1]>=inf) printf("-1\n");
    else printf("%d\n",d[1][1]);
    return 0;
}
