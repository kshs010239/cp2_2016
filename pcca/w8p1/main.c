#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("1232.txt","r",stdin);
    //while(1)
    //{

        int N, i;
        scanf("%d", &N);
        int* prefix = malloc(N * (N + 1) * sizeof(int));
        int tmp;

        scanf("%d", prefix);
        for(i = 1; i < N; i++)
        {
            scanf("%d", &tmp);
            prefix[i] = tmp + prefix[i - 1];
        }
        for(i = 1; i < N; i++)
        {
            scanf("%d", &tmp);
            prefix[i * N] = prefix[(i - 1) * N] + tmp;
            int j;
            for(j = 1; j < N; j++)
            {
                scanf("%d", &tmp);
                prefix[i * N + j] = prefix[(i - 1) * N + j] + prefix[i * N + j - 1] - prefix[(i - 1) * N + j - 1] + tmp;
            }
        }

        int max = 0x80000000;
        int high, wide;
        int j;
        for(high = 0; high < N; high++)
        {
            for(wide = 0; wide < N; wide++)
            {
                if(prefix[high * N + wide] > max)
                    max = prefix[high * N + wide];

                for(i = 1; i < N - wide; i++)
                {
                    const int tmp = prefix[high * N + wide + i] - prefix[high * N + i - 1];
                    if(tmp > max)
                        max = tmp;
                }
                for(i = 1; i < N - high; i++)
                {
                    const int tmp = prefix[(high + i) * N + wide] - prefix[(i - 1) * N + wide];
                    if(tmp > max)
                        max = tmp;

                    for(j = 1; j < N - wide; j++)
                    {
                        const int tmp2 = prefix[(high + i) * N + wide + j] - prefix[(high + i) * N + j - 1] - prefix[(i - 1) * N + wide + j] + prefix[(i - 1) * N + (j - 1)];
                        if(tmp2 > max)
                            max = tmp2;
                    }
                }
            }
        }
        printf("%d\n", max);
    //}
    return 0;
}

