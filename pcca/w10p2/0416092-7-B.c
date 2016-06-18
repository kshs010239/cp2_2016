#include <stdio.h>
#include <stdlib.h>

int check(char board[5][5])
{
    static const char ans[25] = "11111"
                                "01111"
                                "00 11"
                                "00001"
                                "00000";
    int i;
    for(i = 0; i < 25; i++)
    {
        if(ans[i] != board[i / 5][i % 5])
            break;
    }
    if(i == 25)
        return 1;
    else
        return 0;
}

int range_check(int a, int b)
{
    if(a > 4 || a < 0 || b > 4 || b < 0)
        return 0;
    return 1;
}
void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void rec(char board[5][5], int cnt, int xpos, int ypos, int* min)
{
    static const int x_step[8] = {1, -1, 1, -1, 2, -2, 2, -2};
    static const int y_step[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int i;
    if(check(board))
    {
        if(cnt < *min)
            *min = cnt;
    }
    if(cnt == 10)
        return;
    for(i = 0; i < 8; i++)
    {
        if(range_check(xpos + x_step[i], ypos + y_step[i]))
        {
            swap(board[xpos] + ypos, board[xpos + x_step[i]] + ypos + y_step[i]);
            rec(board, cnt + 1, xpos + x_step[i], ypos + y_step[i], min);
            swap(board[xpos] + ypos, board[xpos + x_step[i]] + ypos + y_step[i]);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        char board[5][5];
        int i, j, x, y;
        for(i = 0; i < 5; i++)
        {
            for(j = 0; j < 5; j++)
            {
                board[i][j] = getchar();
                if(board[i][j] == ' ')
                {
                    x = i;
                    y = j;
                }
            }
            getchar();
        }
        int min = 11;
        rec(board, 0, x, y, &min);
        if(min == 11)
        {
            puts("Unsolvable in less than 11 move(s).");
        }
        else
        {
            printf("Solvable in %d move(s).\n", min);
        }
    }
    return 0;
}
