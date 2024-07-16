/*
*  �ۼ��� : 2024-07-16
*  �ۼ��� : ������
*  �н���ǥ :  ������ ���ڸ� �Լ��� ����Ѵ�.
*             Call by Value�� Call by Reference �� ���ؼ� �����Ѵ�.
*/

// ���� - ��, �ּ�, &�ְ�����
// ������ ���� - �ּ� ����. *������������
// ������ ���� ���ϱ� ����. sizeod(������)
// �迭�� ��� ������ : ������ �ּҸ� �������� ���ϰ� �ϴ� ��. Constant pointer
// ����� ����Ű�� ������ : ���� �������� ���Ѵ�. pointer to constant

// �迭�� �Ű� ������ ���� ���ؼ� ������ ����

// �迭�� �����ϴ� �� : int arr[10]; ó�� ������ �� ũ�� ���� ����� ����Ѵ�.
// int arr[?] = �����ϴ� �ڵ尡 �Ұ����ϴ�.
// �迭�� ���������. 
// int arr2[10];
// arr = arr2; -> �̷��� �ȵ�

// ���� �� ũ�⿡ ���� ���Ѵ�.
// ������ �� ���� �ʱ�ȭ���־�� �Ѵ�.

void AddArryElement(int* arr, int len,int add) // �迭 ����� ���� n��ŭ ���ϴ� �Լ��� �����غ�����.
{
    for (int i = 0; i < len; i++)
    {
        arr[i] += add;
        printf("%d \n", arr[i]);
    }
}

// Call by Value vs Call by Reference
// �Լ��� ����� �� ���� ��ȯ�Ѵ�.
// return;  - �׽������� �Լ��� �����Ű�� �Լ��� ȣ���� ������ ���ư���.
// return 0; - �Լ����� �����ϴ� ������ 0�� �ݺ��Ѵ�.

// ��ȯ���� ���� ��� : void
// ��ȯ���� ���� ��� : ��ȯ �ϰ� ���� ���������� �Է����ָ� �ȴ�.

void Call_by_Value(int _num)
{
    _num = _num + 10;

}

void Call_by_Reference(int* _numPtr)
{
    *_numPtr = *_numPtr + 10;
}

// Call by Value ���� ���� ȣ�� : �Լ� ȣ�� �� �⺻������ �ܺο� ������ ���� �ʽ��ϴ�.
// �����Ͷ�� �༮�� *(������ ������)����Ͽ� �Լ� �ܺ� �ּҸ� �����ؼ� ���� ������ �� �־����ϴ�.

#include "lectures.h"

void SquareByValue_20(int num)
{
    num = num * num;
    printf("�Լ��ȿ��� ����� ��� : %d\n", num);
}

void SqureByRef_20(int* numptr)
{
    *numptr = *numptr * *numptr;
}

void ChangeElement(int* a, int* b, int* c)
{
    // a -> b, b -> c, c -> a ���� �����ϴ� �Լ��� ����� ���ƶ�.
    // temp ���
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void ChangeElement_1(int a, int b, int c)
{
    int temp = a;
    a = b;
    b = c;
    c = temp;
    printf("Call By Value : %d %d %d \n", a, b, c);
}

// ���� ����, ���� ����
// ���� ���� : {} �ȿ� �ۼ��Ǵ� ����. {} ������ ����� �� ������ ���� �Ҹ� �ȴ�.
// ���� ���� : 


int global_val_l20 = 30; // ���� ���� : ���� , ���� óġ, While() ����, ������ ���� ���� ��� ������ ���Ǵ� ����

void DoublePointerCallByRef(int** ref)
{
    *ref = &global_val_l20;
}

void DecimalToBinaray(int num)
{
    int binaray[20] = { 0 };
    int pos = 0;

    while (1)
    {
        binaray[pos] = num % 2;
        num = num / 2;
        pos++;

        if (num==0)
            break;
    }
    for (int i = pos - 1; i >= 0; --i)
    {
       
        printf("%d", binaray[i]);
    }
}


void lecture20()
{
    int arr[3] = { 0,1,2 };
    AddArryElement(arr, 3,5); // ������ ���� ������ �� �Լ��� �ٲٴ� ���� ��������?

    int a = 10;
    int num = a;
    int* numptr = &num;

    Call_by_Value(num);
    printf("Call_by_Value�� �� : %d\n", num);
    Call_by_Reference(&num);
    printf("Call_by_Reference�� �� : %d\n", num);

    printf("���� ���� 1\n");
    int b = 3;
    SquareByValue_20(b); // ���� ������� �ʴ� ��
    printf("b�� �� : %d\n", b);
    SqureByRef_20(&b); // ���� ������ �Ǽ� ����� �ǵ���
    printf("b�� �� : %d\n", b);

    printf("���� ����2\n");
    int t1 = 10, t2 = 20, t3 = 30;
    ChangeElement_1(t1, t2, t3);
    ChangeElement(&t1, &t2, &t3);
    printf("%d %d %d\n", t1, t2, t3);

    printf("���� ������\n"); // ������ (�ּ�)���� -�ּ�

    int p1 = 10;
    int p2 = 20;
    int* p1Ptr = &p1;
    int* p2Ptr = &p2;
    int* p3Ptr = NULL;

    p3Ptr = &global_val_l20; // ���� ������ : �ּҸ� ����Ű�� �ִ� ������ �ּ� = 0x111111

    DoublePointerCallByRef(&p1Ptr);
    printf("%d\n",*p1Ptr);

    printf("���� ����3\n");
    // 10������ 2������ ��ȯ�ؼ� �߷��ϴ� �Լ��� ���� ��

    int input;
    scanf_s("%d", &input);

    DecimalToBinaray(input); 

    // 11�� 2������ ����� ��
    // 11/2 = 5 + 1
    // 5/2 = 2 + 1
    // 2/2 = 1 + 0
    // 1/2 = 0 + 1
    // 1011(2) ; 1 + 2 + 8 = 11
  
    


}