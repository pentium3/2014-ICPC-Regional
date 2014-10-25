#include "iostream"
#include "fstream"
using namespace std;
double f[1001],a[1001];
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    f[1]=a[1];
    int sum=1;
    for(int i=2;i<=n;i++)
    {
       int left=1,right=sum;
       while(left<=right)
       {
           int mid=(left+right)/2;
           if(f[mid]<a[i]) left=mid+1;
           else right=mid-1;
       }
       f[left]=a[i];
       if(left>sum) sum++;
    }
    cout<<sum<<endl;
    return 0;
}
