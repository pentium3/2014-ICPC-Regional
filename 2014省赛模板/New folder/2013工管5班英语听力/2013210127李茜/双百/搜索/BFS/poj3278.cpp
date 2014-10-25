#include "iostream"
#include "cstring"
#include "queue"
using namespace std;
#define MAX 100001
int f[MAX];
int n,k;
queue<int> bag;
bool v[MAX];
bool ok=false;
int bfs(int s,int p)
{
    bag.push(s);
    v[s]=true;
    f[s]=p;
    int x;
    while(!bag.empty())
   {
      int head=bag.front();
      bag.pop();
      for(int i=0;i<3;i++)
      {
        x=head;
        switch(i)
        {
        case 0:
            x=x-1;
            break;
        case 1:
            x=x+1;
            break;
        case 2:
            x=x*2;
            break;
        }
        if(x>MAX-1||x<0) continue;
        if(!v[x])
        {
            f[x]=f[head]+1;
            if(x==k) {return f[x];}
            bag.push(x);
            v[x]=true;
        }
    }
    if(ok) break;
  }
}
int main()
{
    cin>>n>>k;
    if(n==k) cout<<"0"<<endl;
    else cout<<bfs(n,0)<<endl;
    return 0;
}
