#include "iostream"
#include "cstring"
#include "fstream"
using namespace std;
int map[101][101],dp[101][101];
int Case,m,n;
const int inf=65535;
void solve(int c)
{
    for(int i=1;i<=m;i++)
    {
        int tmp=dp[i][c-1]+map[i][c];
        dp[i][c]=max(tmp,dp[i][c]);
        for(int j=i+1;j<=m;j++)
        {
            tmp+=map[j][c];
            dp[j][c]=max(dp[j][c],tmp);
        }
    }
    for(int i=m;i>=1;i--)
    {
        int tmp=dp[i][c-1]+map[i][c];
        dp[i][c]=max(tmp,dp[i][c]);
        for(int j=i-1;j>=1;j--)
        {
            tmp+=map[j][c];
            dp[j][c]=max(dp[j][c],tmp);
        }
    }
}
int main()
{
    int no=0;
    cin>>Case;
    while(Case--)
    {
        cin>>m>>n;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                cin>>map[i][j];
                dp[i][j]=-inf;
            }
        dp[1][1]=map[1][1];
        for(int i=2;i<=m;i++) dp[i][1]=dp[i-1][1]+map[i][1];
        for(int i=2;i<=n;i++) solve(i);
        cout<<"Case #"<<++no<<":"<<endl<<dp[1][n]<<endl;
    }
    return 0;
}
