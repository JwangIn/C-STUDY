#include <stdio.h>
#include <string.h>

typedef int Myint;
typedef int* MyintPtr;

typedef struct Monster{
	char name[30];
	char region[30];
	char grade[30];
}Monster;

int Compare(char* str1, char* str2)
{
	while (*str1)
	{
		if (*str1 != *str2)
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str2 == '\0')return 1; // 같으면 1을 반환한다.

	return 0;

}


void ChangeMonsterInfo(Monster(* monster)[100], int* monsterIndexPtr)
{
	char NewName[30];
	char region[30];
	char grade[30];
	printf("변경할 몬스터 이름을 입력해주세요. : ");
	scanf_s("%s", NewName, 30);
	printf("변경할 몬스터 등급을 입력해주세요 : ");
	scanf_s("%s", grade,30);
	printf("변경할 몬스터 지역을 입력해주세요 : ");
	scanf_s("%s", region, 30);

	strcpy_s(monster[*monsterIndexPtr]->name, 30, NewName);
	strcpy_s(monster[*monsterIndexPtr]->grade, 30, grade);
	strcpy_s(monster[*monsterIndexPtr]->region, 30, region);

	(*monsterIndexPtr)++;
}


void ShowMonsterInfo(Monster monster)
{
	printf("몬스터 이름 : %s\n", monster.name);
	printf("몬스터 등급 : %s\n", monster.grade);
	printf("몬스터 지역 : %s\n", monster.region);
}

void SerchMonsterByName(Monster monster)
{
	
	char SearchName[30];
	printf("검색할 이름 : ");
	scanf_s("%s", SearchName,30);
	if (Compare(&monster.name, SearchName))
	{
		printf("몬스터 이름 : %s\n", monster.name);
		printf("몬스터 등급 : %s\n", monster.grade);
		printf("몬스터 지역 : %s\n", monster.region);
	}
	else
	{
		printf("찾을 수 없습니다.\n");
	}

}

int main()
{
	Myint myint = 4;
	printf("%d\n", myint);

	MyintPtr myintptr = &myint;
	printf("%d\n", *myintptr);

	struct Monster m1;
	strcpy_s(m1.name, 30, "고블린");

	printf("몬스터 이름 : %s \n", m1.name);

	// 비교 함수 Compare 함수
	char name1[30] = "홍길동";
	char name2[30] = "홍길동";

	if (Compare(name1, name2))
	{
		printf("같다.\n");
	}
	else
	{
		printf("다르다.\n");
	}


	// 구조체의 포인터 사용법
	// 구조체 변수에 주소연산자 값을 넣는다.
	

	/*
	int monsterSize;
	scanf_s("%s", monsterSize);
	Monster* monsterGptr = malloc(sizeof(Monster) * monsterSize);
	free(monsterGptr);
	*/
	Monster* monsterptr = &m1;
	Monster monsterGroup[100];

	int totalMonsterCounter = 0;


	ChangeMonsterInfo(&monsterGroup, &totalMonsterCounter);

	printf("몬스터 이름 : %s , 몬스터 등급 : %s , 몬스터 지역 : %s", monsterGroup[0].name, monsterGroup[0].grade, monsterGroup[0].region);

	SerchMonsterByName(m1);

}