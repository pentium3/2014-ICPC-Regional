#include "cstdio"
char map[1001][1001];
int f[1001][1001];
int l[1001],r[1001];
int main()
{
    freopen("in.txt","r",stdin);
    int Case,m,n;
    scanf("%d",&Case);
    while(Case--)
    {
        scanf("%d%d",&m,&n);
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf(" %c",&map[i][j]);
                if(map[i][j]=='R') f[i][j]=0;
                else if(map[i][j]=='F') f[i][j]=f[i-1][j]+1; //DP一下确认当前层高度
            }
        }
        int MAX=0,tmp;
        for(int i=1;i<=m;i++) //每一层都是一个HDU 1506问题
        {
            l[1]=1;r[n]=n;
            for(int j=2;j<=n;j++)
            {
                int t=j;
                while (t>1&&f[i][t-1]>=f[i][j]) t=l[t-1];
                l[j]=t;
            }
            for(int j=n-1;j>=1;j--)
            {
                int t=j;
                while (t<n&&f[i][t+1]>=f[i][j]) t=r[t+1];
                r[j]=t;
            }
            for(int j=1;j<=n;j++)
            {
                if((r[j]-l[j]+1)*f[i][j]>MAX) MAX=(r[j]-l[j]+1)*f[i][j];
            }
        }
        printf("%d\n",MAX*3);
    }
    return 0;
}
