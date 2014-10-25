#include "iostream"
#include "vector"
using namespace std;
int num;
vector<int> lib1;
vector<int> lib2;
void dfs1(int *a,int n,int x,int y,int z)
{
	if(n==1)
	{
		for(int i=1;i<=num;i++)
		dfs1(a,n+1,x,y,a[i]);
	}
	if(n==2)
	{
		for(int i=1;i<=num;i++)
		dfs1(a,n+1,x,a[i],z);
	}
	if(n==3)
	{
		for(int i=1;i<=num;i++)
		dfs1(a,n+1,a[i],y,z);
	}
	if(n==4)
	{
       int temp=x*100+y*10+z;
       lib1.push_back(temp);
	}
}

void dfs2(int *a,int n,int x,int y)
{
	if(n==1)
	{
		for(int i=1;i<=num;i++)
		dfs2(a,n+1,x,a[i]);
	}
	if(n==2)
	{
		for(int i=1;i<=num;i++)
		dfs2(a,n+1,a[i],y);
	}
	if(n==3)
	{
       int temp=x*10+y;
       lib2.push_back(temp);
	}
}
int main()
{
	cin>>num;
	int *a=new int[num+1];
	for(int i=1;i<=num;i++)
	cin>>a[i];
	dfs1(a,1,0,0,0);
	dfs2(a,1,0,0);
	for(int i=0;i<lib2.size();i++)
	cout<<lib2[i]<<" ";
	cout<<endl;
	return 0;
	
}
