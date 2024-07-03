#include <stdio.h> // printf, scanf 함수를 사용하기 위해서 필요하다. //시스템 폴더의 헤더파일을 불러온다.
#include "Console.h" // 프로젝트 안에 ""안에 있는 파일을 찾아서 복사해라
#include <stdbool.h>
#include <time.h>
#include <conio.h> // console input output
// main함수에서 사용할 수 있게 키워드를 작성해주세요.

#define MAX 30
#define BLACK 0
#define WHITE 15

void GameOver(void)
{
	int temp;
	printf("플레이어가 사망했습니다.\n 게임을 종료하려면 아무 숫자키를 입력 후 엔터를 쳐주세요.\n");
	scanf_s("%d", &temp); 
	
}

void StartMenu(void)
{
	while (true)
	{
		Clear();
		GotoXY(10, 9);
		printf("별 피하기");
		GotoXY(3, 20);
		printf("키를 입력하여 시작하시요.");

		if (_kbhit())
			break;
	}
}

int main()
{
	// 콘솔창에 게임의 맵의 크기를 만들어 줘야한다.

	SetTitle("별 피하기 _ 박종현");
	SetColor(WHITE, 0);
	SetConsoleSize(30,30);
	SetConsoleCursorVisibility(0);

	// 맵의 크기를 만들었다. 그 다음에 무엇을 해야하나?
	// 캐릭터 + 움직임
	// 캐릭터의 위치 (14,28);

	// 플레이어의 총알 구현(Bullet)
	// GotoXY 와 printf를 이용해 총알 구현

	StartMenu();


	int score = 0;

	int x = 14, y = 28;  // 플레이어의 x,y좌표
	int bx = 0, by = 0;  // 총알의 x,y 좌표
	bool bullet = false; // 현재 총알이 생성되지 않았으면 false, 생성됬으면 true
	int ex[MAX] = {0};
	int	ey[MAX] = {0};  // 별의 x,y 좌표
	bool enemy[MAX] = { false };  // 몬스터가 시작할때 false, 생성될 때 true
	srand(time(NULL));
	bool IsLive = true;
	int Special = 3;
	int Life = 3;

	while (1) // 무한 루프
	{
		
		Clear();
		GotoXY(0, 0);
		printf("SCORE %d", score);
		if (IsLive)
			score++;
	

		for (int i = 0; i < MAX; i++)
		{
			if (enemy[i] != true)
			{

				ex[i] = (rand() % 15) * 2; // rand() 랜덤 함수의 seed 값을 현재 시간에 따라서 변경시켜주는.
				//(rand() % 15) * 2; // rand() => 0 ~ 25947 랜덤숫자 반환 // 0~ 14 반환해주는 값                   
				ey[i] = 2;

				enemy[i] = true;
				break;
			}		
		}


#if true // 플레이어의 이동 조작
		if (IsLive)
		{
			if (GetAsyncKeyState(VK_LEFT) & 8001) // 왼쪽키를 눌렀을 때
			{
				if (x < 1) x = 1;
				x = x - 2;
			}
			else if (GetAsyncKeyState(VK_RIGHT) & 8001)
			{
				if (x > 27) x = 27;
				x = x + 2;
			}
			else if (GetAsyncKeyState(VK_DOWN) & 8001)
			{
				if (y > 28)y = 28;
				y++;
			}
			else if (GetAsyncKeyState(VK_UP) & 8001)
			{
				if (y < 2)y = 2;
				y--;
			}
		}
#endif		
		GotoXY(x, y); // 플레이어가 살아있을 때 현재 플레이어를 출려해주는 코드
		if (IsLive)
		{
			printf("♣");
			SetColor(BLACK, 13);
		}
		else
		{
			printf("＠");
			break;
		}
		

#if true // 총알
		if (IsLive)
		{
			if (GetAsyncKeyState(VK_SPACE) & 8001)
			{
				if (bullet != true)  // !bullet 과 bullet == false 같은 의미
				{
					bx = x;
					by = y - 1;

					bullet = true;
				}

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

#if false //별을 한개 씩 떨어뜨리는 코드
		if (enemy != true)
		{
			srand(time(NULL));
			ex = rand() % 26 + 1; // rand() 랜덤 함수의 seed 값을 현재 시간에 따라서 변경시켜주는.
			   //(rand() % 15) * 2; // rand() => 0 ~ 25947 랜덤숫자 반환 // 0~ 14 반환해주는 값                   
			ey = 0; 
			
			enemy = true;
		}
		if (enemy)
		{
			ey++;
			GotoXY(ex, ey);
			printf("★");
			if (ey > 28)
				enemy = false;
		}
#endif
		
		
			for (int i = 0; i < MAX; i++)
			{
				if (enemy[i])
				{


					GotoXY(ex[i], ey[i]);
					printf("★");
					ey[i]++;

					if (bx == ex[i] && by == ey[i] && bullet == true)
					{
						bullet = false;
						enemy[i] = false;
						score += 100;
					}
					if (ey[i] > 28)
						enemy[i] = false;
				}

				if (ex[i] == x && ey[i] == y) // 플레이어가 충돌
				{
					// 플레이어가 죽었을 때 작동하는 로직
					Life--;
					if (Life < 1)
					{
						IsLive = false;
					}
				}



			}
		
			if (IsLive)
			{
				if (Special > 0)
				{
					if (GetAsyncKeyState(VK_CONTROL) & 8001)
					{
						score += 2000;
						for (int i = 0; i < MAX; i++)
						{
							enemy[i] = false;
						}
						Special--;
					}
				}
			}
			

		

		Sleep(100); // Sleep안의 숫자만큼 기다렸다가 실행

	}

	GameOver();
}