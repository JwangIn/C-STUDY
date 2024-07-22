


#include "lectures.h"

void ChangeDoubleArrValue(int(*tPArr)[4],int addValue)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            tPArr[i][j] += addValue;
        }
    }
}
// char 방식으로 tPArr의 값을 변경하는 함수를 작성해보세요.

void ChangecharValueInDoubleArr(char(*tPArr)[4],char InputChar)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            tPArr[i][j] = InputChar;
        }
    }
}

void lecture23()
{
    // 변수의 선언 
    int num = 10;

    // 포인터 선언
    int* numPtr = &num;

    // 포인터의 포인터
    int** numpPtr = &numPtr;

    printf("변수 : %d, 포인터로부터 값 호출 : %d, 포인터의 포인터 값 호출 : %d\n", num, *numPtr, **numpPtr);

    int arr[3] = { 1,2,3 };

    int* aPtr = arr;

    for (int i = 0; i < 3; i++)
    {
        printf("arr 배열의 값 : %d \n", *(aPtr + i));
        printf("arr[i} 값 출력 : %d \n", aPtr[i]);
    }

    // 2차원 배열

    int arr2[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };

    // 배열의 주소를 가져오는 법
    // int* arrparr[3] = &arr;
    // int(*parr)[3] = &arr;

    // int** doublePtr = &arr2;

    // 2차원 배열을 포인터에 넣기
    // int (*포인터 이름)[가로 크기]; // 가로크기가 n인 배열을 가르키는 포인터.

    int(*parr2)[4] = arr2;
    int** doublePtr = arr2;

    printf("arr2 의 주소 : %p\n", arr2);
    printf("parr2의 주소 : %p\n", parr2);
    printf("doublePtr의 주소 : %p\n", doublePtr);

    // 포인터 변수의 크기로 확인을 해보자
    printf("arr2의 크기 : %d\n", sizeof(arr2));
    printf("parr2의 크기 : %d\n", sizeof(parr2));
    printf("doublePtr의 크기 : %d\n", sizeof(doublePtr));

    // 2차원 배열에서 배열을 포인터로 표시헤본다.
    int arr3[3][4] = { 0 };

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            printf("arr3의 값 : %d\n", arr3[i][j]);
        }
    }

    ChangeDoubleArrValue(arr3, 1);
    for (int i = 0; i < 3; ++i)
       {
            for (int j = 0; j < 4; ++j)
            {
                printf("arr3의 값 : %d\n", arr3[i][j]);
            }
        }
   

    

    // arr[x][y]== (*(arr + x))[y] ==  *(*(arr3+x)+y) // A 치환한다. : *(arr + x) //  A*(arr + x) A[Y] // A[y] // A다시 치환한 값을 넣는다.

    // 2차원 배열을 포인터로 표시하고 값으로 출력하기

    printf("2차원 배열의 값 : %d\n", arr2[1][2]);
    printf("2차원 배열을 포인터로 표시한 값 :  %d \n", *(*(arr2 + 1) + 2));

    printf("2차원 배열에서 세로의 크기의 주소를 출력 : %p\n", (*(arr2 + 1)));
    printf("2차원 ... 세로의 크기가 1이고, 거기서 int크기만큼 +2한 주소 : %p \n", (*(arr2 + 1) + 2));

    // int arr[3][4]에서
    // arr[i]의 의미 : 크기가 4인 int 배열의 3개 있는데. 그 중에서 i번째 배열을 가리켜라.
    // doublePtr : 주소의 주소를 arr[3][4] 표시만 가능하지, 2차원 배열은 표현할 수 없다.
    // 이차원 배열 : int (*arr[세로크기])[가로크기];
    // 포인터의 배열 : int* arr[크기] : 의미... 정수형 포인터의 배열

    // 정리 
    // 2차원 배열을 포인터로 표현하기 위해서는 , 반드시 배열의 갯수를 명시해줘야한다.
    // 데이터타입 (* 포인터 변수이름)(변수크기)


    // ChangecharValueInDoubleArr 함수를 호출해서, 안에 있는 값을 #,$ 등으로 변하는 함수를 작성

    char map[3][4] = { 0 };

    ChangecharValueInDoubleArr(map, '#');
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            printf("map의 값 : %c\n", map[i][j]);
        }
    }

}