#include "iostream"
#include "fstream"
#include "cstdio"
using namespace std;
int p[50001]; //同盟集 
int w[50001]; //敌对集 
int find(int x) //同盟查找 
{
	return p[x]!=x?p[x]=find(p[x]):x;
}
int xfind(int x) //敌对查找 
{
	return w[x]!=x?w[x]=xfind(w[x]):x;
}
int main() 
{
    int N,K;
    cin>>N>>K;
    int d,x,y;
    int fake=0;
    for(int i=1;i<=N;i++) 
	{
		p[i]=i;
		w[i]=i;
	}
    for(int i=1;i<=K;i++)
    {
    	scanf("%d%d%d",&d,&x,&y);
    	if(x>N||y>N||x==y&&d==2)  //二三条件 
		{
			fake++;
			continue;
    	}
    	int a=x,b=y; //做个备份 
    	int xx,yy;//敌对集查找 
    	//先确认同盟关系 
    	x=find(x);y=find(y);
    	if(x==y&&d==2)  fake++;
		if(x!=y) //非同盟 
		{
    	    xx=xfind(a);yy=xfind(b);
    	    if(a!=b) //非敌对 
    	    {
    	    	if(d==1) p[x]=y;
    	    	if(d==2)
    	    	{
    	    		w[yy]=xx; //X吃Y，X为父节点 
    	    	}
    	    }
    	    else //敌对 
    	    {
    	    	if(d==1) 
				{
    	    		fake++;
    	    		continue;
    	    	}
    	    	if(b==xx) fake++;//Y吃X 
    	    }
    	}
    }
    cout<<fake<<endl;
}

