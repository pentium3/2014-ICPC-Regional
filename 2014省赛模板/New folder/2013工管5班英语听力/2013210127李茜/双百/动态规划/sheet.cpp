#include "iostream"
#include "vector"
#include "fstream"
#include "cstring"
using namespace std;
double Q;
int N;
double value[31];
double f[31];
int main()
{
	#define fin cin
	ifstream fin("in.txt");
	do
	{
		cin>>Q>>N;
		if(N)
		{
			//读入 
			for(int i=1;i<=N;i++)
			{
				int x;
				double temp=0,sum=0;
				cin>>x;
				//合并支票 
				for(int j=0;j<x;j++)
				{
					cin>>temp;
					sum+=temp;
				}
				value[i]=sum;
			}
			//处理
          for(int i=1;i<=N;i++)
          {
          	 for(int j=1;j<=N;j++)
          	 {
          	 	 if(f[j-1]+value[i]<=Q)
          	 	  f[j]=f[j]>f[j-1]+value[i]?f[j]:f[j-1]+value[i];
          	 }
          }
        double Max=0;  
        for(int i=1;i<=N;i++)  
        {  
            if(f[i]>Max) 
                Max=f[i];
        }
        cout<<Max<<endl;
        memset(f,0,sizeof(f));
		}
	}while(N);
	return 0;
}
