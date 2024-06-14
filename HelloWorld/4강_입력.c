// 입력
// Scanf 함수의 실습
// 변수 미리 선언 ( 입력을 받아서 저장할 변수를 미리 선언)
// 기본 사용법 : Scanf("%d", &변수의 이름);
// Scanf_s("%d, &num);

#include <stdio.h>

int main(void)
{
    int num;
    // 주석을 보고 함수를 사용 Scanf_S
    // 여러분 입력한 숫자를 " num의 들어간 숫자 : n" 형태로 출력하는 프로그램입니다.
    printf("숫자를 입력해주세요 \n");
    scanf_s("%d", &num);
    printf("num의 들어간 숫자 : %d \n", num);
   
    // 변수의 이름 FirstNum1, FirstNum2. FirstNum3 
    // 문제 1. " 두 개의 정수를 입력 받아서 두 수의 뺼샘과 곱셈의 결과로 출력해보세요."
    
    printf("두 개의 정수를 입력해주세요.\n");

    int FirstNum1, FirstNum2;
    scanf_s("%d %d", &FirstNum1, &FirstNum2);

    printf("문제1. 두 수의 뺄셈 : %d , 두 수의 곱셈 : %d \n", FirstNum1 - FirstNum2, FirstNum1 * FirstNum2);

    // 문제 2. " 3개의 정수를 입력 받아서, SecondNum1 * SecondNum2 + SecondNum3 출력하는 코드를 작성해보세요.

    printf("3개의 정수를 입력해주세요.\n");

    int SecondNum1, SecondNum2, SecondNum3;
    scanf_s(" %d %d %d", &SecondNum1, &SecondNum2, &SecondNum3);

    printf("문제2. %d x %d + %d = %d", SecondNum1, SecondNum2, SecondNum3, SecondNum1 * SecondNum2 + SecondNum3);

    // 문제 3. " 두 개의 정수를 입력받아서 몫과 나머지를 출력하는 코드를 작성해보세요."
    // 몫을 구하는 방식

   



    return 0;
}


