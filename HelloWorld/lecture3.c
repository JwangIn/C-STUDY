#include "lectures.h"

// 기본환경설정
// main함수 시작과 끝을 알리는 핵심 함수이다. 반드시 1개만 존재해야한다. 이름 대소문자 반드시 지켜줘야한다.
// main 이름의 함수가 2이상 존재하면 에러가 발생한다.
// 소스 파일 - 우클릭 - 설정 - 빌드에서 제외 기능으로 원하는 파일만 빌드할 수 있다.

// 작성자   : 박종현
// 작성일자 : 2024-06-12
// 학습주제 : 변수(Variable)

// 컴퓨터 한테 명령을 하고, 그 명령한 내용을 저장하기 위해서 변수를 사용해야 한다.

// 선언(Declare) : 변수를 어떻게 컴퓨터한테 알려주나요?
// 컴파일러에게 변수가 무엇을 저장하고, 얼만큼 저장해야 하는지 알려주는것
// Int   : 무엇을(정수)
// Float : 무엇을(변수)

// 선언 방법
// 데이터 형태 작성(int, float)  변수 이름(a)
// int a(이름);

// 할당(assignment)
// 선언한 변수에 데이터를 넣는것
// a이름의 벼눗에 정수 형태의 데이터를 넣을 수 있게 된다.
// int a = 10;

// 초기화(Initialize)
// 변수에 처음으로 데이터를 할당하는 것

void lecture3()
 {
        int a = 5 + 9;
        a = 4 + 7;
        printf("%d \n", a);
        float b = 3.2f + 4.7f;
        printf("%f \n", b);

        // 문제 1-1. 변수의 이름 width, height, length 정수를 담을 수 있는 변수 선언

        // 문제 1-2. 세 변을 곱한 값(부피) Volume 변수에 저장하세요

        // 문제 1-3. Volume / 165로 나누어 원하는 계산 값을 구한다. Printf 함수로 출력하세요.

        int width = 12;
        int height = 10;
        int length = 8;

        int Volume = width * height * length;
        Volume = (Volume + 164) / 165;

        float Volume_f = width * height * length;
        Volume_f = Volume_f / 165;


        printf("문제 3의 답 : %d \n", Volume);
        printf("문제 3의 답 : %f \n", Volume_f);

        // 문제 2-1. 섭씨, 화씨 변환
        // 화씨 = 9/5 * 섭씨 + 32
        // 화씨가 실수로 표현될 수 있도록 변수를 선언해주세요.
        // 9/5의 값이 1이 아닌 1.8이 나와야 합니다.
        // 섭씨 1, 화시 33.8

        float Celsius = 1;
        float Fahrenheit = 9.0f / 5.0f * Celsius + 32;

        printf("섭씨 to 화씨 : %.2f ", Fahrenheit);

        printf("변수는 3강의 내용입니다.");

        return 0;
}

