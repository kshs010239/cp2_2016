#include <stdio.h>
#include <stdlib.h>
#define min(x,y) ((x < y)? x: y)

void rec(int board[64], int depth, int* max, int value)
{
    static int used[64] = {0};
    if(depth == 8)
    {
        if(value > *max)
            *max = value;
        return;
    }
    int i;
    for(i = 0; i < 8; i++)
    {
        int j;
        for(j = 0; j < depth && !used[j * 8 + i]; j++);
        if(j != depth)
            continue;
        for(j = 1; j <= min(i, depth) && !used[(depth - j) * 8 + (i - j)]; j++);
        if(j != min(i, depth) + 1)
            continue;
        for(j = 1; j <= min(7 - i, depth) & !used[(depth - j) * 8 + (i + j)]; j++);
        if(j != min(7 - i, depth) + 1)
            continue;
        used[depth * 8 + i] = 1;
        rec(board, depth + 1, max, value + board[depth * 8 + i]);
        used[depth * 8 + i] = 0;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int i;
        int board[64];
        for(i = 0; i < 64; i++)
        {
            scanf("%d", board + i);
        }
        int max = 0;
        rec(board, 0, &max, 0);
        printf("%5d\n", max);
    }
    return 0;
}
