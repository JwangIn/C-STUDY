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
		printf("1. ���� ������ �߰�");
		printf("2. ���� ������ ����");
		printf("3. ���� ������ ã��");
		printf("4. ���� ������ ����");
		printf("5. ���α׷� ����");

		scanf_s("%d", &playerInput);

		if (playerInput == 1)
		{
			AddMonsterInfo(monsterGroup, &totalMonsterCount);
		}

		if (playerInput == 2)
		{
			ShowMonsterInfo(monsterGroup, &totalMonsterCount);
		}

		if (playerInput == 3)
		{

		}

		printf("%d", totalMonsterCount);

		if (playerInput == 5) {
			break;
		}
	}


}
