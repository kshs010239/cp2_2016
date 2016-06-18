#include <stdio.h>
#include <stdlib.h>

struct turtle_s
{
    int weight;
    int strength;
};
int cmp(struct turtle_s *a, struct turtle_s *b)
{
    return a->strength > b->strength;
}
int cmp2(struct turtle_s *a, struct turtle_s *b)
{
    return a->weight > b->weight;
}

int main()
{
    struct turtle_s turtle[5607];
    int size = 0;
    while(scanf("%d %d", &turtle[size].weight, &turtle[size].strength) != EOF) size++;
    qsort(turtle, size, sizeof(struct turtle_s), cmp);
    int i;
    int weight = 0;
    struct turtle_s* tmp = malloc(size * sizeof(struct turtle_s));
    int cnt = -1;
    for(i = 0; i < size; i++)
    {
        weight += turtle[i].weight;
        tmp[++cnt] = turtle[i];
        qsort(tmp, cnt + 1, sizeof(struct turtle_s), cmp2);
        if(weight > turtle[i].strength)
        {
            weight -= tmp[cnt].weight;
            cnt--;
        }
    }
    printf("%d\n", cnt + 1);
    return 0;
}
