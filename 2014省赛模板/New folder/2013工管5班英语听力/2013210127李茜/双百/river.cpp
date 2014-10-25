#include "iostream"
#include "cstring"
using namespace std;
int A[99999];
int a[101];
int n,S,T,M;
int Min=101;
void dfs(int N,int b)
{
	A[N]=b;
	if(N>=n)
	{
		if(b<Min) Min=b;
		return;
	}
	for(int i=S;i<=T;i++)
	{
		if(a[N+i]==1)
		{
			if(b+1<A[N+i]) dfs(N+i,b+1);
		}
		else
	    {
	    	if(b<A[N+i]) dfs(N+i,b);
	    }
	}
}
int main()
{
	cin>>n>>S>>T>>M;
	memset(A,101,sizeof(A));
	memset(a,0,sizeof(a));
	for(int i=1;i<=M;i++)
	{
		int temp;
		cin>>temp;
		a[temp]=1;
	}
	dfs(0,0);
	cout<<Min<<endl;
	return 0;
}

