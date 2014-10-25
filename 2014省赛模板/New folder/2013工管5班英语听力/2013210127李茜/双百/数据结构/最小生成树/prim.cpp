#include "iostream"
using namespace std;
const int MAXN=32767;
void prim(int n,int v,int **c)
{
	int *lowcost=new int[n];
	int *closest=new int[n];
	bool *s=new bool[n];
	int i,j,k,min;
	s[v]=true;
	for(int i=0;i<n;i++)
	{
		if(i!=v)
		{
			lowcost[i]=c[0][i];
			closest[i]=v;
			s[i]=false;
		}
	}
	for(int i=1;i<n;i++)
	{
		min=MAXN;
		for(int k=0;k<n;k++)
		{
			if(lowcost[k]<min&&!s[k])
			{
				min=lowcost[k];
				j=k;
			}
		}
		cout<<j+1<<closest[j]+1<<endl;
		s[j]=true;
		for(int k=0;k<n;k++)
		{
			if(c[j][k]<lowcost[k]&&!s[k])
			{
				lowcost[k]=c[j][k];
				closest[k]=j;
			}
		}
	}
}
int main()
{
	int i,j,n,m;
	int u,v,weight;
	int **c;
	cin>>n>>m;
	c=new int *[n];
	for(int i=0;i<n;i++) c[i]=new int[n];
	for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++) c[i][j]=MAXN;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>weight;
		u=u-1;
		v=v-1;
		c[u][v]=weight;c[v][u]=weight;
	}
	cout<<"MST is"<<endl;prim(n,0,c);
	return 0;
}
