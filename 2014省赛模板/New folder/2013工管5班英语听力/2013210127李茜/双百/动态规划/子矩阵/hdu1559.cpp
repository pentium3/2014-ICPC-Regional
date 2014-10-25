#include<iostream>
#include "cstdio"
#include "cstring"
using namespace std;
#define N 1001
int dp[N][N];
int main(void)
{
	int t;
	int n,m,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		scanf("%d%d",&x,&y);
		memset(dp,0,sizeof(int)*n*m);
		int M=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&dp[i][j]);
				dp[i][j]=dp[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
				if(i>=x&&j>=y)
				{
					int temp=dp[i][j]-dp[i-x][j]-dp[i][j-y]+dp[i-x][j-y];
					if(temp>M)
						M=temp;
				}
			}
		printf("%d\n",M);
	}
}
