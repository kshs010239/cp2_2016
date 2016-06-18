#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n;
    scanf("%d", &n);
    int tmp, num[n + 1];
    for(i = 0; i < n + 1; i++) num[i] = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if(tmp <= n)
            num[tmp]++;
    }
    int cnt = 0;
    int cnt_t = 0;
    for(i = 0; i < n + 1; i++)
    {
        if(cnt + num[i] + cnt_t - 1 < i)
        {
            cnt_t += num[i];
        }
        else
        {
            cnt += num[i] + cnt_t;
            cnt_t = 0;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
