#include "iostream"
#include "stdlib.h"
using namespace std;
struct node //s开始时间，f结束时间 
{
	int s;
	int f;
};
node lib[20];
int TimeManage(int k,int n)
{
	int m=k+1;
	while(m<=n&&lib[m].s<lib[k].s) //找到当前最先可加入点，存为m 
	  m++;
	if(m<=n) return TimeManage(m,n)+1; //分治 
	else return 0; //无解情况很重要 
}
int compare(const void *b1,const void *b2)
{
	node *aa=(node*)b1;
	node *bb=(node*)b2;
	return ((aa->f)-(bb->f));
}
int main()
{
	int n=3;
	for(int i=1;i<=n;i++)
	{
		cin>>lib[i].s>>lib[i].f;
	}
	qsort(lib+1,n,sizeof(node),compare); //按照结束时间排序 
	cout<<TimeManage(1,3)<<endl; 
	return 0;
}
