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
	//必须手动赋值NULL，负责下场很惨 
	point->left=NULL;
	point->right=NULL;
	while(x)  
	{
		y=x; //定位父节点 
		if(point->value<x->value) x=x->left;
		else x=x->right;
	}
	point->parent=y;			
	if(y==NULL) *head=point; //父节点为空，则为空树
	else if(point->value<y->value) y->left=point; //非空树，则新节点与父节点连接 
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
		insert(&head,temp); //非双层指针则无法在函数内修改指针 
	}
	output(head);
	node *c=search(head,4);  
	if(!c) cout<<"Y"<<endl;
	return 0;
	
}
