#include "iostream"
#include "string"
#include "cstring"
using namespace std;
int f[101][101];
int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        memset(f,0,sizeof(f));
        for(int i=1;i<=str1.size();i++)
        {
            for(int j=1;j<=str2.size();j++)
            {
                if(str1[i-1]==str2[j-1]) f[i][j]=f[i-1][j-1]+1;
                else f[i][j]=max(f[i-1][j],f[i][j-1]);
            }
        }
        cout<<str1.size()+str2.size()-f[str1.size()][str2.size()]<<endl;
    }
    return 0;
}
