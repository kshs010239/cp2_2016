#include <stdio.h>
#include <stdlib.h>




int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int amount;
        scanf("%d", &amount);
        int* map = malloc(amount * sizeof(int));
        int i;
        int sum = 0;
        for(i = 0; i < amount; i++)
        {
            scanf("%d", map + i);
            sum += map[i];
        }
        int new_map[50001] = {0};
        new_map[0] = 1;
        for(i = 0; i < amount; i++)
        {
            int j;
            for(j = sum; j >= 0; j--)
            {
                if(new_map[j] == 1)
                {
                    new_map[j + map[i]] = 1;
                }
            }
        }
        int min = 1e9;
        for(i = sum; i >= 0; i--)
        {
            int dif = sum - 2 * i;
            if(dif < 0)
                dif *= -1;
            if(new_map[i] && dif < min)
            {
                min = dif;
            }
        }
        printf("%d\n", min);

    }
    return 0;
}

        /*int* new_map = malloc(amount * sizeof(int));
        int* map_amount = malloc(amount * sizeof(int));
        for(i = 0; i < amount; i++)
            map_amount[i] = 0;
        int size = 0;
        new_map[0] = map[0];
        map_amount[0]++;
        for(i = 1; i < amount; i++)
        {
            if(map[i] != new_map[size])
                new_map[++size] = map[i];
            map_amount[size]++;
        }*/

        /*int min = 0x7FFFFFFF;
        int cur = 0;
        rec(size, new_map, map_amount, size, sum, &min, &cur);
        printf("%d\n", min);*/

/*void rec(int size, int map[size], int map_amount[size], int pos, int sum, int* min, int* cur)
{
    int dif = (sum - 2 * *cur);
    if(dif < 0)
        return;
    if(dif < *min)
        *min = dif;
    if(*min == 0)
        return;
    if(pos < 0)
        return;

    int i;
    *cur += map[pos] * (map_amount[pos] + 1);
    for(i = 0; i <= map_amount[pos]; i++)
    {
        *cur -= map[pos];
        rec(size, map, map_amount, pos - 1, sum, min, cur);
    }
}*/
