#include "iostream"
#include "fstream"
#include "cstring"
#include "cstdio"
using namespace std;
int f[2000000];
int v[51],a[51];
int N,V;
void zeroOnePack(int cost,int weight)
{
	for(int j=V;j>=cost;j--)
	  f[j]=f[j]>f[j-cost]+weight?f[j]:f[j-cost]+weight;
}
void completePack(int cost,int weight)
{
	for(int j=cost;j<=V;j++)
	  f[j]=f[j]>f[j-cost]+weight?f[j]:f[j-cost]+weight;
}
void multiPack(int cost,int weight,int amount)
{
	if(cost*amount>=V) 
	{
	   completePack(cost,weight);
	   return;	
	}
	int i=1;
	while(i<amount)
	{
		zeroOnePack(i*cost,i*weight);
		amount-=i;
		i<<=1;
	}
	zeroOnePack(amount*cost,amount*weight);
}
int main()
{ 
       while(scanf("%d",&n),n>=0){
		if(N!=-1)
		{
			int sum=0;
			for(int i=1;i<=N;i++)
			{
				scanf("%d%d",&v[i],&a[i]);
				sum+=v[i]*a[i];
			}
			V=sum/2;
			for(int i=1;i<=N;i++)
			{
				multiPack(v[i],v[i],a[i]);
			}
			if(sum-f[V]>=f[V]) cout<<sum-f[V]<<" "<<f[V]<<endl;
			else cout<<f[V]<<" "<<sum-f[V]<<endl;
		}
		memset(f,0,sizeof(f));
	}
}
