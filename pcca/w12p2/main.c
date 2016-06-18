#include<stdio.h>
#include<stdlib.h>

struct Path
{
    int start;
    int end;
};
int cmp(const void* a, const void* b)
{
    return (((struct Path*)a)->start > ((struct Path*)b)->start)? 1 : -1;
}

int find(struct Path tmp[], int value, int size)
{
    int max = size - 1;
    int min = 0;
    while(max > min)
    {
        int mid = (max + min) / 2;
        if(tmp[mid].start >= value)
            max = mid;
        else
            min = mid + 1;
    }
    if(tmp[max].start == value)
        return max;
    else
    {
        return max + 1;
    }
}

void rec(int p[], struct Path path[], int size, int num, int size_path, int used[], long long* value)
{
    if(used[num])
        return;
    (*value) += p[num];
    used[num] = 1;
    int i;
    for(i = find(path, num, size); path[i].start == num && i < size_path; i++)
    {
        rec(p, path, size, path[i].end, size_path, used, value);
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
        int* popularity = malloc(n * sizeof(int));
        int i;
        for(i = 0; i < n; i++)
            scanf("%d", popularity + i);

        int* start = malloc(m * sizeof(int));
        int* end = malloc(m * sizeof(int));

        /*struct Path* path = malloc(2 * m * sizeof(struct Path));
        for(i = 0; i < 2 * m; i += 2)
        {
            int tmp1, tmp2;
            scanf("%d %d", &tmp1, &tmp2);
            tmp1--;
            tmp2--;
            path[i].start = path[i + 1].end = tmp1;
            path[i].end = path[i + 1].start = tmp2;
        }
        qsort(path, 2 * m, sizeof(path[0]), cmp);
        int used[n];
        for(i = 0; i < n; i++)
            used[i] = 0;
        long long sum = 0;
        for(i = 0; i < n; i++)
        {
            long long tmp = 0;
            rec(popularity, path, n, i, 2 * m, used, &tmp);
            if(tmp > sum)
                sum = tmp;
        }
        printf("%lld\n", sum);
        free(popularity);
        free(path);*/
    }
}


