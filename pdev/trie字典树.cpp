//trie
//bool query(string s):�ж��ַ����Ƿ���ǰ׺���trueΪ��
//void insert(string s,int v):��ǰ׺���������ַ���s��vΪ������Ϣ
//code��POJ1056������һ���ַ��������Ƿ�����������������ַ���a��b��a����b��ǰ׺

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define maxnode 1000
#define sigma_size 30

//struct Trie
//{
    int ch[maxnode][sigma_size];        //ch[i][j]����¼���i���Ǹ����Ϊj���ӽڵ�
    int val[maxnode];                    //val[i]��i�ڵ�ĸ�����Ϣ����������������¼�Ƿ�һ�����ʵĽ���
                                        //������trie����root->iһ·�����Ƿ���һ�������ĵ��ʣ�
    int sz;
    void Trie()
    {
        sz=1;
        memset(ch[0],0,sizeof(ch[0]));
    }
    int idx(char c)                       //idx(c)���ַ�c�ı�š�
    {
        return c-'0';                    //�˴���һ���ַ���0����return c-'0'
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
            if (val[u]==1)  return true;    //����ʱs��û���굫trie�����Ѿ��ߵ���β�ˣ������ϵ�����s��ǰ׺
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