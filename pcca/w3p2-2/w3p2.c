#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int t, n, i, j;
    while(scanf("%d %d", &t, &n) && n != 0)
    {
        int *x = malloc(n * sizeof(int));

        for(i = 0; i < n; i++)
        {
            scanf("%d", x + i);
        }
        int temp = (int)pow(2, n);
        for(i = temp - 1; i >= 0; i--)
        {
            int sum = 0;
            int seq[12];
            int seqLen = 0;
            for(j = 0; j < n; j++)
            {
                if((int)(i / pow(2, n - j - 1)) % 2)
                {
                    sum += x[j];
                    seq[seqLen++] = x[j];
                }
            }
            if(sum == t)
            {
                printf("%d", seq[0]);
                int k;
                for(k = 1; k < seqLen; k++)
                    printf("+%d", seq[k]);
                puts("");
            }
        }
    }
    return 0;
}
