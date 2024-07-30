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
	if (*str2 == '\0')return 1; // ������ 1�� ��ȯ�Ѵ�.

	return 0;

}


void AddMonsterInfo(Monster monster[100], int* monsterIndexPtr)
{
	

	printf("�߰��� ���� �̸��� �Է����ּ���. : ");
	scanf_s("%s", monster[*monsterIndexPtr].name, 30);
	printf("�߰��� ���� ����� �Է����ּ��� : ");
	scanf_s("%s", monster[*monsterIndexPtr].grade, 30);
	printf("�߰��� ���� ������ �Է����ּ��� : ");
	scanf_s("%s", monster[*monsterIndexPtr].region, 30);

	(*monsterIndexPtr)++;
}


void ShowMonsterInfo(Monster monster[100],int len)
{

	for (int i = 0; i < len; ++i)
	{
		printf("���� %d ��°�� �̸� : %s\n",i, monster[i].name);
		printf("���� %d ��°�� ��� : %s\n", i,monster[i].grade);
		printf("���� %d ��°�� ���� : %s\n \n",i, monster[i].region);
	}
}

void SerchMonsterByName(Monster monster[100],int monsterIndexPtr)
{

	char SearchName[30];
	printf("�˻��� �̸� : ");
	scanf_s("%s", SearchName, 30); // �����Ҵ�, ���α׷� ���� �ڿ� �˻��ϰ� ���� �ܾ searchname ������ ����

	for (int i = 0; i < monsterIndexPtr; ++i)
	{
		if (Compare(monster[i].name, &SearchName))
		{
			printf("���� �̸� : %s\n", monster[i].name);
			printf("���� ��� : %s\n", monster[i].grade);
			printf("���� ���� : %s\n", monster[i].region);
			return;
		}
		printf("ã�� �� �Ͽ����ϴ�.\n");
	
	}
	
	
}

void DeleteMonsterByNumber(Monster monster[100])
{
	// 0,1,2,3... ���� 2�� ����� 0,1,3,... ����ְԵȴ�.
	// �迭�� �缱���ؼ� �������� �ٽ� �����͸� �Է�������Ѵ�.
	
	int i;
	printf("����� ���� ��ȣ�� �Է� ���ּ���.(����: 0 ~ 99) : ");
	scanf_s("%d", &i);
	
	strcpy_s(monster[i].name, 30, "������.");
	strcpy_s(monster[i].grade, 30, "������.");
	strcpy_s(monster[i].region, 30, "������.");



}