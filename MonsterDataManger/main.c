#include <stdio.h>
#include <string.h>
#include "function.h"

/*
* typedef struct Monster {
* 	char name[30];
*	char region[30];
*	char garde[30];
*	int level;
* }Monster;
*/

// 1. Monster name,region,grade,level 구조체 변수를 선언해서 print 출력
// 2. 구조체 배열. 만들어 보고 반복문으로 몬스터 배열 출력
// 3. 배열에다가 구조체 배열 데이터를 넣어야한다
// 4. char name[100][30] = Monster.name



int main()
{
	int playerInput = 0;

	char monster_name[100][30];
	char monster_region[100][30];
	char monster_grand[100][30];
	int monster_level[100][30];


	Monster monsterGroup[100]; // 몬스터의 정보를 넣을 수 있는 구조체
	int totalMonsterCount = 0;   // 몬스터 데이터에 몇번 Index에 저장되었는가

	while (1)
	{
		// 1. 몬스터 데이터 추가
		// 2. 몬스터 데이터 보기
		// 3. 몬스터 데이터 찾기
		// 4. 몬스터 데이터 삭제
		// 5. 프로그램 종료
		//system("cls");
		printf("1. 몬스터 데이터 추가");
		printf("2. 몬스터 데이터 보기");
		printf("3. 몬스터 데이터 찾기");
		printf("4. 몬스터 데이터 삭제");
		printf("5. 프로그램 종료");

		scanf_s("%d", &playerInput);

		if (playerInput == 1)
		{
			AddMonsterInfo(monsterGroup, &totalMonsterCount);
		}

		if (playerInput == 2)
		{
			ShowMonsterInfo(monsterGroup, &totalMonsterCount);
		}

		if (playerInput == 3)
		{

		}

		printf("%d", totalMonsterCount);

		if (playerInput == 5) {
			break;
		}
	}


}
