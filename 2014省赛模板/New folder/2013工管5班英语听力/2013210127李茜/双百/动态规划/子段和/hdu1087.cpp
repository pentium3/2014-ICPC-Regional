#include "iostream"
#include "cstdio"
#include "string"
#include "cstring"
#include "fstream"
using namespace std;
int arr[1001],sum[1001];
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    string line;
    int n,MAX;
    while(cin>>n&&n!=0)
    {
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        sum[1]=arr[1];
        for(int i=2;i<=n;i++)
        {
            MAX=0;
            for(int j=1;j<i;j++)
                if(sum[j]>MAX&&arr[i]>arr[j]) MAX=sum[j];
            sum[i]=MAX+arr[i];
        }
        MAX=0;
        for(int i=1;i<=n;i++) if(sum[i]>MAX) MAX=sum[i];
        cout<<MAX<<endl;
        memset(sum,0,sizeof(sum));
    }
}
