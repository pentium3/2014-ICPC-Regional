#include "iostream"
#include "fstream"
#include "stdlib.h"
using namespace std;
int p[1001];
int find(int x) //���鼯���ĺ��� 
{
	return p[x]!=x?p[x]=find(p[x]):x;
}
struct edge
{
	int x,y;
	int v;
};
int compare(const void *a,const void *b)
{
	edge *aa=(edge*)a;
	edge *bb=(edge*)b;
	return ((aa->v)-(bb->v));
}
edge bag[1001];
int main()
{
	#define fin cin
	ifstream fin("in.txt");
	int n,m;
	int x,y,z;
	int a,b;
	cin>>n>>m;
	for(int i=0;i<n;i++) p[i]=i;
	for(int j=0;j<m;j++)
	{
		cin>>bag[j].x>>bag[j].y>>bag[j].v;	
	}
	qsort(bag,m,sizeof(edge),compare);
	int sum=0;int k=n-1;//����n-1���߾�ֹͣ 
	for(int i=0;i<=m;i++)
	{
		if(k==0) break;
		a=find(bag[i].x);b=find(bag[i].y);
		if(a!=b) //���ɻ�����ab���㲻��һ�������� 
		{
			p[a]=b;
			sum+=bag[i].v;
			cout<<bag[i].x<<" "<<bag[i].y<<endl;
			k--;
		}
	}
	cout<<sum<<endl;
	
}
