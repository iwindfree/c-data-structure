#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node *next;
} Node;

typedef struct _clist {
	Node* tail;
	Node* current;
	Node* before;
	int numOfData;
} CLinkedList;

typedef CLinkedList List;

void ListInit(List *pList);
void LInsert(List *pList, Data data);
void LInsertFront(List *pList, Data data);

int LFirst(List *pList, Data *pData);
int LNext(List *pList, Data *pData);
Data LRemove(List *pList);
int LCount();

#endif