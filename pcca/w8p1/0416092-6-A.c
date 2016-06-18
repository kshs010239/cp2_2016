#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j;
    scanf("%d", &N);
    int* prefix = malloc(N * (N + 1) * sizeof(int));
    int tmp;
    for(i = 0; i < N; i++)
    {
        prefix[i * (N + 1)] = 0;
        for(j = 1; j < N + 1; j++)
        {
            scanf("%d", &tmp);
            prefix[i * (N + 1) + j] = prefix[i * (N + 1) + j - 1] + tmp;
        }
    }
    int max = 0x80000000;
    int col_a, col_b;
    for(col_a = 0; col_a < N + 1; col_a++)
    {
        for(col_b = col_a + 1; col_b < N + 1; col_b++)
        {
            int cur_max = 0;
            for(i = 0; i < N; i++)
            {
                cur_max += prefix[col_b + i * (N + 1)] - prefix[col_a + i * (N + 1)];
                if(cur_max > max)
                    max = cur_max;
                if(cur_max < 0)
                {
                    cur_max = 0;
                }
            }
        }
    }
    printf("%d\n", max);
    return 0;
}

