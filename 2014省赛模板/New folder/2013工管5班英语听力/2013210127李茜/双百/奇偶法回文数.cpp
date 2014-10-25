#include "iostream"
#include "string"
#include "stdio.h"
using namespace std;
int bit(long long int x)
{
	int value=0;
	while(x>0)
	{
		x/=10;
		value++;
	}
	return value;
}
string mirror(string str)
{
	string x(str);
	int tail=str.size()-1;
	int head=0;
	for(int i=0;i<str.size();i++)
	{
		x[head]=str[tail];
		head++;
		tail--;
	}
	return x;
}
int main()
{
	int Min;
	long long int Max;
	cin>>Min>>Max;
	Min=bit(Min);Max=bit(Max);
	for(int i=Min;i<=Max;i++) //顺位计算 
	{
		int left,right=1;
		if(i%2==0) //偶数 
		{
			for(int j=1;j<=i/2;j++)
				right*=10;
			left=right/10;
			right=right-1;
			for(int j=left;j<=right;j++)
			{
				string str;
				int num=j;
				int temp;
				while(num>0)
				{
					temp=num%10;
					str.push_back(temp+48);
					num=num/10;
				}
				cout<<mirror(str)+str<<endl;
			}
		}
		else //奇数 
		{
			for(int j=1;j<=i/2+1;j++)
			  right*=10;
			left=right/10;
			right=right-1;
			for(int j=left;j<=right;j++)
			{
				string str;
				int num=j;
				int temp;
				while(num>0)
				{
					temp=num%10;
					str.push_back(temp+48);
					num=num/10;
				}
				cout<<mirror(str).erase(str.size()-1,str.size()-1)+str<<endl;
			}
		}
	}

	return 0;
}
