#include "iostream"
#include "fstream"
#include "cstring"
using namespace std;
int f[201][201]={65535};
int c[101],d[101];
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    //memset(f,30000,sizeof(f));
    for(int i=200;i>=0;i--)
        for(int j=200;j>=0;j--)
           f[i][j]=30000;
    int n,t,q;
    while(cin>>n>>t>>q&&n!=0)
    {
        for(int i=1;i<=n;i++)
            cin>>c[i]>>d[i];
        f[100][100]=0;
            for(int j=100;j>=0;j--)
            {
                for(int k=100;k>=0;k--)
                {
                    if(j==100) continue;
                    int Min=30000;
                    for(int x=1;x<=n;x++) //技能使用回合
                    {
                        if(j+d[x]<=100&&k+c[x]<=100) //不被秒
                        {
                            if(f[j+d[x]][k+c[x]]<Min)
                            {
                                Min=f[j+d[x]][k+c[x]];
                            }
                        }
                    }
                    //我打击回合
                    if(j+1<=100&&f[j+1][k]<Min) Min=f[j+1][k];
                    //我回复回合#1
                    if(k+t<100&&f[j][k+t]<Min) Min=f[j][k+t];
                     //我回复回合#2
                    //if(k+t>=100&&f[j][100]<Min) Min=f[j][100];
                    f[j][k]=Min+1;
                }
            }
        int res=30000;
            for(int j=0;j<=100;j++)
                cout<<f[0][j]<<endl;
               //*if(f[i][0][j]) cout<<i<<" "<<j<<endl;
        //cout<<res<<endl;
        return 0;
    }
}
