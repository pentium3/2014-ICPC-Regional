#include "cstdio"
#include "cstring"
int p[50001];
int find(int x)
{
	return p[x]!=x?p[x]=find(p[x]):x;
}
int main()
{
	freopen("in.txt","r",stdin);
	int n,m,x,y;
	int no=0;
	int sum;
	while(scanf("%d%d",&n,&m)&&n&&m)
	{
		no++;
		sum=0;
		for(int i=1;i<=n;i++)
		  p[i]=i;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			x=find(x);y=find(y);p[x]=y;
		}
		int temp;
		for(int i=1;i<=n;i++)
		{
			temp=find(i);
			if(i==temp) sum++;
		}
		printf("Case %d: %d\n",no,sum);
		memset(p,0,sizeof(p));
	}
}
