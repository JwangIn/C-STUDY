#include <stdio.h>
#include <string.h>

typedef struct Monster {
	char name[30];
	char region[30];
	char garde[30];
	int level;
}Monster;

// 1. Monster name,region,grade,level ����ü ������ �����ؼ� print ���
// 2. ����ü �迭. ����� ���� �ݺ������� ���� �迭 ���
// 3. �迭���ٰ� ����ü �迭 �����͸� �־���Ѵ�
// 4. char name[100][30] = Monster.name

int AddMonster(char(*monster_name)[30],char(*monster_region)[30],char(*monster_grand)[30],int level, int* totalCount,Monster *monster)
{
	scanf_s("%s", *monster_name); // �ϴ� ���� �ϳ��� ����� �Լ��� ���� ����
	*monster->name = *monster_name;
}

int SearchMonster(); // compare �Լ� ������ �Ѵ�.

int ShowAllMonster(); // printf( ��� �迭�� �ִ� ��� ��� . monster[i] name )

int DeleteMonster(); // Ư�� �迭 ��� �˻��ؼ� �����Ͱ� ������ �ش� �����͸� null ����.



int main()
{
	int playerInput = 0;

	char monster_name[100][30];
	char monster_region[100][30];
	char monster_grand[100][30];
	int monster_level[100][30];

	int totalMonsterCount; // ���� �����Ϳ� ��� Index�� ����Ǿ��°�

	while (1)
	{
		// 1. ���� ������ �߰�
		// 2. ���� ������ ����
		// 3. ���� ������ ã��
		// 4. ���� ������ ����
		// 5. ���α׷� ����
		system("cls");
		printf("1. ���� ������ �߰�");

		
		printf("5. ���α׷� ����");

		scanf_s("%d", &playerInput);

		if (playerInput == 5) {
			break;
		}
	}


}
