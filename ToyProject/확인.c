#include <stdio.h>
#include "Console.h"
#include <stdbool.h>
#include <stdlib.h>


char map[50][30] = { 0 };

void mapmake()
{
    for (int row = 0; row < 50; row++)
    {
        for (int col = 0; col < 30; col++)
        {
            map[row][col] = 0;

            if (row == 0 || row == 49)
            {
                map[row][col] = 1;
            }
            if (col == 0 || col == 29)
            {
                map[row][col] = 1;
            }
        }
        
    }

    



}


int main()
{
    for (int row = 0; row < 30; row++)
    {
        for (int col = 0; col < 50; col++)
        {
            map[row][col] = 0;

            if (row == 0 || row == 29)
            {
                map[row][col] = 1;
            }
            if (col == 0 || col == 49)
            {
                map[row][col] = 1;
            }

            printf("%d", map[row][col]);
           
        }
        printf("\n");
    }

    



    return 0;
}