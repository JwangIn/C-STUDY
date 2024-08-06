#include <stdio.h>
#include <stdbool.h>
#include "Console.h"

#define ROWS 30 // ���� 
#define COLS 30 // ���� 
#define filename "playerData.txt"

char map[ROWS][COLS] = { 0 };  // �ʾȿ� �ִ� ����
// ROWS +1 : ���๮�� \n�� ���Ѱ�
// (COLS x ROWS) +1 �� 
char mapString[(COLS * (ROWS+1)) + 1];  // �����ͷ� ���� ����ϴ� ���ڿ�


void InputProcess(int* X,int* Y) // x 1 ~ 48 y 1 ~ 29
{
	if (GetAsyncKeyState(VK_LEFT) & 8001) // ����Ű�� ������ ��
	{
		if (*X < 2) *X = 2;
		*X = *X - 1;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (*X > 27) *X = 27;
		*X = *X + 1;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 8001)
	{
		if (*Y > 27) *Y = 27;
		(*Y)++;
	}
	else if (GetAsyncKeyState(VK_UP) & 8001)
	{
		if (*Y < 2)*Y = 2;
		(*Y)--;
	}

}

void InteractOther(int* playerX, int* playerY, int* itemX, int* itemY,bool* item)
{
	if (*playerX == *itemX && *playerY == *itemY)
	{
		*item = true;
	}
}


void GoToTargetPos(int a, int b, char* s)
{
	GotoXY(a, b);
	printf("%s", s);
}

void MakeMap(char Wall, char(*map)[ROWS]) // map -> 30 * 30
{
	for (int i = 0; i < COLS; ++i) 
	{
		for (int j = 0; j < ROWS; ++j)
		{
			map[i][j] = ' ';
		}
	}
	for (int i = 0; i < ROWS; ++i) // ' ' => 32 '#' => 35
	{
		map[i][0] = Wall;
		map[i][ROWS - 1] = Wall;

	}
	for (int j = 0; j < COLS; ++j)
	{
		map[0][j] = Wall;
		map[COLS - 1][j] = Wall;
	}

}

void RenderMap()  // ������� ���� �׸��� �Լ�
{
	int mapIndex = 0;

	for (int i = 0; i < COLS; ++i)
	{
		for (int j = 0; j < ROWS; ++j)
		{
			mapString[mapIndex] = map[i][j];
			mapIndex++;                           // ++ ���� �����ڶ� ����� ������ +��
		}
		mapString[mapIndex++] = '\n';
	}
	mapString[mapIndex] = '\0';
}


void GameInfo() // ������ ������ ����ϴ� �Լ��� ���.
{


}

typedef struct PlayerData 
{
	char name[30];  // �̸��� �����ϱ� ���� �迭
	int score;      // ���� ���·� ������ �����Ѵ�.
}PlayerData;

void SavePlayerData(PlayerData* player, int totalCount)
{
	FILE* fp = fopen(filename, "w");

	if (fp == NULL) {
		perror("Write Error! \n");
	}


	for (int i = 0; i < totalCount; ++i) {
		fprintf(fp, "%s %d \n", player[i].name, player[i].score);
	}


	fclose(fp);

}

void LoadMonsterData(PlayerData* player, int* totalCount)
{


	FILE* fp = fopen(filename, "r");

	if (fp == NULL) {
		perror("Load Error! \n");
		return;
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
		fscanf_s(fp, "%s %d", (player + i)->name, 30, &(player + i)->score);
	}


	fclose(fp);
}



int main()
{	
	PlayerData allPlayerData[100];
	int totalcount;

	LoadMonsterData(allPlayerData,&totalcount);
	printf("%s %d", allPlayerData[0].name, allPlayerData[0].score);
	
	//SelectStartMenu(18);

	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);

	// �÷��̾��� ����
	int playerX = 15, playerY = 28; // �÷��̾��� ��ǥ

	bool itemFound = false; // �������� �߰��ϸ� true�� ������
	bool canMove = true; // canMove�� true�� ���� ��������.
	
	int itemX = 8, itemY = 8;

	// ���� �� ����

	// �ܺ� ����
	MakeMap('#', map);
	
	// ���� ����
	map[10][10] = '#';
	map[10][11] = '#';
	map[10][12] = '#';
	map[9][12] = '#';
	map[8][12] = '#';

	
	RenderMap();

	while (1)
	{
		Clear();
		//GameInfo();
		GoToTargetPos(0, 0, mapString);
		

		GoToTargetPos(playerX, playerY,"@" );
		
		

		if (itemFound != true)
		{
			GoToTargetPos(itemX, itemY, "$");
		}
		else
		{
			GoToTargetPos(1, 35, "�������� ŉ���߽��ϴ�.");
		}
		
		
	

		InputProcess(&playerX,&playerY); // �÷��̾��� �Է��� �޾� �����̴� �Լ�
		InteractOther(&playerX, &playerY,&itemX,&itemY,&itemFound );

		

		



		Sleep(50);
	}


	

}