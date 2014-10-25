#include<iostream>
#include<cstdio>
#include<cstring>
#include "fstream"
using namespace std;
const int maxn=1010;
int dp[maxn][maxn],a[maxn];
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    int n;
    while(cin>>n&&n!=0)
    {
        for(int i=0;i<n;i++)
            cin>>a[i]>>a[i+1];
        for(int i=1;i<=n;i++)
            dp[i][i]=0;
        for(int p=2;p<=n;p++)
        {
            for(int i=1;i<=n;i++)
            {
                int j=i+p-1;
                dp[i][j]=1000000;
                for(int k=i;k<j;k++)
                {
                    int ans=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
                    if(ans<dp[i][j])
                        dp[i][j]=ans;
                }
            }
        }
        cout<<dp[1][n]<<endl;
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
