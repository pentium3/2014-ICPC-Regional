#include"iostream"
#include "vector"
#include "fstream"
#include <algorithm>
using namespace std;
struct formula
{
	int a,b;
	char x;
    int res;
};
bool isF=false;
void dfs(int dep,vector<formula> lib,vector<int> lic)
{	
    if(dep==4&&!isF) //打完了 
	{
		if(lic[0]==24)
		{
		  for(vector<formula>::iterator ivec=lib.begin();ivec!=lib.end();ivec++)
		 {
			cout<<ivec->a<<ivec->x<<ivec->b<<"="<<ivec->res<<endl;
		 }
		 isF=true;
	}
		return;
	}
	//四则运算搜索
    int num=lic.size();
	formula temp;
	//加
	for(int i=0;i<=num-2;i++)
	{
		for(int j=i+1;j<=num-1;j++)
		{
			temp.a=lic[i];
			temp.b=lic[j];
			temp.x='+';
			temp.res=lic[i]+lic[j];
			vector<formula> bag=lib;
			bag.push_back(temp);
			vector<int> bagx=lic;
			bagx.erase(find(bagx.begin(),bagx.end(),lic[i]));
			bagx.erase(find(bagx.begin(),bagx.end(),lic[j]));
			bagx.push_back(temp.res);
			dfs(dep+1,bag,bagx);
	   }
    }
	//减
	for(int i=0;i<=num-2;i++)
	{
		for(int j=i+1;j<=num-1;j++)
		{
			if(lic[i]>lic[j])
			{
				temp.a=lic[i];
				temp.b=lic[j];
			}
			else
			{
				temp.a=lic[j];
				temp.b=lic[i];
			}
			temp.x='-';
			temp.res=temp.a-temp.b;
			vector<formula> bag=lib;
			bag.push_back(temp);
			vector<int> bagx=lic;
			bagx.erase(find(bagx.begin(),bagx.end(),lic[i]));
			bagx.erase(find(bagx.begin(),bagx.end(),lic[j]));
			bagx.push_back(temp.res);
			dfs(dep+1,bag,bagx);
	   }
    }
    //乘
    for(int i=0;i<=num-2;i++)
	{
		for(int j=i+1;j<=num-1;j++)
		{
			temp.a=lic[i];
			temp.b=lic[j];
			temp.x='*';
			temp.res=lic[i]*lic[j];
			vector<formula> bag=lib;
			bag.push_back(temp);
			vector<int> bagx=lic;
			bagx.erase(find(bagx.begin(),bagx.end(),lic[i]));
			bagx.erase(find(bagx.begin(),bagx.end(),lic[j]));
			bagx.push_back(temp.res);
			dfs(dep+1,bag,bagx);
	   }
    }
    //除
	for(int i=0;i<=num-2;i++)
	{
		for(int j=i+1;j<=num-1;j++)
		{
			if(!lic[i]||!lic[j]) return; //除数和被除数不能为0 
			if(lic[i]>lic[j])
			{
				temp.a=lic[i];
				temp.b=lic[j];
			}
			else
			{
				temp.a=lic[j];
				temp.b=lic[i];
			}
			temp.x='/';
			if(temp.a%temp.b==0)
			{
			temp.res=temp.a/temp.b;
			vector<formula> bag=lib;
			bag.push_back(temp);
			vector<int> bagx=lic;
			bagx.erase(find(bagx.begin(),bagx.end(),lic[i]));
			bagx.erase(find(bagx.begin(),bagx.end(),lic[j]));
			bagx.push_back(temp.res);
			dfs(dep+1,bag,bagx);
		   }
	   }
    }
}

int main()
{
	vector<formula> lib;
	vector<int> lic;
	int input;
	for(int i=0;i<4;i++)
	{
		cin>>input;
		lic.push_back(input);
	}
	dfs(1,lib,lic);
	if(!isF) cout<<"No Answer"<<endl;
	return 0;
}
 
