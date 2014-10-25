#include "iostream"
#include "fstream"
#include "string"
#include "queue"
#include "cstring"
using namespace std;
char map[31][31][31];
int f[31][31][31];
bool s[31][31][31];
struct node
{
    int x,y,z;
};
node S,E;
queue<node> bag;
int x,y,z;
node make(int a,int b,int c)
{
    node tmp;
    tmp.z=a;
    tmp.x=b;
    tmp.y=c;
    return tmp;
}
bool Run(int X,int Y,int Z)
{
    if(X<1||X>x||Y<1||Y>y||Z<1||Z>z)
        return false;
    else
    {
        if(map[Z][X][Y]=='#'||s[Z][X][Y]) return false;
        else return true;
    }
}
int bfs(int v)
{
    f[S.z][S.x][S.y]=v;
    s[S.z][S.x][S.y]=true;
    bag.push(S);
    while(!bag.empty())
    {
        node head=bag.front();
        bag.pop();
        int X,Y,Z;
        //开始搜索 上下左右前后
        for(int i=1;i<=6;i++)
        {
            X=head.x;Y=head.y;Z=head.z;
            switch(i)
            {
            case 1:
                Z++;
                break;
            case 2:
                Z--;
                break;
            case 3:
                X--;
                break;
            case 4:
                X++;
                break;
            case 5:
                Y--;
                break;
            case 6:
                Y++;
                break;
            }
            if(Run(X,Y,Z))
            {
                //cout<<map[Z][X][Y];
                f[Z][X][Y]=f[head.z][head.x][head.y]+1;
                if(map[Z][X][Y]=='E') return f[Z][X][Y];
                s[Z][X][Y]=true;
                bag.push(make(Z,X,Y));
            }
        }
    }
    return 0;
}
int main()
{
    //#define fin cin
    //ifstream fin("in.txt");
    string tmp;
    while(cin>>z>>y>>x&&z!=0)
    {
        for(int i=1;i<=z;i++)
          for(int j=1;j<=y;j++)
            {
                cin>>tmp;
                for(int k=0;k<x;k++)
                {
                    map[i][k+1][j]=tmp[k];
                    if(tmp[k]=='S') S=make(i,k+1,j);
                }
            }
          int res=bfs(0);
          if(res) cout<<"Escaped in "<<res<<" minute(s)."<<endl;
          else cout<<"Trapped!"<<endl;
         //数据清理
         queue<node> BAG;
         bag=BAG;
         memset(map,0,sizeof(map));
         memset(f,0,sizeof(f));
         memset(s,false,sizeof(s));
    }

    return 0;
}
