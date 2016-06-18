#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, w, m;
        scanf("%d %d %d", &n, &w, &m);
        int a[n];
        int max;
        for(i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            if(!i || a[i] > a[i - 1])
                max = a[i];
        }
        for(i = 0; i < n; i++)
        {
            if(a[i] != 0)
                break;
        }
        if(i == n)
        {
            puts("0");
            continue;
        }
        for(i = 1; i < max; i *= 2);
        int x = i;
        int step = i;
        int cnt;
        int temp[n];
        int first = 1;
        while(step)
        {
            step /= 2;
            for(i = 0; i < n; i++)
            {
                temp[i] = a[i];
            }
            cnt = 0;
            for(i = 0; i < n - w; i++)
            {
                if(temp[i])
                {
                    int sub;
                    if(temp[i] % x)
                    {
                        sub = (temp[i] / x + 1) * x;
                        cnt += temp[i] / x + 1;
                    }
                    else
                    {
                        sub = temp[i] / x * x;
                        cnt += temp[i] / x;
                    }
                    for(j = i; j < i + w; j++)
                    {
                        if(temp[j] >= sub)
                        {
                            temp[j] -= sub;
                        }
                        else
                            temp[j] = 0;
                    }
                }
            }
            for(; i < n; i++)
            {

                if(temp[i])
                {
                    int sub;
                    if(temp[i] % x)
                    {
                        sub = (temp[i] / x + 1) * x;
                        cnt += temp[i] / x + 1;
                    }
                    else
                    {
                        sub = temp[i] / x * x;
                        cnt += temp[i] / x;
                    }
                    for(j = i; j < n; j++)
                    {
                        if(temp[j] >= sub)
                            temp[j] -= sub;
                        else
                        {
                            temp[j] = 0;
                        }
                    }
                }
            }
            if(cnt > m && first == 1)
                break;
            else
                first = 0;
            if(cnt <= m)
                x -= step;
            if(cnt > m)
                x += step ? step : step + 1;
        }
        if(cnt > m && first == 1)
        {
            puts("-1");
            continue;
        }
        printf("%d\n", x);
    }
    return 0;
}
