#include <stdio.h>
#include <string.h>
#include "function.h"

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

void ShowMenu()
{

}

int main()
{
	int playerInput = 0;

	char monster_name[100][30];
	char monster_region[100][30];
	char monster_grand[100][30];
	int monster_level[100][30];


	Monster monsterGroup[100]; // ������ ������ ���� �� �ִ� ����ü
	int totalMonsterCount = 0;   // ���� �����Ϳ� ��� Index�� ����Ǿ��°�

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


}
