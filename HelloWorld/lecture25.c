#include "lectures.h"
#include <string.h>



// ����ü 
// �����͸� �ݺ������� ǥ��, �迭�̶�� ������ �����.
// �ּ��� ���� ������ �پ��� ������ �ڷḦ ����� �� �ְ� ���ִ� ��
// ����� ������ �ڷ���

// 1. ����ü�� ���� : Ű���� struct
#pragma pack(push,2)
typedef struct People {
    char name[25];
    int age;
}People;
#pragma pop
// Point, x, y��ǥ
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
    printf("���� ���� ��ǥ : [ %d, %d ] \n", circle.centerPos.posx, circle.centerPos.posy);
    printf("���� ������ : %lf \n", circle.radius);
}

void ShowRectangleInfo(Rectangle rectangle)
{

    printf("�簢���� leftUp ��ǥ : [%d, %d] \n",rectangle.leftUpPos.posx, rectangle.leftUpPos.posy);
    printf("�簢���� leftDown ��ǥ : [%d, %d] \n", rectangle.leftUpPos.posx, rectangle.rightDownPos.posy);
    printf("�簢���� rightDown ��ǥ : [%d, %d] \n", rectangle.rightDownPos.posx, rectangle.rightDownPos.posy);
    printf("�簢���� rightUp ��ǥ : [%d, %d] \n", rectangle.rightDownPos.posx, rectangle.leftUpPos.posy);
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
    // p1.name = "ȫ�浿"; // ������ �ߴ� ����. name : �迭. "ȫ�浿" ���ͷ� ���ڿ�. �ּ�
    strcpy_s(p1.name, 20, "ȫ�浿");
    p1.age = 10;
    printf("%s %d\n", p1.name, p1.age);

    // 2. ����ü�� ����� ���ÿ� �ʱ�ȭ �ϴ� ���
    struct People p2 = {
        {"�̼���"},{11}
    };
    printf("%s %d\n", p2.name, p2.age);

    // 3. typedef struct People{} People;
    People p3={
        {"������"}, {12}
    };
    printf("%s %d\n", p3.name, p3.age);

    // x��ǥ : 10 y��ǥ : 5
    Point po1 = {
        {10},{5}
    };
    printf("x��ǥ : %d y��ǥ : %d\n", po1.posx, po1.posy);

    // 4. ����ü�� �迭��  ǥ���� �غ���.

    Point pointArr[3] = {
        {1,2},
        {10,20},
        {30,40}
    };

    for (int i = 0; i < 3; ++i)
    {
        printf("x��ǥ : %d y��ǥ : %d\n", pointArr[i].posx, pointArr[i].posy);
    }

    People peopleArr[3] = {
        {"�̼���",21},
        {"������",22},
        {"�庸��",23}
    };

    for (int i = 0; i < 3; ++i)
    {
        printf("�̸� : %s , ���� : %d \n", peopleArr[i].name, peopleArr[i].age + 3);
    }

    // 5. ����ü ������
    Point point3 = { 1,2 };
    Point* pPtr = &point3;

    pPtr->posx = 5; // (*pPtr).posx = 10; // point3
    point3.posx = 7;
    (*pPtr).posx = 9;

    printf("point3�� �� : %d\n", point3);

    People p4;
    People* peoplePtr = &p4;

    //peoplePtr->name = "ȫ�浿";
    strcpy_s(peoplePtr->name, 20, "ȫ�浿");
    peoplePtr->age = 20;

    printf("%s %d \n", peoplePtr->name, peoplePtr->age);

    // ���� ���� 1.
    // Point ��ǥ�� ����ü ��������ϴ�. ����ü�� ����ü �����ͷ� ���� �����ؼ� ����� �Ұǵ�,
    
    // void ShowPointInfo(����ü ������) ���� �����ϰ�, point ����ϴ� �Լ��� �����ƶ�

    Point point4 = { 2,4 };

    ShowPointInfo(&point4,4,8);
    
    // 6. ���� �Ҵ�. �ּ��� �޸𸮸� ���� �Ҵ� ���� �� �ִ�. malloc - free

    People* newPeoplePtr = malloc(sizeof(People));
    // People char 20 -20, int 4 - 24ũ��
    printf("People ����ü�� ũ�� : %d \n",sizeof(People));

    strcpy_s(newPeoplePtr->name, 20, "�̼���");
    newPeoplePtr->age = 30;

    printf("%s %d \n", newPeoplePtr->name, newPeoplePtr->age);
    free(newPeoplePtr);

    // ����ü �������� �����Ҵ��� �� ���� �ݵ�� sizeof ����ü �̸� ������ �ؾ� �Ѵ�.
    // �ֳ��ϸ� ����ü�� ũ��� ����ü ���� ��� ������ ũ�� x �� ���� ������� ������� �ʱ� �����̴�.
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
