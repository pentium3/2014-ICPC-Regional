//insert 插入
//remove 删除
//_find 查找
//kth 返回root为根的树中第k大的元素
//treap插入、删除、查询时间复杂度均为O(logn)
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

struct Node
{
    Node* ch[2];
    int r,v,s;    //r:随机优先级，v:值，s:以本节点为根的子树的结点总数
    bool operator < (const Node& rhs)
    {
        return (r<rhs.r);
    }
    int cmp(int x)
    {
        if (x==v) return -1;
        return x<v?0:1;
    }
    void maintain()
    {
        s=1;
        if (ch[0]!=NULL) s+=ch[0]->s;
        if (ch[1]!=NULL) s+=ch[1]->s;
    }
    Node (int v):v(v)        //结构体的构造函数
    {
        ch[0]=ch[1]=NULL;
        r=rand();
        s=1;
    }
};

void rotate(Node* &o,int d)
{
    Node* k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    o->maintain();
    k->maintain();
    o=k;
}

void insert(Node* &o,int x)
{
    if (o==NULL)
        o=new Node(x);
    else
    {
        //int d=o->cmp(x);        //不用cmp
        int d=(x < o->v ? 0 : 1);
        insert(o->ch[d],x);
        if (o->ch[d]->r > o->r)
            rotate(o,d^1);
    }
    o->maintain();
}

void remove(Node* &o,int x)
{
    int d=o->cmp(x);
    if (d==-1)
    {
        Node *u=o;
        if ((o->ch[0]!=NULL) && (o->ch[1]!=NULL))
        {
            int d2=(o->ch[0]->r > o->ch[1]->r ? 1 : 0);
            rotate(o,d2);
            remove(o->ch[d2],x);
        }
        else
        {
            if (o->ch[0]==NULL)
                o=o->ch[1];
            else
                o=o->ch[0];
            delete u;
        }
    }
    else
        remove(o->ch[d],x);
    if (o!=NULL)
        o->maintain();
}

int kth(Node* o,int k)
{
    if ((o==NULL)||(k<=0)||(k > o->s))
        return 0;
    int s=(o->ch[1]==NULL ? 0 : o->ch[1]->s);
    if (k==s+1)
        return o->v;
    else if (k<=s)
        return kth(o->ch[1],k);
    else
        return kth(o->ch[0],k-s-1);

}

int _find(Node* o,int x)
{
    while (o!=NULL)
    {
        int d=o->cmp(x);
        if (d==-1)
            return 1;
        else
            o=o->ch[d];
    }
    return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);

    int n,m,opr,x;
    srand(time(0));
    cin>>n;
    Node* root=new Node(0);
    for (int i=1;i<=n;i++)
    {
        cin>>opr>>x;
        if (opr==1)
        {
            insert(root,x);
        }
        else if (opr==2)
        {
            if (!_find(root,x))
                cout<<"Not Found,Operation Failed"<<endl;
            else
                remove(root,x);
        }
    }
    cout<<"-----------------"<<endl;
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>x;
        if (_find(root,x))
            cout<<"Found"<<endl;
        else
            cout<<"Not Found"<<endl;
    }
    cout<<"-----------------"<<endl;
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>x;
        int ans=kth(root,x);
        cout<<x<<"th: "<<ans<<endl;
    }
}