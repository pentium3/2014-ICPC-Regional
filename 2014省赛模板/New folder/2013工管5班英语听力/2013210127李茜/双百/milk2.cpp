#include "iostream"
#include "cstring"
using namespace std;
#define MAX 1000001
int a[1000001];
int main()
{
	memset(a,0,sizeof(a));
	int n;
	cin>>n;
	int max=0;
	int phead=0;
	int M1=0,M2=0;
	for(int i=0;i<n;i++)
	{
		long long int head,tail;
		cin>>head>>tail;
		if(phead==0) phead=head;
		if(tail>max)  max=tail;
		for(int j=head;j<=tail;j++)
		a[j]=1;
	}
	bool ishead=true,istail=false;
	int c1=0,c2=0;
	for(int i=1;i<=max;i++)
	{
		if(a[i]==1) 
		{
		   if(!ishead)
		   {
		   	  if(c2>M2) M2=c2;
		   	  c2=0;
		   }  
		   c1++;
		   ishead=true;
		   continue;
	    }
		else 
		{
			if(ishead) 
			{
				if(c1>M1) M1=c1;
				c1=0;
				ishead=false;
				c2++;
				continue;
			}
			c2++;		
		}
	}
	if(c1>M1) M1=c1;
	if(c2>M2) M2=c2;
	cout<<M1-1<<" "<<M2+1<<endl;
	return 0;
}
	
	
	
	

