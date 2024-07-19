#include <stdio.h>
#include <stdbool.h>
#include "Console.h"

#define ROWS 30 // 가로 
#define COLS 30 // 세로 

char map[COLS][ROWS] = { 0 };  // 맵안에 있는 정보
// ROWS +1 : 개행문자 \n을 더한것
// (COLS x ROWS) +1 은 
char mapString[(COLS * (ROWS+1)) + 1];  // 데이터로 부터 출력하는 문자열


void InputProcess(int* X,int* Y) // x 1 ~ 48 y 1 ~ 29
{
	if (GetAsyncKeyState(VK_LEFT) & 8001) // 왼쪽키를 눌렀을 때
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

void GameInfo() // 게임의 정보를 출력하는 함수를 담당.
{

}



int main()
{	
	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);

	// 플레이어의 정보
	int playerX = 15, playerY = 28; // 플레이어의 좌표

	
	bool itemFound = false; // 아이템을 발견하면 true로 만들어 준다
	
	int itemX = 8, itemY = 8;

	// 게임 맵 세팅
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
			mapString[mapIndex++] = map[i][j]; // ++ 후위 연산자라 계산이 끝나면 +함
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
			GoToTargetPos(1, 35, "아이템을 흭득했습니다.");
		}
		
		
	

		InputProcess(&playerX,&playerY); // 플레이어의 입력을 받아 움직이는 함수
		InteractOther(&playerX, &playerY,&itemX,&itemY,&itemFound );

		

		



		Sleep(50);
	}


	

}