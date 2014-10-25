#include "iostream"
#include "math.h"
using namespace std;
bool isPrime(int n)
{
	if(n==1) return false;
	int x=sqrt(n);
	for(int i=2;i<=x;i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	int phead=1,ptail;
	if(n==1)
	{
		phead=3;
		ptail=9;
	}
	else
	{
	    for(int i=0;i<n-1;i++)
	    {
	    	phead*=10;
		}
		ptail=phead*10-1;
	}
	for(int i=phead;i<=ptail;i++)
	{
		
		int x=(ptail+1)/10;
		int temp=i/x;
		int count=0;
		while(temp<=i)
		{
			if(isPrime(temp)) count++;
			else break;
			x=x/10;
			if(x>=1)
			temp=i/x;
			else break;
		}
		if (count==n) cout<<i<<endl;
	}
	return 0;

}
