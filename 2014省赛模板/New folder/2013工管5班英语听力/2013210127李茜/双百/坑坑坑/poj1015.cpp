#include "iostream"
#include "fstream"
#include "queue"
#include "vector"
using namespace std;
struct jury
{
    int d,p;
    int v;
};
struct node
{
    int v;
    int d,p;
    vector<jury>  bag;
};
int d[201],p[201];
node f[201];
bool s[201];
int ab(int a,int b)
{
    int t=a-b;
    return t>0?t:-t;
}
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    int n,m;
    while(cin>>n>>m&&n!=0)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>p[i];
        }
        //先行处理前m
        for(int i=1;i<=m;i++)
        {
           f[i].v=ab(f[i-1].d+d[i],f[i-1].p]+p[i]);
           f[i].bag=f[i-1].bag;
           jury tmp;tmp.d=d[i];tmp.p=p[i];tmp.v=ab(d[i],p[i]);
           f[i].bag.push_back(tmp);
           f[i].d=f[i-1].d+d[i];
           f[i].p=f[i-1].p+p[i];
        }
        for(int i=m+1;i<=n;i++)
        {
           int Min=65535,MinJ;
           int MIN=65535,MinO;
           for(int j=m;j<i;j++)
           {
               if(ab(f[j].d+d[i],f[j].p+p[i])<Min)
               {
                   Min=ab(f[j].d+d[i],f[j].p+p[i]);
                   MinJ=j;
               }
               if(f[j].v<MIN) MIN=f[j].v;
           }
           if(Min<MIN) //更优，替换
           {
               jury k;k.v=x;k.d=d[i];k.p=p[i];
               f[i].v=f[i-1].v-x+tmp.v;
               f[i].bag=f[i-1].bag;
               f[i].bag.pop();
               f[i].bag.push(k);
           }
           else if (x==tmp.v&&d[i]+p[i]>tmp.d+tmp.p) //次优
           {
               s[i-1]=true; //一旦进行次优替换，则被替换点一定不是需要的结果
               jury k;k.v=x;k.d=d[i];k.p=p[i];
               f[i].bag=f[i-1].bag;
               f[i].bag.pop();
               f[i].bag.push(k);
           }
           else
           {
               f[i].v=f[i-1].v;
               f[i].bag=f[i-1].bag;
           }
        }
        int Min=65535,MinJ;
        for(int i=m;i<=n;i++)
        {
            if(f[i].v<Min&&!s[i]) {Min=f[i].v;MinJ=i;}
        }
        int D=0,P=0;
        while(!f[MinJ].bag.empty())
        {
            jury tmp=f[MinJ].bag.top();
            D+=tmp.d;P+=tmp.p;
            f[MinJ].bag.pop();
        }
        cout<<Min<<endl;
        cout<<D<<" "<<P<<endl;
    }
    return 0;
}
