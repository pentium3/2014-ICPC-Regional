#include "iostream"
#include "vector"
#include "cstring"
#include "set"
#include "fstream"
using namespace std;
long f[501];
long A[501],B[501];
int main()
{
    int Case,n1,n2;
    cin>>Case;
    while(Case--)
    {
        cin>>n1;
        for(int i=1;i<=n1;i++)
            cin>>A[i];
        cin>>n2;
        for(int i=1;i<=n2;i++)
            cin>>B[i];
        for(int i=1;i<=n1;i++)
        {
            long MAX=0;
            for(int j=1;j<=n2;j++)
            {
                if(A[i]>B[j]) MAX=max(MAX,f[j]);
                else if(A[i]==B[j]) f[j]=max(f[j],MAX+1);
            }
        }
        long MAX=0;
        for(int i=1;i<=n2;i++) if(f[i]>MAX) MAX=f[i];
        cout<<MAX<<endl;
        memset(f,0,sizeof(f));
    }
    return 0;
}
