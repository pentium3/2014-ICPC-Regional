#include "iostream"
#include "vector"
using namespace std;
int N;
struct node
{
	int s,f;
	int value;
};
int v[10001];
node f[10001];
vector<int> lib;
int main()
{
	while(cin>>N)
	{
		for(int i=1;i<=N;i++)
		  cin>>v[i];
		  f[1].value=v[1];
		  f[1].s=1;
		  f[1].f=1;
		for(int i=2;i<=N;i++)
		{
			  if(v[i]>f[i-1].value+v[i])
			  {
			  	 f[i].value=v[i];
			  	 f[i].s=i;
			  	 f[i].f=i;
			  }
			  else
			  {
			  	 f[i].value=f[i-1].value+v[i];
			  	 f[i].s=f[i-1].s;
			  	 f[i].f=i;
			  }
		}
		//从头到尾扫一下 
		int MAX=0,left=v[1],right=v[N];
		for(int i=1;i<=N;i++)
        if(f[i].value>MAX) 
		{
		   MAX=f[i].value;
		   left=v[f[i].s];
		   right=v[f[i].f];
		}
        cout<<MAX<<" "<<left<<" "<<right<<endl;
	}
	return 0;
}
