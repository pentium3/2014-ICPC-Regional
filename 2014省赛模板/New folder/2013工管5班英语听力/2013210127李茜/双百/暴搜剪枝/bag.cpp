#include "iostream"
using namespace std;
int w[]={99,29,26,18,16,13,10,8,5,3,1};
int k[11]; //��¼ÿ����Ʒ��ȡ��ȡ��� 
int S=50,n=10;
void dfs(int i,int j) //��i����ʱ����j�ռ� 
{
	if(i>n) //Խ�� 
	{
		if(j==0) //�������� 
		{
		    for(int i=1;i<=n;i++) //��� 
		    {
		    	if(k[i]) cout<<"("<<i<<","<<w[i]<<") ";
		    }
		    cout<<endl;
		}
		return;		
	}
	if(j-w[i]>=0) //ȡ��ǰ��i��Ʒ 
	{
		k[i]=1;
	    dfs(i+1,j-w[i]); //�ж��¸���Ʒ 
	}
	k[i]=0; //��ȡ��ǰ��Ʒ 
	dfs(i+1,j); //�ж��¸���Ʒ 
}

int main()
{
	dfs(1,S);
	return 0;
}
