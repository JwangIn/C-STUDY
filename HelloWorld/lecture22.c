/*
*  작성일 : 2024-07-19
*  작성자 : 박종현
*  학습 목표 : 2차원 배열의 이해
*/

// 1. 선언
// 자료형 배열이름[세로크기][가로크기] 



#include "lectures.h"

void lecture22()
{
    // 2차원 배열에 초기화 표현 방법
    int numArr[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };

    int numArr2[3 * 4] = { 0 }; // 1차원 배열에 벽 30x30


    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            numArr[i][j] = 10;
            printf("%d ", numArr[i][j]);
        }
    }
    printf("\n");


    char map[10][10] = { 0 };
    
    for (int i = 0; i < 10; ++i) // ' ' => 32 '#' => 35
    {
        for (int j = 0; j < 10; ++j)
        {
            map[i][j] = ' ';
        }
    }


    for (int i = 0; i < 10; ++i) // ' ' => 32 '#' => 35
    {
        map[i][0] = '#';
        map[i][9] = '#';
    }
    for (int j = 0; j < 10; ++j) // ' ' => 32 '#' => 35
    {
        map[0][j] = '#';
        map[9][j] = '#';
    }

    for (int i = 0; i < 10; ++i) // ' ' => 32 '#' => 35
    {
        for (int j = 0; j < 10; ++j)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

}