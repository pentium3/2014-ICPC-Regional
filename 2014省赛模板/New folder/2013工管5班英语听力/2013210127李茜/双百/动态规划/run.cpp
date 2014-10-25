#include "iostream"
#include "cstring"
using namespace std;
int m,s,t;
int Min=0;
int A[1001][1001],B[1001][1001],C[1001][1001];
int Max(int a,int b,int c)
{
	if(a>=b&&a>=c) return a;
	if(b>=a&&b>=c) return b;
	if(c>=a&&c>=b) return c;
}
int dp(int T,int M)
{
	if(T==0) return 0;
	if(!A[T][M]) A[T][M]=dp(T-1,M)+17;
	if(!B[T][M]&&M>=10) B[T][M]=dp(T-1,M-10)+60;
	if(!C[T][M]) C[T][M]=dp(T-1,M+4);
	int temp=Max(A[T][M],B[T][M],C[T][M]);
	if(temp>s)
	{
		if(!Min) Min=T;
		else
		{
			if(T<Min) Min=T;
		}
	}
	return temp;
}
int main()
{
	cin>>m>>s>>t;
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	memset(C,0,sizeof(C));
	int temp=dp(t,m);
	if(temp>=s) 
	{
		cout<<"Yes"<<endl;
		cout<<Min<<endl;
	}
	else 
	{
		cout<<"No"<<endl;
	    cout<<temp<<endl;
	}
	return 0;
	
}
