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

// 과제 요구사항에 맞게 깔끔하게 서식을 다듬은 출력 함수
int printLinkedList(LinkedList* li) {
	PointType* current = li->head;
	if (li->size == 0) {
		printf("리스트가 비어 있습니다.\n");
		return 0;
	}
	printf("현재 리스트: ");
	for (int i = 0; i < li->size; i++) {
		printf("%d", current->x);
		if (current->next != NULL) {
			printf(" -> ");
		}
		current = current->next;
	}
	printf("\n");
	return 1;
}

LinkedList* insertLastLinkedList(LinkedList* li, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;
	nPtr->next = NULL;

	// ★ 버그 수정: 리스트가 완전히 비어있을 때 예외 처리 추가
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
	if (at >= 0 && at < li->size) {
		PointType* nPtr = li->head;

		if (at == 0) {
			PointType* fPtr = li->head;
			li->head = fPtr->next;
			free(fPtr);
		}
		else {
			// 인덱스 바로 전 노드까지 이동
			for (int i = 0; i < at - 1; i++) {
				nPtr = nPtr->next;
			}
			PointType* fPtr = nPtr->next;
			nPtr->next = fPtr->next;
			free(fPtr);
		}
		li->size--;
	}
	return li; // ★ 버그 수정: 누락되었던 return 추가
}

LinkedList* insertItemLinkedList(LinkedList* li, PointType* pre, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	if (pre != NULL) {
		nPtr->next = pre->next;
		pre->next = nPtr;
	}
	else {
		nPtr->next = li->head;
		li->head = nPtr;
	}

	li->size++;
	return li; // ★ 버그 수정: 누락되었던 return 추가
}

PointType deleteFirstLinkedList(LinkedList* li) {
	if (li->size != 0) {
		PointType* tPtr = li->head;
		li->head = tPtr->next;

		PointType temp = *tPtr;
		free(tPtr);

		li->size--;
		return temp;
	}
	else {
		return (PointType) { 0, 0, NULL };
	}
}

PointType deleteLastLinkedList(LinkedList* li) {
	PointType* pre = li->head;

	if (pre == NULL) {
		return (PointType) { 0, 0, NULL };
	}

	PointType* iPtr = pre->next;

	if (iPtr == NULL) {
		li->head = NULL;
		PointType temp = *pre;
		free(pre);
		li->size--;
		return temp;
	}
	else {
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
