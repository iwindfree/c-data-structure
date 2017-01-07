#ifndef __D_STACK_H__
#define __D_STACk_H__

#define TRUE	1
#define FALSE	0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node * next;
} Node;

typedef struct _ListStack
{
	Node * head;
	Node * cur;
	int numOfData;

} ListStack;


typedef ListStack Stack;

void Init(Stack *pstack);
void Push(Stack *pstack, LData data);
LData Pop(Stack* pstack);
LData Peek(Stack* pstack);
int IsEmpty(Stack *pstack);

#endif