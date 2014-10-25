#include "iostream"
using namespace std;
int n,k,r;
void div(int dep,int prev,int now)
{
	if(dep==k)
	{
		if(now>=prev)
		{
			r++;
			return;
		}
	}
	for(int i=prev;i<=now/2;i++)
	  div(dep+1,i,now-i);
}

int main()
{
	cin>>n>>k;
	r=0;
	div(1,1,n);
	cout<<r<<endl;
}
