#include "iostream"
using namespace std;
struct node
{
	char value;
	node *prev;
	node *next;
};
node *create()
{
	char temp;
	node *head=NULL;
	node *tail=head;
	node *pE=NULL;
	node *pS=NULL;
	do
	{
		cin>>temp;
		if(temp!='#')
		{
			pS=new node;
			pS->value=temp;
			if(head==NULL)
			{
				head=pS;
			}
			else
			{
				tail->next=pS;
				pE=tail;
			}
			tail=pS;
			tail->prev=pE;
		}
	}while(temp!='#');
	tail->next=NULL; //断尾
	head->prev=tail; //双向链表构建
	return head;
}
int main()
{
	node *head=create();
	node *pOut=head;
	while(pOut!=NULL)
	{
		cout<<pOut->value;
		pOut=pOut->next;
	}
	cout<<endl;
	pOut=head->prev;
	while(pOut!=head)
    {
        cout<<pOut->value;
        pOut=pOut->prev;
    }
    cout<<head->value<<endl;//双向输出BUG
    pOut=head;
    node *del;
    while(pOut!=NULL) //清除
    {
        del=pOut;
        delete del;
        pOut=pOut->next;
    }
	return 0;
}
