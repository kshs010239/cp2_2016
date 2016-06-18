#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int i, n;
        unsigned long long t;
        scanf("%d %lld", &n, &t);
        int statue[n];
        for(i = 0; i < n; i++)
        {
            scanf("%d", statue + i);
        }
        int binary_code[n];
        binary_code[n - 1] = !statue[n - 1];
        for(i = n - 2; i >= 0; i--)
        {
            binary_code[i] = !(statue[i] ^ binary_code[i + 1]);
        }


        int max = n > 63 ? 63 : n;
        for(i = 63; i < n; i++)
        {
            if(binary_code[i])
                break;
        }
        unsigned long long bi_sum = 0;
        if(i == n || n < 63)
        {
            for(i = 0; i < max; i++)
            {
                bi_sum += ((unsigned long long)binary_code[i] << i);
            }
            if(t >= bi_sum)
            {
                printf("%d\n", n);
                continue;
            }
        }

        int black = 0;
        for(i = n - 1; i > max - 1; i--)
        {
            black += statue[i];
        }
        int pre_t = 0;
        if(t & ((unsigned long long)1 << (max - 1)))
        {
            pre_t = 1;
            black += !statue[max - 1];
        }
        else
            black += statue[max - 1];
        for(i = max - 2; i >= 0; i--)
        {
            int temp = (t & ((unsigned long long)1 << i)) ? 1 : 0;
            black += (temp ^ pre_t) ? !statue[i] : statue[i];
            pre_t = temp ? 1 : 0;
        }
        printf("%d\n", black);
    }
    return 0;
}
