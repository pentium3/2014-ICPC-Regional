#include "cstdio"
#include "cstring"
int p[30001];
int find(int x)
{
	return p[x]!=x?p[x]=find(p[x]):x;
}
int main()
{

	int n,m,num,tmp,bak,x,y,sum;
	while(scanf("%d%d",&n,&m)&&n)
	{
		sum=0;
		for(int i=0;i<n;i++)
		  p[i]=i;
		for(int i=1;i<=m;i++) //ºÏ²¢ 
		{
			scanf("%d",&num);
			for(int j=1;j<=num;j++)
			{
				scanf("%d",&tmp);
				if(j==1) 
				{
					bak=tmp;
					continue;
				}
				x=find(bak);y=find(tmp);p[x]=y;
			}
		}
		for(int i=1;i<n;i++)
		{
			if(find(i)==find(0))
			{
				sum++;
			}
		}
		sum++;
		if(n==1) sum=1;
		printf("%d\n",sum);
		memset(p,0,sizeof(p));
	}
	return 0;
}
