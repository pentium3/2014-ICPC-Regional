#include "iostream"
#include "vector"
using namespace std;
#define INT long long
INT num;
bool flag=false;
vector<INT> ces;
void dfs(INT x,INT res,int list,vector<INT> xx)
{
    if(res==num&&xx.size()>=3&&xx.size()<=100)
    {
        ces=xx;
        flag=true;
        return;
    }
    if(x==0) return;
    for(int i=2;i<=100;i++)
    {
        if(x%i==0)
        {
            vector<INT> a=xx;
            a.push_back(x/i);
            if(list%2==0) dfs(x/i,res-x/i,list+1,a);
            else dfs(x/i,res+x/i,list+1,a);
        }
    }
}
int main()
{
    int Case;
    cin>>Case;
    int no=0;
    while(Case--)
    {
        no++;
        cin>>num;
        vector<INT> emp,cc;
        for(int i=100;i<=num*10;i++)
        {
            cc.push_back(i);
            dfs(i,i,2,cc);
            if(flag)
           {
              for(int i=0;i<ces.size();i++)
                cout<<ces[i]<<" ";
             cout<<endl;
             break;
           }
        }
    }
    return 0;
}
