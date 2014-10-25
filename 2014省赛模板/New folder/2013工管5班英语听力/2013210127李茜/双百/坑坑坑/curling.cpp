#include "iostream"
#include "cstring"
#include "fstream"
using namespace std;
int n,m;
int map[25][25];
int sx,sy,ex,ey;
int Min=65535;
void dfs(int i,int j,int k)
{
    if(k==11) return;
    int x=i,y=j;
    //up
    while(map[x][y]!=1)
    {
        y--;
        if(y<1) break;
        if(map[x][y]==3)
        {
            if(k<Min) Min=k;
            break;
        }
    }
    if(map[x][y]==1&&!map[x][y+1])
    {
        map[x][y]=0;
        dfs(x,y+1,k+1);
        map[x][y]=1;
    }
    if(map[x][y]==1&&map[x][y+1]==2)
    {
        if(map[i][j]!=2)
        {
        map[x][y]=0;
        dfs(x,y+1,k+1);
        map[x][y]=1;
        }
    }
    //down
    x=i;y=j;
    while(map[x][y]!=1)
    {
        y++;
        if(y>m) break;
        if(map[x][y]==3)
        {
            if(k<Min) Min=k;
            break;
        }
    }
   if(map[x][y]==1&&!map[x][y-1])
    {
        map[x][y]=0;
        dfs(x,y-1,k+1);
        map[x][y]=1;
    }
     if(map[x][y]==1&&map[x][y-1]==2)
    {
        if(map[i][j]!=2)
        {
        map[x][y]=0;
        dfs(x,y-1,k+1);
        map[x][y]=1;
        }
    }
    //left
    x=i;y=j;
    while(map[x][y]!=1)
    {
        x--;
        if(x<1) break;
        if(map[x][y]==3)
        {
            if(k<Min) Min=k;
            break;
        }
    }
    if(map[x][y]==1&&!map[x+1][y])
    {
        map[x][y]=0;
        dfs(x+1,y,k+1);
        map[x][y]=1;
    }
     if(map[x][y]==1&&map[x+1][y]==2)
    {
        if(map[i][j]!=2)
        {
        map[x][y]=0;
        dfs(x+1,y,k+1);
        map[x][y]=1;
        }
    }
    //right
    x=i;y=j;
    while(map[x][y]!=1)
    {
        x++;
        if(x>n) break;
        if(map[x][y]==3)
        {
            if(k<Min) Min=k;
            break;
        }
    }
    if(map[x][y]==1&&!map[x-1][y])
    {
        map[x][y]=0;
        dfs(x-1,y,k+1);
        map[x][y]=1;
    }
    if(map[x][y]==1&&map[x-1][y]==2)
    {
        if(map[i][j]!=2)
        {
        map[x][y]=0;
        dfs(x-1,y,k+1);
        map[x][y]=1;
        }
    }
}
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>map[i][j];
                if(map[i][j]==2) {sx=i;sy=j;}
                if(map[i][j]==3) {ex=i;ey=j;}
            }
        }
        dfs(sx,sy,1);
        if(Min!=65535) cout<<Min<<endl;
        else cout<<"-1"<<endl;
        memset(map,0,sizeof(map));
        Min=65535;
    }
    return 0;
}

