/*
*  �ۼ��� : 2024-07-15
*  �ۼ��� : ������ 
*  �н���ǥ : �迭�� �������� ���� => "���" ������
*/

// 1. �迭�� �������� ���� 
// (1) sizeof(�迭) , sizeof(�����ͺ���) ������ ���� �ٸ��� ���Դ�.
// (2) �迭�� ��� �����ʹ�.

// 2. ������ �� ���
// (1) ����� ����Ű�� ������ pointer to constant
// (2) ������ �� ��ü�� ��� constant pointer
// (3) ����� ����Ű�� �� ��ü�� ����� ������ constant pointer to constant
#include "lectures.h"

void ShowData(const int* ptr)    // const int* arr�� �ǹ̸� �ѹ� �����غ���
{
    const int* rPtr = ptr;
    printf("%d\n", *rPtr);
    

}
void showAllData(const int*  arr, int len)
{
    // for  �ݺ������� arr�� ���� ��ŭ �迭��Ҹ� printf �Լ��� ������

    int* const tempArr = arr;
    for (int i = 0;i < len;i++)
    {
        printf("%d", arr[i]);
    }

}

void lecture19()
{
    const int s_num = 10;
    int* s_numPtr = &s_num;
    ShowData(s_numPtr);

    int s_arr[4] = { 1,2,3,4 };
    int* s_arrPtr = s_arr;

    showAllData(s_arrPtr, sizeof(s_arr) / sizeof(int)); // sizeof(arr) -> 


    
    
    // (1) sizeof ������ 
    int arr[3] = { 1,2,3 };
    int* arrPtr = arr; // &arr[0] ǥ���� �� �ִ�.
   
    printf("�迭�� ũ�� : %d \n", sizeof(arr));       // sizeof(int) x 1 = 4
    
    printf("�������� ũ�� : %d \n", sizeof(arrPtr));  // 16����. 32��Ʈ, 64��Ʈ   8 x 4��Ʈ (32) , 16 x 4��Ʈ (64)

    // �����ͷ� �ڵ带 �ۼ��ϴ� ��. �Ǽ��� ������ ���ɼ� ��������, �����ϱ⵵ �����ϴ�.
    // 4000����Ʈ 8����Ʈ ǥ���� �� �� �ִ�.
    // ������ ���� ������� �ʴ� ���.

    // Constant (���)
    // Pi = 3.14;
    // �ڵ��� �������� �����ִ� ������. �ڿ� ����Ǵ� ������ �ٲ� �� ����.
    // const int Pi = 3.14;
    // Pi = 3.5; 

    // (1) ����� ����Ű�� ������ pointer to constant
    // num�� ���� �������� ���ϰ� �����ش�.

    const int num = 10;
   
    const int* numPtr = &num;

    // (2) ������ �� ��ü�� ��� constant pointer

    int num1 = 20;
    int num2 = 30;
    int* const numCptr = &num1; // ��� �������� ����. �迭�� ��� ������.
    // numCptr = &num2l         // ��� ������. �ּҸ� �������� ���Ѵ�.
                                // �迭�� ��� ������. �迭�� ���� �� �� �迭�� �ּҸ� ������ �� ����.

    // (3) ����� ����Ű�� �� ��ü�� ����� ������ constant pointer to constant
    const int num3 = 40;
    const int num4 = 50;
    const int* const numCptr2 = &num3;
    // *numCptr = 50;
    // numCptr2 = &num4

    // ���� 
    // ������. ����.
    // ���� - ��, �ּ�(&)
    // ������ - �ּ�,  ��(*)

    // ������ ����
    // + Const
    // �� const, �ּ� const
    // �� const - ��� ������      constant pointer
    // �ּ� const - ����� ����Ű�� ������ pointer to constant
    // const �����Ϳ� ����ϴ� ����
    // ������ ������ ����� ������� �ʱ⸦ �����Ϸ� �ܰ迡�� �����ϱ� ���Ͽ� ( �������� �����ϱ� ����)



}