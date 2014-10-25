#include "iostream"
#include "map"
using namespace std;
struct node
{
	bool visit;
	map<int,int> link;	
};

int main()
{
	int n,m;
	cin>>n>>m;
	node *lib=new node[n+1];
	int head,tail,value;
	for(int i=1;i<=n;i++) //初始化 
	{
		cin>>head>>tail>>value;
		lib[i].visit=false;
		lib[i].link[tail]=value;
		lib[tail].link[i]=value; //??
	}
	lib[1].visit=true;
	int sum=0;
	for(int i=1;i<n;i++)
	{
		int MAX=30000;
		int k;
		for(int j=1;j<=n;j++) //所有点的子点找合适点 
		{
			if(lib[j].visit)
			{
				for(map<int,int>::iterator ivec=lib[j].link.begin();ivec!=lib[j].link.end();ivec++)
				{
					if(ivec->second<MAX&&!lib[ivec->first].visit)
					{
						MAX=ivec->second;
						k=ivec->first;
					}
				}
			}
		}
		lib[k].visit=true;
		sum+=MAX;
	}
	cout<<sum<<endl;
	return 0;
}
