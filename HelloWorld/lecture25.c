#include "lectures.h"
#include <string.h>



// 구조체 
// 데이터를 반복문으로 표현, 배열이라는 문법을 배웠다.
// 주소의 시작 점에서 다양한 데이터 자료를 사용할 수 있게 해주는 것
// 사용자 정의형 자료형

// 1. 구조체를 선언 : 키워드 struct
#pragma pack(push,2)
typedef struct People {
    char name[25];
    int age;
}People;
#pragma pop
// Point, x, y좌표
typedef struct Point {
    int posx;
    int posy;
}Point;

typedef struct Rectangle {
    Point leftUpPos;
    Point rightDownPos;
}Rectangle;

typedef struct Circle {
    Point centerPos;
    double radius;
}Circle;

void ShowCircleinfo(Circle circle)
{
    printf("원의 원점 좌표 : [ %d, %d ] \n", circle.centerPos.posx, circle.centerPos.posy);
    printf("원의 반지름 : %lf \n", circle.radius);
}

void ShowRectangleInfo(Rectangle rectangle)
{

    printf("사각형의 leftUp 좌표 : [%d, %d] \n",rectangle.leftUpPos.posx, rectangle.leftUpPos.posy);
    printf("사각형의 leftDown 좌표 : [%d, %d] \n", rectangle.leftUpPos.posx, rectangle.rightDownPos.posy);
    printf("사각형의 rightDown 좌표 : [%d, %d] \n", rectangle.rightDownPos.posx, rectangle.rightDownPos.posy);
    printf("사각형의 rightUp 좌표 : [%d, %d] \n", rectangle.rightDownPos.posx, rectangle.leftUpPos.posy);
}

void ShowPointInfo(Point* pPtr,int xValue,int yValue)
{
    pPtr->posx = xValue;
    pPtr->posy = yValue;
    printf("%d %d \n", pPtr->posx, pPtr->posy);

}

Point AddPoint(Point p1, Point p2)
{
    Point newPoint;
    newPoint.posx = p1.posx + p2.posx;
    newPoint.posy = p1.posy + p2.posy;
    return newPoint;
}

void lecture25()
{
    struct People p1;
    // p1.name = "홍길동"; // 에러가 뜨는 이유. name : 배열. "홍길동" 리터럴 문자열. 주소
    strcpy_s(p1.name, 20, "홍길동");
    p1.age = 10;
    printf("%s %d\n", p1.name, p1.age);

    // 2. 구조체의 선언과 동시에 초기화 하는 방법
    struct People p2 = {
        {"이순신"},{11}
    };
    printf("%s %d\n", p2.name, p2.age);

    // 3. typedef struct People{} People;
    People p3={
        {"강감찬"}, {12}
    };
    printf("%s %d\n", p3.name, p3.age);

    // x좌표 : 10 y좌표 : 5
    Point po1 = {
        {10},{5}
    };
    printf("x좌표 : %d y좌표 : %d\n", po1.posx, po1.posy);

    // 4. 구조체를 배열로  표현을 해보자.

    Point pointArr[3] = {
        {1,2},
        {10,20},
        {30,40}
    };

    for (int i = 0; i < 3; ++i)
    {
        printf("x좌표 : %d y좌표 : %d\n", pointArr[i].posx, pointArr[i].posy);
    }

    People peopleArr[3] = {
        {"이순신",21},
        {"강감찬",22},
        {"장보고",23}
    };

    for (int i = 0; i < 3; ++i)
    {
        printf("이름 : %s , 나이 : %d \n", peopleArr[i].name, peopleArr[i].age + 3);
    }

    // 5. 구조체 포인터
    Point point3 = { 1,2 };
    Point* pPtr = &point3;

    pPtr->posx = 5; // (*pPtr).posx = 10; // point3
    point3.posx = 7;
    (*pPtr).posx = 9;

    printf("point3의 값 : %d\n", point3);

    People p4;
    People* peoplePtr = &p4;

    //peoplePtr->name = "홍길동";
    strcpy_s(peoplePtr->name, 20, "홍길동");
    peoplePtr->age = 20;

    printf("%s %d \n", peoplePtr->name, peoplePtr->age);

    // 예제 문제 1.
    // Point 좌표를 구조체 만들었습니다. 구조체를 구조체 포인터로 값을 변경해서 출력을 할건데,
    
    // void ShowPointInfo(구조체 포인터) 값을 변경하고, point 출력하는 함수를 만들어보아라

    Point point4 = { 2,4 };

    ShowPointInfo(&point4,4,8);
    
    // 6. 동적 할당. 주소의 메모리를 직접 할당 해줄 수 있다. malloc - free

    People* newPeoplePtr = malloc(sizeof(People));
    // People char 20 -20, int 4 - 24크기
    printf("People 구조체의 크기 : %d \n",sizeof(People));

    strcpy_s(newPeoplePtr->name, 20, "이순신");
    newPeoplePtr->age = 30;

    printf("%s %d \n", newPeoplePtr->name, newPeoplePtr->age);
    free(newPeoplePtr);

    // 구조체 포인터의 동적할당을 할 때는 반드시 sizeof 구조체 이름 선언을 해야 한다.
    // 왜냐하면 구조체의 크기는 구조체 안의 모든 데이터 크기 x 수 더한 방식으로 저장되지 않기 때문이다.
    // 25 + 4 = 29

    Rectangle r1 = { {1,2},{4,8} };

    ShowRectangleInfo(r1);

    Circle circle;
    circle.centerPos.posx = 0;
    circle.centerPos.posy = 0;
    circle.radius = 5;
    ShowCircleinfo(circle);

    Point c_p1 = { 1,1 };
    Point c_p2 = { 2,3 };
    Point c_p3 = AddPoint(c_p1, c_p2);

    printf("[%d, %d] \n", c_p3.posx, c_p3.posy);

}
