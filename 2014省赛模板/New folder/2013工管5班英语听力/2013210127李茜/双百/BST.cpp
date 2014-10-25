#include "iostream"
using namespace std;
struct node
{
	node *parent;
	node *left;
	node *right;
	int value;
};

bool insert(node **head,int key)
{
	node *x=*head;
	node *y=NULL;
	node *point=new node;
	point->value=key;
	//�����ֶ���ֵNULL�������³��ܲ� 
	point->left=NULL;
	point->right=NULL;
	while(x)  
	{
		y=x; //��λ���ڵ� 
		if(point->value<x->value) x=x->left;
		else x=x->right;
	}
	point->parent=y;			
	if(y==NULL) *head=point; //���ڵ�Ϊ�գ���Ϊ����
	else if(point->value<y->value) y->left=point; //�ǿ��������½ڵ��븸�ڵ����� 
	else y->right=point;
}
bool output(node *x)
{
	if(x)
	{
		output(x->left);
		cout<<x->value<<" ";
		output(x->right);
	}
}
node *search(node *x,int key)
{
	while(x&&key!=x->value)
	{
		if(key<x->value) x=x->left;
		else x=x->right;
	}
	return x;
}
int main()
{

	int temp;
	node *head=NULL;
	while(cin>>temp)
	{
		insert(&head,temp); //��˫��ָ�����޷��ں������޸�ָ�� 
	}
	output(head);
	node *c=search(head,4);  
	if(!c) cout<<"Y"<<endl;
	return 0;
	
}
