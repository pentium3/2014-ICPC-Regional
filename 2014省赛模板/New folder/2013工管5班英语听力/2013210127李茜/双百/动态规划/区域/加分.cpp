#include "iostream"
#include "fstream"
#include "cstring"
using namespace std;
int f[31][31];
int m[31][31];
int node[31];
void print(int i,int j)
{
    cout<<m[i][j]<<" ";
    if(i<=m[i][j]-1) print(i,m[i][j]-1);
    if(m[i][j]+1<=j) print(m[i][j]+1,j);
}
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    int n;
    while(cin>>n)
    {
    for(int i=1;i<=n;i++)
        cin>>node[i];
    for(int i=1;i<=n;i++)
    {
        f[i][i]=node[i];
        m[i][i]=i;
        f[i][i+1]=node[i]+node[i+1];
        m[i][i+1]=i;
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            int MAX=0;
            if(i==j+1||j==i+1||i==j) continue;
            for(int k=i;k<=j;k++)
            {
                if((f[i][k-1]*f[k+1][j]+node[k])>MAX)
                {
                    MAX=f[i][k-1]*f[k+1][j]+node[k];
                    m[i][j]=k;
                }
            }
            f[i][j]=MAX;
        }
    }
    cout<<f[1][n]<<endl;
    print(1,n);
    }
    return 0;
}
