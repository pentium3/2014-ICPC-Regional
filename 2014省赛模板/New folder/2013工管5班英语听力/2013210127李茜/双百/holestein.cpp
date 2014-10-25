#include "iostream"
#include "vector"
#include "fstream"
using namespace std;
int n,m;
int lim[26];
vector<int> food[16];
int MIN=99;
//int A[16][10][1001],B[16][16][1001]; //状态依序：序号/吃掉数/背包首营养 
int count=0;
int dfs(int c,int r,vector<int> bag)
{
	if(c>m) //清算 
	{
		int count=0;
		for(int i=1;i<=n;i++)
		{
			if(bag[i-1]>=lim[i]) count++;
		}
		if(count==n&&r<MIN) 
		{
			MIN=r;
		}
		return 0;
	}
	count++;
	vector<int> copy=bag;
	for(int i=0;i<n;i++)
	{
	   copy[i]+=food[c][i];
	}
	dfs(c+1,r+1,copy)+1;
	dfs(c+1,r,bag);
}
int main()
{
	#define fin cin
	ifstream fin("in.txt");
	cin>>n;
	vector<int> lib;
	for(int i=1;i<=n;i++)
	{
	   cin>>lim[i];
	   lib.push_back(0); //添加养料库位置 
    }
	cin>>m;
	int temp;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>temp;
			food[i].push_back(temp);
		}
	}
	dfs(1,0,lib);
	cout<<MIN<<endl;
	cout<<"算法共执行"<<count<<"步"<<endl; 
	return 0;
}
