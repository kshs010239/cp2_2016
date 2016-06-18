#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int m, k;
        scanf("%d %d", &m, &k);
        int i;
        int* p = malloc(m * sizeof(int));
        long long int min = 0, max = 0;
        for(i = 0; i < m; i++)
        {
            scanf("%d", p + i);
            if(p[i] > min)
                min = p[i];
            max += p[i];
        }
        while(max > min)
        {
            long long int mid = (max + min) / 2;
            long long int tmp = 0;
            int amount = 0;
            for(i = 0; i < m; i++)
            {
                if(tmp + p[i] > mid)
                {
                    amount++;
                    tmp = 0;
                }
                tmp += p[i];
            }
            if(amount < k)
                max = mid;
            else
                min = mid + 1;
        }
        int* div = malloc(m * sizeof(int));
        for(i = 0; i < m; i++)
            div[i] = 0;
        int sum = 0;
        int amount = k;
        for(i = m - 1; i >=0; i--)
        {
            if(amount > i + 1)
            {
                for(; i >= 0; i--)
                    div[i] = 1;
                break;
            }
            if(sum + p[i] > min)
            {
                div[i] = 1;
                sum = 0;
                amount--;
            }
            sum += p[i];
        }
        for(i = 0; i < m - 1; i++)
        {
            printf("%d ", p[i]);
            if(div[i] == 1)
                printf("/ ");
        }
        printf("%d\n", p[i]);
    }
    return 0;
}


