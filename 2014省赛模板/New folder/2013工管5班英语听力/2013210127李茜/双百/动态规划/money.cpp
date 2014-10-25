#include "iostream"
#include "fstream"
using namespace std;
long long int f[26][10001];
int a[26];
int N,V;
int main()
{
	#define fin cin
	ifstream fin("in.txt");
	cin>>N>>V;
	for(int i=1;i<=N;i++)
	  cin>>a[i];
	int k=0;
	while(k*a[1]<=V)
	{
		f[1][k*a[1]]=1;
		k++;
	}
	for(int i=2;i<=N;i++)
	{
		for(int j=0;j<=V;j++)
		{
			int m=0;
			while(j-m*a[i]>=0)
			{
				   f[i][j]+=f[i-1][j-m*a[i]];
                   m++;
			}
		}
	}
	  cout<<f[N][V]<<endl;
	return 0;
}
