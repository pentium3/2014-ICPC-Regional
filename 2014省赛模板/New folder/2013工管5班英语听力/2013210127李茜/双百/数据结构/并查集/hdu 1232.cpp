#include "iostream"
#include "fstream"
#include "cstdio"
using namespace std;
int p[1001];
int find(int x)
{
	return p[x]!=x?p[x]=find(p[x]):x;
}

int main()
{
	freopen("in.txt","r",stdin);
	int n,m,a,b;
while(scanf("%d",&n)&&n)
{
	scanf("%d",&m);
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		a=find(a);b=find(b);
		if(a!=b) p[a]=b; //不要重复添加 
	}
	//搜索
	int sum=0;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			a=find(i);b=find(j); 
			if(a!=b)
			{
				p[a]=b;
				sum++;
			}       
		}						
	}
	cout<<sum<<endl;
}
	return 0;
}
