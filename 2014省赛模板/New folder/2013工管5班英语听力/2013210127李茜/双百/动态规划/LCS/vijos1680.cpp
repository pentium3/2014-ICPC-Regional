#include "iostream"
#include "string"
using namespace std;
int f[2001][2001];
int ABS(int x)
{
    if(x<0) return -x;
    else return x;
}
int main()
{
    int k;
    string str1,str2;
    cin>>str1>>str2>>k;
    for(int i=1;i<=str1.size();i++) f[i][0]=f[i-1][0]+k;
    for(int i=1;i<=str2.size();i++) f[0][i]=f[0][i-1]+k;
    for(int i=1;i<=str1.size();i++)
    {
        for(int j=1;j<=str2.size();j++)
        {
            int t1=ABS(str1[i-1]-str2[j-1])+f[i-1][j-1],t2=k+f[i-1][j],t3=k+f[i][j-1];
            t1=min(t1,t2);
            t2=min(t1,t3);
            f[i][j]=t2;
        }
    }
    cout<<f[str1.size()][str2.size()]<<endl;
    return 0;

}
