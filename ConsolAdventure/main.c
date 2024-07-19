#include <stdio.h>
#include <stdbool.h>
#include "Console.h"

#define ROWS 30 // ���� 
#define COLS 30 // ���� 

char map[COLS][ROWS] = { 0 };  // �ʾȿ� �ִ� ����
// ROWS +1 : ���๮�� \n�� ���Ѱ�
// (COLS x ROWS) +1 �� 
char mapString[(COLS * (ROWS+1)) + 1];  // �����ͷ� ���� ����ϴ� ���ڿ�


void InputProcess(int* X,int* Y) // x 1 ~ 48 y 1 ~ 29
{
	if (GetAsyncKeyState(VK_LEFT) & 8001) // ����Ű�� ������ ��
	{
		if (*X < 1) *X = 1;
		*X = *X - 1;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (*X > 29) *X = 29;
		*X = *X + 1;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 8001)
	{
		if (*Y > 29) *Y = 29;
		(*Y)++;
	}
	else if (GetAsyncKeyState(VK_UP) & 8001)
	{
		if (*Y < 1)*Y = 1;
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

void GameInfo() // ������ ������ ����ϴ� �Լ��� ���.
{

}



int main()
{	
	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);

	// �÷��̾��� ����
	int playerX = 15, playerY = 28; // �÷��̾��� ��ǥ

	
	bool itemFound = false; // �������� �߰��ϸ� true�� ����� �ش�
	
	int itemX = 8, itemY = 8;

	// ���� �� ����
	// MakeMap();
	

	for (int i = 0; i < COLS; ++i) // ' ' => 32 '#' => 35
	{
		for (int j = 0; j < ROWS; ++j)
		{
			map[i][j] = ' ';
		}
	}
	for (int i = 0; i < COLS; ++i) // ' ' => 32 '#' => 35
	{
		map[i][0] = '#';
		map[i][ROWS - 1] = '#';

	}
	for (int j = 0; j < ROWS; ++j)
	{
		map[0][j] = '#';
		map[COLS - 1][j] = '#';
	}

	int mapIndex = 0;

	for (int i = 0; i < COLS; ++i)
	{
		for (int j = 0; j = ROWS; ++j)
		{
			mapString[mapIndex++] = map[i][j]; // ++ ���� �����ڶ� ����� ������ +��
		}
		mapString[mapIndex++] = '\n';
	}
	mapString[mapIndex] = '\0';


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