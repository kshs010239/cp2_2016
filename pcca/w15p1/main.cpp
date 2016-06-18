#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    int cnt = 0;
    while(scanf("%d", &n) && n)
    {
        int i, j, k, x[n], y[n];

        for(i = 0; i < n; i++)
            scanf("%d %d", &x[i], &y[i]);

        int *w[n], d[n];
        for(i = 0; i < n; i++)
            w[i] = (int *)malloc(n * sizeof(int));

        for(i = 0; i < n; i++)
        {
            d[i] = (int)pow((double)(x[i] - x[0]), 2) + (int)pow((double)(y[i] - y[0]), 2);
            for(j = 0; j < n; j++)
                w[i][j] = (int)pow((double)(x[i] - x[j]), 2) + (int)pow((double)(y[i] - y[j]), 2);
        }

        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                for(k = 0; k < n; k++)
                    if(d[j] > (d[k] > w[k][j]? d[k] : w[k][j]))
                        d[j] = (d[k] > w[k][j]? d[k] : w[k][j]);
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++cnt,sqrt((double)d[1]));
    }
    return 0;
}
