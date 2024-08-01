#pragma once
#include <stdio.h>

#define filename "Test\\people.txt"
#define filename2 "Test\\people.txt"

// ~~.h : 함수의 원형을 선언한다

// (데이터 타입) 1. void  2. (반환값 데이터형) <- int, double, char, char*, int, double, struct people

// int 함수이름(); : 반환값이 int이고 함수이름에 해당하는 녀석이 존재합니다. 컴파일러한테.

// 구조체 헤더 파일에 가져올 때. 구조체도 본문 내용을 작성을 안해도 될까요? 안된다. 구조체의 내용물도 전부 작성해줘야한다.

typedef struct Person {
    char name[30];
    int age;
}Person;


void WriteFile();

void ReadFile();

void WriteFileByStruct();

void ReadFileByStruct();