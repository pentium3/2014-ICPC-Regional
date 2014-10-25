#include "iostream"
#include "stdlib.h"
#include "cstring"
using namespace std;
struct block
{
    int a,b;
}B[10001];
int n;
int f[10001];
int cmp(const void *a,const void *b)
{
    block *aa=(block*)a;
    block *bb=(block*)b;
    if(aa->a==bb->a) return aa->b-bb->b;
    else return aa->a-bb->a;
}
int LIS()
{
    int *arr=new int[n+1];
    int *f=new int[n+1];
    for(int i=1;i<=n;i++) arr[i]=B[i].b;
    int sum=1;f[1]=arr[1];
    int left,right,mid;
    for(int i=2;i<=n;i++)
    {
        left=1;right=sum;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(f[mid]<=arr[i]) left=mid+1;
            else right=mid-1;
        }
        f[left]=arr[i];
        if(left>sum) sum++;
    }
    return sum;
}
int main()
{
    while(cin>>n&&n!=0)
    {
        for(int i=1;i<=n;i++)
            cin>>B[i].a>>B[i].b;
        qsort(B+1,n,sizeof(block),cmp);
        for(int i=1;i<=n;i++)
        {
            f[i]=1;
            for(int j=1;j<i;j++)
                if(B[i].b>=B[j].b&&f[j]+1>f[i]) f[i]=f[j]+1;
        }
        int MAX=0;
        for(int i=1;i<=n;i++)
            if(f[i]>MAX) MAX=f[i];
        cout<<MAX<<endl;
        memset(f,0,sizeof(f));
    }
    cout<<"*"<<endl;
    return 0;
}
