/*
*  작성일 : 2024-07-12
*  장성자 : 박종현
*  학습목표 : 
*/

#include "lectures.h"

void lecture18()
{
    // num변수 10. 정수형 포인터 numPtr
    // num - numPtr 연결. numPtr num에 들어간 값을 1증가 시켜 출력

    int num=10;
    int* numPtr = &num; // 주소룰 초기화
    (*numPtr)++;        // 역참조연산자 : 주소가 가르키는 값을 반환
    printf("num의 값 : %d\n", num);

    // *(numPtr) <- 에러가 나온다


    // 16진수로 포인터 변수에 값을 넣어서 주소의 값을 지정.
    int* numptrA=0x100000;
    int* numptrB= 0x100000;

    numptrA = numptrA + 1;// numptr++
    numptrB = numptrB + 2;

    printf("ptrA 의 값 : %p\n", numptrA);
    printf("ptrB 의 값 : %p\n", numptrB);

    // 주소의 크기를 구해보자
    printf("포인터 변수의 크기 : %d\n", sizeof(numptrA)); // x86 : 4
    printf("포인터 변수의 크기 : %d\n", sizeof(numptrB)); // x64 : 8

    // 포인터 변수의 크기가 다른 이유
    // 주소를 저장하는 변수. 크기를 가집니다.
    // 16진수 1개의 바이트 공간. 8개 - 4비트 x 8 = 32비트
    // x86 : 왜 32비트? Intel 에서 만든 개인컴퓨터가 86이라 32비트 = x86

    // 4바이트 - 정수, 주소는 공간의 첫번쨰 바이트에 저장. 시작부터 크기까지 공간을 확보해서 저장

    // 포인터와 배열
    // int 형 데이터 타입 int num1, num2, num3, num4 ....;
    // 배열을 어떻게 사용할 수 있는가?

    int numArr[5] = { 11,22,33,44,55 };

    int index = 0;

    // numArr 33의 값을 출력해주는 코드를 printf 작성해보세요.
    printf("numArr 3번재 요소 출력 : %d\n", numArr[index + 2]); // 배열의 시작은 0부터

    // index의 값에 더하기 또는 뺴기 연산자를 사용해서 numArr을 반복문으로 출력해보세요.


    printf("numArr 역방향 출력:");
    for (int i = 4; i >= 0; i--)
    {
        printf("%d ", numArr[i]);
    }

    // 배열의 index가 배열이 가지고 있는 값을 가리키고있다.
    // 배열을 포인터로 바꿀 수 있지 않을까?

    printf("\n");
    int arr1[3] = { 0,1,2 };
    printf("배열의 이름 : %p\n", arr1);

    for (int i = 0; i < 3; i++)
    {
        printf("배열의 요소 %d 요소 %p\n", i, &arr1[i]);
    }

    // 정리
    // 베열의 첫번째 요소의 값의 주소를 반환을 했더니
    // 그 결과 값이 배열의 이름의 주소와 같다.
    // 배열의 이름은 포인터였습니다.

    // 배열에서 포인터 연산자. &, *;

    // 정리.
    // int 포인터 변수 +1 : 주고의 값이 4만큼 크기가 커젔습니다.

    char* charPtr = 0x100000;  // 1바이트
    charPtr++;
    printf("%p\n", charPtr); 
    short* shortPtr = 0x100000;  // 2바이트
    shortPtr++;
    printf("%p\n", shortPtr);

    // 포인터 연산의 공식 
    // sizeof(char)* : 데이터의 크기
    charPtr += 10; // 0x100000 + 10(1x10);
    shortPtr += 10;  // 0x100000 + 20(2x10);

    // int포인터 10만큼 증가 4x10
    // 포인터의 연산은 sizeof(데이터형) x n(더해준 수) zmrlrk wmdrkgksek


    int arr2[3] = { 0,1,2 };
    // 배열도 포인터, 포인터 변수 선언 배열을 연결.
    int* s_ptr = arr2;
    int* s_ptr2 = &arr2[0];

    &arr2[0]; // 주소 arr2 배열 1번째 주소
    &arr2[1]; // 2번째 주소
    &arr2[2]; // 3번째 주소

    printf("주소의 연산 후 역참조 : %d\n",*(s_ptr+1)); // s_ptr 포인터 변수. s_ptr가리크고 있는 주소 4를 증가 시켰다.

    printf("역참조 후 값을 덧셈 : %d\n", (*s_ptr)++);

    //printf("주소의 연산 후 역참조 : %d\n", *(s_ptr++)); // s_ptr 포인터 변수. s_ptr가리크고 있는 주소 4를 증가 시켰다.

    // 예제 문제

    // 길이가 5인 배열 선언. firstArr (1,2,3,4,5)
    // firstArr이름을 firstArrPtr 포인터 변수에 넣고
    // firstArrptr 연산을 이용해서 해당 주소의 값을 3을 증가시키기
    // 반복문을 사용해서 1 -> 4, 2 -> 5...

    
      
    int firstArr[5] = { 1, 2, 3, 4, 5, };
        
    int* firstArrPtr = firstArr;  // 배열 자체가 주소를 가리킨다(배열 자체가 포인터) 
    
    // 포인터 덧셈(연산)
    // sizeof(type) +1 다음 배열 요소를 가리킨다.
    // firstArr[i] +=3; i+1; <- 포인터 변수로 표현

    for (int i = 0; i < 5; i++)
    {
        *firstArrPtr += 3;     // firstarr[i] +=3;
        firstArrPtr++;         // i+1
    }
    for (int i = 0; i < 5; i++)
    {
        printf("배열의 요소에 3을 증가시킨 값 : %d\n", firstArr[i]);
    }
    // 정리 
    // *(ptr)++;  의미 : 포인터가 가리키고 있는 참조값 반환 그 값에 1을 더해라. num = 10, 1을 더해서 11이 반환된다.
    // *(ptr +1); 의미 : 포인터가 가리키고있는 주소 type 크기를 더해서, 현재 가리키고 있는 주소를 변형시킨다.

    // 배열은 포인터. 완벽하게 같나?

    int exArr[5] = { 0 };
    int* arrPtr2 = exArr;
    printf("배열의 크기 : %d\n", sizeof(exArr));
    printf("포인터의 크기 : %d\n", sizeof(arrPtr2));

    // c언어 -> 최대한 메모리를 아껴 쓰자
    // arr[1000] -> 4 x 1000; 8



    // 예제 문제2. 포인터 연산의 뺄셈을 사용해서 배열의 큰 수부터 작은 수를 출력 하도록

    int secondArr[5] = { 1,2,3,4,5 }; // 정수형 배열 5개를 선언 및 초기화
    int* secondArrPtr = secondArr;    // 포인터(주소를 저장하는 변수) 배열의 이름 자체가 포인터, &secondArr : 주소의 주소
    secondArrPtr += 4;                // 포인터 변수 +5 : sizeof(int) * n 
    
    for (int i = 0;i < 5;i++)
    {
        printf("%d \n", *secondArrPtr);  // 값을 변경햇서 저장을 해도되겠습니다.
        secondArrPtr--;
    }
    


    // 정리 
    // 변수 - 값, 주소
    // &주소연산자, 포인터 int *
    // 포인터 변수 역참조연산자 * 포인터변수
    // 포인터 변수 ++
    // 16진수 0x1000; +1 sizeof(short)
    // 배열의 이름 __ 포인터 변수

    // 정리(2)

    int o_Arr[3] = { 1,2,3 };
    int* o_ArrPtr = o_Arr;

    for (int i = 0; i < 3;i++)
    {
        printf(" *(Ptr + i) : %d ", *(o_ArrPtr + i));
        printf(" *(arr + i) : %d", *(o_Arr + i));
        printf(" arr[i] : %d", o_Arr[0 + i]);
        printf(" ptr[i] : %d \n", o_ArrPtr[i]);
    }

    // 배열과 포인터 정리
    /*
    *  (ptr + 0) (ptr + 1) (ptr + 2) // 포인터 변수 주소의 연산
    *  (arr + 0) (arr + 1) (arr + 2) // 배열 이름(주소) 연산
    *  ptr[0] = *(ptr + 0);
    *  arr[0] = *(arr + 0);
    *  ptr[0] ptr[1] ptr[2] // 해당 주소의 값을 출력 역참조
    *  arr[0] arr[1] arr[2]
    * 
    * 배열과 포인터 사이의 공식 : arr[i] = &(arr +i);
    */

    // 잘못된 포인터의 사용, 널 포인터 
    //int* o_numptrA = 0x100000;
    
    //printf("%p", o_numptrA);  // 0x100000 메모리 주소에 여기에 있을수도 있고 없을수도 있음
    //printf("%d", *o_numptrA); // 포인터 직접 주소 배정해주는 것은 위험하다.-> 오류가 발생할 가능성이 매우 높다.

    int* o_numPtrA = 0;     // NULL : 널 포인터, 이 주소가 아무 것도 기리키고 있지않다.
    int* o_numptrA = NULL;   


    // 예제 문제3. 길이가 6인 배열을 선언해서 1,2,3,4,5,6 -> 6,5,4,3,2,1 출력하게 하는 코드를 작성.

    int t_arr[6] = { 1,2,3,4,5,6 }; // 1~6 정수형 선언 초기화
    int* frontPtr = (t_arr + 0);
    int* backPtr = (t_arr + 5);
    int temp;
    
    printf("바꾸기 이전의 값 \n");
    for (int i = 0;i < 6;i++)
    {
        printf(" %d", t_arr[i]);
    }

    for (int i = 0;i < 3;i++) // 배열의 길이 (6) 나누기 2 한 값 : 3
    {
        temp = *frontPtr;
        *frontPtr = *backPtr;
        *backPtr = temp;
        frontPtr++;
        backPtr--;
    }

    printf("\n바꾸기 이후의 값 \n");
    for (int i = 0;i < 6;i++)
    {
        printf(" %d", t_arr[i]);
    }

}