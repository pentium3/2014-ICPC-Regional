#include "iostream"
using namespace std;
int count=0;
void QuickSort(int *a,int left,int right)
{
	int p=(left+right)/2;
	int key=a[p];
	for(int i=left,j=right;i<j;)
	{
		while(i<=p&&a[i]<=key)
		i++;
		if(i<p)
		{
			a[p]=a[i];
			p=i;
			count++;
		}
		while(j>=p&&a[j]>=key)
     	j--;
     	if(j>p)
     	{
     		a[p]=a[j];
     		p=j;
     		count++;
     	}
	}
	a[p]=key;
	if(p-left>1) QuickSort(a,left,p-1);
	if(right-p>1) 	QuickSort(a,p+1,right);
}
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	QuickSort(a,0,n-1);
	cout<<count<<endl;
	return 0;
}
