#include "iostream"
#include "fstream"
#include "cstdio"
using namespace std;
int p[50001]; //ͬ�˼� 
int w[50001]; //�жԼ� 
int find(int x) //ͬ�˲��� 
{
	return p[x]!=x?p[x]=find(p[x]):x;
}
int xfind(int x) //�жԲ��� 
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
    	if(x>N||y>N||x==y&&d==2)  //�������� 
		{
			fake++;
			continue;
    	}
    	int a=x,b=y; //�������� 
    	int xx,yy;//�жԼ����� 
    	//��ȷ��ͬ�˹�ϵ 
    	x=find(x);y=find(y);
    	if(x==y&&d==2)  fake++;
		if(x!=y) //��ͬ�� 
		{
    	    xx=xfind(a);yy=xfind(b);
    	    if(a!=b) //�ǵж� 
    	    {
    	    	if(d==1) p[x]=y;
    	    	if(d==2)
    	    	{
    	    		w[yy]=xx; //X��Y��XΪ���ڵ� 
    	    	}
    	    }
    	    else //�ж� 
    	    {
    	    	if(d==1) 
				{
    	    		fake++;
    	    		continue;
    	    	}
    	    	if(b==xx) fake++;//Y��X 
    	    }
    	}
    }
    cout<<fake<<endl;
}

