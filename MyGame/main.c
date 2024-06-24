#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	// printf 함수와 scanf 함수를 사용해서 게임의 느낌을 만들어 보도록 하자.

	// 플레이어를 환영하는 텍스트를 출력해주세요.

	// prinrf(숫자를 입력하면 게임이 시작한다.) Press start Any Key 느낌
	// scanf -> 입력을 받는다... 커서가 멈춘상태로 대기하고 있다.

	// 정수 또는 실수 데이터를 만들어서 컴퓨터가 생각하는 결과를 출력하고,
	// 내가 생각하는 결과를 같이 출력하는 프로그램을 만들어 보세요.


	srand(time(NULL));
	int computerValue = rand() % 100 + 1; // 1~100 랜덤한 숫자가 computerValue에 입력이 됩니다.
	
	
	printf("★☆ 환영합니다. ☆★\n");
	printf("숫자를 입력하면 게임을 시작합니다.\n");
	int Start;
	scanf_s("%d", &Start);
	printf("게임 시작!\n");

	printf("플레이어의 값을 입력해주세요.\n");
	int userValue;
	scanf_s("%d", &userValue);
	
	printf("플레이어의 값은 %d 입니다.\n", userValue);

	// 플레이어 값과 컴퓨터의 값이 같으면 "축하합니다. 게임을 클리어 하셨습니다."

	// 플레이어의 값과 컴퓨터의 값이 다르면 "틀렸습니다. 다시 시도해보세요."

	if (userValue == computerValue)
		printf("축하합니다. 게임을 클리어 하셨습니다.");
	else if(userValue>computerValue)
	{
		printf("컴퓨터의 값이 더 작습니다.\n");
		printf("다시 시도해 보세요\n");
		
	}
	else if (userValue < computerValue)
	{
		printf("컴퓨터의 값이 더 큽니다.\n");
		printf("다시 시도해 보세요\n");
	}

	
	printf("컴퓨터의 값은 %d 입니다.\n",computerValue);

	return 0;
}