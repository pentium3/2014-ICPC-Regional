#include "iostream"
#include "vector"
using namespace std;
int bomb[]={1,389,207,155,300,299,170,158,65};
//int f[21];
struct node
{
	int value;
	vector<int> lib;
};
node f[21];
int main()
{
	int n=8;
	vector<int> x;
	f[0].value=0;
	f[0].lib=x;
	for(int i=1;i<=n;i++)
	{
		f[i].value=1;
		f[i].lib=x;
		f[i].lib.push_back(bomb[i]);
		for(int j=1;j<i;j++)
		{
		    if(bomb[i]<bomb[j]) //©ирт 
			{
			   if(f[i].value<f[j].value+1)
			   {
			   	  f[i].value=f[j].value+1;
			   	  f[i].lib=f[j].lib;
			   	  f[i].lib.push_back(bomb[i]);
			   }
			      
			}
		}
	}
	int Max=0;int loc;
	for(int i=1;i<=n;i++)
	{
		if(f[i].value>Max) 
		{
		   Max=f[i].value;
		   loc=i;	
		}
	}
	cout<<Max<<endl;
	for(vector<int>::iterator ivec=f[loc].lib.begin();ivec!=f[loc].lib.end();ivec++)
	  cout<<*ivec<<" ";
	  return 0;
	  
}
