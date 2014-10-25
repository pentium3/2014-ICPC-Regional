#include "iostream"
#include "queue"
#include "cstring"
#include "fstream"
using namespace std;
int p[501];
int find(int x)
{
    return x!=p[x]?p[x]=find(p[x]):x;
}
struct road
{
    int u,v,w;
    bool operator < (const road &a) const
    {
        return w > a.w;
    }
};
int dist[501][501];
priority_queue<road> ROAD,emp;
int main()
{
    int Case,n;
    cin>>Case;
    while(Case--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
               cin>>dist[i][j];
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
        {
             road tmp;tmp.u=i;tmp.v=j;tmp.w=dist[i][j];
             ROAD.push(tmp);
        }
        for(int i=1;i<=n;i++) p[i]=i;
        int count=0;
        int u,v;
        int MAX=0;
        int sum=0;
        while(count<n-1)
        {
            road tt=ROAD.top();
            ROAD.pop();
            u=find(tt.u);v=find(tt.v);
            if(u!=v)
            {
                p[v]=u;
                if(tt.w>MAX) MAX=tt.w;
                count++;
            }
        }
        cout<<MAX<<endl;
        memset(p,0,sizeof(p));
        ROAD=emp;
    }
    return 0;
}
