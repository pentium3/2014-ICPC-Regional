#include "iostream"
using namespace std;
int w[]={99,29,26,18,16,13,10,8,5,3,1};
int k[11]; //记录每个物品的取或不取情况 
int S=50,n=10;
void dfs(int i,int j) //第i个数时还有j空间 
{
	if(i>n) //越界 
	{
		if(j==0) //符合条件 
		{
		    for(int i=1;i<=n;i++) //输出 
		    {
		    	if(k[i]) cout<<"("<<i<<","<<w[i]<<") ";
		    }
		    cout<<endl;
		}
		return;		
	}
	if(j-w[i]>=0) //取当前的i物品 
	{
		k[i]=1;
	    dfs(i+1,j-w[i]); //判断下个物品 
	}
	k[i]=0; //不取当前物品 
	dfs(i+1,j); //判断下个物品 
}

int main()
{
	dfs(1,S);
	return 0;
}
