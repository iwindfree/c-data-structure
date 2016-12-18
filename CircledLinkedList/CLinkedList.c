#include "CLinkedList.h"
#include <stdio.h>
void ListInit(List *pList) {
	pList->before = NULL;
	pList->current = NULL;
	pList->tail = NULL;
	pList->numOfData = 0;
}

void LInsert(List *pList, Data data) {
	/* step 1 : new node 생성 및 데이터 값 할당*/
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	 
	/* step 2 : 초기 상태이면 새로운 데이터가 추가되면서 next 도 자기 자신을 가리키게 설정*/
	if (pList->tail == NULL) {
		newNode->next = newNode;
		pList->tail = newNode;
	}
	else {
		newNode->next = pList->tail->next;    // 현재 plist->tail->next 는 head, 새로운 node 의 next 가 head 를 가리키도록 설정
		pList->tail->next = newNode;   // 현재 list tail 의 next 를 새로운 node 로 설정
		pList->tail = newNode;  // List 의 tail 이 새 노드를 가리키도록 설정.
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

