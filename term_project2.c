#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void gotoxy(int x, int y);

int main(void)
{
	int horse_num, horse_distance[10] = { 0 };	//말 숫자, 말 주행거리
	char horse_name[10][10];	//말 이름
	int i, j, number, race, count = 0, rank[10] = { 0 };
	double duration;

	printf("경마게임\n\n");
	printf("경주할 말의 숫자 <최대 10> 를 입력하고 Enter>");
	scanf("%d", &horse_num);
	printf("\n\n");
	printf("%d개 말의 이름 <최대 한글 3자> 을 입력하고 Enter하세요\n", horse_num);
	printf("\n");

	for (i = 0; i < horse_num; i++)
	{
		printf("%d번 말 이름 :", i + 1);

		scanf("%s", horse_name[i]);
	}
	system("cls");	//clean screen 화면싹지움

	printf("\n\n");
	printf("(start)  1         10         20        30        40(finish) 등수 시간(초)\n");
	printf("----------------------------------------------------------------------\n");
	gotoxy(50, 1);		//50칸 1줄로 커서이동
	printf("소요시간:");

	for (i = 0; i < horse_num; i++)
	{
		gotoxy(1, 7 + 3 * i);		//1번마 : 1칸 7줄로 이동, n번마 : 1칸 7줄 + 3n 줄로 이동
		printf("%s	:>\n\n", horse_name[i]);

	}
	printf("\n\n아무키나 누르면 경주를 시작합니다. \n");

	srand(time(NULL));
	clock_t start = clock();	//시작시간 start에 저장

	while (count != horse_num)		//다 도착하면 종료
	{
		number = rand() % horse_num;	// 0부터 말번호-1 수까지의 난수를 number에 저장
		if (rank[number] != 0)	//말의 등수가 0등이 아니면 계속진행
			continue;

		race = rand() % 2 + 1;	 // 1or 2의 난수를 race에 저장
		horse_distance[number] = horse_distance[number] + race; // 말 주행거리에 race를 더함
		Sleep(300);		//0.3초 쉼

		if (horse_distance[number] >= 40)	 //어느말이든 도착하면
		{
			horse_distance[number] = 40;	//도착한 말의 주행거리는 40(41이여도 40으로 표시)
			if (!rank[number])	//말 등수가 없으면
			{
				count++;
				rank[number] = count;	 //말 등수 rank에 저장
				gotoxy(10, 7 + 3 * number);

				for (j = 0; j < horse_distance[number]; j++)
				{
					printf(" ");	//주행거리-1까지 스페이스키로 나타냄
				}
				if (horse_distance[number])
				{
					printf(">%d", horse_distance[number]);	//현재위치(>(거리))로 나타냄
				}
				gotoxy(55, 7 + 3 * number);

				printf("   %d등    ", count);	//등수 나타내기
				clock_t finish = clock();	 //끝난시간 finish에 저장
				duration = (double)(finish - start) / CLOCKS_PER_SEC; //(끝-시작)/CLOCKS_PER_SEC => 초단위로 나타내서 take_time에 저장
				printf("%.3lf", duration);
			}
		}
		else	//아무도 도착하지 않았을때
		{
			gotoxy(10, 7 + 3 * number);
			for (j = 0; j < horse_distance[number]; j++)
			{
				printf(" ");
			}
			if (horse_distance[number])
			{
				printf(">%d", horse_distance[number]);	//스페이스 + >주행거리 나타내기
			}
		}
		gotoxy(60, 1);
		clock_t finish = clock();
		duration = (double)(finish - start) / CLOCKS_PER_SEC; //CLK_TCK
		printf("%.3lf초", duration);
	}
	gotoxy(1, 25);
	printf("게임 종료!\n");

	return 0;
}
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
