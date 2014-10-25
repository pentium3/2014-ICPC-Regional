#include "iostream"
using namespace std;
int a[]={99,4,1,3,2,16,9,10,14,8,7};
int size=sizeof(a)/sizeof(int)-1;
void MaxHeapify(int *a,int i) //最大堆整理 
{
	int l=2*i;
	int r=l+1;
	int largest;
	if(l<=size&&a[l]>a[i])
	largest=l;
	else largest=i;
	if(r<=size&&a[r]>a[largest])
	largest=r;
	if(largest!=i)
	{
		int temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		MaxHeapify(a,largest);
	}
}
void MaxHeapBuild(int *a)
{
	for(int i=size/2;i>=1;i--)
	  MaxHeapify(a,i);
}
void HeapSort(int *a)
{
	MaxHeapBuild(a);
	for(int i=size;i>=2;i--)
	{
		int temp=a[i];
		a[i]=a[1];
		a[1]=temp;
		size--;
		MaxHeapify(a,1);
	}
}
int main()
{
	HeapSort(a);
	for(int i=1;i<=10;i++)
	  cout<<a[i]<<" ";
	  return 0;	
}
