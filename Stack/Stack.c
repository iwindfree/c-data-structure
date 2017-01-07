#include "Stack.h"
#include <stdio.h>
void Init(Stack *pstack) {
	pstack = (Stack*)malloc(sizeof(Stack));
	pstack->head = NULL;
}

void Push(Stack *pstack, LData data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = pstack->head;
	pstack->head = node;
}
LData Pop(Stack* pstack) {
	if (IsEmpty) {
		return NULL;
	}
	Node* node = pstack->head;
	LData data = node->data;
	pstack->head = node->next;
	free(node);
}
LData Peek(Stack* pstack) {
	if (IsEmpty) {
		return NULL;
	}
	return pstack->head->data;
}
int IsEmpty(Stack *pstack) {
	if (pstack->head != NULL) {
		return TRUE;
	}
	return FALSE;
}