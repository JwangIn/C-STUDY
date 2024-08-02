#include <stdio.h>
#include "Console.h"
#include <stdbool.h>




void LoadData()
{

}



void MenuMove(int* y)
{
	

	if (GetAsyncKeyState(VK_DOWN) & 8001)
	{
		if (y > 23)y = 23;
		y += 5;
	}
	else if (GetAsyncKeyState(VK_UP) & 8001)
	{
		if (y < 13)y = 13;
		y -= 5;
	}
}


void StartMenu(int* x, int* y)
{
	while (true)
	{
		Clear();
		GotoXY(18, 13);
		printf("1 . 게 임 시 작");
		GotoXY(18, 18);
		printf("2. 기 록 확 인");
		GotoXY(18, 23);
		printf("3. 종 료 ");

		GotoXY(18, 18);
		void MenuMove(int* y);

	}
}


int main()
{
	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);
	
	StartMenu();

	while (1)
	{

	}





}