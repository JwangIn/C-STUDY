#pragma once
typedef struct Monster {
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


void AddMonsterInfo(Monster(*monster)[100], int* monsterIndexPtr)
{
	char NewName[30];
	char region[30];
	char grade[30];
	printf("추가할 몬스터 이름을 입력해주세요. : ");
	scanf_s("%s", NewName, 30);
	printf("추가할 몬스터 등급을 입력해주세요 : ");
	scanf_s("%s", grade, 30);
	printf("추가할 몬스터 지역을 입력해주세요 : ");
	scanf_s("%s", region, 30);

	strcpy_s(monster[*monsterIndexPtr]->name, 30, NewName);
	strcpy_s(monster[*monsterIndexPtr]->grade, 30, grade);
	strcpy_s(monster[*monsterIndexPtr]->region, 30, region);

	(*monsterIndexPtr)++;
}


void ShowMonsterInfo(Monster(*monster)[100],int len)
{

	for (int i = 0; i < len; ++i)
	{printf("몬스터 이름 : %s\n", monster[i]->name);
	printf("몬스터 등급 : %s\n", monster[i]->name);
	printf("몬스터 지역 : %s\n", monster[i]->name);
	}
}

void SerchMonsterByName(Monster monster)
{

	char SearchName[30];
	printf("검색할 이름 : ");
	scanf_s("%s", SearchName, 30);
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