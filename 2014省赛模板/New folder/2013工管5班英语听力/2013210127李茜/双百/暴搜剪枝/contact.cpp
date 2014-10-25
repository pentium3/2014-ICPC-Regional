#include "iostream"
#include "fstream"
#include "vector"
using namespace std;
int n;
int map[51][51];
int a[51];
int dp(int k,int j,vector<int> bag)
{
    if(k>n) 
	{
		return 0;
	}
    int c=0,b=0;
    vector<int> copy1=bag;
    //vector<int> copy2=bag; 
    if(j==0) //加入始点 
    {
    	copy1.push_back(k);
    	c=dp(k+1,j+1,copy1)+1;
    }
    else //加入次点 
    {
       int i;
       int count=0;
       for(vector<int>::iterator ivec=copy1.begin();ivec!=copy1.end();ivec++)
       {
       	  i=*ivec;
       	  if(map[k][i]&&map[i][k]) count++;
       }
       if(count==j)
       {
       	  copy1.push_back(k);
       	  c=dp(k+1,j+1,copy1)+1;
       }
    }
    b=dp(k+1,j,bag);
    return c>b?c:b;
}
int main()
{
	#define fin cin
	ifstream fin("in.txt");
	cin>>n;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	   cin>>map[i][j];
	   vector<int> tree;
	cout<<dp(1,0,tree)<<endl;
	return 0;
	
}
