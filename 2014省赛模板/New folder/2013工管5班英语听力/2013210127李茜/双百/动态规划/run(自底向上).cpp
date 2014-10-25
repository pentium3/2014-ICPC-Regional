#include "iostream"
using namespace std;
int f[1001][10001];
int Max(int a,int b,int c)
{
	if(a>=b&&a>=c) return a;
	if(b>=a&&b>=c) return b;
	if(c>=a&&c>=b) return c;
}
int main()
{
	int M,S,T;
	cin>>M>>S>>T;
	f[0][M]=0;
	for(int i=1;i<=T;i++)
	{
		for(int j=0;j<=M;j++)
		{
			if(j>=10) f[i][j]=Max(f[i-1][j]+17,f[i-1][j-10]+60,f[i-1][j+4]);
			else f[i][j]=f[i-1][j]+17>f[i-1][j+4]?f[i-1][j]+17:f[i-1][j+4];
		}
	}
	cout<<f[T][M]<<endl;
	return 0;
}
