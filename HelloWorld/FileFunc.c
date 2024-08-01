#include "FileFunc.h"

#define filename "C:\\Users\\Administrator\\Desktop\\C-STUDY\\HelloWorld\\Test\\people.txt"

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



Person People[3] = {
        {"이순신", 31},
        {"강감찬",32},
        {"장보고",33}
};

void WriteFile()
{
    FILE* fp = fopen(filename, "w"); // 앞은 파일의 이름 뒤는 w의 준말 //  a.txt파일과 운영체제를 파일 스트림과 연결
    //fp = fopen_s(&fp,"a.txt" ,"w"); 

    // fopen 스트림을 연결해주는 함수가 정상적으로 실행되지 않을 때
    if (fp == NULL) {
        printf("Write Error! \n");
        return 0;
    }

    fputs("Hello World!!\n", fp);  // fputs(입력하고싶은값,스트림);

    // FILE* 파일 스트림을 저장하는 구조체, stdout  : 모니터에 연결해주는 스트림
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

    // fgetc : 한개씩 읽어오는 함수 
    // fgets : 문자열로 읽어오는 함수 

    char buffer[100]; // 버퍼 : 데이터를 임시적으로 보관했다고 필요할 때 쓰는 용도 

    fgets(buffer, 100, fp);
    printf("%s\n", buffer);
}

void WriteFileByStruct()
{
    for (int i = 0; i < 3; ++i) {
        printf("이름 : %s 나이 : %d\n", People[i].name, People[i].age);
    }

    FILE* fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Write Error !! \n");
        return 0;
    }

    for (int i = 0; i < 3; ++i) {
        fprintf(fp, "이름 : %s 장군님 나이 : %d \n", People[i].name, People[i].age);
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
        fscanf_s(fp, "이름 : %s 장군님 나이 : %d ", People[0].name, 30, &People[0].age);

        printf("이름 : %s 장군님 나이 : %d ", People[0].name, People[0].age);
    }
}





// 구조체로 데이터를 저장하는 방법 고민!
// 구조체 만들고 
// File* 연결하고 파일 스트림 
// 구조체 변수를 넣는 것을 고민헤보시면 되겠습니다