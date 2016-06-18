#include <stdio.h>
#include <stdlib.h>

int main()
{

    freopen("123.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, i;
        scanf("%d", &n);
        int a[n];
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        int group;
        int inversion = 0;
        for(group = 2; group <= 2 * n; group *= 2)
        {
            for(i = 0; i <= n - group; i += group)
            {
                int j;
                int temp[group], first_g = i, second_g = i + group / 2;
                for(j = 0; j < group; j++)
                {
                    if(first_g >= group / 2 + i)
                        temp[j] = a[second_g++];
                    else if(second_g >= group + i)
                        temp[j] = a[first_g++];
                    else if(a[first_g] <= a[second_g])
                        temp[j] = a[first_g++];
                    else if(a[first_g] > a[second_g])
                    {
                        temp[j] = a[second_g++];
                        inversion += i + group / 2 - first_g;
                    }
                }
                for(j = 0; j < group; j++)
                    a[i + j] = temp[j];
            }

            if(n - i <= group / 2)
            {
                continue;
            }

            int temp[n - 1], first_g = i, second_g = i + group / 2;
            int j;
            for(j = 0; j < n - i; j++)
            {
                if(first_g >= group / 2 + i)
                    temp[j] = a[second_g++];
                else if(second_g >= n)
                    temp[j] = a[first_g++];
                else if(a[first_g] <= a[second_g])
                    temp[j] = a[first_g++];
                else if(a[first_g] > a[second_g])
                {
                    temp[j] = a[second_g++];
                    inversion += i + group / 2 - first_g;
                }
            }
            for(j = 0; j < n - i; j++)
                a[i + j] = temp[j];

        }
        printf("%d\n", inversion);
    }
    return 0;
}
