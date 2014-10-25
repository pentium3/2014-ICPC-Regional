
#include<iostream>
#include "fstream"
using namespace std;
int bomb[21];
int result[21];
int f[21];
int main()
{
		ifstream fin("in.txt");
	#define cin fin
		int n, i, j;
		cin>>n;
		for(i = 0; i < n; ++i)
		{
			cin>>bomb[i];
		}
		result[0] = bomb[0];
		int sum = 1;
		for(int i = 0; i < n; ++i)
		{
			int left=0,right=sum-1;
			while(left<=right)
			{
				int mid=(left+right)/2;
				if(result[mid]>bomb[i]) left=mid+1;
				else right=mid-1;
			}
			result[left]=bomb[i];
			if(left>=sum)
			{
				sum++;
				for(int k=0;k<sum;k++)
				  f[k]=result[k];
			}
		}
		cout<<sum<<endl;
		for(int i=0;i<sum;i++)
		cout<<f[i]<<" ";
	return 0;
}
