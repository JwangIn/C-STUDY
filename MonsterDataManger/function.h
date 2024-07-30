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


void AddMonsterInfo(Monster monster[100], int* monsterIndexPtr)
{
	

	printf("추가할 몬스터 이름을 입력해주세요. : ");
	scanf_s("%s", monster[*monsterIndexPtr].name, 30);
	printf("추가할 몬스터 등급을 입력해주세요 : ");
	scanf_s("%s", monster[*monsterIndexPtr].grade, 30);
	printf("추가할 몬스터 지역을 입력해주세요 : ");
	scanf_s("%s", monster[*monsterIndexPtr].region, 30);

	(*monsterIndexPtr)++;
}


void ShowMonsterInfo(Monster monster[100],int len)
{

	for (int i = 0; i < len; ++i)
	{
		printf("몬스터 %d 번째의 이름 : %s\n",i, monster[i].name);
		printf("몬스터 %d 번째의 등급 : %s\n", i,monster[i].grade);
		printf("몬스터 %d 번째의 지역 : %s\n \n",i, monster[i].region);
	}
}

void SerchMonsterByName(Monster monster[100],int monsterIndexPtr)
{

	char SearchName[30];
	printf("검색할 이름 : ");
	scanf_s("%s", SearchName, 30); // 동적할당, 프로그램 실행 뒤에 검색하고 싶은 단어를 searchname 공간에 저장

	for (int i = 0; i < monsterIndexPtr; ++i)
	{
		if (Compare(monster[i].name, &SearchName))
		{
			printf("몬스터 이름 : %s\n", monster[i].name);
			printf("몬스터 등급 : %s\n", monster[i].grade);
			printf("몬스터 지역 : %s\n", monster[i].region);
			return;
		}
		printf("찾지 못 하였습니다.\n");
	
	}
	
	
}

void DeleteMonsterByNumber(Monster monster[100])
{
	// 0,1,2,3... 에서 2를 지우면 0,1,3,... 비어있게된다.
	// 배열을 재선언해서 차곡차곡 다시 데이터를 입력해줘야한다.
	
	int i;
	printf("지우고 싶은 번호를 입력 해주세요.(예시: 0 ~ 99) : ");
	scanf_s("%d", &i);
	
	strcpy_s(monster[i].name, 30, "삭제됨.");
	strcpy_s(monster[i].grade, 30, "삭제됨.");
	strcpy_s(monster[i].region, 30, "삭제됨.");



}