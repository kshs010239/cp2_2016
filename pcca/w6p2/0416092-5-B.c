#include <stdio.h>
#include <stdlib.h>

struct Line
{
    int l;
    int r;
};

int cmp(const void *a, const void *b)
{
    const struct Line *ta = a;
    const struct Line *tb = b;
    if(ta->l > tb->l)
        return 1;
    else
        return -1;
}

int main()
{

    int t;
    scanf("%d", &t);
    while(t--)
    {
        int m, left_bound = 0;
        scanf("%d", &m);
        struct Line line[100000];
        int i = 0;
        while(scanf("%d %d", &(line[i].l), &(line[i].r)) && (line[i].l || line[i].r)) i++;
        qsort(line, i, sizeof(struct Line), cmp);
        int length = i;

        int j = 0;
        i = 0;
        int cnt = 0;
        struct Line cover[5000];
        while(1)
        {
            int max = left_bound;
            for(; line[j].l <= left_bound && j < length; j++)
            {
                if(line[j].r > max)
                {
                    max = line[j].r;
                    cover[cnt] = line[j];
                }
            }
            if(max == left_bound)
            {
                puts("0");
                break;
            }
            left_bound = max;
            cnt++;
            if(left_bound >= m)
            {
                printf("%d\n", cnt);
                for(j = 0; j < cnt; j++)
                    printf("%d %d\n", cover[j].l, cover[j].r);
                break;
            }
            if(j >= length)
            {
                puts("0");
                break;
            }
        }
        puts("");
    }
    return 0;
}
