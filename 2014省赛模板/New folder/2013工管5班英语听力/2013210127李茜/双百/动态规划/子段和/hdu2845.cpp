#include "iostream"
#include "fstream"
#include "cstring"
using namespace std;
const int MX=2001;
int map[MX][MX];
int f[MX];
int h[MX];
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    int n,m;
    while(cin>>n>>m) //
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
             cin>>map[j][i];
        for(int i=1;i<=n;i++) //��ɨ
        {
            if(i-3>=0) f[i]=max(f[i-2],f[i-3]);//�̳�,ע��1��2��������ѡ�����Ե�����������Ž����Ϊ����
            for(int j=1;j<=m;j++) //������һ������Ҫ����1,3,5��Ծ
            {
               if(j-3>=0) h[j]=max(h[j-2],h[j-3]);
               h[j]+=map[j][i];
            }
            f[i]+=max(h[m],h[m-1]);
            memset(h,0,sizeof(h));
        }
        cout<<max(f[n],f[n-1])<<endl;
        memset(f,0,sizeof(f));
    }
}
