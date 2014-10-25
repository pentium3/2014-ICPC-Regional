#include "iostream"
#include "queue"
#include "vector"
using namespace std;
int main()
{
	int N,sum=0,tmp;
	long long int money=0;
	priority_queue<int, vector<int>, greater<int> > bag;
	cin>>N;
	int x,y;
	for(int i=1;i<=N;i++)
	{
		cin>>tmp;
		bag.push(tmp);
	}
	for(int i=1;i<=N-1;i++)
	{
		x=bag.top();
		bag.pop();
		y=bag.top();
		bag.pop();
		money=money+x+y;
		bag.push(x+y);
	}
	cout<<money<<endl;
	return 0;
}
