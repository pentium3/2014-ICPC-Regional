#include "iostream"
#include "cstring"
using namespace std;
int a[1001][1001];
int N;
int f[1001][1001];
int dp(int n,int m,int p)
int main()
{
	while(cin>>N)
    {
	for(int i=1;i<=N;i++)
	  for(int j=1;j<=i;j++)
	    cin>>a[i][j];
	int MAX=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			f[i][j]=a[i][j]+f[i+1][j]>f[i+1][j+1];
			if(f[i][j]>MAX) MAX=f[i][j];
		}
	}
	cout<<MAX<<endl;
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
    }
	return 0;
}
