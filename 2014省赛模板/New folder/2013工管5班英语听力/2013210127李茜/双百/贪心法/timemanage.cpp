#include "iostream"
#include "stdlib.h"
using namespace std;
struct node //s��ʼʱ�䣬f����ʱ�� 
{
	int s;
	int f;
};
node lib[20];
int TimeManage(int k,int n)
{
	int m=k+1;
	while(m<=n&&lib[m].s<lib[k].s) //�ҵ���ǰ���ȿɼ���㣬��Ϊm 
	  m++;
	if(m<=n) return TimeManage(m,n)+1; //���� 
	else return 0; //�޽��������Ҫ 
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
	qsort(lib+1,n,sizeof(node),compare); //���ս���ʱ������ 
	cout<<TimeManage(1,3)<<endl; 
	return 0;
}
