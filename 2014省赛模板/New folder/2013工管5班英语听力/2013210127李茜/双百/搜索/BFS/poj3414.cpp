#include "iostream"
#include "cstring"
#include "queue"
using namespace std;
bool s[101][101];
struct node
{
    int a,b;
};
struct data
{
    queue<int> pack;
    int f;
};
data f[101][101];
queue<node> bag;
int A,B,C;
node make(int a,int b)
{
    node tmp;
    tmp.a=a;
    tmp.b=b;
    return tmp;
}
data bfs(int v)
{
    f[0][0].f=v;
    s[0][0]=true;
    node tmp;
    tmp.a=0;tmp.b=0;bag.push(tmp);
    int a,b;
    while(!bag.empty())
    {
        node head=bag.front();
        bag.pop();
        int vol;
        for(int i=1;i<=6;i++)
        {
            a=head.a;b=head.b;
            switch(i)
            {
            case 1:
               a=A;
               break;
            case 2:
               a=0;
               break;
            case 3:
                vol=B-b;
                if(a<=vol) {b=b+a;a=0;}
                else {a=a-vol;b=B;}
                break;
            case 4:
                b=B;
                break;
            case 5:
                b=0;
                break;
            case 6:
                vol=A-a;
                if(b<=vol) {a=a+b;b=0;}
                else {b=b-vol;a=A;}
                break;
            }
            if(!s[a][b])
            {
                f[a][b].f=f[head.a][head.b].f+1;
                f[a][b].pack=f[head.a][head.b].pack;
                f[a][b].pack.push(i);
                if(a==C||b==C) return f[a][b];
                s[a][b]=true;
                bag.push(make(a,b));
            }
        }
    }
    data err;
    err.f=-1;
    return err;
}
int main()
{
    cin>>A>>B>>C;
    data res=bfs(0);
    if(res.f!=-1)
    {
    cout<<res.f<<endl;
    int opr;
    while(!res.pack.empty())
    {
       opr=res.pack.front();
       res.pack.pop();
       switch(opr)
       {
       case 1:
        cout<<"FILL(1)"<<endl;
        break;
       case 2:
        cout<<"DROP(1)"<<endl;
        break;
       case 3:
        cout<<"POUR(1,2)"<<endl;
        break;
       case 4:
        cout<<"FILL(2)"<<endl;
        break;
       case 5:
        cout<<"DROP(2)"<<endl;
        break;
       case 6:
        cout<<"POUR(2,1)"<<endl;
        break;
       }
    }
    }
    else cout<<"impossible"<<endl;
    return 0;
}
