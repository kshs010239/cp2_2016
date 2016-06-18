#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    while(scanf("%d", &n) && n)
    {
        while(1)
        {
            int num[n];
            scanf("%d", num);
            if(*num == 0)
                break;
            for(i = 1; i < n; i++)
            {
                scanf("%d", num + i);
            }
            int temp = num[0];
            int used[n + 1];
            for(i = 0; i < n + 1; i++)
                used[i] = 0;
            used[num[0]] = 1;
            for(i = 1; i < n; i++)
            {
                if(temp - 1 > num[i])
                {
                    for(j = temp - 1; j > num[i]; j--)
                    {
                        if(!used[j])
                            break;
                    }
                    if(j != num[i])
                        break;
                }
                temp = num[i];
                used[num[i]] = 1;
            }
            if(i == n)
                puts("Yes");
            else
                puts("No");
        }
        puts("");
    }
    return 0;
}
