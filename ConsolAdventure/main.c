#include <stdio.h>
#include <stdbool.h>
#include "Console.h"

char wall[100] =  "##########" ;

void GameInfo() // 게임의 정보를 출력하는 함수를 담당.
{

}

void Wall(int* PlayerX,int* PlayerY,int* WallX,int* WallY)
{
	if (*PlayerX == *WallX -1)
	{
		*PlayerX--;
	}
}

void InputProcess(int* X,int* Y)
{
	if (GetAsyncKeyState(VK_LEFT) & 8001) // 왼쪽키를 눌렀을 때
	{
		if (*X < 1) *X = 1;
		*X = *X - 1;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (*X > 48) *X = 48;
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

int main()
{
	
	Clear();
	

	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);

	// 플레이어의 정보
	int playerX = 15, playerY = 28; // 플레이어의 좌표

	
	bool itemFound = false; // 아이템을 발견하면 true로 만들어 준다
	
	int itemX = 8, itemY = 8;
	
	

	while (1)
	{
		Clear();
		//GameInfo();
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