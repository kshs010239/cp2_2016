#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define turn(x) ((x) = ((x) == '#') ? 'O' : '#')

void press(char map[10][10], int x, int y)
{
    turn(map[x][y]);
    if(x != 0)
        turn(map[x - 1][y]);
    if(y != 0)
        turn(map[x][y - 1]);
    if(x != 9)
        turn(map[x + 1][y]);
    if(y != 9)
        turn(map[x][y + 1]);
}

int main()
{
    int i, j;
    char map[10][10];
    char cas[100];
    while(1)
    {

        scanf("%s", cas);
        if(cas[0] == 'e' && cas[1] == 'n' && cas[2] == 'd' && cas[3] == '\0')
            break;
        for(i = 0; i < 10; i++)
        {
            getchar();
            for(j = 0; j < 10; j++)
                map[j][i] = getchar();
        }
        char map_temp[10][10];
        int temp = (int)pow(2, 10);
        for(i = temp - 1; i >= 0; i--)
        {
            int k;
            for(j = 0; j < 10; j++)
                for(k = 0; k < 10; k++)
                    map_temp[j][k] = map[j][k];
            int sum = 0;
            for(j = 0; j < 10; j++)
                if((int)(i / pow(2, j)) % 2)
                {
                    press(map_temp, j, 0);
                    sum++;
                }

            for(j = 0; j < 9; j++)
                for(k = 0; k < 10; k++)
                    if(map_temp[k][j] == 'O')
                    {
                        press(map_temp, k, j + 1);
                        sum++;
                    }
            for(j = 0; j < 10; j++)
                if(map_temp[j][9] != '#')
                    break;
            if(j == 10)
                printf("%s %d\n", cas, sum);
        }
    }
    return 0;
}

