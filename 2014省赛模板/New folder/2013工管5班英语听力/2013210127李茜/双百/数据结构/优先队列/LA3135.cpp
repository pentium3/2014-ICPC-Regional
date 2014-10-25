#include "cstdio"
#include "queue"
using namespace std;
struct element
{
	int num,period,time;
	bool operator < (const element &a) const
	{
		return time > a.time || (time==a.time && num>a.num);
	}
};
int main()
{
	char a[20];
	int QNum,Period;
	priority_queue<element> bag;
	while(scanf("%s",a)&&a[0]!='#')
	{
		scanf("%d%d",&QNum,&Period);
		element temp;
		temp.num=QNum;temp.period=Period;temp.time=Period;
		bag.push(temp);
	}
	
	int k;
	scanf("%d",&k);
	while(k--)
	{
		printf("%d\n",bag.top().num);
		element temp=bag.top();
		temp.time+=temp.period;
		bag.pop();
		bag.push(temp);		
	}
	return 0;
}
