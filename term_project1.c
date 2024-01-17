#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNT 200

typedef struct phone_number {
	char name[10];  //이름
	int age;  //나이
	char number[14];  //전화번호
}p;
int print(p *friends_p, int count) { //전화번호 출력
	if (count > 0) {
		for (int i = 0; i < count; i++) {
			printf("%d. %s", i + 1, friends_p->name);
			printf(" %d", friends_p->age);
			printf(" %s\n", friends_p->number);
			friends_p++;
		}
	}
	else
		printf("등록된 친구가 없습니다.\n");
}
int add(p *friends_p, int count) { //전화번호 등록
	int i;
	p*ptr = friends_p;

	if (count < MAX_COUNT) {
		ptr = friends_p + count;
		printf("1. 이름 : ");
		scanf("%s", &ptr->name);
		printf("2. 나이 : ");
		scanf("%d", &ptr->age);
		printf("3. 전화번호 : ");
		scanf("%s", &ptr->number);

		if (count > 0) {
			for (i = 0; i < count; i++) {
				if (strcmp(friends_p[count].number, friends_p[i].number) == 0) { //두 숫자가 똑같다면
					printf("이미 등록된 번호입니다.\n");
					return 0;
				}
			}
			printf("등록되었습니다\n");
			return 1;
		}
		else {
			printf("등록되었습니다\n");
			return 1;
		}
	}
	else {
		printf("입력할 수 있는 인원을 초과 했습니다.\n");
		return 0;
	}
}
int deleted(p *friends_p, int count) {  //전화번호 삭제
	int num2;
	printf("삭제할 행번호 : ");
	scanf("%d", &num2);
	if (num2 <= count) {
		for (int i = 0; i < count; i++) {
			if (i + 1 == num2) {
				for (int j = i; j < count; j++) { //연락처 앞으로 당기기 
					strcpy(friends_p[j].name, friends_p[j + 1].name);
					friends_p[j].age = friends_p[j + 1].age;
					strcpy(friends_p[j].number, friends_p[j + 1].number);
				}
				*friends_p[count - 1].name = NULL; //맨 마지막 연락처 지우기
				friends_p[count - 1].age = NULL;
				*friends_p[count - 1].number = NULL;
				printf("삭제되었습니다.\n");
				return 1;
			}
		}
	}
	else
		printf("삭제할 연락처가 없습니다.\n");
	return 0;
}
int search(p* friends_p, int count) { //전화번호 검색
	char find[MAX_COUNT] = { "" };
	int search_count = 0;

	printf("찾으실 번호를 입력하시오 : ");
	scanf("%s", &find);
	for (int i = 0; i < 30; i++) {
		if (strstr(friends_p[i].number, find)) {
			search_count++;
			printf("%d. %s", i + 1, friends_p[i].name);
			printf(" %d", friends_p[i].age);
			printf(" %s\n", friends_p[i].number);
		}
		else {
			continue;
		}
	}
	if (search_count == 0) {
		printf("검색결과 0건\n.");
		return 0;
	}
}
int main() {
	p friends[MAX_COUNT];
	int count = 0, num;

	while (1) {
		printf("\n##########연락처 관리##########\n");
		printf("1. 연락처 출력\n");
		printf("2. 연락처 등록\n");
		printf("3. 연락처 삭제\n");
		printf("4. 연락처 검색\n");
		printf("5. 끝내기\n");
		printf("선택 : ");
		scanf("%d", &num);

		if (num == 1) {
			print(friends, count);
		}
		else if (num == 2) {
			if (1 == add(friends, count))
				count++;
		}
		else if (num == 3) {
			if (1 == deleted(friends, count));
			count--;
		}
		else if (num == 4) {
			int a;
			a = search(friends, count);
			if (1 == a)
				printf((char*)search(friends, count));

			else
				//printf("검색결과 0건\n");
				continue;
		}
		else if (num == 5) {
			break;
		}
		else {
			printf("다른 번호를 입력하시오\n");
		}
	}
}
