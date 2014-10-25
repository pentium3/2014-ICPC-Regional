#include "iostream"
using namespace std;
int A[30][1001],B[30][1001];
int n,sum;
int count;
int f[10001][10001];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	   sum+=i;
	if(sum&1) cout<<"impossible"<<endl;
	else
	{
		sum>>=1;
		f[1][1]=1;//f[1][0]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<=sum;j++)
			{
				if(j-i>0) f[i][j]=f[i-1][j]+f[i-1][j-i];
				else f[i][j]=f[i-1][j];
			}
		}
	}
	cout<<f[n][sum]<<endl;
	return 0;
}
