#include <stdio.h> // printf, scanf 함수를 사용하기 위해서 필요하다. //시스템 폴더의 헤더파일을 불러온다.
#include "Console.h" // 프로젝트 안에 ""안에 있는 파일을 찾아서 복사해라
#include <stdbool.h>
// main함수에서 사용할 수 있게 키워드를 작성해주세요.


int main()
{
	// 콘솔창에 게임의 맵의 크기를 만들어 줘야한다.

	SetConsoleSize(30,30);
	SetConsoleCursorVisibility(0);

	// 맵의 크기를 만들었다. 그 다음에 무엇을 해야하나?
	// 캐릭터 + 움직임
	// 캐릭터의 위치 (14,28);

	// 플레이어의 총알 구현(Bullet)
	// GotoXY 와 printf를 이용해 총알 구현

	int x = 14, y = 28;  // 플레이어의 x,y좌표
	int bx = 0, by = 0;  // 총알의 x,y 좌표
	bool bullet = false; // 현재 총알이 생성되지 않았으면 false, 생성됬으면 true

	while (1) // 무한 루프
	{
		Clear();

#if true // 플레이어의 이동 조작
		if (GetAsyncKeyState(VK_LEFT) & 8001) // 왼쪽키를 눌렀을 때
		{
			if (x < 1) x = 1;
			x--;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 8001)
		{
			if (x > 27) x = 27;
			x++;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 8001)
		{
			if (y > 28)y = 28;
			y++;
		}
		else if (GetAsyncKeyState(VK_UP) & 8001)
		{
			if (y < 1)y = 1;
			y--;
		}
#endif		
		GotoXY(x, y);
		printf("♣");

#if true // 총알
		if (GetAsyncKeyState(VK_SPACE) & 8001)
		{
			if (bullet != true)  // !bullet 과 bullet == false 같은 의미
			{
				bx = x;
				by = y - 1;

				bullet = true;
			}
			
		}
		
		if (bullet) // 총알이 생성되어 있을 경우에만
		{
			by--; // 한 칸위로 움직이고
			GotoXY(bx, by);
			printf("↑");

			if (by < 1) // 총알이 가장 위로 넘어가면 종료
			bullet = false;
		}
#endif
		// 하늘에서 떨어지는 것들?
		// x=1~27,y=1 에서 생성 되야함. y++ 되야함. y28넘어가면 사라짐 + bullet을 만나도 사라저야될듯?


		Sleep(50); // Sleep안의 숫자만큼 기다렸다가 실행

	}
}