#include <stdio.h>
#include <stdbool.h>
#include "Console.h"

#define ROWS 30 // 가로 
#define COLS 30 // 세로 

char map[ROWS][COLS] = { 0 };  // 맵안에 있는 정보
// ROWS +1 : 개행문자 \n을 더한것
// (COLS x ROWS) +1 은 
char mapString[(COLS * (ROWS+1)) + 1];  // 데이터로 부터 출력하는 문자열


void InputProcess(int* X,int* Y) // x 1 ~ 48 y 1 ~ 29
{
	if (GetAsyncKeyState(VK_LEFT) & 8001) // 왼쪽키를 눌렀을 때
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

void RenderMap()  // 만들어진 맵을 그리는 함수
{
	int mapIndex = 0;

	for (int i = 0; i < COLS; ++i)
	{
		for (int j = 0; j < ROWS; ++j)
		{
			mapString[mapIndex] = map[i][j];
			mapIndex++;                           // ++ 후위 연산자라 계산이 끝나면 +함
		}
		mapString[mapIndex++] = '\n';
	}
	mapString[mapIndex] = '\0';
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

	bool itemFound = false; // 아이템을 발견하면 true로 만들어라
	bool canMove = true; // canMove가 true일 때만 움직여라.
	
	int itemX = 8, itemY = 8;

	// 게임 맵 세팅

	// 외벽 세팅
	MakeMap('#', map);
	
	// 내벽 세팅
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
			GoToTargetPos(1, 35, "아이템을 흭득했습니다.");
		}
		
		
	

		InputProcess(&playerX,&playerY); // 플레이어의 입력을 받아 움직이는 함수
		InteractOther(&playerX, &playerY,&itemX,&itemY,&itemFound );

		

		



		Sleep(50);
	}


	

}