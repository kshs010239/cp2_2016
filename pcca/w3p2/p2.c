#include <stdio.h>
#include <stdlib.h>

void rec(int t, int n, int x[n], int xNum[n], int depth, int *hasAns)
{
    static int seq[12] = {0};
    static int seqLen = 0;
    static int sum = 0;
    int i;
    if(sum == t && x[depth - 1] != x[depth - 2])
    {
        printf("%d", seq[0]);
        for(i = 1; i < seqLen; i++)
            printf("+%d", seq[i]);
        *hasAns = 1;
        puts("");
        return;
    }
    if(depth == n || sum > t)
    {
        return;
    }
    for(i = 0; i < xNum[depth]; i++)
    {
        seq[seqLen++] = x[depth];
        sum += x[depth];
    }
    rec(t, n, x, xNum, depth + 1, hasAns);
    for(i = 0; i < xNum[depth]; i++)
    {
        seqLen--;
        sum -= x[depth];
        rec(t, n, x, xNum, depth + 1, hasAns);
    }
    return;
}

int main()
{
    int t, n, i, j;
    while(scanf("%d %d", &t, &n) && n != 0)
    {
        int *x = malloc(n * sizeof(int)), *xNum = malloc(n * sizeof(int));
        for(i = 0; i < n; i++)
            xNum[i] = 0;
        j = 1;
        scanf("%d", x);
        xNum[0] = 1;
        for(i = 1; i < n; i++)
        {
            scanf("%d", x + j);
            if(x[j] == x[j - 1])
            {
                xNum[--j]++;
            }
            else
                xNum[j]++;
            j++;
        }
        int hasAns = 0;
        printf("Sums of %d:\n", t);
        rec(t, j, x, xNum, 0, &hasAns);
        if(hasAns == 0)
            puts("NONE");
    }
    return 0;
}











