#include "cstdio"
#define MAX 100001
int p[MAX];
int find(int x)
{
	return p[x]!=x?p[x]=find(p[x]):x;
}
int main()
{
	for(int i=1;i<=MAX;i++) p[i]=i;
	int a,b;
	while(scanf("%d",&a)!=a!=-1)
	{
		int sum=0;
		scanf("%d",&b);
		a=find(a);b=find(b);
		if(a!=b)
		{
			p[a]=b;
		}
		else sum++;
	}
	while()
	printf("%d\n",sum);
}
