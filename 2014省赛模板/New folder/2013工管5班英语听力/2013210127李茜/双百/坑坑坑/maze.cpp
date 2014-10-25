#include "iostream"
using namespace std;
long long int f[1100];
int p[1100];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    int start=1;
    long long int step=0;
    int ok=false;
    while(!ok)
    {
        if(start==n+1) {ok=true;continue;}
        f[start]++;
        if(f[start]%2==0) start++;
        else start=p[start];
        step++;
    }
    step=step%1000000007;
    cout<<step<<endl;
    return 0;
}
