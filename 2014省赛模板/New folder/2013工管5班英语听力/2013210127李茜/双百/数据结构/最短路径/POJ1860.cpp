#include "iostream"
#include "cstring"
#include "fstream"
using namespace std;
struct edge
{
    int u,v;
    double r,c;
}Edge[1000];
int n,m,s;
double v,d[101];
bool Bellman_Ford()
{
    memset(d,0,sizeof(d));
    d[s]=v;
    for(int i=1;i<=n-1;i++) //Relax
    {
        for(int j=1;j<=2*m;j++)
        {
            if(((d[Edge[j].u]-Edge[j].c)*Edge[j].r)>d[Edge[j].v])
                d[Edge[j].v]=(d[Edge[j].u]-Edge[j].c)*Edge[j].r;
        }
    }
    for(int j=1;j<=m*2;j++) //Judge
    {
        if(((d[Edge[j].u]-Edge[j].c)*Edge[j].r)>d[Edge[j].v])
            return true;
    }
    return false;
}
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    int U,V;
    double ra,rb,ca,cb;
    while(cin>>n>>m>>s>>v)
    {
        for(int i=1;i<=2*m;i=i+2) //Ìí¼Ó±ß
        {
            cin>>U>>V>>ra>>ca>>rb>>cb;
            Edge[i].u=U;Edge[i].v=V;Edge[i].r=ra;Edge[i].c=ca;
            Edge[i+1].u=V;Edge[i+1].v=U;Edge[i+1].r=rb;Edge[i+1].c=cb;
        }
        if(Bellman_Ford()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
