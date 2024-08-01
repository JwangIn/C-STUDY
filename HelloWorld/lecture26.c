#include "lectures.h"
#include "FileFunc.h"




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




// ���� �����2
// ����. "w+" Appendix ����
// w+ ���
// ��� : ������ �а� ���� ���� ���. ������ �������� ������ ������ ���� �����ϰ�, ������ �����ϸ� ������ ��� ����� �ٽ� ���ϴ�.

// r+ ���
// ��� : ������ ���� �� ���� ���� ���. ���Ͽ� �������� ������ ������ �����.

// a���(appendix)
 // ��� : ������ �߰� ���� ���� ���� ���.

// a+��� 
// ��� : ������ �߰� �� �Ŀ� �б� ���� ������ ���

// fseek �Լ� : ������ ������� �� ������ ũ�⸸ŭ file pointer ����Ű�� ���� �޶����Եȴ�.
// fp�� �̿��ؼ� ���ÿ� �б⸦ ���ÿ� �Ѵٸ� ó���� ���⸦ fp ������ ���� ����Ű�� �ȴ�
// ó������ �б� ���ؼ� fp�� �ٽ� ���������� �������� �ʿ䰡 �ִ�

// fseek(fp, 0 , SEEK_SET)
// SEEK_SET : ������ ������ 
// SEEK_END : ������ ����
// SEEK_CUR : ������ 

// ��� 
// w+ : ����->�б� ������ ���, ������ �����ϸ� ������ ��� ����� ���� ����
// r+ : �ϱ�->���� ������ ���, ������ ���� �Ŀ� �ٽ� ���Ⱑ ������ ���
// a : ������ ����Ű�� ������ ��ġ���� �����͸� �߰��ϴ� ���
// a+ : ������ �߰��� �Ŀ� �б� ���� ������ ���


WritePlus()
{
    FILE* fp = fopen(filename2, "w+");

    if (fp == NULL)
    {
        printf("���� ���� ����!\n");

    }
    // ���� �Է�(write)
    fputs("Hello World!\n", fp);
    // ������ ������ �� '\0' End of FILE EOF : �ü�Ը��� �ٸ� 

    fseek(fp, 0, SEEK_SET);
    // ���� ���(read)
    char buffer[100];
    fgets(buffer, sizeof(buffer), fp);
    printf("Read from this file : %s", buffer);
    fclose(fp);

}

void Indicator()
{
    FILE* fp = fopen(filename2, "r");
    if (fp == NULL)
    {
        //ferror(fp);
        printf("���� �б� ���� \n");
    }
    fgetc(fp); // FILE���� fp�� �ּҰ� ����Ű���ִ� char�� ������ ��, fp�� ���� �ּҸ� ����Ų��.
    fgetc(fp);
    fgetc(fp);
    fgetc(fp);
    fgetc(fp);
    fseek(fp, 0, SEEK_CUR);
    printf("���� �����Ͱ� ����Ű�� �ִ� ���� : %c\n", fgetc(fp));
    fclose(fp);

}

void ReadPlus()
{
    FILE* fp = fopen(filename2, "r+");
    if (fp == NULL)
    {
        
        printf("���� �б� ���� \n");
    }
    char buffer[100];
    fgets(buffer, sizeof(buffer), fp);
    printf("Read from this file : %s", buffer);

    fseek(fp, 0, SEEK_END);
    fputs("Append text \n", fp);
    fclose(fp);
}

void AppendixMode()
{
    FILE* fp = fopen(filename2, "a");
    if (fp == NULL)
    {
        printf("append Mode Error! \n");
    }

    fputs("Append More Text \n", fp);

    fclose(fp);
}

void AppendixPlusMode()
{
    FILE* fp = fopen(filename2, "a+");
    if (fp == NULL)
    {
        perror("append plus Error! \n");
    }

    fputs("Append even More Text \n", fp);

    fseek(fp, 0, SEEK_SET);

    char buffer[100];
    fgets(buffer, sizeof(buffer), fp);
    printf("Read from file %s\n", buffer);

    fclose(fp);
}

void lecture26()
{
    //WriteFile(); //������ �Ἥ �����ϴ� �Լ�
    //ReadFile();
    //WriteFileByStruct();
    //ReadFileByStruct();
    //WritePlus();
    // Indicator();
    //ReadPlus();
    //AppendixMode();
    //AppendixPlusMode();
}

// ����ü�� �����͸� �����ϴ� ��� ���!
// ����ü ����� 
// File* �����ϰ� ���� ��Ʈ�� 
// ����ü ������ �ִ� ���� ����캸�ø� �ǰڽ��ϴ�