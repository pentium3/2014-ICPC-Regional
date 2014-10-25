#include "iostream"
#include "string"
#include "queue"
#include "fstream"
#include "cstring"
using namespace std;
struct edge
{
    int u,v,w;
    bool operator < (const edge &a) const
    {
        return w > a.w;
    }
};
priority_queue<edge> Edge;
int p[2001];
string vertex[2001];
int find(int x)
{
    return x!=p[x]?p[x]=find(p[x]):x;
}
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    int n;
    while(cin>>n&&n!=0)
    {
        for(int i=1;i<=n;i++)
        cin>>vertex[i];
        for(int i=1;i<=n;i++)
        {
           for(int j=i+1;j<=n;j++)
          {
              int tmp=0;
              for(int k=0;k<vertex[j].size();k++)
              if(vertex[i][k]!=vertex[j][k]) tmp++;
              edge tt;tt.u=i;tt.v=j;tt.w=tmp;
              Edge.push(tt);
          }
        }
        for(int i=1;i<=n;i++) p[i]=i;
        int sum=0;
        int count=0;
        while(count<n-1)
        {
            edge tmp=Edge.top();
            Edge.pop();
            int u=find(tmp.u);int v=find(tmp.v);
            if(u!=v)
            {
                sum+=tmp.w;
                cout<<tmp.u<<" "<<tmp.v<<" "<<tmp.w<<endl;
                p[v]=u;
                count++;
            }
        }
        cout<<"The highest possible quality is 1/"<<sum<<"."<<endl;
        priority_queue<edge> emp;
        Edge=emp;
        memset(p,0,sizeof(p));
    }
    return 0;
}
