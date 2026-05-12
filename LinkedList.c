#include "LinkedList.h"

LinkedList* createLinkedList() {
	struct linkedList* r;
	r = (struct linkedList*)malloc(sizeof(struct linkedList));

	r->head = (struct pointType*)NULL;
	r->size = 0;

	return r;
}

int destroyLinkedList(LinkedList* li) {
	struct pointType* nptr, * mptr;
	for (nptr = li->head; nptr != NULL; nptr = mptr) {
		mptr = nptr->next;
		free(nptr);
	}

	free(li);

	return 1;
}

int isEmptyLinkedList(LinkedList* li) {
	return (li->size == 0);
}

int sizeLinkedList(LinkedList* li) {
	return li->size;
}

LinkedList* insertFirstLinkedList(LinkedList* li, PointType item) {
	PointType* ptr = (PointType*)malloc(sizeof(PointType));
	*ptr = item;

	ptr->next = li->head;
	li->head = ptr;
	li->size++;

	return li;
}

int printLinkedList(LinkedList* li) {
	PointType* current = li->head;
	printf("LinkedList:\n");
	printf("LinkedList size: %d\n", li->size);

	for (int i = 0; i < li->size; i++) {
		printf("[%d] x:%d, y:%d, next:%p\n", 
			i, current->x, current->y, (void*)current->next);

		current = current->next;
	}
    return 1;
}

LinkedList* insertLastLinkedList(LinkedList* li, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;
	nPtr->next = NULL;

	if (li->head == NULL) {
		li->head = nPtr;
	} else {
		PointType* ptr = li->head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = nPtr;
	}

	li->size++;
	return li;
}

LinkedList* deleteAtLinkedList(LinkedList* li, int at) {
	if (li == NULL || at < 0 || at >= li->size) {
		return li;
	}

	PointType* fPtr = NULL;

	if (at == 0) {
		fPtr = li->head;
		li->head = fPtr->next;
	} else {
		PointType* pre = li->head;
		for (int i = 0; i < at - 1; i++) {
			pre = pre->next;
		}
		fPtr = pre->next;
		pre->next = fPtr->next;
	}

	free(fPtr);
	li->size--;

	return li;
}

LinkedList* insertItemLinkedList(LinkedList* li, PointType* pre, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	if (pre != NULL) {
		nPtr->next = pre->next;
		pre->next = nPtr;
	} else {
		nPtr->next = li->head;
		li->head = nPtr;
	}

	li->size++;
	return li;
}

PointType deleteFirstLinkedList(LinkedList* li) {
	if (li->size != 0) {
		PointType* tPtr = li->head;
		li->head = tPtr->next;

		PointType temp = *tPtr;
		free(tPtr);

		li->size--;
		return temp;
	} else {
		return (PointType) { 0, 0, NULL };
	}
}

PointType deleteLastLinkedList(LinkedList* li) {
	if (li->head == NULL) {
		return (PointType) { 0, 0, NULL };
	}

	PointType* pre = li->head;
	PointType* iPtr = pre->next;

	if (iPtr == NULL) {
		PointType temp = *pre;
		free(pre);
		li->head = NULL;
		li->size--;
		return temp;
	} else {
		while (iPtr->next != NULL) {
			pre = iPtr;
			iPtr = iPtr->next;
		}

		PointType temp = *iPtr;
		pre->next = NULL;
		free(iPtr);
		li->size--;

		return temp;
	}
}
