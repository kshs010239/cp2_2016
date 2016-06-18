#include<stdio.h>
#include<stdlib.h>

void check(int map[], int used[], int n, int m, int* cnt, int pos)
{
    if(used[pos])
        return;
    used[pos] = 1;
    (*cnt)++;
    if(pos % m > 0 && map[pos - 1] == 1)
        check(map, used, n, m, cnt, pos - 1);
    if(pos % m < m - 1 && map[pos + 1] == 1)
        check(map, used, n, m, cnt, pos + 1);
    if(pos >= m && map[pos - m] == 1)
        check(map, used, n, m, cnt, pos - m);
    if(pos < (n - 1) * m && map[pos + m] == 1)
        check(map, used, n, m, cnt, pos + m);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int* map = malloc(n * m * sizeof(int));
    int cnt = 0;
    int i, j;
    for(i = 0; i < n; i++)
    {
        getchar();
        for(j = 0; j < m; j++)
        {
            char tmp;
            scanf("%c", &tmp);
            if(tmp == '#')
            {
                cnt++;
                map[i * m + j] = 1;
            }
            else
                map[i * m + j] = 0;
        }
    }
    if(cnt < 3)
        puts("-1");
    else
    {
        int ans = 2;
        for(i = 0; i < n * m; i++)
        {
            if(map[i] == 1)
            {
                int tmp = 0;
                map[i] = 0;
                int used[n * m];
                for(j = 0; j < n * m; j++)
                    used[j] = 0;
                if(i % m < m - 1 && map[i + 1] == 1)
                    check(map, used, n, m, &tmp, i + 1);
                else if(i % m > 0 && map[i - 1] == 1)
                    check(map, used, n, m, &tmp, i - 1);
                else if(i >= m && map[i - m] == 1)
                    check(map, used, n, m, &tmp, i - m);
                else
                    check(map, used, n, m, &tmp, i + m);
                if(tmp < cnt - 1)
                    ans = 1;
                map[i] = 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
