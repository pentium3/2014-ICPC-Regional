/*
���⣺�����ͼ��ŷ����·��ÿ����ֻ��һ�Σ�
��ŷ����·���ڣ�ͼ��ֻ������0��or2�������ȵĵ㡣
���ʱ�����������ȵĵ㣬�����Ӹõ㿪ʼ��������Դ���һ�㿪ʼ
�����̣�dfs
���ͣ�
//�����򲿷�
# circuit is a global array
   find_euler_circuit
     circuitpos = 0
     find_circuit(node 1)
---------------------------------------------
# nextnode and visited is a local array
# the path will be found in reverse order
//�ݹ麯��
  find_circuit(node i)
    if node i has no neighbors then
      circuit(circuitpos) = node i
      circuitpos = circuitpos + 1
    else
      while (node i has neighbors)
          pick a random neighbor node j of node i
          delete_edges (node j, node i)
          find_circuit (node j)
      circuit(circuitpos) = node i
      circuitpos = circuitpos + 1
-------------------------------------------
���ս������circuit()���鵹���������
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define INF 999999

int dx=INF,dy=0,n,f,x,y,p;
int e[1100][1100];
int t[1100],seq[1100];

void dfs(int x)
{
    for (int i=dx;i<=dy;i++)
        if (e[x][i]>0)
        {
            e[x][i]--;
            e[i][x]--;
            dfs(i);
        }
    p++;
    seq[p]=x;
}

int start()
{
    for (int i=dx;i<=dy;i++)
        if (t[i]%2!=0)
            return i;
    return 1;
}

int main()
{
    memset(e,0,sizeof(e));
    memset(t,0,sizeof(t));
    cin>>f;
    for (int i=1;i<=f;i++)
    {
        cin>>x>>y;
        e[x][y]++;
        e[y][x]++;
        t[x]++;
        t[y]++;
        if (x<dx)   dx=x;
        if (y<dx)   dx=y;
        if (x>dy)   dy=x;
        if (y>dy)   dy=y;

    }

    x=start();
    //cout<<dx<<" "<<dy<<"--"<<x<<endl;
    p=0;
    dfs(x);

    //cout<<p<<endl;
    for (int i=p;i>=1;i--)
        cout<<seq[i]<<endl;

    return 0;
}