#include "iostream"
#include "vector"
using namespace std;
int ff[25][25][25];
int A,B,C;
vector<int> lib;
bool isFirst=true;
void dfs(int a,int b,int c)
{
	if(ff[a][b][c])
	return;
	ff[a][b][c]=1;
	  if(a==0)
	{
		lib.push_back(c);
	}
	if(a!=0)
	{
		//a->b
		if(a-(B-b)<0) dfs(0,b+a,c);
		else 
		{
			if(B-b!=0)
			dfs(a-(B-b),B,c);
		}
		//a->c
		if(a-(C-c)<0) dfs(0,b,c+a);
		else 
		{
			if(a-(C-c)!=a)
			dfs(a-(C-c),b,C);
		}
	}
	if(b!=0)
	{
		//b->a
		if(b-(A-a)<0) dfs(a+b,0,c);
		else 
		{
			if(b-(A-a)!=b)
			dfs(A,b-(A-a),c);
		}
		//b->c
		if(b-(C-c)<0) dfs(a,0,c+b);
		else 
		{
			if(b-(C-c)!=b)
			dfs(a,b-(C-c),C);
		}
	}
	if(c!=0)
	{
		//c->a
		if(c-(A-a)<0) dfs(a+c,b,0);
		else 
		{
			if(A-a!=0)
			dfs(A,b,c-(A-a));
		}
		//c->b
		if(c-(B-b)<0) dfs(a,b+c,0);
		else 
		{  
			if(c-(B-b)!=c)
			dfs(a,B,c-(B-b));
		}
	}
}
int main()
{
	cin>>A>>B>>C;
	dfs(0,0,C);
	for(int i=0;i<lib.size();i++)
	{
		cout<<lib[i]<<" ";
	}
	cout<<endl;
	return 0;
	
}
