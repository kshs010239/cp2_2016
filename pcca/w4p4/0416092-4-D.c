#include <stdio.h>
#include <stdlib.h>

int exgcd(int a, int b, int *x, int *y)
{
    if(b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = *x;
    *x = *y;
    *y = t - (a / b) * (*y);
    return r;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    if(n == m)
    {
        printf("%d\n", n);
        return 0;
    }
    if(n == 1 || m == 1)
    {
        puts("2");
        return 0;
    }
    if(n < m)
    {
        int t = n;
        n = m;
        m = t;
    }
    int x, y;
    int r = exgcd(n, m, &x, &y);
    if(r > 1)
    {
        printf("%lld", (long long)n * m / r);
    }
    else
        printf("%lld", x > 0 ? (long long)n * x : (long long)m * y);
    return 0;
}

