#include "lectures.h"
#include "FileFunc.h"




// 파일이 저장되는 위치.
// 

// 파일 입출력
// printf scanf
// 키보드의 입력 모니터에 출력

// printf : 모니터에 출력
// scanf : 키보드로 입력받은 값을 주소로 전달해서 주소에 저장
// fopen : 파일을 열가나 쓰기 위해서 운영 체제가 지원해주는 함수
// 윈도우,리녹스,맥 운영체제가 여러개 있다.
// 키보드 , 마우스 , 모니터 , ... 하드웨어가 컴퓨터에서 작동하게 해준다.
// 하드웨어도 회사가 정말 다양하고, 
// 스트림 : 모니터, 키보드 , 마우스  <- 서로 다른 하드웨어를 연결해준는 것 

// 변수를 저장. -> RAM : 휘발성 메모리 : 컴퓨터 또는 프로그램이 종료되면 사라지는 메모리
// 비휘발성 메모리 : 프로그램이 종료되고 컴퓨터가 종료되도 사라지지 않는 메모리(HDD, SDD)
// 데이터를 저장하고 싶다.
// 운영체제가 다르고, 종류도 다 다른 이 데이터를 저장하려면 , 파일 스트림을 연결해줘야한다.
// 구조체 File 




// 파일 입출력2
// 쓰기. "w+" Appendix 쓰기
// w+ 모드
// 기능 : 파일을 읽고 쓰기 위한 모드. 파일이 존재하지 않으면 파일을 새로 생성하고, 파일이 존재하면 내용을 모두 지우고 다시 씁니다.

// r+ 모드
// 기능 : 파일을 읽은 후 쓰기 위한 모드. 파일에 존재하지 않으면 에러가 생긴다.

// a모드(appendix)
 // 기능 : 파일을 추가 모드로 열기 위한 모드.

// a+모드 
// 기능 : 파일을 추가 한 후에 읽기 까지 가능한 모드

// fseek 함수 : 파일을 입출력할 때 파일의 크기만큼 file pointer 가리키는 값이 달라지게된다.
// fp를 이용해서 쓰시와 읽기를 동시에 한다면 처음에 쓰기를 fp 마지막 값을 가리키게 된다
// 처음부터 읽기 위해서 fp를 다시 시작점으로 돌려야할 필요가 있다

// fseek(fp, 0 , SEEK_SET)
// SEEK_SET : 파일의 시작점 
// SEEK_END : 파일의 끝점
// SEEK_CUR : 파일의 

// 요약 
// w+ : 쓰기->읽기 가능한 모드, 파일이 존재하면 내용을 모두 지우고 새로 시작
// r+ : 일기->쓰기 가능한 모드, 파일을 읽은 후에 다시 쓰기가 가능한 모드
// a : 파일이 가리키는 마지막 위치에서 데이터를 추가하는 모드
// a+ : 파일을 추가한 후에 읽기 까지 가능한 모드


WritePlus()
{
    FILE* fp = fopen(filename2, "w+");

    if (fp == NULL)
    {
        printf("파일 연결 실패!\n");

    }
    // 파일 입력(write)
    fputs("Hello World!\n", fp);
    // 파일을 파일의 끝 '\0' End of FILE EOF : 운영체게마다 다름 

    fseek(fp, 0, SEEK_SET);
    // 파일 출력(read)
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
        printf("파일 읽기 실패 \n");
    }
    fgetc(fp); // FILE에서 fp의 주소가 가리키고있는 char를 가져온 후, fp는 다음 주소를 가리킨다.
    fgetc(fp);
    fgetc(fp);
    fgetc(fp);
    fgetc(fp);
    fseek(fp, 0, SEEK_CUR);
    printf("현재 포인터가 가리키고 있는 문자 : %c\n", fgetc(fp));
    fclose(fp);

}

void ReadPlus()
{
    FILE* fp = fopen(filename2, "r+");
    if (fp == NULL)
    {
        
        printf("파일 읽기 실패 \n");
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
    //WriteFile(); //파일을 써서 저장하는 함수
    //ReadFile();
    //WriteFileByStruct();
    //ReadFileByStruct();
    //WritePlus();
    // Indicator();
    //ReadPlus();
    //AppendixMode();
    //AppendixPlusMode();
}

// 구조체로 데이터를 저장하는 방법 고민!
// 구조체 만들고 
// File* 연결하고 파일 스트림 
// 구조체 변수를 넣는 것을 고민헤보시면 되겠습니다