#include <stdio.h>
#include <stdlib.h>
#define min(x,y) ((x < y)? x: y)
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int space_tmp, color;
        scanf("%d %d", &space_tmp, &color);
        int cur[space_tmp];
        int tmp, i, j, space = 0, amount = 0;
        for(i = 0; i < space_tmp; i++)
        {
            scanf("%d", &tmp);
            if(space > 1 && tmp == cur[space - 2])
            {
                amount++;
                space--;
            }
            if(space <= 0 || tmp != cur[space - 1])
            {
                cur[space++] = tmp;
            }
        }
        printf("%d %d", amount, space);
        int dp[space][space], wide;
        for(i = 0; i < min(3, space); i++)
            for(j = 0; j < space; j++)
                dp[i][j] = i + 1;
        for(i = 3; i < space; i++)
            for(j = 0; j < space; j++)
                dp[i][j] = 0;
        for(wide = 3; wide < space; wide++)
        {
            for(i = 0; i < space - wide; i++)
            {
                if(cur[i] == cur[i + wide])
                    dp[wide][i] = dp[wide - 1][i];
                else
                {
                    int min_tmp = 0x7FFFFFFF;
                    for(j = 0; j < wide; j++)
                    {
                        int tmp = dp[j][i] + dp[wide - j - 1][i + j + 1];
                        if(tmp < min_tmp)
                            min_tmp = tmp;
                    }
                    dp[wide][i] = min_tmp;
                }
            }
        }
        printf("%d\n", dp[space - 1][0] + amount);
    }
    return 0;
}

