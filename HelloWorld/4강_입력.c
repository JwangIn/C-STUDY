// �Է�
// Scanf �Լ��� �ǽ�
// ���� �̸� ���� ( �Է��� �޾Ƽ� ������ ������ �̸� ����)
// �⺻ ���� : Scanf("%d", &������ �̸�);
// Scanf_s("%d, &num);

#include <stdio.h>

int main(void)
{
    int num;
    // �ּ��� ���� �Լ��� ��� Scanf_S
    // ������ �Է��� ���ڸ� " num�� �� ���� : n" ���·� ����ϴ� ���α׷��Դϴ�.
    printf("���ڸ� �Է����ּ��� \n");
    scanf_s("%d", &num);
    printf("num�� �� ���� : %d \n", num);
   
    // ������ �̸� FirstNum1, FirstNum2. FirstNum3 
    // ���� 1. " �� ���� ������ �Է� �޾Ƽ� �� ���� �E���� ������ ����� ����غ�����."
    
    printf("�� ���� ������ �Է����ּ���.\n");

    int FirstNum1, FirstNum2;
    scanf_s("%d %d", &FirstNum1, &FirstNum2);

    printf("����1. �� ���� ���� : %d , �� ���� ���� : %d \n", FirstNum1 - FirstNum2, FirstNum1 * FirstNum2);

    // ���� 2. " 3���� ������ �Է� �޾Ƽ�, SecondNum1 * SecondNum2 + SecondNum3 ����ϴ� �ڵ带 �ۼ��غ�����.

    printf("3���� ������ �Է����ּ���.\n");

    int SecondNum1, SecondNum2, SecondNum3;
    scanf_s(" %d %d %d", &SecondNum1, &SecondNum2, &SecondNum3);

    printf("����2. %d x %d + %d = %d", SecondNum1, SecondNum2, SecondNum3, SecondNum1 * SecondNum2 + SecondNum3);

    // ���� 3. " �� ���� ������ �Է¹޾Ƽ� ��� �������� ����ϴ� �ڵ带 �ۼ��غ�����."
    // ���� ���ϴ� ���

   



    return 0;
}


