#include <stdio.h>
#include "Console.h"
#include <stdbool.h>
#include <stdlib.h>


#define ROWS 30 // ���� 
#define COLS 30 // ���� 


char map[ROWS][COLS] = { 0 };
char mapString[(COLS * (ROWS + 1)) + 1];

typedef struct {
    int x;
    int y;
} Position;

void LoadData()
{

}


void StartMenu(int y)
{
	
	while (true)
	{
		Clear();
		GotoXY(18, 13);
		printf("1 . �� �� �� ��");
		GotoXY(18, 18);
		printf("2. �� �� Ȯ ��");
		GotoXY(18, 23);
		printf("3. �� �� ");

		
		if (GetAsyncKeyState(VK_DOWN) & 8001)
		{

			if(y > 18)y = 18;
			y += 5;

		}
		else if (GetAsyncKeyState(VK_UP) & 8001)
		{
			if (y < 18)y = 18;
			y -= 5;
		}
	
		GotoXY(13, y);
		printf("->");
		
		if (y == 13 && GetAsyncKeyState(VK_CONTROL) & 8001)
			break;
		
		else if (y == 18 && GetAsyncKeyState(VK_CONTROL) & 8001)
		{
			//LoadData;
		}
		else if (y == 23 && GetAsyncKeyState(VK_CONTROL) & 8001)
			exit(0);

		
		Sleep(100);
	}
	
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
	for (int i = 0; i < COLS; ++i) // ' ' => 32 '#' => 35
	{
		map[i][0] = Wall;
		map[i][ROWS - 1] = Wall;

	}
	for (int j = 0; j < ROWS; ++j)
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


void GoToTargetPos(int a, int b, char* s)
{
	GotoXY(a, b);
	printf("%s", s);
}



void Monster1(int*x,int* y) // �� ����ٴϸ鼭 �÷��̾����� �Ѿ�
{
	GoToTargetPos(*x, *y, "o");

	int dx[4] = { 0, 1, 0, -1 }; // �� ������ �Ʒ� ����
	int dy[4] = { -1, 0, 1, 0 };

	int i = 0;
	
	int new_x = *x + dx[i];
	int new_y = *y + dy[i];

	if (map[COLS][ROWS] != 0)
		i++;

	*x = new_x;
	*y = new_y;
}

void Monster2()	// ������� �� ������ �����
{

}

void Monster3() // �÷��̾����� ���� 
{
	
}

void Boss()
{

}


void InputProcess(int* X, int* Y) // x 1 ~ 48 y 1 ~ 29
{
	if (GetAsyncKeyState(VK_LEFT) & 8001) // ����Ű�� ������ ��
	{
		if (*X < 2) *X = 2;
		*X = *X - 1;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (*X > 50) *X = 50;
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

int main()
{
	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);

	int playerX = 15, playerY = 15;

	int StartX = 15, StartY = 18;

	StartMenu(StartY); 

	MakeMap('#', map);
	RenderMap();
	int mx = 3, my = 4;
	while (1)
	{
		Clear;
		GoToTargetPos(0, 0, mapString);

		GoToTargetPos(playerX, playerY, "@");
		
		if (map[ROWS][COLS] == 0)
		{
			InputProcess(&playerX, &playerY);
		}

		/*
		*  1. ���� ��ȯ (�����ϸ� ��������)
		*  2. ���� óġ �� ���� ���� (x���� ���� �����)
		*  3. x�� �ݺ� �� ���� 
		*  4. ���� ���� �� ���� ���� ����
		*  5. 1~4�� �ݺ�
		*  6. �������� �����Ѱ� ǥ�� �� ���� �ε尡�� �ϰ�
		*/

		
		
		Monster1(&mx, &my);









		Sleep(100);
	}





}