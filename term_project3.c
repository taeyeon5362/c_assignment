#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNT 500

typedef struct boookinformation
{
	char symbol[7];
	char name[21];
	char writer[11];
	char shop[11];
	int year;
	int state;
}book;
int Registration(int count, book* library_p)
{
	book* cnt = library_p;
	if (count < MAX_COUNT)
	{
		cnt = library_p + count;
		printf("청구기호 입력(최대6글자) > ");
		scanf("%s", &cnt->symbol);
		printf("도서명 입력(최대20글자) > ");
		scanf("%s", &cnt->name);
		printf("제1 저자명 입력(최대10글자) > ");
		scanf("%s", &cnt->writer);
		printf("발행사 입력(최대10글자) > ");
		scanf("%s", &cnt->shop);
		printf("출판년도 입력(정수 4자) >");
		scanf("%d", &cnt->year);
		cnt->state = 0; // state가 0이면 정상(대출 가능) state 가 1이면 대출(대출불가능)
		return 1;
	}
	else
	{
		printf("더이상 등록할 수 없습니다\n");
		return 0;
	}
}
int print(int count, book* library_p)
{
	int number, max, temp;

	while (1)
	{
		printf("도서현황\n\n");
		printf("다음의 현황 출력기준 중에서 선택\n\n");
		printf("1. 도서등록\n");
		printf("2. 출판년도\n");
		printf("3. 대출도서\n");
		printf("4. 이전 메뉴로\n\n");
		printf("번호를 입력하고 Enter > ");
		scanf("%d", &number);

		if (number == 1)
		{
			printf("청구기호 서명\t\t저자\t발행사\t출판년도  상태\n ");
			printf("------------------------------------------------------------------------\n");

			if (count > 0)
			{

				for (int i = 0; i < count; i++)
				{
					printf("%s\  %s\t\t %s\t %s\t %d\t %d\n ", library_p->symbol, library_p->name, library_p->writer, library_p->shop, library_p->year, library_p->state);
					library_p++;
				}
			}
			else
			{
				printf("책이 없습니다\n");
			}
		}
		else if (number == 2)
		{
			max = library_p[0].year;

			printf("청구기호 서명\t\t저자\t발행사\t출판년도  상태\n ");
			printf("------------------------------------------------------------------------\n");
			if (count > 0)
			{
				for (int i = 0; i < count; i++)
				{
					if (max < library_p[i].year)
					{
						max = library_p[i].year;
					}
				}
				for (int i = 0; i < count; i++)
				{
					for (int j = 0; j < count - 1; j++)
					{
						if (library_p[j].year < library_p[j + 1].year)
						{
							temp = library_p[j].year;
							library_p[j].year = library_p[j + 1].year;
							library_p[j + 1].year = temp;
						}
					}
				}
				for (int i = 0; i < count; i++)
				{
					printf("%s\  %s\t\t %s\t %s\t %d\t %d\n  ", library_p->symbol, library_p->name, library_p->writer, library_p->shop, library_p->year, library_p->state);
					library_p++;
				}
			}
			else
			{
				printf("책이 없습니다\n");
			}
		}
		else if (number == 3)
		{
			printf("청구기호 서명\t\t저자\t발행사\t출판년도  상태\n ");
			printf("------------------------------------------------------------------------\n");
			for (int i = 0; i < count; i++)
			{
				if (library_p[i].state == 0)
				{
					printf("%s\  %s\t\t %s\t %s\t %d\t %d\n  ", library_p->symbol, library_p->name, library_p->writer, library_p->shop, library_p->year, library_p->state);
					library_p++;
				}
				else
				{
					continue;
				}
			}
		}
		else if (number == 4)
		{
			break;
		}
		else
		{
			printf("다른 번호를 선택하세요\n");
		}
	}
}
int Search(int count, book* library_p)
{
	int number;
	int search_count = 0;
	char find_symbol[7], find_name[21], find_writer[11];

	while (1)
	{
		printf("도서 대출\n\n");
		printf("검색할 도서의 항목 선택\n\n");
		printf("1. 청구기호 입력(최대 영문 6자리) > \n");
		printf("2. 도서명입력(최대 20자리) > \n");
		printf("3. 제1 저자명 입력(최대 10자리) > \n");
		printf("4. 이전 메뉴로 \n");
		printf("번호를 입력하고 Enter > ");
		scanf("%d", &number);

		if (number == 1)
		{
			printf("대출할 도서의 청구기호를 입력하고 Enter(최대 영문 6자리) > ");
			scanf("%s", &find_symbol);
			printf("검색결과\n");
			printf("청구기호 서명\t\t저자\t발행사\t출판년도  상태\n ");
			printf("------------------------------------------------------------------------\n");
			for (int i = 0; i < 7; i++)
			{
				if (strstr(library_p[i].symbol, find_symbol)) 
				{
					search_count++;
					printf("%s\  %s\t\t %s\t %s\t %d\t %d\n ", library_p[i].symbol, library_p[i].name, library_p[i].writer, library_p[i].shop, library_p[i].year, library_p[i].state);
				}
				else
				{
					continue;
				}
			}
			if (search_count == 0)
			{
				printf("검색결과 0건\n.");
				return 0;
			}
		}
		else if (number == 2)
		{
			printf("대출할 도서의 도서명을 입력하고 Enter(최대 20자리) > ");
			scanf("%s", &find_name);
			printf("청구기호 서명\t\t저자\t발행사\t출판년도  상태\n ");
			printf("------------------------------------------------------------------------\n");
			for (int i = 0; i < 21; i++)
			{
				if (strstr(library_p[i].name, find_name))
				{
					search_count++;
					printf("%s\  %s\t\t %s\t %s\t %d\t %d\n ", library_p[i].symbol, library_p[i].name, library_p[i].writer, library_p[i].shop, library_p[i].year, library_p[i].state);
				}
				else
				{
					continue;
				}
			}
			if (search_count == 0)
			{
				printf("검색결과 0건\n.");
				return 0;
			}
		}
		else if (number == 3)
		{
			printf("대출할 도서의 제1 저자명을 입력하고 Enter (최대 10자리) > ");
			scanf("%s", &find_writer);
			printf("청구기호 서명\t\t\t저자\t\t발행사\t\t출판년도\t상태\n ");
			printf("-----------------------------------------------------------------------------------------\n");
			for (int i = 0; i < 21; i++)
			{
				if (strstr(library_p[i].writer, find_writer))
				{
					search_count++;
					printf("%s\  %s\t\t %s\t %s\t %d\t %d\n ", library_p[i].symbol, library_p[i].name, library_p[i].writer, library_p[i].shop, library_p[i].year, library_p[i].state);
				}
				else
				{
					continue;
				}
			}
			if (search_count == 0)
			{
				printf("검색결과 0건\n.");
				return 0;
			}
		}
		else if (number == 4)
		{
			break;
		}
		else
		{
			printf("다른 번호를 입력하시오\n");
		}
	}
}
int Loans(int count, book* library_p)
{
	int number;
	int i;
	int search_count = 0;
	char loans_symbol[7], loans_name[20], loans_writer[10];
	char find_symbol[7], find_name[20], find_writer[10];

	while (1)
	{
		printf("도서 대출\n\n");
		printf("대출할 도서의 항목 선택\n\n");
		printf("1. 청구기호 입력(최대 영문 6자리) \n");
		printf("2. 도서명입력(최대 20자리)\n");
		printf("3. 제1 저자명 입력(최대 10자리) \n");
		printf("4. 이전 메뉴로 \n");
		printf("번호를 입력하고 Enter > ");
		scanf("%d", &number);

		if (number == 1)
		{
			printf("대출할 도서의 청구기호를 입력하고 Enter(최대 영문 6자리) > ");
			scanf("%s", loans_symbol);
			for (int i = 0; i < 7; i++)
			{
				if (strstr(library_p[i].symbol, find_symbol))
				{
					search_count += 1;
				}
				else
				{
					continue;
				}
			}
			if (library_p[search_count-1].state == 1)
			{
				printf("이미 대출된 책입니다.\n");
			}
			else
			{
				printf("책이 성공적으로 대출되었습니다.\n");
				library_p[search_count-1].state = 1;
			}
		}
		else if (number == 2)
		{
			printf("대출할 도서의 도서명을 입력하고 Enter(최대 20자리) > ");
			scanf("%s", library_p->name);
			for (int i = 0; i < 20; i++)
			{
				if (strstr(library_p[i].name, find_name))
				{
					search_count += 1;
				}
				else
				{
					continue;
				}
			}
			if (library_p[search_count].state == 1)
			{
				printf("이미 대출된 책입니다.\n");
			}
			else
			{
				printf("책이 성공적으로 대출되었습니다.\n");
				library_p[search_count].state = 1;
			}
		}
		else if (number == 3)
		{
			printf("대출할 도서의 제1 저자명을 입력하고 Enter (최대 10자리) > ");
			scanf("%s", library_p->writer);
			for (int i = 0; i < 10; i++)
			{
				if (strstr(library_p[i].writer, find_writer))
				{
					search_count += 1;
				}
				else
				{
					continue;
				}
			}
			if (library_p[search_count-1].state == 1)
			{
				printf("이미 대출된 책입니다.\n");
			}
			else
			{
				printf("책이 성공적으로 대출되었습니다.\n");
				library_p[search_count-1].state = 1;
			}
		}
		else if (number == 4)
		{
			break;
		}
		else
		{
			printf("다른 번호를 입력하시오\n");
		}
	}
}
int Return(int count, book* library_p)
{
	int number;
	int search_count = 0;
	char return_symbol[7], find_symbol[7];

	printf("도서 반납\n\n");
	printf("반납할 도서의 청구기호를 입력하고 Enter(최대 영문 6자리) > ");
	scanf("%s", return_symbol);
	for (int i = 0; i < 7; i++)
	{
		if (strstr(library_p[i].symbol, find_symbol))
		{
			search_count += 1;
		}
		else
		{
			continue;
		}
	}
	if (library_p[search_count].state == 0)
	{
		printf("이미 반납된 책입니다.\n");
	}
	else
	{
		printf("책이 성공적으로 반납되었습니다.\n");
		library_p[search_count].state = 0;
	}
}
int main()
{
	int count = 0;
	int num;
	book library[MAX_COUNT];

	while (1)
	{
		printf("\n도서관리 program\n\n");
		printf("1. 도서등록\n");
		printf("2. 도서현황\n");
		printf("3. 도서검색\n");
		printf("4. 도서대출\n");
		printf("5. 도서반납\n");
		printf("6. 종료\n\n");
		printf("번호를 입력하고 Enter > ");
		scanf("%d", &num);

		if (num == 1)
		{
			if (1 == Registration(count, library))
				count++;
		}
		else if (num == 2)
		{
			print(count, library);
		}
		else if (num == 3)
		{
			int a;
			a = Search(count, library);
			if (a == 1)
			{
				printf((char*)Search(count, library));
			}
			else
			{
				continue;
			}
		}
		else if (num == 4)
		{
			Loans(count, library);
		}
		else if (num == 5)
		{
			Return(count, library);
		}
		else if (num == 6)
		{
			break;
		}
		else
		{
			printf("다른 번호를 입력하시오\n");
		}
	}
}
