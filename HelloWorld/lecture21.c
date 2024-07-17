/*
*  작성일 : 2024-07-17
*  작성자 : 박종현
*  학습 목표 : 메모리 공간에 대한 이해, 동적 메모리 할당, 포인터 사용
*/

/*
*  코드 영역 : CPU가 읽어 들인 파일을 실행시킨다. 명령어로 실행한다.
*  데이터 영역 : 
*  힙 영역 : 메모리를 수동으로 해제해야 하는 저장 공간
*  스택 영역 : 메모리가 자동으로 해제되는 저장 공간.
*/

// 1. 스택 영역 : 함수를 호출 call by value, 정보를 표현할 때, 기존 값은 유지한 채로 다른 결과를 표시하고 싶을 때
// 2. 힙 영역 : 배열의 크기에 대해서 고찰. 필요한 데이터 공간만큼 적저잭소로 넣으면 베스트가 된다.

// 스택, 힙 영역을 나누는 이유
// 메모리 공간이 한정적이기 때문이다.

// 오버플로우 
// 힙 오버 플로우 : 힙이 스택을 침범
// 스택 오버 플로우 : 스택이 힙을 침범

// 재귀 함수 : 함수가 자기자신을 호출하도록 한 후, 무한 반복.
// 힙 오버 플로우 예시 : malloc, free 직접 메모리 할당 및 해제. 어떤 함수를 실행할 때 마다 malloc 공간을 배정.

#include "lectures.h"

void AllocateArray(int count)
{
    int*newPtr = malloc(sizeof(int) * count);

    for (int i = 0; i < count; i++)
    {
        *(newPtr + i) = i + 1;
        printf("%d\n", newPtr[i]);
    }
    free(newPtr);
}

void lecture21()
{
    // 동적으로 메모리를 할당 하는 함수 malloc.
    // memory + allocation = malloc : 메모리 할당 함수  
    // 포인터 변수 = malloc(크기); 크기 : 메모리 공간의 크기

    int num1 = 20;
    int* numptr = &num1;
    int* const numptr2 = malloc(4);

    *numptr2 = num1;
    printf("%d\n", *numptr);

    // 동적 할당한 메모리는 반드시 해제해줘야 합니다.
    // free
    free(numptr2);

    int arr[4] = { 1,2,3,4 };
    int* numptr3 = malloc(sizeof(int) * 4); // 4 x 4 = 16
    numptr3 = arr;


    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", *(numptr3 + i));
    }
   


    printf("예제 문제\n");
    
    // 동적으로 정수형 포인터 크기를 생성하는 함수를 작성해볼 것.
    
    int* a_ptr=NULL;
    int count;
    //scanf_s("%d", &count);

    //AllocateArray(count);

    // 게임을 만들 때.. 숫자를 데이터로 사용하지만 , text를 많이 사용된다.

    char c = 69;// 69에 대응 되는 ASII문자 하나가 출력;
    char c2 = 'a';
    printf("%d\n", c2);
    printf("%c\n", c2);

    // H, e, l, l, o
    // 문자열 (string)
    char* s = "Hello";
    printf("%s\n", s);

    // 리터럴 문자열 "@@@@"
    // 컴파일시에 0x000000 주소를 반환합니다.

    char sArr[5] = { 'H','e','l','l','o' };

    for (int i = 0; i < 5; i++)
    {
        printf("%c\n", sArr[i]);
    }

    char* s2 = "Hello World";
    printf("%s \n", s2);
    
    printf("%c\n", *(s2 + 1));
    // 대문자 W를 출력 해보고
    printf("%c %d\n", *(s2 + 6), *(s2 + 6));
    // d 출력 해보기
    printf("%c %d\n", *(s2 + 10), *(s2 + 10));
    // 6번째에 있는 공백문자도 출력.
    printf("%c %d\n", *(s2 + 5), *(s2 + 5)); // 띄어쓰기가 32번 아스키 코드로 등록되어 있다.
    // d문자의 다음 요소도 출력
    printf("%c %d\n", *(s2 + 11), *(s2 + 11)); // 문자열의 마지막에는 \'0'=NULL 문자.

    // NULL문자. 문자열의 마지막을 알려주기 위한 문자.
    printf("NULL문자를 이용해서 문자열 출력하기\n");
    int index = 0;

    while (*(s2 + index) != 0) // 조건문을 종료
    {
        printf("%c" ,*(s2 + index));
        index++;
    }



}