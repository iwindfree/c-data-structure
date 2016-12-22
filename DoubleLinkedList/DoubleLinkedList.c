#include <stdio.h>
#include "DoubleLinkedList.h"

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));
	plist->count = 0;
	plist->cur = plist->head;
	plist->tail->prev = plist->head;
	plist->head->next = plist->tail;
}

void LInsert(List *plist, Data data) {
	Node *newNode = malloc(sizeof(Node));
	newNode->data = data;
	plist->tail->prev->next = newNode; 
	newNode->prev = plist->tail->prev;

	newNode->next = plist->tail;
	plist->tail->prev = newNode;
	
	plist->count++;
}

int LFirst(List *plist, Data *pdata) {
	if (plist->head->next == plist->tail) {
		return FALSE;
	}
	*pdata = plist->head->next->data;
	plist->cur = plist->head->next;
	return TRUE;
}

int LNext(List *plist, Data *pdata) {
	if (plist->cur == plist->tail){
		return FALSE;
	}
	*pdata = plist->cur->next->data;
	plist->cur = plist->cur->next;
	return TRUE;
}

int LCount(List *plist) {
	return plist->count;
}

Data LRemove(List *plist) {
	Node *delNode = plist->cur;
	Data data = delNode->data;

	delNode->prev->next = delNode->next;
	delNode->next->prev = delNode->prev;

	plist->cur = plist->cur->prev;
	plist->count--;
	free(delNode);
	return data;
}