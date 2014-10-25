#include "cstdio"
int bomb[31];
int f[31];
int tmp;
int LIS(bool type)
{
    int sum=1,left,right,mid;
    f[1]=bomb[1];
    for(int i=2;i<tmp;i++)
    {
        left=1,right=sum;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(type)
            {
               if(f[mid]>=bomb[i]) left=mid+1;
               else right=mid-1;
            }
            else
            {
                if(f[mid]<=bomb[i]) left=mid+1;
                else right=mid-1;
            }
        }
        f[left]=bomb[i];
        if(left>sum) sum++;
    }
    return sum;
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d,",&bomb[++tmp])!=-1);
    printf("%d,%d",LIS(true),LIS(false)-1);
    return 0;
}
