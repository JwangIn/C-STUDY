#include <stdio.h> // printf, scanf �Լ��� ����ϱ� ���ؼ� �ʿ��ϴ�. //�ý��� ������ ��������� �ҷ��´�.
#include "Console.h" // ������Ʈ �ȿ� ""�ȿ� �ִ� ������ ã�Ƽ� �����ض�
#include <stdbool.h>
// main�Լ����� ����� �� �ְ� Ű���带 �ۼ����ּ���.


int main()
{
	// �ܼ�â�� ������ ���� ũ�⸦ ����� ����Ѵ�.

	SetConsoleSize(30,30);
	SetConsoleCursorVisibility(0);

	// ���� ũ�⸦ �������. �� ������ ������ �ؾ��ϳ�?
	// ĳ���� + ������
	// ĳ������ ��ġ (14,28);

	// �÷��̾��� �Ѿ� ����(Bullet)
	// GotoXY �� printf�� �̿��� �Ѿ� ����

	int x = 14, y = 28;  // �÷��̾��� x,y��ǥ
	int bx = 0, by = 0;  // �Ѿ��� x,y ��ǥ
	bool bullet = false; // ���� �Ѿ��� �������� �ʾ����� false, ���������� true

	while (1) // ���� ����
	{
		Clear();

#if true // �÷��̾��� �̵� ����
		if (GetAsyncKeyState(VK_LEFT) & 8001) // ����Ű�� ������ ��
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
		printf("��");

#if true // �Ѿ�
		if (GetAsyncKeyState(VK_SPACE) & 8001)
		{
			if (bullet != true)  // !bullet �� bullet == false ���� �ǹ�
			{
				bx = x;
				by = y - 1;

				bullet = true;
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


		Sleep(50); // Sleep���� ���ڸ�ŭ ��ٷȴٰ� ����

	}
}