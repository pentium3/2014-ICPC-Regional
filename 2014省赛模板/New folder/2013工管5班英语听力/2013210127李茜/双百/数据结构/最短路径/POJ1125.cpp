#include "iostream"
using namespace std;
int G[101][101];
int n;
const int inf=100000;
int main()
{
    int m,obj,time;
    while(cin>>n&&n!=0)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                G[i][j]=inf;
            }
        for(int i=1;i<=n;i++)
        {
            cin>>m;
            for(int j=1;j<=m;j++)
            {
                cin>>obj>>time;
                G[i][obj]=time;
            }
        }
        for(int k=1;k<=n;k++) //floyd
            for(int i=1;i<=n;i++)
              for(int j=1;j<=n;j++)
                 if(G[i][k]+G[k][j]<G[i][j]) G[i][j]=G[i][k]+G[k][j];
        int MAX=0,Min=inf;
        int src;
        for(int i=1;i<=n;i++)
        {
            MAX=0;
            for(int j=1;j<=n;j++)
                if(i!=j&&G[i][j]>MAX) MAX=G[i][j];
            if(MAX<Min)
            {
                Min=MAX;
                src=i;
            }
        }
        if(Min>=inf) cout<<"disjoint"<<endl;
        else cout<<src<<" "<<Min<<endl;
    }
}
