#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, number, attempts = 0;

    // �õ�(seed) ������ ���� ���� �ð��� ���
    srand(time(NULL));

    // 1���� 100 ������ ������ ���� ����
    number = rand() % 100 + 1;

    printf("1���� 100 ������ ���ڸ� ���纸����.\n\n");

    do {
        printf("������ ���ڸ� �Է��ϼ���: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("�� ���� ���ڸ� �Է��ϼ���.\n");
        }
        else if (guess < number) {
            printf("�� ū ���ڸ� �Է��ϼ���.\n");
        }
        else {
            printf("�����մϴ�! %d��° �õ��� ���ڸ� ���߼̽��ϴ�!\n", attempts);
        }
    } while (guess != number);

    return 0;
}