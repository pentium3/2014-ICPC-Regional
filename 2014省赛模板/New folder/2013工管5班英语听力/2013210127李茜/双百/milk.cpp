#include "iostream"
using namespace std;
struct cos
{
	int cost;
	int num;
};
void QuickSort(cos *a,int left,int right)
{
	int p=(left+right)/2;
	cos key=a[p];
	for(int i=left,j=right;i<j;)
	{
		while(i<=p&&a[i].cost<=key.cost)
		i++;
		if(i<p)
		{
			a[p]=a[i];
			p=i;
		}
		while(j>=p&&a[j].cost>=key.cost)
		j--;
		if(j>p)
		{
			a[p]=a[j];
			p=j;
		}
	}
	a[p]=key;
	if(p-left>1) QuickSort(a,left,p-1);
	if(right-p>1) QuickSort(a,p+1,right);
}
int main()
{
	int m,n;
	cin>>m>>n;
	cos *a=new cos[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i].cost>>a[i].num;
	}
	QuickSort(a,0,n-1);
	int x=0;int list=0;
	int cost=0;
	while(x<m)
	{
	   x+=a[list].num;
	   cost+=a[list].num*a[list].cost;
	   list++;
	}
	if(x>100)
	{
		list--;
		cost-=(x-100)*a[list].cost;
	}
	cout<<cost<<endl;
	return 0;
}
