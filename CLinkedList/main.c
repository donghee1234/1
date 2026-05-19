#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

int main() {
	CLinkedList* myList = createCLinkedList();
	int menu = -1;
	int x, y, index;
	PointType item;

	while (menu != 0) {
		printf("--- 이중 원형 연결 리스트 메뉴 ---\n");
		printf("1. 맨 앞에 추가\n");
		printf("2. 맨 뒤에 추가\n");
		printf("3. 특정 위치에 추가\n");
		printf("4. 특정 위치 삭제\n");
		printf("5. 전체 목록 출력\n");
		printf("6. 리스트 크기 확인\n");
		printf("0. 종료\n");
		printf("메뉴 선택: ");

		if (scanf("%d", &menu) != 1) {
			printf("올바른 숫자를 입력하세요.\n\n");
			while (getchar() != '\n');
			continue;
		}

		switch (menu) {
		case 1:
			printf("맨 앞에 추가할 좌표 입력 (x y): ");
			if (scanf("%d %d", &x, &y) == 2) {
				item.x = x;
				item.y = y;
				item.prev = NULL;
				item.next = NULL;
				insertFirstCLinkedList(myList, item);
				printf("좌표 (%d, %d)가 추가되었습니다.\n\n", x, y);
			}
			break;

		case 2:
			printf("맨 뒤에 추가할 좌표 입력 (x y): ");
			if (scanf("%d %d", &x, &y) == 2) {
				item.x = x;
				item.y = y;
				item.prev = NULL;
				item.next = NULL;
				insertLastCLinkedList(myList, item);
				printf("좌표 (%d, %d)가 추가되었습니다.\n\n", x, y);
			}
			break;

		case 3:
			printf("추가할 위치(index) 입력 (0 ~ %d): ", myList->size);
			if (scanf("%d", &index) == 1) {
				if (index < 0 || index > myList->size) {
					printf("잘못된 범위입니다.\n\n");
					break;
				}
				printf("추가할 좌표 입력 (x y): ");
				if (scanf("%d %d", &x, &y) == 2) {
					item.x = x;
					item.y = y;
					item.prev = NULL;
					item.next = NULL;
					insertAtCLinkedList(myList, index, item);
					printf("%d번 위치에 (%d, %d)가 추가되었습니다.\n\n", index, x, y);
				}
			}
			break;

		case 4:
			if (myList->size == 0) {
				printf("삭제할 노드가 없습니다.\n\n");
				break;
			}
			printf("삭제할 위치(index) 입력 (0 ~ %d): ", myList->size - 1);
			if (scanf("%d", &index) == 1) {
				if (index < 0 || index >= myList->size) {
					printf("잘못된 범위입니다.\n\n");
					break;
				}
				PointType deleted = deleteAtCLinkedList(myList, index);
				printf("%d번 노드 삭제 완료! [삭제된 값 -> x: %d, y: %d]\n\n", index, deleted.x, deleted.y);
			}
			break;

		case 5:
			printCLinkedList(myList);
			break;

		case 6:
			printf("현재 저장된 총 노드 개수: %d\n\n", myList->size);
			break;

		case 0:
			printf("모든 메모리를 해제하고 프로그램을 종료합니다.\n");
			destoryCLinkedList(myList);
			break;

		default:
			printf("잘못된 메뉴 번호입니다. 다시 입력해주세요.\n\n");
			break;
		}
	}
	return 0;
}
