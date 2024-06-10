#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, number, attempts = 0;

    // 시드(seed) 설정을 위해 현재 시간을 사용
    srand(time(NULL));

    // 1부터 100 사이의 임의의 숫자 생성
    number = rand() % 100 + 1;

    printf("1부터 100 사이의 숫자를 맞춰보세요.\n\n");

    do {
        printf("추측한 숫자를 입력하세요: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("더 작은 숫자를 입력하세요.\n");
        }
        else if (guess < number) {
            printf("더 큰 숫자를 입력하세요.\n");
        }
        else {
            printf("축하합니다! %d번째 시도에 숫자를 맞추셨습니다!\n", attempts);
        }
    } while (guess != number);

    return 0;
}