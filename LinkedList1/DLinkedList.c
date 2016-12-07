#include "DLinkedList.h"
#include <stdio.h>
void ListInit(List * plist) {
	plist->numOfData = 0;
	plist->before = NULL;
	plist->cur = NULL;
	plist->comp = NULL;
	plist->head = (Node*) malloc(sizeof(Node)); // dummy node
	plist->head->next = NULL;
}

void LInsert(List * plist, LData data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = plist->head->next;
	plist->head->next = newNode;
	plist->numOfData++;
}


int LFirst(List * plist, LData * pdata) {
	if (plist->numOfData == 0) {
		return 0;
	}
	else {
		plist->before = plist->head;
		plist->cur = plist->head->next;
		*pdata = plist->cur->data;
	}
	return 1;
}

int LNext(List * plist, LData * pdata) {
	if (plist->cur->next == NULL) {
		return 0;
	} 
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return 1;
}

LData LRemove(List * plist) {
	Node* curNode = plist->cur;
	LData removeData = plist->cur->data;
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	free(curNode);
	plist->numOfData--;
	return removeData;
}
int LCount(List * plist) {
	return plist->numOfData;
}
