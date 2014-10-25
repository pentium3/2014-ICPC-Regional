#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "fstream"
using namespace std;
int G[401][401],link[401];
int map[410][410];
bool vis[801];
int Case,n,m,pos;
void AddEdge(int x,int y)
{
    G[x][y]=1; //本点连影子点
}
bool dfs(int u)
{
    for(int v=1;v<=pos;v++)
    {
        if(G[u][v]&&!vis[v])
        {
            vis[v]=true;
            if(!link[v]||dfs(link[v]))
            {
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    string line;
    cin>>Case;
    while(Case--)
    {
        pos=0;
        int res=0;
        cin>>n>>m;
        getline(cin,line);
        for(int i=1;i<=n;i++) //吸收残留
        {
            getline(cin,line);
            for(int j=0;j<line.size();j++)
                if(line[j]=='*') map[i][j+1]=++pos;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(map[i][j]&&map[i-1][j]) AddEdge(map[i][j],map[i-1][j]);
                if(map[i][j]&&map[i+1][j]) AddEdge(map[i][j],map[i+1][j]);
                if(map[i][j]&&map[i][j-1]) AddEdge(map[i][j],map[i][j-1]);
                if(map[i][j]&&map[i][j+1]) AddEdge(map[i][j],map[i][j+1]);
            }
        }
        for(int i=1;i<=pos;i++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i)) res++;
        }
        res=pos-res/2;
        cout<<res<<endl;
        memset(map,0,sizeof(map));
        memset(G,0,sizeof(G));
        memset(link,0,sizeof(link));
    }
}

