#include <stdio.h>
#include "Console.h"
#include <stdbool.h>
#include <stdlib.h>


#define ROWS 50 // 가로 
#define COLS 30 // 세로 


int map[COLS][ROWS] = { 0 };
char mapString[(COLS * (ROWS + 1)) + 1];

typedef struct Postion
{
	int x;
	int y;
	bool live;
}Postion;


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



void ShowGameRecord()
{

}


void StartMenu(int y)
{
	
	while (true)
	{
		Clear();
		GotoXY(11, 5);
		printf("방향키와 Ctrl을 눌러 조작합니다.");
		GotoXY(18, 13);
		printf("1 . 게 임 시 작");
		GotoXY(18, 18);
		printf("2 . 기 록 확 인");
		GotoXY(18, 23);
		printf("3 . 종 료 ");

		
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

void RenderMap(char Wall)  // 만들어진 맵을 그리는 함수
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

			mapIndex++;                         // ++ 후위 연산자라 계산이 끝나면 +함
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




void Monster1(Monster* monster) // 벽 따라다니면서 플레이어한테 총알
{
	GoToTargetPos(monster->x, monster->y, "o");

	int dx[4] = { 0, 1, 0, -1 }; // 위 오른쪽 아래 왼쪽
	int dy[4] = { -1, 0, 1, 0 };

	if (map[monster->y + dy[monster->direction]][monster->x + dx[monster->direction]] == 1)
		(monster->direction)++;

	if ((monster->direction) > 3)
		monster->direction = 0;


	monster->x = monster->x + dx[monster->direction];
	monster->y = monster->y + dy[monster->direction];

}

void monsterfire(Monster* monster,Bullet* monsterbullet)
{
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
		if (playerbullet->x  > xx && playerbullet->y == yy) // 총알이 플레이어 오른쪽
		{
			GoToTargetPos(playerbullet->x, playerbullet->y, "x");
			(playerbullet->x)++;
		}
		else if (playerbullet->x <xx && playerbullet->y == yy) // 총알이 플레이어 왼쪽
		{
			GoToTargetPos(playerbullet->x, playerbullet->y, "x");
			(playerbullet->x)--;
		}
		else if (playerbullet->y > yy && playerbullet->x == xx) // 총알이 플레이어보다 아래에 있다
		{
			GoToTargetPos(playerbullet->x, playerbullet->y, "x");
			(playerbullet->y)++;
		}
		else if (playerbullet->y < yy && playerbullet->x == xx) // 총알이 플레이어보다 작다. 총알이 플레이어보다 위에있다
		{
			GoToTargetPos(playerbullet->x, playerbullet->y, "x");
			(playerbullet->y)--;
		}

	}

	if (playerbullet->x < 1 || playerbullet->x>49 || playerbullet->y < 1 || playerbullet->y>28)
	{
		playerbullet->bullet = Not;
	}


}

void InputProcess(Postion* player) // x 1 ~ 48 y 1 ~ 29
{
	if (GetAsyncKeyState(VK_LEFT) & 8001) // 왼쪽키를 눌렀을 때
	{
		if (player->x < 0) player->x = 0;
		// x가 왼쪽으로 갔을때 map의 값이 0이면 움직여라 
		// map[][]는 0,1밖에 없음
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
		if (map[player->y +1][player->x] == 0)
		(player->y)--;
	}

}

void PlayerDead(Bullet* bullet,Postion* player)
{
	if (bullet->bullet == Fire)
	{
		if (player->x == bullet->x && player->y==bullet->y)
		{
			player->live = false;
			GoToTargetPos(15, 18, " 죽었습니다.");
			exit(1);
		}
	}
}

void MonsterDead(Bullet* bullet, Monster* monster)
{
	if (bullet->bullet == Fire)
	{
		if (monster->x == bullet->x && monster->y == bullet->y)
		{
			monster->live = false;
		}
	}
}

void MonsterRevive(Monster* monster, int revivecount)
{
	if (monster->live == false)
	{
		revivecount++;
	}
	if (revivecount++ == 150)
	{
		monster->live= true;
		revivecount = 0;
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

	Monster m1 = { 4,4,0 };
	Bullet MonsterBullet ;
	MonsterBullet.bullet = Not;
	m1.live = true;

	int StartX = 15, StartY = 18;

	StartMenu(StartY); 

	MakeMap(map);
	
	RenderMap('#');
	int mx = 3, my = 4;

	int revivecount = 0;

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
		
		if(m1.live==true)
		{ 
			Monster1(&m1);
			monsterfire(&m1, &MonsterBullet);
		}
		


		Sleep(100);
	}





	/*
		*  1. 몬스터 소환 (가능하면 랜덤으로)
		*  2. 몬스터 처치 시 상점 등장 (x초후 몬스터 재등장)
		*  3. x번 반복 후 보스
		*  4. 몬스터 등장 수 증가 상점 증가
		*  5. 1~4를 반복
		*  6. 스테이지 증가한거 표시 및 저장 로드가능 하게
		*/



}