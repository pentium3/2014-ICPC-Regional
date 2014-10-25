#include "iostream"
using namespace std;
struct node
{
	node *prev; //指向前一个进栈元素 
	int value;
};
void Push(node **stack,int key)
{
	node *pS=new node;
	pS->value=key;
	pS->prev=NULL;
	if(!*stack) //如果为空栈，则栈顶为新结点 
	{
		*stack=pS;
	}
	else
	{
	    pS->prev=*stack; //否则，把新元素的前一个元素设置为原栈顶 
		*stack=pS; //把栈顶设置为新元素 
		//这一手法在后续链表里叫做  先连后断 
	}	
}
void Pop(node **stack)
{
	if(!*stack) return; //空栈退出 
	*stack=(*stack)->prev; //栈顶改变 
}
int main()
{
	node *stack=NULL;
	Push(&stack,3);
	Push(&stack,2);
	Push(&stack,1);
	while(stack)
	{
		cout<<stack->value<<" ";
		Pop(&stack);
	}
	return 0;
}
