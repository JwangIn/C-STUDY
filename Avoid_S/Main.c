#include <stdio.h> // printf, scanf �Լ��� ����ϱ� ���ؼ� �ʿ��ϴ�. //�ý��� ������ ��������� �ҷ��´�.
#include "Console.h" // ������Ʈ �ȿ� ""�ȿ� �ִ� ������ ã�Ƽ� �����ض�
#include <stdbool.h>
#include <time.h>
#include <conio.h> // console input output
// main�Լ����� ����� �� �ְ� Ű���带 �ۼ����ּ���.

#define MAX 30
#define BLACK 0
#define WHITE 15

void GameOver(void)
{
	int temp;
	printf("�÷��̾ ����߽��ϴ�.\n ������ �����Ϸ��� �ƹ� ����Ű�� �Է� �� ���͸� ���ּ���.\n");
	scanf_s("%d", &temp); 
	
}

void StartMenu(void)
{
	while (true)
	{
		Clear();
		GotoXY(10, 9);
		printf("�� ���ϱ�");
		GotoXY(3, 20);
		printf("Ű�� �Է��Ͽ� �����Ͻÿ�.");

		if (_kbhit())
			break;
	}
}

int main()
{
	// �ܼ�â�� ������ ���� ũ�⸦ ����� ����Ѵ�.

	SetTitle("�� ���ϱ� _ ������");
	SetColor(WHITE, 0);
	SetConsoleSize(30,30);
	SetConsoleCursorVisibility(0);

	// ���� ũ�⸦ �������. �� ������ ������ �ؾ��ϳ�?
	// ĳ���� + ������
	// ĳ������ ��ġ (14,28);

	// �÷��̾��� �Ѿ� ����(Bullet)
	// GotoXY �� printf�� �̿��� �Ѿ� ����

	StartMenu();


	int score = 0;

	int x = 14, y = 28;  // �÷��̾��� x,y��ǥ
	int bx = 0, by = 0;  // �Ѿ��� x,y ��ǥ
	bool bullet = false; // ���� �Ѿ��� �������� �ʾ����� false, ���������� true
	int ex[MAX] = {0};
	int	ey[MAX] = {0};  // ���� x,y ��ǥ
	bool enemy[MAX] = { false };  // ���Ͱ� �����Ҷ� false, ������ �� true
	srand(time(NULL));
	bool IsLive = true;
	int Special = 3;
	int Life = 3;

	while (1) // ���� ����
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

				ex[i] = (rand() % 15) * 2; // rand() ���� �Լ��� seed ���� ���� �ð��� ���� ��������ִ�.
				//(rand() % 15) * 2; // rand() => 0 ~ 25947 �������� ��ȯ // 0~ 14 ��ȯ���ִ� ��                   
				ey[i] = 2;

				enemy[i] = true;
				break;
			}		
		}


#if true // �÷��̾��� �̵� ����
		if (IsLive)
		{
			if (GetAsyncKeyState(VK_LEFT) & 8001) // ����Ű�� ������ ��
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
		GotoXY(x, y); // �÷��̾ ������� �� ���� �÷��̾ ������ִ� �ڵ�
		if (IsLive)
		{
			printf("��");
			SetColor(BLACK, 13);
		}
		else
		{
			printf("��");
			break;
		}
		

#if true // �Ѿ�
		if (IsLive)
		{
			if (GetAsyncKeyState(VK_SPACE) & 8001)
			{
				if (bullet != true)  // !bullet �� bullet == false ���� �ǹ�
				{
					bx = x;
					by = y - 1;

					bullet = true;
				}

			}
		}
		if (bullet) // �Ѿ��� �����Ǿ� ���� ��쿡��
		{
			by--; // �� ĭ���� �����̰�
			GotoXY(bx, by);
			printf("��");

			if (by < 1) // �Ѿ��� ���� ���� �Ѿ�� ����
			bullet = false;
		}
#endif
		// �ϴÿ��� �������� �͵�?
		// x=1~27,y=1 ���� ���� �Ǿ���. y++ �Ǿ���. y28�Ѿ�� ����� + bullet�� ������ ������ߵɵ�?

#if false //���� �Ѱ� �� ����߸��� �ڵ�
		if (enemy != true)
		{
			srand(time(NULL));
			ex = rand() % 26 + 1; // rand() ���� �Լ��� seed ���� ���� �ð��� ���� ��������ִ�.
			   //(rand() % 15) * 2; // rand() => 0 ~ 25947 �������� ��ȯ // 0~ 14 ��ȯ���ִ� ��                   
			ey = 0; 
			
			enemy = true;
		}
		if (enemy)
		{
			ey++;
			GotoXY(ex, ey);
			printf("��");
			if (ey > 28)
				enemy = false;
		}
#endif
		
		
			for (int i = 0; i < MAX; i++)
			{
				if (enemy[i])
				{


					GotoXY(ex[i], ey[i]);
					printf("��");
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

				if (ex[i] == x && ey[i] == y) // �÷��̾ �浹
				{
					// �÷��̾ �׾��� �� �۵��ϴ� ����
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
			

		

		Sleep(100); // Sleep���� ���ڸ�ŭ ��ٷȴٰ� ����

	}

	GameOver();
}