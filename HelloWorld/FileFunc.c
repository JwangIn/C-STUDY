#include "FileFunc.h"

#define filename "C:\\Users\\Administrator\\Desktop\\C-STUDY\\HelloWorld\\Test\\people.txt"

// ������ ����Ǵ� ��ġ.
// 

// ���� �����
// printf scanf
// Ű������ �Է� ����Ϳ� ���

// printf : ����Ϳ� ���
// scanf : Ű����� �Է¹��� ���� �ּҷ� �����ؼ� �ּҿ� ����
// fopen : ������ ������ ���� ���ؼ� � ü���� �������ִ� �Լ�
// ������,���콺,�� �ü���� ������ �ִ�.
// Ű���� , ���콺 , ����� , ... �ϵ��� ��ǻ�Ϳ��� �۵��ϰ� ���ش�.
// �ϵ��� ȸ�簡 ���� �پ��ϰ�, 
// ��Ʈ�� : �����, Ű���� , ���콺  <- ���� �ٸ� �ϵ��� �������ش� �� 

// ������ ����. -> RAM : �ֹ߼� �޸� : ��ǻ�� �Ǵ� ���α׷��� ����Ǹ� ������� �޸�
// ���ֹ߼� �޸� : ���α׷��� ����ǰ� ��ǻ�Ͱ� ����ǵ� ������� �ʴ� �޸�(HDD, SDD)
// �����͸� �����ϰ� �ʹ�.
// �ü���� �ٸ���, ������ �� �ٸ� �� �����͸� �����Ϸ��� , ���� ��Ʈ���� ����������Ѵ�.
// ����ü File 



Person People[3] = {
        {"�̼���", 31},
        {"������",32},
        {"�庸��",33}
};

void WriteFile()
{
    FILE* fp = fopen(filename, "w"); // ���� ������ �̸� �ڴ� w�� �ظ� //  a.txt���ϰ� �ü���� ���� ��Ʈ���� ����
    //fp = fopen_s(&fp,"a.txt" ,"w"); 

    // fopen ��Ʈ���� �������ִ� �Լ��� ���������� ������� ���� ��
    if (fp == NULL) {
        printf("Write Error! \n");
        return 0;
    }

    fputs("Hello World!!\n", fp);  // fputs(�Է��ϰ������,��Ʈ��);

    // FILE* ���� ��Ʈ���� �����ϴ� ����ü, stdout  : ����Ϳ� �������ִ� ��Ʈ��
    fputs("Hello World!!\n", stdout);


    fclose(fp);

}

void ReadFile()
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\aRead Error\n");
        return 0;
    }

    // string, char 

    // fgetc : �Ѱ��� �о���� �Լ� 
    // fgets : ���ڿ��� �о���� �Լ� 

    char buffer[100]; // ���� : �����͸� �ӽ������� �����ߴٰ� �ʿ��� �� ���� �뵵 

    fgets(buffer, 100, fp);
    printf("%s\n", buffer);
}

void WriteFileByStruct()
{
    for (int i = 0; i < 3; ++i) {
        printf("�̸� : %s ���� : %d\n", People[i].name, People[i].age);
    }

    FILE* fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Write Error !! \n");
        return 0;
    }

    for (int i = 0; i < 3; ++i) {
        fprintf(fp, "�̸� : %s �屺�� ���� : %d \n", People[i].name, People[i].age);
    }
    fclose(fp);
}

void ReadFileByStruct()
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Read Error !! \n");
        return 0;
    }
    Person People[3];


    for (int i = 0; i < 3; ++i) {
        fscanf_s(fp, "�̸� : %s �屺�� ���� : %d ", People[0].name, 30, &People[0].age);

        printf("�̸� : %s �屺�� ���� : %d ", People[0].name, People[0].age);
    }
}





// ����ü�� �����͸� �����ϴ� ��� ���!
// ����ü ����� 
// File* �����ϰ� ���� ��Ʈ�� 
// ����ü ������ �ִ� ���� ����캸�ø� �ǰڽ��ϴ�