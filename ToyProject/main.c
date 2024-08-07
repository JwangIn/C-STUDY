#include <stdio.h>
#include "Console.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50 // ���� 
#define COLS 30 // ���� 
#define filename "Record.txt"

int map[COLS][ROWS] = { 0 };
char mapString[(COLS * (ROWS + 1)) + 1];
int floor = 0;


typedef struct Postion
{
	int x;
	int y;
	bool live;
}Postion;

typedef enum MonsterNum
{
	One,Two,Three,Four,Five,Six,Seven,Eight,Nine
}MonsterNum;

typedef enum Direction
{
	Up, Right, Down, Left
}Direction;

typedef enum BulletBe
{
	Not,Fire
}BulletBe;

typedef struct Monster {
	int x;
	int y;
	Direction direction;
	bool live;
}Monster;

typedef struct Bullet
{
	int x;
	int y;
	BulletBe bullet;
}Bullet;

typedef struct PlayerData
{
	char name[30];  // �̸��� �����ϱ� ���� �迭
	int score;      // ���� ���·� ������ �����Ѵ�.
}PlayerData;

void ShowGameRecord(PlayerData* player, int* totalCount)
{

	FILE* fp = fopen(filename, "r");

	if (fp == NULL) {
		perror("Load Error! \n");
		return;
	}

	int count = 0;
	char ch;

	if (fgetc(fp) != EOF)
	{
		count = 1;
	}

	fseek(fp, 0, SEEK_SET); // fp�� ����Ű�� �ּҸ� ������ �������� �̵�

	while (fgetc(fp) != EOF)
	{
		ch = fgetc(fp);
		if (ch == '\n') {
			count++;
		}
	}

	fseek(fp, 0, SEEK_SET);
	*totalCount = count;

	for (int i = 0; i < count; ++i)
	{
		fscanf_s(fp, "%s %d", (player + i)->name, 30, &(player + i)->score);
	}


	fclose(fp);
}

void SaveGameRecord(PlayerData* player, int totalCount)
{
	FILE* fp = fopen(filename, "w");

	if (fp == NULL) {
		perror("Write Error! \n");
	}


	for (int i = 0; i < totalCount; ++i) {

		fprintf(fp, "%s %d \n", player[i].name, player[i].score);
	}


	fclose(fp);

}


void StartMenu(int y)
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
			y += 5;
			if(y > 23)y = 23;
		}
		else if (GetAsyncKeyState(VK_UP) & 8001)
		{
			y -= 5;
			if (y < 13)y = 13;
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

void MakeMap(int(*map)[ROWS]) // map -> 30 * 30
{
	for (int i = 0; i < COLS; ++i)
	{
		for (int j = 0; j < ROWS; ++j)
		{
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < COLS; ++i) // ' ' => 32 '#' => 35
	{
		map[i][0] = 1;
		map[i][ROWS - 1] = 1;

	}
	for (int j = 0; j < ROWS; ++j)
	{
		map[0][j] = 1;
		map[COLS - 1][j] = 1;
	}

}

void RenderMap(char Wall)  // ������� ���� �׸��� �Լ�
{
	int mapIndex = 0;

	for (int i = 0; i < COLS; ++i)
	{
		for (int j = 0; j < ROWS; ++j)
		{
			if(map[i][j]==0)
				mapString[mapIndex] = ' ';
			else if (map[i][j] == 1)
				mapString[mapIndex] = Wall;

			mapIndex++;                         // ++ ���� �����ڶ� ����� ������ +��
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




void Monster1(Monster* monster) // �� ����ٴϸ鼭 �÷��̾����� �Ѿ�
{
	if (monster->live != true && monster->live != false)
	{
		monster->live = true;
	}
	if (monster->live == true)
	{
		GoToTargetPos(monster->x, monster->y, "o");

		int dx[4] = { 0, 1, 0, -1 }; // �� ������ �Ʒ� ����
		int dy[4] = { -1, 0, 1, 0 };

		if (map[monster->y + dy[monster->direction]][monster->x + dx[monster->direction]] == 1)
			(monster->direction)++;

		if ((monster->direction) > 3)
			monster->direction = 0;


		monster->x = monster->x + dx[monster->direction];
		monster->y = monster->y + dy[monster->direction];
	}
}

void monsterfire(Monster* monster,Bullet* monsterbullet)
{
	if (monsterbullet->bullet != Not && monsterbullet->bullet != Fire)
	{
		monsterbullet->bullet = Not;
	}
	if (monsterbullet->bullet==Not)
	{
		monsterbullet->x = monster->x;
		monsterbullet->y = monster->y;
		;
		monsterbullet->bullet = Fire;

	}
	if (monsterbullet->bullet == Fire)
	{ 
		if (monster->direction == Up)
		{
			(monsterbullet->x)++;
			monsterbullet->y;
			GoToTargetPos(monsterbullet->x, monsterbullet->y, "*");
		}
		else if (monster->direction == Right)
		{
			monsterbullet->x;
			(monsterbullet->y)++;
			GoToTargetPos(monsterbullet->x, monsterbullet->y, "*");
		}
		else if (monster->direction == Down)
		{
			(monsterbullet->x)--;
			monsterbullet->y;
			GoToTargetPos(monsterbullet->x, monsterbullet->y, "*");
		}
		else if (monster->direction == Left)
		{
			monsterbullet->x;
			(monsterbullet->y)--;
			GoToTargetPos(monsterbullet->x, monsterbullet->y, "*");
		}
	
		if (monsterbullet->x < 1 || monsterbullet->x>49||monsterbullet->y<1||monsterbullet->y>28)
		{
			monsterbullet->bullet = Not;
		}
		
	}
	
}

int xx, yy;

void playerattack(Postion* player,Bullet* playerbullet)
{

	if(playerbullet->bullet==Not)
	{
		if (GetAsyncKeyState(VK_UP)  && GetAsyncKeyState(VK_CONTROL) & 8001 )
		{
			playerbullet->x = player->x;
			playerbullet->y = (player->y) -2;
			xx = player->x;
			yy = player->y;
			playerbullet->bullet = Fire;
		}
		else if (GetAsyncKeyState(VK_DOWN) && GetAsyncKeyState(VK_CONTROL) & 8001)
		{
			playerbullet->x = player->x;
			playerbullet->y = (player->y)+2;
			xx = player->x;
			yy = player->y;
			playerbullet->bullet = Fire;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_CONTROL) & 8001)
		{
			playerbullet->x = (player->x)+2;
			playerbullet->y = player->y;
			xx = player->x;
			yy = player->y;
			playerbullet->bullet = Fire;
		}
		else if (GetAsyncKeyState(VK_LEFT) && GetAsyncKeyState(VK_CONTROL) & 8001)
		{
			playerbullet->x = (player->x)-2;
			playerbullet->y = player->y;
			xx = player->x;
			yy = player->y;
			playerbullet->bullet = Fire;
		}
	}


	if (playerbullet->bullet == Fire)
	{
		
		if (playerbullet->x  > xx && playerbullet->y == yy) // �Ѿ��� �÷��̾� ������
		{
			GoToTargetPos(playerbullet->x, playerbullet->y, "x");
			(playerbullet->x)++;

		}
		else if (playerbullet->x <xx && playerbullet->y == yy) // �Ѿ��� �÷��̾� ����
		{
			GoToTargetPos(playerbullet->x, playerbullet->y, "x");
			(playerbullet->x)--;
		}
		else if (playerbullet->y > yy && playerbullet->x == xx) // �Ѿ��� �÷��̾�� �Ʒ��� �ִ�
		{
			GoToTargetPos(playerbullet->x, playerbullet->y, "x");
			(playerbullet->y)++;
		}
		else if (playerbullet->y < yy && playerbullet->x == xx) // �Ѿ��� �÷��̾�� �۴�. �Ѿ��� �÷��̾�� �����ִ�
		{
			GoToTargetPos(playerbullet->x, playerbullet->y, "x");
			(playerbullet->y)--;
		}
		
	}
	

	if (playerbullet->x < 1 || playerbullet->x>49 || playerbullet->y < 1 || playerbullet->y>28)
	{
		playerbullet->x = 0;
		playerbullet->y = 0;
		playerbullet->bullet = Not;
	}


}

void InputProcess(Postion* player) // x 1 ~ 48 y 1 ~ 29
{
	if (GetAsyncKeyState(VK_LEFT) & 8001) // ����Ű�� ������ ��
	{
		if (player->x < 0) player->x = 0;
		// x�� �������� ������ map�� ���� 0�̸� �������� 
		// map[][]�� 0,1�ۿ� ����
		if( map[player->y][player->x - 1]==0)
		player->x = player->x - 1;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 8001)
	{
		if (player->x > 49) player->x = 49;
		if ( map[player->y][player->x + 1] == 0)
		player->x = player->x + 1;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 8001)
	{
		if (player->y > 29) player->y = 29;
		if (map[player->y + 1][player->x] == 0)
		(player->y)++;
	}
	else if (GetAsyncKeyState(VK_UP) & 8001)
	{
		if (player->y < 0)player->y = 0;
		if (map[player->y -1][player->x] == 0)
		(player->y)--;
	}

}

void PlayerDead(Bullet* bullet,Postion* player,Monster* monster)
{
	if (bullet->bullet == Fire)
	{
		if (player->x == bullet->x && player->y==bullet->y)
		{
			player->live = false;
			GoToTargetPos(15, 18, " �׾����ϴ�.");
		}
	}
	if (monster->x == player->x && monster->y == player->y)
	{
		player->live = false;
		GoToTargetPos(15, 18, " �׾����ϴ�.");
	}
	
}

void MonsterDead(Bullet* bullet, Monster* monster)
{
	if (bullet->bullet == Fire)
	{
		if (monster->x == bullet->x && monster->y == bullet->y)
		{
			bullet->x = 0;
			bullet->y = 0;
			
			monster->live = false;
		}
	}
}

void MonsterRevive(Monster* monster, int* revivecount)
{
	
	if (monster->live == false)
	{
		(*revivecount)--;
	}
	if (*revivecount == 0)
	{
		monster->live= true;
		floor++;
		*revivecount = 50;
		
	}

}



int main()
{
	SetConsoleSize(50, 50);
	SetConsoleCursorVisibility(0);

	Postion player={15,15};
	Bullet playerbullet;
	playerbullet.bullet = Not;
	player.live = true;

	Monster m1;
	Bullet MonsterBullet ;
	
	m1.x = 4;
	m1.y = 4;
	m1.direction = 0; // 0 ~ 3 ����

	Monster monster[10];
	Bullet monsterbullet[10];


	int StartX = 15, StartY = 18;

	StartMenu(StartY); 

	MakeMap(map);
	
	RenderMap('#');
	int revivecount = 50;

	while (1)
	{
		Clear;

		GoToTargetPos(0, 0, mapString);

		GoToTargetPos(player.x, player.y, "@");
		


		if (player.live==true)
		{
			InputProcess(&player);
			playerattack(&player, &playerbullet);
		}
		
		Monster1(&m1);
		monsterfire(&m1, &MonsterBullet);
		
		MonsterRevive(&m1, &revivecount);
		MonsterDead(&playerbullet, &m1);
		

		PlayerDead(&MonsterBullet, &player, &m1);
		if (player.live == false)
		{
			Clear;
			GoToTargetPos(15, 18, " �׾����ϴ�.");
			break;
		}

		GoToTargetPos(0, 32, "���� ��Ȱ���� :");
		printf("%d", revivecount);
		GoToTargetPos(0, 33, "���� ���� : ");
		printf("%d", floor);

		Sleep(100);
	}





	/*
		*  1. ���� ��ȯ (�����ϸ� ��������)
		*  2. ���� óġ �� ���� ���� (x���� ���� �����)
		*  3. x�� �ݺ� �� ����
		*  4. ���� ���� �� ���� ���� ����
		*  5. 1~4�� �ݺ�
		*  6. �������� �����Ѱ� ǥ�� �� ���� �ε尡�� �ϰ�
		*/

	// ���� ����ü �迭�� monster.live ��ΰ� �׾����� revie�� ����


}