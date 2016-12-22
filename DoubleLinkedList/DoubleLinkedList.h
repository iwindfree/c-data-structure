#ifndef __double_linkedlist_h__
#define __double_linkedlist_h__

typedef int Data;


typedef struct _node {
	Data data;
	struct _node *next;
	struct _node *prev;
} Node;

#define TRUE 1;
#define FALSE 0;


typedef struct _dbLinkedList {
	Node *head;
	Node *tail;
	Node* cur;
	int count;
} DbLinkedList;

typedef DbLinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, Data data);
int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);
Data LRemove(List *plist);
int LCount(List *plist);

#endif