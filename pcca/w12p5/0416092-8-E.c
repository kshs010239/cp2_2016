#include <stdio.h>
#include <stdlib.h>


struct Pair
{
    int a, b;
};
int find(struct Pair map[], int size, int value)
{
    int max = size - 1;
    int min = 0;
    while(max > min)
    {
        int mid = (max + min) / 2;
        if(map[mid].a >= value)
            max = mid;
        else
            min = mid + 1;
    }
    return min;
}

int cmp(const void *a, const void *b)
{
    return ((struct Pair*)a)->a > ((struct Pair*)b)->a? 1 : -1;
}

void rec(struct Pair pair[], int used[], int loc[], int size, int* disable, int value)
{
    if(*disable || used[value])
        return;
    used[value] = 1;
    int pos;
    for(pos = find(pair, size, value); pair[pos].a == value; pos++)
    {
        int a = loc[value], b = loc[pair[pos].b];
        if(a == b  && a != 0)
        {
            *disable = 1;
            return;
        }
        else if(a == b)
        {
            loc[value] = 1;
            loc[pair[pos].b] = 2;
        }
        else if(a != 0 && b == 0)
        {
            if(a == 1)
                loc[pair[pos].b] = 2;
            else
                loc[pair[pos].b] = 1;
        }
        else if(a == 0 && b != 0)
        {
            if(b == 1)
                loc[value] = 2;
            else
                loc[value] = 1;
        }
        rec(pair, used, loc, size, disable, pair[pos].b);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int i;
        struct Pair* pair = malloc(2 * m * sizeof(struct Pair));
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &pair[i].a, &pair[i].b);
            pair[i].a--;
            pair[i].b--;
            pair[m + i].a = pair[i].b;
            pair[m + i].b = pair[i].a;
        }
        qsort(pair, 2 * m, sizeof(pair[0]), cmp);
        int loc[n], used[n];
        for(i = 0; i < n; i++)
            loc[i] = used[i] = 0;
        //for(i = 0; i < 2 * m; i++)
        //    printf("%d %d\n", pair[i].a, pair[i].b);
        int disable = 0;
        for(i = 0; i < n; i++)
        {
            rec(pair, used, loc, n, &disable, i);
            if(disable)
                break;
        }
        if(disable)
            puts("-1");
        else
        {
            int one = 0, two = 0;
            for(i = 0; i < n; i++)
            {
                if(loc[i] == 1)
                    one++;
                if(loc[i] == 2)
                    two++;
            }
            int max = one;
            if(two > max)
                max = two;
            if((n + 1) / 2 > max)
                max = (n + 1) / 2;
            printf("%d\n", max);
        }
    }
    return 0;
}
