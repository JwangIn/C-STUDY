// void�� ���� ���� (1) �Լ��� ��ȯ�� (2) void Pointer
// Enum�� ���� ���� (1) Enum�� �� �ʿ��Ѱ�

// ������ ������ �� �� ���ϰڴ� ��� : �����ϱ� , �ܼ־�庥ó[����ü, ���� ���� ���]
// �����ϴ� �κ�(����� ���� ������Ʈ�� ���ϴ� ��) : ���� ������ ���α׷�, ���� ���� ���α׷�, ��Ʈ����, ���� �޸��� ���� �� 
// ������ �κ�, ���װ� �߻�, ������ �ް� ���� �κ�. -> �����ؼ� ���� 

// �Լ����� ��ȯ���� � ���ΰ�
// void : �����ϴ�, ����ִ�. �Լ��� ��ȯ���� ���Ǹ� ��ȯ��(Return Type)�� ����  

// Swap(int* a,int*b)(int temp; temp,*a,*b) : a�� �����Ϳ� b�� �����͸� ��ȯ�Ѵ�.
// void Swap : ���ڷ� �Ѱ��ִ� a��b�� ���� �������ְ� ����ȴ�.
// int Compare() : // ������ return 0 Ʋ���� 1�� ��ȯ�ϵ��� �ؼ� if���̶� ����ߴ�.
// c++, stdbool -True False ��ȯ�ؼ� ����ϰ� �ִ�. 


#include "lectures.h"

void Add_one(int* a)
{
    *a = *a + 1;
}

// ��ȯ���� �����ϴ� ���� : �����Ϸ��� �� �ڵ带 ������ ũ�⸦ �̸� �������ִ� ���.
// int_num

// void�� �޸� ������ �󸶳� ����Ǵ��� �˼� ��� void�� ������ ������ �� ����.
// void*�� �ҿ����� �����̴�. �� �Ҿ��� �Ѱ�?
// �޸� ������ �󸶳� �����ϴ��� ũ�⸦ �˷��ش�. + ����, �Ǽ�, ����ü

// ���� 
// int* : �޸� ������ 4����Ʈ Ȯ���ϰ�, 4����Ʈ ������ int �������� �����͸� �о�Ͷ�.
// void* : �޸� ������ 8����Ʈ�� Ȯ���ߴµ�, � �������� �𸥴�. ������ �ִ�.
// void �����͸� ����ϴ� ������ �����ϱ�
// IntSwap,DoubleSwap,FloatSwap ������ Ÿ�Ը� �ٸ� ������ �Լ����� ���̰� �ִ�.
// Ÿ���� �������ִ� ��� -> void pointer

#define INT 1
#define DOUBLE 2
#define FLOAT 3

// defint INT,DOUBLE, FLOAT
// ����� �ѹ��� ǥ���ϴ� ��� : enum Ű���带 �����ϰ� �ֽ��ϴ�.

// ������ ENUM ����ϴ� ���� 
// 1. �ڵ��� ������ ���� : ����� ǥ���ϴ� ������ �̸��� ��Ȯ�� � �������� �Ҿ����ϴ�. enum ����� �̸����� �����ϴ� ������ ����� �̴ϴ�. TYPE -> ���3�� (Float,Int,Double)
// 2. ���ӽ����̽� ���� ���� : �Լ��� ���ڷ� enum type�� ����� �� �ִ�.
// 3. ���������� �������� : ���ӽ����̽� ������ ���� ������ �Ǿ������Ƿ� ���׸� ã�⵵ ����������.
// 4. Ÿ�� �������� ����ϴ� : ����� �����͸� ���� ������ �ʿ� ���� enum type�� �����ϸ� �ȴ�.

typedef enum TYPE { TYPE_Char, TYPE_INT, TYPE_Double }Type;


void SwapValue(void* ptr1, void* ptr2, Type type)
{
    switch (type)
    {
        case TYPE_Char :
        {
            char temp;
            temp = (*(char*)ptr1);
            (*(char*)ptr1) = (*(char*)ptr2);
            (*(char*)ptr2) = temp;
            break;
        }
        case TYPE_INT:
        {
            int temp;
            temp = (*(int*)ptr1);
            (*(int*)ptr1) = (*(int*)ptr2);
            (*(int*)ptr2) = temp;
            break;
        }
        case TYPE_Double:
        {
            double temp;
            temp = (*(double*)ptr1);
            (*(double*)ptr1) = (*(double*)ptr2);
            (*(double*)ptr2) = temp;
            break;
        }
        default:
            printf("�ش��ϴ� Ÿ���� �����ϴ�.");


    }


}

void IntSwap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void DoubleSwap(double* a, double* b)
{
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void FloatSwap(float* a, float* b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}



void lecture27()
{
    // void �Լ��� �̷��� ����ϸ� �ȵȴ�.
    int num = 1; // �����Ϸ��� �̸� �޸� ������ 4����Ʈ Ȯ���� �Ѵ�. 2������ �ۼ��� 0101�����ͷ� ���� ������ ����
    // void some; // �����Ϸ��� �޸� ������ �󸶳� �����ؾߵǴ��� �� �� �ֳ���?
    Add_one(&num);

    void* voidPtr; // ������ ������ 64��Ʈ �ý����� �� 8����Ʈ�� ũ�⸦ Ȯ���մϴ�.
    printf("void*�� ũ�� : %d\n", sizeof(voidPtr));

    double a = 1.1;
    voidPtr = &a;

    // voidPtr�� double* �������� Type ��ȯ�ϰڴ�.
    

    printf("voidPtr�� ����Ű�� �� : %lf\n", *(double*)voidPtr);

    char c1 = 'a';
    char c2 = 'b';
    
    SwapValue(&c1, &c2, TYPE_Char);

    printf("�� Ȯ�� %c %c\n", c1, c2);

    int a1 = 1;
    int a2 = 2;
    SwapValue(&a1, &a2, TYPE_INT);

    printf("�� Ȯ�� %d %d\n", a1, a2);

    double d1 = 1.1;
    double d2 = 2.2;
    SwapValue(&d1, &d2, TYPE_Double);

    printf("�� Ȯ�� %f %f\n", d1, d2);

}