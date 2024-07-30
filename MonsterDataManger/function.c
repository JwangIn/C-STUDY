#pragma once
#include <stdio.h>
#include <string.h>
#include "function.h"

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
	if (*str2 == '\0')return 1; // ������ 1�� ��ȯ�Ѵ�.

	return 0;

}


void AddMonsterInfo(Monster(*monster)[100], int* monsterIndexPtr)
{
	char NewName[30];
	char region[30];
	char grade[30];
	printf("�߰��� ���� �̸��� �Է����ּ���. : ");
	scanf_s("%s", NewName, 30);
	printf("�߰��� ���� ����� �Է����ּ��� : ");
	scanf_s("%s", grade, 30);
	printf("�߰��� ���� ������ �Է����ּ��� : ");
	scanf_s("%s", region, 30);

	strcpy_s(monster[*monsterIndexPtr]->name, 30, NewName);
	strcpy_s(monster[*monsterIndexPtr]->grade, 30, grade);
	strcpy_s(monster[*monsterIndexPtr]->region, 30, region);

	(*monsterIndexPtr)++;
}


void ShowMonsterInfo(Monster(*monster)[100], int len)
{

	for (int i = 0; i < len; ++i)
	{
		printf("���� �̸� : %s\n", monster[i]->name);
		printf("���� ��� : %s\n", monster[i]->grade);
		printf("���� ���� : %s\n", monster[i]->region);
	}
}

void SerchMonsterByName(Monster(*monster)[100])
{

	char SearchName[30];
	printf("�˻��� �̸� : ");
	scanf_s("%s", SearchName, 30);

	if (Compare(monster[100]->name, SearchName))
	{
		printf("���� �̸� : %s\n", monster[100]->name);
		printf("���� ��� : %s\n", monster[100]->grade);
		printf("���� ���� : %s\n", monster[100]->region);

		return;
	}
	else
	{
		printf("ã�� �� �����ϴ�.\n");
	}

}