#include "iostream"
#include "vector"
#include "queue"
#include "cstring"
#include "fstream"
using namespace std;
const int inf=1000000000;
struct node
{
    int p,w;
};
vector<node> G[501]; //�ڽӱ�
int n,m,w;
bool vis[501];
int d[501];
int cnt[501]; //�����ڲ����鲻���ʼ��
bool SPFA()
{
    queue<int> Q;
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++) d[i]=inf;
    d[1]=0;
    Q.push(1);
    cnt[1]++;
    vis[1]=true;
    while(!Q.empty())
    {
        int x=Q.front();Q.pop();
        vis[x]=false;
        for(int i=0;i<G[x].size();i++) //x���ڽ�����v����Relax��
        {
            if(d[x]+G[x][i].w<d[G[x][i].p])
            {
                d[G[x][i].p]=d[x]+G[x][i].w;
                if(!vis[G[x][i].p])
                {
                    vis[G[x][i].p]=true;
                    Q.push(G[x][i].p);
                    if(++cnt[G[x][i].p]>n) return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    int Case,S,E,T;
    cin>>Case;
    while(Case--)
    {
        cin>>n>>m>>w;
        node tmp;
        for(int i=1;i<=m;i++) //��Ȩ��
        {
            cin>>S>>E>>T;
            tmp.p=E;tmp.w=T;
            G[S].push_back(tmp);
            tmp.p=S;tmp.w=T;  //�走����Ȩ������ͼ����Ȩ������ͼ
            G[E].push_back(tmp);
        }
        for(int i=1;i<=w;i++) //��Ȩ��
        {
            cin>>S>>E>>T;
            tmp.p=E;tmp.w=-T;
            G[S].push_back(tmp);
        }
        if(SPFA()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        for(int i=1;i<=500;i++) G[i].clear();
    }
}
