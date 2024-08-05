#include <stdio.h>
#include "Console.h"
#include <stdbool.h>
#include <stdlib.h>


char map[50][30] = { 0 };

void mapmake(char* wall)
{
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            map[i][j] = 0;

            if (i == 0 || i == 29)
            {
                map[i][j] = 1;
            }
            if (j == 0 || j == 49)
            {
                map[i][j] = 1;
            }

            if (map[i][j] == 1)
                printf("%c", *wall);
            else if (map[i][j] == 0)
                printf(" ");
        }
        printf("\n");
    }
}


int main()
{
    
    mapmake("#");




    return 0;
}