#pragma once
typedef struct Monster {
	char name[30];
	char region[30];
	char grade[30];
}Monster;

int Compare(char* str1, char* str2);


void AddMonsterInfo(Monster monster[100], int* monsterIndexPtr);



void ShowMonsterInfo(Monster monster[100], int len);

void SerchMonsterByName(Monster monster[100], int monsterIndexPtr);


void DeleteMonsterByNumber(Monster monster[100]);
