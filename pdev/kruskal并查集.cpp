#include <iostream>
using namespace std;

struct abc
{
    int x,y,dat;
};

struct abc e[1000];
int f[1000];
int i,j,k,ans,n,m,tx,ty,tmp;

int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return f[x];
}

void iunion(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if (fx!=fy)
        f[fy]=fx;
}

void qsort(int l,int r)
{
   int i,j,mid;
   struct abc t; 
   i=l;
   j=r;
   mid=e[(l+r)/2].dat;
   do{
       while (e[i].dat<mid) i++;
       while (e[j].dat>mid) j--;
       if (!(i>j))
       {
           t=e[i];
           e[i]=e[j];
           e[j]=t;
           i++;
           j--;
       }
   }while (i<=j);
   if (l<j) qsort(l,j);
   if (i<r) qsort(i,r);
}

int main()
{
    
    cin>>n>>m;
    for (i=1;i<=m;i++)
    {
        cin>>tx>>ty>>tmp;
        e[i].x=tx;
        e[i].y=ty;
        e[i].dat=tmp;
    }

    for (i=1;i<=n;i++)
        f[i]=i;
    qsort(1,m);
    
    k=1;
    ans=0;
    for (i=1;i<=n-1;i++)
    {
        while (find(e[k].x)==find(e[k].y)) k++;
        iunion(e[k].x,e[k].y);
        ans=ans+e[k].dat;
        cout<<e[k].x<<" "<<e[k].y<<" "<<e[k].dat<<endl;
    }
    
    cout<<ans<<endl;
}