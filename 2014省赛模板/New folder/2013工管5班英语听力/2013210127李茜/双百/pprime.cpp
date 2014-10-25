#include "iostream"
#include "math.h"
using namespace std;
bool isPrime(int n)
{
	int x=sqrt(n);
	for(int i=2;i<=x;i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
bool isBack(int n)
{
	int temp=n;
	int a[10];
	int count=0;
	while(temp>0)
	{
		a[count]=temp%10;
		temp/=10;
		count++;
	}
	int phead=0,ptail=count-1;
	int c=0;
	for(int i=0;i<count;i++)
	{
		if(a[phead]==a[ptail]) c++;
		phead++;
		ptail--;
	}
	if(c==count) return true;
	else return false;
}

int  main()
{
	int n,m;
	cin>>n>>m;
    for(int i=n;i<=m;i++)
    {
    	if(isPrime(i)&&isBack(i)) cout<<i<<endl;
    }
	return 0;
}
