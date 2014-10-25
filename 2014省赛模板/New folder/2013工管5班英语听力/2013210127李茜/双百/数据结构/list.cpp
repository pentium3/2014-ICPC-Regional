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
	tail->next=NULL; //��β
	head->prev=tail; //˫��������
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
    cout<<head->value<<endl;//˫�����BUG
    pOut=head;
    node *del;
    while(pOut!=NULL) //���
    {
        del=pOut;
        delete del;
        pOut=pOut->next;
    }
	return 0;
}
