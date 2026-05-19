#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

CLinkedList* createCLinkedList() {
	CLinkedList* temp = (CLinkedList*)malloc(sizeof(CLinkedList));
	if (temp == NULL) return NULL;
	temp->tail = NULL;
	temp->size = 0;
	return temp;
}

void destoryCLinkedList(CLinkedList* cl) {
	if (cl == NULL) return;

	if (cl->size > 0) {
		PointType* temp = cl->tail->next;
		int currentSize = cl->size;

		for (int i = 0; i < currentSize; i++) {
			PointType* nPtr = temp->next;
			free(temp);
			temp = nPtr;
		}
	}
	free(cl);
}

int insertFirstCLinkedList(CLinkedList* cl, PointType item) {
	if (cl == NULL) return 0;

	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	if (nPtr == NULL) return 0;
	*nPtr = item;

	if (cl->size == 0) {
		nPtr->next = nPtr;
		nPtr->prev = nPtr;
		cl->tail = nPtr;
	}
	else {
		PointType* head = cl->tail->next;
		nPtr->next = head;
		nPtr->prev = cl->tail;
		head->prev = nPtr;
		cl->tail->next = nPtr;
	}

	cl->size++;
	return 1;
}

int insertLastCLinkedList(CLinkedList* cl, PointType item) {
	if (cl == NULL) return 0;

	if (insertFirstCLinkedList(cl, item)) {
		cl->tail = cl->tail->next;
		return 1;
	}
	return 0;
}

int insertAtCLinkedList(CLinkedList* cl, int index, PointType item) {
	if (cl == NULL || index < 0 || index > cl->size) return 0;

	if (index == 0) return insertFirstCLinkedList(cl, item);
	if (index == cl->size) return insertLastCLinkedList(cl, item);

	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	if (nPtr == NULL) return 0;
	*nPtr = item;

	PointType* prevNode = cl->tail->next;
	for (int i = 0; i < index - 1; i++) {
		prevNode = prevNode->next;
	}
	PointType* nextNode = prevNode->next;

	nPtr->next = nextNode;
	nPtr->prev = prevNode;
	prevNode->next = nPtr;
	nextNode->prev = nPtr;

	cl->size++;
	return 1;
}

PointType deleteAtCLinkedList(CLinkedList* cl, int index) {
	PointType dummy;
	dummy.x = 0;
	dummy.y = 0;
	dummy.prev = NULL;
	dummy.next = NULL;

	if (cl == NULL || cl->size == 0 || index < 0 || index >= cl->size) return dummy;

	PointType* head = cl->tail->next;
	PointType* target = head;

	for (int i = 0; i < index; i++) {
		target = target->next;
	}

	PointType rItem = *target;

	if (cl->size == 1) {
		cl->tail = NULL;
	}
	else {
		target->prev->next = target->next;
		target->next->prev = target->prev;

		if (target == cl->tail) {
			cl->tail = target->prev;
		}
	}

	free(target);
	cl->size--;
	return rItem;
}

void printCLinkedList(CLinkedList* cl) {
	if (cl == NULL) return;

	printf("\n[Print Doubly Circular Linked List]\n");
	printf("Size: %d\n", cl->size);

	if (cl->size == 0) {
		printf("리스트가 비어있습니다.\n\n");
		return;
	}

	PointType* start = cl->tail->next;

	for (int i = 0; i < cl->size; i++) {
		printf("[%d] x: %d, y: %d (prev: %p, next: %p)\n",
			i, start->x, start->y, (void*)start->prev, (void*)start->next);
		start = start->next;
	}
	printf("\n");
}
