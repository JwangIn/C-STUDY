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
	if (*str2 == '\0')return 1; // ������ 1�� ��ȯ�Ѵ�.

	return 0;

}


void ChangeMonsterInfo(Monster(* monster)[100], int* monsterIndexPtr)
{
	char NewName[30];
	char region[30];
	char grade[30];
	printf("������ ���� �̸��� �Է����ּ���. : ");
	scanf_s("%s", NewName, 30);
	printf("������ ���� ����� �Է����ּ��� : ");
	scanf_s("%s", grade,30);
	printf("������ ���� ������ �Է����ּ��� : ");
	scanf_s("%s", region, 30);

	strcpy_s(monster[*monsterIndexPtr]->name, 30, NewName);
	strcpy_s(monster[*monsterIndexPtr]->grade, 30, grade);
	strcpy_s(monster[*monsterIndexPtr]->region, 30, region);

	(*monsterIndexPtr)++;
}


void ShowMonsterInfo(Monster monster)
{
	printf("���� �̸� : %s\n", monster.name);
	printf("���� ��� : %s\n", monster.grade);
	printf("���� ���� : %s\n", monster.region);
}

void SerchMonsterByName(Monster monster)
{
	
	char SearchName[30];
	printf("�˻��� �̸� : ");
	scanf_s("%s", SearchName,30);
	if (Compare(&monster.name, SearchName))
	{
		printf("���� �̸� : %s\n", monster.name);
		printf("���� ��� : %s\n", monster.grade);
		printf("���� ���� : %s\n", monster.region);
	}
	else
	{
		printf("ã�� �� �����ϴ�.\n");
	}

}

int main()
{
	Myint myint = 4;
	printf("%d\n", myint);

	MyintPtr myintptr = &myint;
	printf("%d\n", *myintptr);

	struct Monster m1;
	strcpy_s(m1.name, 30, "���");

	printf("���� �̸� : %s \n", m1.name);

	// �� �Լ� Compare �Լ�
	char name1[30] = "ȫ�浿";
	char name2[30] = "ȫ�浿";

	if (Compare(name1, name2))
	{
		printf("����.\n");
	}
	else
	{
		printf("�ٸ���.\n");
	}


	// ����ü�� ������ ����
	// ����ü ������ �ּҿ����� ���� �ִ´�.
	

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

	printf("���� �̸� : %s , ���� ��� : %s , ���� ���� : %s", monsterGroup[0].name, monsterGroup[0].grade, monsterGroup[0].region);

	SerchMonsterByName(m1);

}