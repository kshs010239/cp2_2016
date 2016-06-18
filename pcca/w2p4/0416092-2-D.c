#include <stdio.h>
#include <stdlib.h>

int cmp(char *a, char *b)
{
    int i;
    for(i = 0; a[i] != '\0'; i++)
    {
        if(a[i] > b[i])
            return 1;
        else if(a[i] < b[i])
            return -1;
    }
    return 0;
}

int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    getchar();
    char digit[n - 1];
    int sum = 0, i;
    for(i = 0; i < n - 1; i++)
        digit[i] = getchar();
    for(i = 0; i < n - 1; i++)
        sum += digit[i] - '0';
    int isroot[10], sum_temp,rootnum = 0;
    for(i = 0; i <= 9; i++)
    {
        sum_temp = sum + i;
        while(sum_temp >= 10)
            sum_temp = sum_temp / 100 + (sum_temp / 10) % 10 + sum_temp % 10;
        if(sum_temp == r)
        {
            isroot[i] = 1;
            rootnum++;
        }
        else
            isroot[i] = 0;
    }
    char ans[n * rootnum][n + 1];
    int k = 0, j, rplace, root;
    for(root = 0; root <= 9; root++)
        if(isroot[root] == 1)
            for(rplace = 0; rplace < n; rplace++)
            {
                for(j = 0; j < rplace; j++)
                    ans[k][j] = digit[j];
                ans[k][j] = root + '0';
                for(j = rplace + 1; j < n; j++)
                    ans[k][j] = digit[j - 1];
                ans[k][j] = '\0';
                if(k != 0)
                {
                    for(j = 0; j < n; j++)
                        if(ans[k][j] != ans[k - 1][j])
                            break;
                    if(j == n)
                        k--;
                }
                k++;
            }
    qsort(ans, k, sizeof(ans[0]), cmp);
    for(i = 1; i < k - 1; i++)
    {
            printf("%s\n", ans[i]);
    }
    return 0;
}



