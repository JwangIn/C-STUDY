#include "Mygame.h"



void SelectStartMenu(int y)
{

	while (true)
	{
		Clear();
		GotoXY(11, 5);
		printf("����Ű�� Ctrl�� ���� �����մϴ�.");
		GotoXY(18, 13);
		printf("1 . �� �� �� ��");
		GotoXY(18, 18);
		printf("2 . �� �� Ȯ ��");
		GotoXY(18, 23);
		printf("3 . �� �� ");


		if (GetAsyncKeyState(VK_DOWN) & 8001)
		{

			if (y > 18)y = 18;
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
			//ShowGameRecord();
		}
		else if (y == 23 && GetAsyncKeyState(VK_CONTROL) & 8001)
			exit(0);


		Sleep(100);
	}
}


void ShowGameRecord();
