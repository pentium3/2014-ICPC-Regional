#include <iostream>
#include <math.h>
#include "fstream"
#include "stdlib.h"
using namespace std;
struct road
{
    int a,b;
}R[1001];
int f[1001];
int cmp(const void *a,const void *b)
{
    road *aa=(road*)a;
    road *bb=(road*)b;
    if(aa->a==bb->a) return aa->b-bb->b;
    else return aa->a-bb->a;
}
int main()
{
    //#define fin cin
    //ifstream fin("in.txt");
    int n,m,k;
    cin>>n>>m>>k;
    if(n>m) swap(n,m);
    for(int i=1;i<=k;i++)
        cin>>R[i].a>>R[i].b;
    qsort(R+1,k,sizeof(road),cmp);
    for(int i=1;i<=k;i++)
    {
        f[i]=1;
        for(int j=1;j<i;j++)
            if(R[i].a>R[j].a&&R[i].b>R[j].b&&f[j]+1>f[i])
                f[i]=f[j]+1;
    }
    int MAX=0;
    for(int i=1;i<=k;i++)
        if(f[i]>MAX) MAX=f[i];
    if(MAX>n) MAX=n;
    double res=(n+m-MAX*2)*100+MAX*sqrt(2)*100;
    if(res>=(int)res+0.5) cout<<(int)++res<<endl;
    else cout<<(int)res<<endl;
    return 0;
}
