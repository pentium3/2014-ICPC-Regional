/*
��״�������ģ��	
2014.4.30 Ver2.0

��ʼ����a[i]ΪҪ��������飬��n��Ԫ�أ��� 
	for i:=1 to n do add(i,a[i]); 

add(x,d):��x��λ�ü���d  (�൱��a[x]=a[x]+d)
sum(x):��a[1]~a[x]�ĺ� 

�¼���get!:�ɶθ���(�μ�frozenc�����blog)
modify(l,r,tmp):a[l..r]������ÿ����������tmp
writeln:����޸ĺ��������
*/

#include <iostream>
#include <cstring>
using namespace std;
int c[1000],a[1000],b[1000];
int n,tmp,tl,tr,m;

int lowbit(int x)
{
     return x&(-x);
}

int sum(int x)
{
	int ret=0;
	while (x>0)
	{
		ret=ret+c[x];
		x=x-lowbit(x);
	}
	return ret;
}

void add(int x,int d)
{
	while (x<=n)
	{
		c[x]=c[x]+d;
		x=x+lowbit(x);
	}
}

void modify(int l,int r,int tmp)
{
    add(l,tmp);
    if (r+1<=n) add(r+1,-tmp);
}

void writeln()
{
    cout<<"Printing the answer sequence: ";
    for (int i=1;i<=n;i++)
        cout<<a[i]+sum(i)<<" ";
    cout<<endl;
}

int main()
{
	memset(c,0,sizeof(c));
    memset(a,0,sizeof(a));

    /*
	cin>>n;
	for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        add(i,a[i]);
    }

    for (int i=1;i<=n;i++)
        cout<<sum(i)<<"  ";
    cout<<endl;
    */

    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    cin>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>tl>>tr>>tmp;
        memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        modify(tl,tr,tmp);
        writeln();
    }

	return 0;
}
