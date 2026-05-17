#include <stdio.h>
#include "LinkedList.h"

int main() {
	LinkedList* myList = createLinkedList();
	int menu = -1;
	int value, index;

	while (menu != 0) {
		printf("\n--- 연결 리스트 메뉴 ---\n");
		printf("1. 맨 앞에 추가\n2. 맨 뒤에 추가\n3. 특정 위치에 추가\n");
		printf("4. 특정 위치 삭제\n5. 전체 목록 출력\n6. 리스트 크기 확인\n0. 종료\n");
		printf("메뉴 선택: ");
		scanf("%d", &menu);

		switch (menu) {
		case 1:
			printf("추가할 정수 입력: ");
			scanf("%d", &value);
			insertFirstLinkedList(myList, (PointType) { value, 0, NULL });
			printf("맨 앞에 %d 추가 완료.\n", value);
			break;

		case 2:
			printf("추가할 정수 입력: ");
			scanf("%d", &value);
			insertLastLinkedList(myList, (PointType) { value, 0, NULL });
			printf("맨 뒤에 %d 추가 완료.\n", value);
			break;

		case 3:
			printf("삽입할 위치(Index) 입력: ");
			scanf("%d", &index);
			printf("추가할 정수 입력: ");
			scanf("%d", &value);

			if (index < 0 || index > sizeLinkedList(myList)) {
				printf("올바르지 않은 위치입니다.\n");
			} else if (index == 0) {
				insertFirstLinkedList(myList, (PointType) { value, 0, NULL });
				printf("0번 인덱스에 %d 추가 완료.\n", value);
			} else {
				// 삽입할 위치 바로 직전 노드를 찾아 그 뒤에 쏙 끼워넣기
				PointType* pre = myList->head;
				for (int i = 0; i < index - 1; i++) {
					pre = pre->next;
				}
				insertItemLinkedList(myList, pre, (PointType) { value, 0, NULL });
				printf("%d번 인덱스에 %d 추가 완료.\n", index, value);
			}
			break;

		case 4:
			printf("삭제할 위치(Index) 입력: ");
			scanf("%d", &index);

			int listSize = sizeLinkedList(myList);
			if (index < 0 || index >= listSize) {
				printf("삭제할 수 없는 위치입니다.\n");
			} else {
				PointType deletedNode;

				// [개선 포인트] 기존 함수들의 리턴값을 활용해 대폭 단순화!
				if (index == 0) {
					deletedNode = deleteFirstLinkedList(myList);
				} else if (index == listSize - 1) {
					deletedNode = deleteLastLinkedList(myList);
				} else {
					// 중간 삭제는 값을 먼저 백업 후 지우기
					PointType* target = myList->head;
					for (int i = 0; i < index; i++) {
						target = target->next;
					}
					deletedNode = *target; // 구조체 값 복사
					deleteAtLinkedList(myList, index);
				}
				
				printf("%d번 인덱스의 값 %d 삭제 완료.\n", index, deletedNode.x);
			}
			break;

		case 5:
			printLinkedList(myList);
			break;

		case 6:
			printf("현재 리스트 크기: %d\n", sizeLinkedList(myList));
			break;

		case 0:
			printf("프로그램을 종료합니다.\n");
			destroyLinkedList(myList);
			break;

		default:
			printf("잘못된 메뉴입니다.\n");
			break;
		}
	}
	return 0;
}
