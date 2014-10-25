#include "iostream"
#include "fstream"
#include "cstring"
using namespace std;
int num[7];
int V;
int f[60000];
void zeroOnePack(int cost,int weight)
{
	for(int i=V;i>=cost;i--)
		f[i]=f[i-cost]+weight>f[i]?f[i-cost]+weight:f[i];
}
void completePack(int cost,int weight)
{
	for(int i=cost;i<=V;i++)
	   f[i]=f[i-cost]+weight>f[i]?f[i-cost]+weight:f[i];
}
void MultiPack(int cost,int weight,int amount)
{
	if(cost*amount>=V)
	{
		completePack(cost,weight);
		return;
	}
	int i=1;
	while(i<amount)
	{
		zeroOnePack(i*cost,i*weight);
		amount-=i;
		i<<=1;
	}
	zeroOnePack(amount*cost,amount*weight);
}
int main()
{
    #define fin cin
    ifstream fin("in.txt");
	int no=0;
	while(cin>>num[1])
	{
       V+=num[1];
	   for(int i=2;i<=6;i++)
	  {
	     cin>>num[i];
	     V+=num[i]*i;
	  }
	  if(V)
	  {
	  	no++;
	 	if(V%2==1) cout<<"Collection #"<<no<<":"<<endl<<"Can't be divided."<<endl<<endl;
	 	else
	 	{   V>>=1;
	 		for(int i=1;i<=6;i++)
	 		  MultiPack(i,i,num[i]);
	 		  if(f[V]==V) cout<<"Collection #"<<no<<":"<<endl<<"Can be divided."<<endl<<endl;
	 		  else cout<<"Collection #"<<no<<":"<<endl<<"Can't be divided."<<endl<<endl;
	 	}
	  }
	  memset(f,0,sizeof(f));
      V=0;
    }
    return 0;

}
