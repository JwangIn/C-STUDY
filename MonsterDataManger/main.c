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

// 1. Monster name,region,grade,level ����ü ������ �����ؼ� print ���
// 2. ����ü �迭. ����� ���� �ݺ������� ���� �迭 ���
// 3. �迭���ٰ� ����ü �迭 �����͸� �־���Ѵ�
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

	fseek(fp, 0, SEEK_SET); // fp�� ����Ű�� �ּҸ� ������ �������� �̵�

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

	Monster monsterGroup[100]; // ������ ������ ���� �� �ִ� ����ü
	int totalMonsterCount = 0;   // ���� �����Ϳ� ��� Index�� ����Ǿ��°�

	LoadMonsterData(monsterGroup, &totalMonsterCount);

	while (1)
	{
		// 1. ���� ������ �߰�
		// 2. ���� ������ ����
		// 3. ���� ������ ã��
		// 4. ���� ������ ����
		// 5. ���α׷� ����
		//system("cls");
		printf("1. ���� ������ �߰�\n");
		printf("2. ���� ������ ����\n");
		printf("3. ���� ������ ã��\n");
		printf("4. ���� ������ ����\n");
		printf("5. ���α׷� â ����\n");
		printf("6. ���α׷� ����\n");

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
