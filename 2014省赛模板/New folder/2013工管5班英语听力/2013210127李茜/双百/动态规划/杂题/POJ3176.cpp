#include "iostream"
#include "fstream"
using namespace std;
int a[1001][1001];
int f[1001][1001];
int N;
/*
int dp(int i,int j)
{
    if(i>N) return 0;
    if(f[i][j]) return f[i][j];
    int k1=a[i][j]+dp(i+1,j);
    int k2=a[i][j]+dp(i+1,j+1);
    return f[i][j]=k1>k2?k1:k2;
}*/ //自顶向下居然TLE了，POJ你就是个坑
int count=0;
int main()
{
    #define fin  cin
    ifstream fin("in.txt");
    cin>>N;
    for(int i=1;i<=N;i++)
	  for(int j=1;j<=i;j++)
	    cin>>a[i][j];
    f[1][1]=a[1][1];
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
            f[i][j]=f[i-1][j-1]+a[i][j]>f[i-1][j]+a[i][j]?f[i-1][j-1]+a[i][j]:f[i-1][j]+a[i][j];
            count++;
        }
    }
    int MAX=0;
    for(int i=1;i<=N;i++)
    {
        if(f[N][i]>MAX) MAX=f[N][i];
    }
    cout<<MAX<<endl;
    return 0;
}
