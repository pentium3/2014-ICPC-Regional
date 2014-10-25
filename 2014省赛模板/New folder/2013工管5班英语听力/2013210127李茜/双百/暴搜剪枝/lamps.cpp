#include "iostream"
#include "vector"
#include "cstring"
#include "fstream"
#include "set"
using namespace std;
vector<int> o;
vector<int> c;
int N,C;
int queue[7];//优化队列 
int res[101];
set<vector<int> > bag; //集合，存无重复的结果 
void dfs(int dep)
{
	if(dep<1)
	{
		vector<int> temp;
		for(int i=1;i<=6;i++)
		 temp.push_back(queue[i]);
		bag.insert(temp);
		return;		 
	}
	//执行四项操作
	//#1
	for(int i=1;i<=6;i++)
	{
		if(queue[i]) queue[i]=0;
		else queue[i]=1;
	}
	dfs(dep-1);
	for(int i=1;i<=6;i++)
	{
		if(queue[i]) queue[i]=0;
		else queue[i]=1;
	}
	//#2
	for(int i=1;i<=6;i++)
	{
		if(i&1)
		{
			if(queue[i]) queue[i]=0;
		    else queue[i]=1;
		}
	}
	dfs(dep-1);
	for(int i=1;i<=6;i++)
	{
		if(i&1)
		{
			if(queue[i]) queue[i]=0;
		    else queue[i]=1;
		}
	}
	//#3
	for(int i=1;i<=6;i++)
	{
		if(!i&1)
		{
			if(queue[i]) queue[i]=0;
		    else queue[i]=1;
		}
	}
	dfs(dep-1);
	for(int i=1;i<=6;i++)
	{
		if(!i&1)
		{
			if(queue[i]) queue[i]=0;
		    else queue[i]=1;
		}
	}
	//#4
	for(int i=1;i<=6;i++)
	{
		if(i==1||i==4)
		{
			if(queue[i]) queue[i]=0;
		    else queue[i]=1;
		}
	}
	dfs(dep-1);
	for(int i=1;i<=6;i++)
	{
		if(i==1||i==4)
		{
			if(queue[i]) queue[i]=0;
		    else queue[i]=1;
		}
	}	
}
int main()
{
	#define fin cin
	ifstream fin("in.txt");
	cin>>N>>C;
	int temp;
	//确认要求的开关队列
	do
	{
		cin>>temp;
		if(temp!=-1)
		{
			o.push_back(temp);
		}
	}while(temp!=-1);
	do
	{
		cin>>temp;
		if(temp!=-1)
		{
			c.push_back(temp);
		}
	}while(temp!=-1);
	while(C>4)
	{
		C-=2;
	}
	memset(queue,1,sizeof(queue));
	dfs(C);
	//生成与输出
	for(set<vector<int> >::iterator i=bag.begin();i!=bag.end();i++)
	{
		vector<int> k=*i;
		int count=0;
		for(int i=1;i<=N;i++)
		{
		   res[i]=k[count];
		   count++;
		   if(count>=6) count-=6;
		}
		//验证
		int os=o.size();
		int cs=c.size();
		int oc=0,cc=0;
		for(int i=1;i<=os;i++)
		{
			if(res[o[i-1]]) oc++;
		}
		for(int i=1;i<=cs;i++)
		{
			if(!res[c[i-1]]) cc++;
		}
		if(oc==os&&cc==cs)
		{
			for(int i=1;i<=N;i++)
			  cout<<res[i]<<" ";
			  		cout<<endl;
		}
	}
	return 0;
}
