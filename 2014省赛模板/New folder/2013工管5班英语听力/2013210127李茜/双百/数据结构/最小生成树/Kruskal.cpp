x#include "iostream"
#include "stdlib.h"
#include "fstream"
using  namespace std;
struct node
{
	int edge;
	int x,y;
};
int compare(const void *b1,const void *b2)
{
	node *aa=(node*)b1;
	node *bb=(node*)b2;
	return ((aa->edge)-(bb->edge));
}
int sum=0;
void Kruskal(int n,int m,node *Edge)
{
	int i,j,u,v,temp1,temp2,parts=0;
	int *vertex=new int[n+1];
	qsort(Edge+1,m,sizeof(node),compare);
	for(int i=1;i<=n;i++) vertex[i]=0;
	for(int i=1;i<=m;i++)
	{
		u=Edge[i].x;v=Edge[i].y;
		if(!vertex[u]&&!vertex[v])
		{
			parts++;
			vertex[u]=parts;vertex[v]=parts;
			sum+=Edge[i].edge;
			cout<<u<<" "<<v<<endl;
		}

		else if(vertex[u]&&!vertex[v])
		{
			vertex[v]=vertex[u];
			sum+=Edge[i].edge;
			cout<<u<<" "<<v<<endl;
		}
		else if(!vertex[u]&&vertex[v])
		{
		    vertex[u]=vertex[v];
		    sum+=Edge[i].edge;
		    cout<<u<<" "<<v<<endl;
		}
		else if(vertex[u]!=vertex[v]) //该步是先连接，然后整理相同集合的编号 
		{
			cout<<u<<" "<<v<<endl;
			sum+=Edge[i].edge;
			temp1=vertex[u];
			temp2=vertex[v];
			if(temp1>temp2)
			{
				temp1=vertex[v];
				temp2=vertex[u];
			}
			for(int j=1;j<=m;j++)
			{
				if(vertex[j]==temp2)
				vertex[j]=temp1;
			}
     	}
     	//最后漏掉的情况是u=v，这个铁定成环，所以无视掉了 
	}
}

int main()
{
	#define cin fin
	ifstream fin("in.txt");
	int n,m;
	int i;node *Edge;
	cin>>n>>m;
	Edge=new node[m+1];
	for(int i=1;i<=m;i++)
	{
		cin>>Edge[i].x>>Edge[i].y>>Edge[i].edge;
	}
	cout<<"MST is"<<endl;
	Kruskal(n,m,Edge);
	cout<<"Sum is "<<sum<<endl;
	delete Edge;
	return 0;
}
