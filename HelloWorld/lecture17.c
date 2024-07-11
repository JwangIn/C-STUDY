/*
*  작성일 : 2024-07-11
*  작성자 : 박종현
*  학습목표 : 포인터에 대한 이해
*/

// 포인터의 선언 
// (데이터타입) * 이름;

// 포인터가 뭔가?
// 포인터 변수. 변하는 값(주소)을 저장.

// 메모리를 구하는 연산자 : 주소연산자 &
// 사용법 : 변수를 먼저 선언. &num
// 의미 : num이 가지고 있는 주소를 반환하라.

// 주소를 16진수 8개 ~ 16개 비트 공간을 사용해서 메모라 주소 표현.
// 주소를 표현핳 뎨 {16진수 4비트}
// 0xABCE0202 <- 주소. 32비트
// 0x 00000000 ABCE0202 <- 64비트

// 메모리의 주소 저장
// int* numPointer (줄인말 numPtr) 변수의 이름
// 포인터 변수를 선언하는 것.

// 포인터를 왜 써야하는가?

#include "lectures.h"

void lecture17()
{
    int num; // 변수의 선언

    printf("숫자를 입력해 주세요.\n");
    scanf_s("%d", &num);
    printf("num의 값 출력 : %d\n", num);
 
    // 포인터에 대해소 익숙해지자.
    int* numPtr = &num; // int* numPtr 포인터변수 선언과 초기화

    // 예제 문제
    int * numPtr2=&num;
    int *numPtr3=& num;

    printf("%p\n", numPtr);
    printf("%p\n", numPtr2);
    printf("%p\n", numPtr3);

    printf("%d\n", *numPtr);
    printf("%d\n", *numPtr2);
    printf("%d\n", *numPtr3);
    // 포인터를 사용해서 출력 : 16진수 주소가 출력된다.

    // 주소에 저장된 값을 출력하는 방법.
    // 역참조 연산자
    // '*' 이항연산자 : 곱하기
    // 단항연산자 : 이미 선언된 포인터 변수 앞에 *numPtr
    // numPtr 가리키고 있는 값을 참조한다.
    // intsum = 2 * 4;

    // 실습> 정수 int number20을 할당해주세요. 정수형 포인터 변수 number 선언하고 , number에있는 주소를 할당해주세요.
    // pritnf를 사용해서 numberPtr에 있는 값을 출력해보시면 됩니다.(*연산자 사용해주세요.)

    // 변수 -> 값 + 주소.

    // 0. 변수 선언 및 초기화
    int number = 20; // number이름 20 값. number 주소
    // 1. 포인터 변수를 선언하는 방법 : int*
    // 2. 변수의 주소를 반환하는 연산자 주소 연산자&
    int* numberPtr = &number;
    
    // 포잍너 변수
    // 포인터 변수의 값 : 주소, 주소가 가르키고 있는 데이터(참조)
    printf("numberPtr 주소 : %p\n", numberPtr);
    // 3. 포인터 변수가 가리키고 있는  참조를 반환하는 연산자 *
    printf("numberPtr의 참조 값 : %d\n", *numberPtr);

    // 포인터 주소가 참조하고
    // 주소를 이용해서 값을 변경하는 작업에 익숙해저야한다.
    printf("기존 number의 값 : %d\n ", number);
    *numberPtr = 30;
    printf("number의 값 : %d\n ", number);

    // 한번 더 정리
    // 1. 변수 num1 = 10;    변수의 특징 : 메모리 주소를 몰라도 값을 가져오거나 저장할 수 있다.
    // 2. 주소 연산자& : 변수의 메모리 주소를 구하는 녀석. &num1 : 변수로 부터 주소를 구할 수 있다.0xABCD;
    // 3. 역참조 연산자* : 포인터 변수가 참조하고 있는(메모리 상에 가리키고) 값에 접근할 수 있다.
    
    // int * numPtr : 포인터 변수 선언
    // *numPtr      : 포인터 변수의 참조 값을 호출, numPtr이 포인터 변수다.
    // *numPtr = 30;  포인터 가리키고 있는 참조의 값을 변경한다. 포인터가 가리키고 있는 변수의 값이 변한다.

    // 포인터 연습 문제

    int a_num = 10;
    int* a_numPtr = &a_num;
    int* b_numPtr = a_numPtr;

    (*a_numPtr)++; 
    (*b_numPtr)++;
    printf("%d\n", a_num);

    // 예제 문제 ( A와 B를 선언 후 숫자를 할당하고 포인터를 사용하여 A와 B에 들어간 숫자를 바꿔 출력되게하기) 
    // e_num1, e_num2 선언해서 10, 20 할당해주세요.
    // e_num1, e_num2를 가리키는 포인터 e_num1Ptr, e_num2Ptr 를 선언 후 대입헤주세요.
    // int* temp 포인터 하나를 선언 하고
    // temp에 e_numPtr 대입, e_num2에 -> e_num1 , e_num2 temp 값 받아오기.
    // Swap 구현
    int e_num1 = 10,e_num2 = 20;
    int* e_num1Ptr = &e_num1;
    int* e_num2Ptr = &e_num2;

    printf("%d %d \n", *e_num1Ptr, *e_num2Ptr);

    int* temp = e_num1Ptr;

    e_num1Ptr = e_num2Ptr;
    e_num2Ptr = temp;

    printf("%d %d \n", *e_num1Ptr, *e_num2Ptr);




}