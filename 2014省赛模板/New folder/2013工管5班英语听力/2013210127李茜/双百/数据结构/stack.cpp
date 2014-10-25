#include "iostream"
using namespace std;
struct node
{
	node *prev; //ָ��ǰһ����ջԪ�� 
	int value;
};
void Push(node **stack,int key)
{
	node *pS=new node;
	pS->value=key;
	pS->prev=NULL;
	if(!*stack) //���Ϊ��ջ����ջ��Ϊ�½�� 
	{
		*stack=pS;
	}
	else
	{
	    pS->prev=*stack; //���򣬰���Ԫ�ص�ǰһ��Ԫ������Ϊԭջ�� 
		*stack=pS; //��ջ������Ϊ��Ԫ�� 
		//��һ�ַ��ں������������  ������� 
	}	
}
void Pop(node **stack)
{
	if(!*stack) return; //��ջ�˳� 
	*stack=(*stack)->prev; //ջ���ı� 
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
