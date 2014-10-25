//trie
//bool query(string s):判断字符串是否在前缀树里，true为是
//void insert(string s,int v):向前缀树插入新字符串s，v为附加信息
//code：POJ1056：给你一堆字符串，问是否满足对于任意两个字符串a、b，a不是b的前缀

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define maxnode 1000
#define sigma_size 30

//struct Trie
//{
    int ch[maxnode][sigma_size];        //ch[i][j]：记录结点i的那个编号为j的子节点
    int val[maxnode];                    //val[i]：i节点的附加信息，这里我们用来记录是否到一个单词的结束
                                        //（即在trie树上root->i一路下来是否是一个完整的单词）
    int sz;
    void Trie()
    {
        sz=1;
        memset(ch[0],0,sizeof(ch[0]));
    }
    int idx(char c)                       //idx(c)即字符c的编号。
    {
        return c-'0';                    //此处第一个字符是0所以return c-'0'
    }
    void Insert(string s,int v)
    {
        int u=0,n=s.length();
        for (int i=0;i<n;i++)
        {
            int c=idx(s[i]);
            if (!ch[u][c])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=0;
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]=v;
    }
    bool query(string s)     //true:s is a prefix
    {
        int u=0,c;
        for (int i=0;i<s.length();i++)
        {
            c=s[i]-'0';
            if (!ch[u][c])    return false;

            u=ch[u][c];
            if (val[u]==1)  return true;    //若此时s还没走完但trie树上已经走到结尾了，即树上单词是s的前缀
        }
        return true;
    }
//};

bool ok;
string str;

int main()
{
    //freopen("in.txt","r",stdin);

    ok=true;
    Trie();
    int num=0;
    while (cin>>str)
    {
        if (str=="9")
        {
            num++;
            if (ok)
                printf("Set %d is immediately decodable\n",num);
            else
                printf("Set %d is not immediately decodable\n",num);
            ok=true;
            Trie();
        }
        else
        {
            if (query(str))
                ok=false;
            Insert(str,1);
        }
    }
}