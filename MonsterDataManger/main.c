#include <stdio.h>
#include <string.h>
#include "function.h"


#define filename "monsterData.txt"
/*
* typedef struct Monster {
* 	char name[30];
*	char region[30];
*	char garde[30];
*	int level;
* }Monster;
*/

// 1. Monster name,region,grade,level 구조체 변수를 선언해서 print 출력
// 2. 구조체 배열. 만들어 보고 반복문으로 몬스터 배열 출력
// 3. 배열에다가 구조체 배열 데이터를 넣어야한다
// 4. char name[100][30] = Monster.name

void PrintMonsterList(Monster* monsterList, int totalCount)
{
	FILE* fp = fopen(filename, "w"); 

	if (fp == NULL) {
		perror("Write Error! \n");		
	}
	
	 
	for (int i = 0; i < totalCount; ++i) {
		fprintf(fp, "%s %s %s\n", monsterList[i].name, monsterList[i].grade, monsterList[i].region);
	}
	

	fclose(fp);

}

void LoadMonsterData(Monster* monsterList, int* totalCount)
{
	

	FILE* fp = fopen(filename, "r");

	if (fp == NULL) {
		perror("Load Error! \n");
	}

	int count = 0;
	char ch;

	if (fgetc(fp) != EOF)
	{
		count = 1;
	}

	fseek(fp, 0, SEEK_SET); // fp가 가리키는 주소를 파일의 시작으로 이동

	while (fgetc(fp) != EOF)
	{
		ch = fgetc(fp);
		if (ch == '\n') {
			count++;
		}
	}

	fseek(fp, 0, SEEK_SET);
	*totalCount = count;

	for (int i = 0; i < count; ++i)
	{
		fscanf_s(fp, "%s %s %s", (monsterList + i)->name,30, (monsterList + i)->grade,30, (monsterList + i)->region,30);
	}


	fclose(fp);
}

int main()
{
	int playerInput = 0;

	Monster monsterGroup[100]; // 몬스터의 정보를 넣을 수 있는 구조체
	int totalMonsterCount = 0;   // 몬스터 데이터에 몇번 Index에 저장되었는가

	LoadMonsterData(monsterGroup, &totalMonsterCount);

	while (1)
	{
		// 1. 몬스터 데이터 추가
		// 2. 몬스터 데이터 보기
		// 3. 몬스터 데이터 찾기
		// 4. 몬스터 데이터 삭제
		// 5. 프로그램 종료
		//system("cls");
		printf("1. 몬스터 데이터 추가\n");
		printf("2. 몬스터 데이터 보기\n");
		printf("3. 몬스터 데이터 찾기\n");
		printf("4. 몬스터 데이터 삭제\n");
		printf("5. 프로그램 창 정리\n");
		printf("6. 프로그램 종료\n");

		scanf_s("%d", &playerInput);

		if (playerInput == 1)
		{
			AddMonsterInfo(monsterGroup, &totalMonsterCount);
		}

		if (playerInput == 2)
		{
			ShowMonsterInfo(monsterGroup, totalMonsterCount);
		}

		if (playerInput == 3)
		{
			SerchMonsterByName(monsterGroup,totalMonsterCount);
		}
		if (playerInput == 4)
		{
			DeleteMonsterByNumber(monsterGroup);
		}
		if (playerInput == 5)
		{
			system("cls");
		}

		if (playerInput == 6) {
			break;
		}
	}

	PrintMonsterList(monsterGroup, totalMonsterCount);

	return 0;
}
