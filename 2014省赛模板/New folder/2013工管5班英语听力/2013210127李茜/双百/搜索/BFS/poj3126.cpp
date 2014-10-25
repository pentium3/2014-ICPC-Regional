#include "iostream"
#include "string"
#include "queue"
#include "math.h"
#include "cstring"
using namespace std;
int Min=65535;
int ori,work;
int f[10000];
bool s[10000];
queue<int> bag;
bool isPrime(int k)
{
   double c=k;
   double n=sqrt(c);
   for(int i=2;i<=n;i++)
   {
       if(k%i==0) return false;
   }
   return true;
}
int bfs(int o,int v)
{
    f[o]=v;
    s[o]=true;
    bag.push(o);
    int head;
    while(!bag.empty())
    {
        head=bag.front();
        bag.pop();
        int pha,tmp,phs;
        for(int i=1;i<=4;i++)
        {
            if(i==1) pha=head/1000;
            if(i==2) {pha=head/100;pha=pha%10;}
            if(i==3) {pha=head/10;pha=pha%10;}
            if(i==4) pha=head%10;
            for(int j=0;j<=9;j++)
            {
                if(i==1&&j==0) continue;
                if(i==1) phs=(j-pha)*1000;
                if(i==2) phs=(j-pha)*100;
                if(i==3) phs=(j-pha)*10;
                if(i==4) phs=j-pha;
                tmp=phs+head; //变换
                if(tmp%2==0||!isPrime(tmp)) continue; //偶数和非质数剪枝
                if(!s[tmp])
                {
                f[tmp]=f[head]+1;
                s[tmp]=true;
                if(tmp==work) {return f[tmp];}
                bag.push(tmp);
                }

            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>ori>>work;
        if(ori==work) cout<<"0"<<endl;
        else  cout<<bfs(ori,0)<<endl;
        memset(f,0,sizeof(f));
        memset(s,false,sizeof(s));
        queue<int> BAG;
        bag=BAG;
    }
}
