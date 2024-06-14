#include "lectures.h"

/*
  4강, 이스케이프 문자
  작성자   : 박종현
  작성일   : 2024-06-13
  학습목표 : 이스케이프  문자 사용
  */

void lecture4()
{
    int num = 500;

    printf("지금 보유한 금액 : 500원 \n");
    printf("\"지금 보유한 금액 : %d원\" \n", num);

    // 약속된 규칙으로 문자 출력을 할 수 없는 문자들이 있다.
    // 이러한 문자들을 출력하고 싶을 때 이스케이프 : "\"
    // \ + (약속된 문자) : 새로운 기능을 구현할 수 있다.
    // 종류 : \n , \a , \t , \b , \r , \\ , \? , \" , \'

    /*
      \n : 한 줄을 띄어준다, 개행 , new line
      \a : alarm, 윈도우 경보음을 출력
      \t : tab 문자 문자사이의 공간을 생성(tab) 기능.
      \b : backpace, 콘솔 커서를 한 칸 옮긴다.
      \r : return, 마우스 커서를 맨 처음으로 이동한다.
      \\,\?,\",\' : \뒤에 글자를 나오게 해준다.

    */

    printf("지금 보유한 금액 : %d원 \n", num);
    printf("\a");
    printf("Hello\b\b hi \n");
    printf("건냥하세요 \r안녕\n");
    printf("반갑\t습니다. \n");
    printf("\\ \' \" \? 에러가 발생 하나요? \n");

    // 변수를 이용한 데이터의 저장.
    // 변수를 저장하는 다양한 방법
    // (1) 변수를 선언, 선언 할당
    int num1;
    num1 = 10;
    // (2) 변수 초기화. (선언과 할당)
    int num2 = 20;
    // (3) 변수를 동시에 선언, 단 데이터 형태 같은 것만! ( , 를 사용한다)
    int num3, num4, num5;
    num3 = 10, num4 = 20, num5 = 30;
    printf("%d %d %d \n", num3, num4, num5);
    // (4) 변수를 동시에 선언과 함께 할당

    // 변수 이름 작성시 주의 사항

    // 변수의 이름의 첫 글자에 숫자가 들어가면 안된다.
    // #,$ 등 특수 기호를 이름으로 사용할 수 없다.
    // 문자 이름 사이에 띄어쓰기(공백 문자)를 할 수 없다.
    // 키워드도 이름으로 사용할 수 없다.
    // auto, enum, break, return, void, float, short, while 등

    // 변수에 이름을 잘 지을 것을 생각을 해야한다.


// 입력
// Scanf 함수의 실습
// 변수 미리 선언 ( 입력을 받아서 저장할 변수를 미리 선언)
// 기본 사용법 : Scanf("%d", &변수의 이름);
// Scanf_s("%d, &num);


    int number;
    // 주석을 보고 함수를 사용 Scanf_S
    // 여러분 입력한 숫자를 " num의 들어간 숫자 : n" 형태로 출력하는 프로그램입니다.
    printf("숫자를 입력해주세요 \n");
    scanf_s("%d", &number);
    printf("num의 들어간 숫자 : %d \n", number);

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
    printf("문제3 \n");
    int third1, third2, third3;
    scanf_s(" %d %d %d", &third1, &third2, &third3);




    return 0;
}
