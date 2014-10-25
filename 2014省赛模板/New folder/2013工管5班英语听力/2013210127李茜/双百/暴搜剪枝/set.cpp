#include "iostream"
using namespace std;
int f[1001];
int n;
void dfs(int i)
{
	if(i>n)
	{
		int count=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]) 
			{
				cout<<i<<" ";
				count++;
			}
		}
		if(count==0) cout<<"¿Õ¼¯"; 
		cout<<endl;
		return;
	}
	f[i]=0;
	dfs(i+1);
	f[i]=1;
	dfs(i+1);
}
int main()
{
	cin>>n;
	dfs(1);
	return 0;
}
