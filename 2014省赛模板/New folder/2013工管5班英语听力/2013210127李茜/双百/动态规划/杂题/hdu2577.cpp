#include "iostream"
#include "cstring"
#include "string"
#include "fstream"
using namespace std;
int f[101][2];
const int inf=3000;
bool isBig(char x)
{
    if(x>=65&&x<=90) return true;
    else return false;
}
int main()
{
    int n;
    string str;
    cin>>n;
    while(n--)
    {
       cin>>str;
       if(isBig(str[0]))
       {
           f[1][0]=2;
           f[1][1]=2;
       }
       else
       {
           f[1][0]=1;
           f[1][1]=2;
       }
       for(int i=2;i<=str.size();i++)
       {
           if(isBig(str[i-1]))
           {
               f[i][0]=min(f[i-1][0]+2,f[i-1][1]+2);
               f[i][1]=min(f[i-1][0]+2,f[i-1][1]+1);
           }
           else
           {
               f[i][0]=min(f[i-1][0]+1,f[i-1][1]+2);
               f[i][1]=min(f[i-1][0]+2,f[i-1][1]+2);
           }
       }
       int Min=f[str.size()][0]<f[str.size()][1]+1?f[str.size()][0]:f[str.size()][1]+1;
       cout<<Min<<endl;
    }
}
