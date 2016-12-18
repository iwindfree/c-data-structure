#include "CLinkedList.h"
#include <stdio.h>
void ListInit(List *pList) {
	pList->before = NULL;
	pList->current = NULL;
	pList->tail = NULL;
	pList->numOfData = 0;
}

void LInsert(List *pList, Data data) {
	/* step 1 : new node ���� �� ������ �� �Ҵ�*/
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	 
	/* step 2 : �ʱ� �����̸� ���ο� �����Ͱ� �߰��Ǹ鼭 next �� �ڱ� �ڽ��� ����Ű�� ����*/
	if (pList->tail == NULL) {
		newNode->next = newNode;
		pList->tail = newNode;
	}
	else {
		newNode->next = pList->tail->next;    // ���� plist->tail->next �� head, ���ο� node �� next �� head �� ����Ű���� ����
		pList->tail->next = newNode;   // ���� list tail �� next �� ���ο� node �� ����
		pList->tail = newNode;  // List �� tail �� �� ��带 ����Ű���� ����.
	}

	(pList->numOfData)++;
}

void LInsertFront(List *pList, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (pList->tail == NULL) {
		newNode->next = newNode;
		pList->tail = newNode;
	}
	else {
		newNode->next = pList->tail->next;
		pList->tail->next = newNode;
	}
	(pList->numOfData)++;
}


int LFirst(List *pList, Data *pData) {
	if (pList->tail == NULL) {
		return FALSE;
	}
	else {
		pList->current = pList->tail->next;
		pList->before = pList->tail;
		*pData = pList->current->data;
		
	}
	return TRUE;
}

int LNext(List *pList, Data *pData) {
	if (pList->tail == NULL) {
		return FALSE;
	}
	pList->before = pList->current;
	pList->current = pList->current->next;
	*pData = pList->current->data;
	return TRUE;
}

Data LRemove(List *pList){
	Node *delNode = pList->current;
	Data delData = delNode->data;

	if (delNode == pList->tail) {
		if (pList->tail->next == pList->tail) {
			pList->tail = NULL;
		}
		else {
			pList->tail = pList->before;
		}
	}

	pList->before->next = pList->current->next;
	pList->current = pList->before;

	free(delNode);
	pList->numOfData--;
	return delData;
}

int LCount(List *pList) {
	return pList->numOfData;
}

