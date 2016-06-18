#include <stdio.h>
#include <stdlib.h>

int log(int tmp)
{
    int cnt = 0;
    while(tmp)
    {
        tmp = tmp >> 1;
        cnt++;
    }
    return cnt;
}

int main()
{
    int n;
    while(scanf("%d", &n) && n)
    {
        int arr[100][100];
        int i, j, k;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                arr[i][j] = 0;
        }
        while(1)
        {
            int start;
            scanf("%d", &start);
            if(start == 0)
                break;
            int end;
            while(scanf("%d", &end) && end)
            {
                arr[start - 1][end - 1] = 1;
            }
        }
        int cnt = log(n);
        while(cnt--)
        {
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < n; j++)
                {
                    for(k = 0; k < n; k++)
                    {
                        arr[i][j] = arr[i][j] || (arr[i][k] && arr[k][j]);
                    }
                }
            }
        }
        int m;
        scanf("%d", &m);
        for(i = 0; i < m; i++)
        {
            int test;
            scanf("%d", &test);
            test--;
            int cnt = 0;
            int tmp[100];
            for(j = 0; j < n; j++)
            {
               if(arr[test][j] == 0)
               {
                   tmp[cnt++] = j;
               }
            }
            printf("%d", cnt);
            for(j = 0; j < cnt; j++)
                printf(" %d", tmp[j] + 1);
            puts("");
        }
    }
    return 0;
}
