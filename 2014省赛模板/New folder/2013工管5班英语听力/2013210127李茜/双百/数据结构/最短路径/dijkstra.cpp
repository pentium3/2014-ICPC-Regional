#include "iostream"
#include "fstream"
using namespace std;
int map[99][99];
int n;
int d[99];
bool s[99];
void dijkstra()
{
	for(int i=1;i<=n;i++)
	   d[i]=map[1][i]; //4
	   s[4]=true;
	 for(int i=1;i<=n;i++)
	{
		int MIN=65535;
        int k;
		for(int j=1;j<=n;j++)
		{
			if(d[j]<MIN&&!s[j])
			{
				MIN=d[j];
				k=j;
			}
		}
		s[k]=true;
		for(int j=1;j<=n;j++)
		{
			if(d[k]+map[k][j]<d[j]&&!s[j])
			  d[j]=d[k]+map[k][j];
		}
	}
}
int main()
{
	#define fin cin
	ifstream fin("in.txt");
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	 for(int j=1;j<=n;j++)
	 {
	    cin>>map[i][j];
	    if(map[i][j]==-1) map[i][j]=65535;
	 }
    }
    dijkstra();
    cout<<d[3]<<endl;
    return 0;


}
