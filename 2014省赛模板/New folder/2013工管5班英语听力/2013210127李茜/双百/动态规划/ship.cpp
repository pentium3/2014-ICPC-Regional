#include "iostream"
using namespace std;
int f[101][101];
int map[101][101];
int N;
int dp(int i,int j)
{
	if(f[i][j]) return f[i][j];
	if(i==N) return 0; //避免dp(N,N)无限大 
	//开始搜索
	int Min=9999;
	for(int k=i+1;k<=N;k++) 
	{
		int len=map[i][k]+dp(k,N);
		if(len<Min) Min=len;
	}
    return f[i][j]=Min;
}
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	  for(int j=i+1;j<=N;j++)
	    cin>>map[i][j];
	for(int i=1;i<=N;i++)
	f[i][i]=0;
	cout<<dp(0,0)<<endl;
	return 0;
}
