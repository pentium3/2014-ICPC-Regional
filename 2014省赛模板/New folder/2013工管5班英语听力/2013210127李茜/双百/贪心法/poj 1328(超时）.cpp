#include "iostream"
#include "cstdio"
#include "cstring"
#include "vector"
#include "map"
using namespace std;
int mac;
int x[1001],y[1001];
int N,d;
int Left=65535;
int Right=-65535;
int sum=0;
int k[1001];
bool scan(int x,int y,int k)
{
	if(x>=k-d&&x<=k+d&&y>=-d&&y<=d)
	   return true;
	else return false;
}
int main()
{
	freopen("in.txt","r",stdin);
	int no=0;
	while(scanf("%d%d",&N,&d)==2&&N>0)
	{
		no++;
		map<int,int> land;
		for(int i=1;i<=N;i++)
		{
		  scanf("%d%d",&x[i],&y[i]);
		  if(x[i]>Right) Right=x[i];
		  if(x[i]<Left) Left=x[i];
	    }
	    while(sum<N)
	    {
	    	vector<int> kami;
	    	int Max=0;
	    	int p=0;
	    	for(int i=Left;i<=Right;i++) //这一趟中找出最大不重合点x(一个） 
	    	{
	    		if(land.count(i)) continue;
	    		int tmp=0;
	    		vector<int> bag;
	    		for(int j=1;j<=N;j++)
	    		{
	    			if(scan(x[j],y[j],i)&&!k[j]) //抓住岛屿 
	    			{
	    				tmp++;
	    				bag.push_back(i);
	    			}
	    		}
	    		if(tmp>Max)
	    		{
	    			p=i;
	    			Max=tmp;
	    			kami=bag;
	    		}
	    	}
	    	//战后统计
			for(int i=0;i<kami.size();i++)
			{
				k[kami[i]]=1;
			}
			sum+=kami.size();
			mac++;
			land[p]=1;
	    }
	    cout<<"Case "<<no<<": "<<mac<<endl;
	    //数据清理
	    memset(x,0,sizeof(x));
	    memset(y,0,sizeof(y));
	    memset(k,0,sizeof(k));
	    Left=65535;
	    Right=-65535;
	    mac=0;
	    sum=0;
	}
	
}
