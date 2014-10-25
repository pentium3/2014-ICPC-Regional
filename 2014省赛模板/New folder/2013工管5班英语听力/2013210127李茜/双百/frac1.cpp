#include "iostream"
#include "vector"
using namespace std;
struct K
{
	int x;
	int y;
	double value;
};
void QuickSort(vector<K> &a,int left,int right)
{
	int p=(left+right)/2;
	K backup=a[p];
	double key=a[p].value;
	for(int i=left,j=right;i<j;)
	{
		while(i<=p&&a[i].value<=key)
		i++;
		if(i<p)
		{
			a[p]=a[i];
			p=i;
		}
		while(j>=p&&a[j].value>=key)
		j--;
		if(j>p)
		{
			a[p]=a[j];
			p=j;
		}
	}
	a[p]=backup;
	if(p-left>1)  QuickSort(a,left,p-1);
	if(right-p>1) QuickSort(a,p+1,right);
}
int main()
{
	int n;
	cin>>n;
	vector<K> a;
	for(int i=n;i>1;i--)
	{
		for(int j=i-1;j>=1;j--)
		{
			K temp;
		    temp.x=j;
		    temp.y=i;
		    temp.value=(double)j/i;
			a.push_back(temp);
		}
	}
	K t1,t2;
	t1.x=0;t1.y=1;t1.value=0;
	t2.x=1;t2.y=1;t2.value=1;
	a.push_back(t1);
	a.push_back(t2);
    QuickSort(a,0,a.size()-1);
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i].x<<"/"<<a[i].y<<endl;
	}
	return 0;
}
	
