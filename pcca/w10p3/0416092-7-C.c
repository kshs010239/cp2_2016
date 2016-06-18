#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int string[], int a, int b)
{
    int i;
    int tmp = string[b];
    for(i = b - 1; i >= a; i--)
    {
        string[i + 1] = string[i];
    }
    string[a] = tmp;
}

int test(int size, int string[])
{
    int used[10] = {0};
    int ordered = 0;
    int i;
    for(i = 0; i < size; i++)
    {
        if(used[i])
            continue;
        ordered++;
        int j;
        int k = i;
        for(j = i + 1; j < size; j++)
        {
            if(string[j] == string[k] + 1)
            {
                used[j] = 1;
                k = j;
            }
        }
    }
    if(ordered > 3)
        return (ordered - 3) / 2 + 2;
    else
        return ordered - 1;
}
int value(int size, int string[])
{
    static const int map[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
    int i;
    int ans = 0;
    int used[10] = {0};
    for(i = 0; i < size; i++)
    {
        int k = 0;
        int j;
        for(j = 1; j < string[i]; j++)
        {
            if(!used[j])
                k++;
        }
        ans += k * map[size - i - 1];
        used[string[i]] = 1;
    }
    return ans;
}

void rec(int size, int string[], int depth, int depth_limit, int *found, int used[])
{
    const int value_tmp = value(size, string);
    if(depth >= used[value_tmp] && used[value_tmp] != 0)
        return;
    else
        used[value_tmp] = depth;
    if(*found)
        return;
    int wide, i;
    for(i = 0; i < size; i++)
        if(string[i] != i + 1) break;
    if(i == size)
    {
        *found = 1;
        return;
    }
    if(depth == depth_limit)
        return;

    int string_tmp[10];
    for(wide = 1; wide < size; wide++)
    {
        for(i = 0; i < size - wide; i++)
        {
            int j;
            for(j = 0; j < size; j++)
            {
                string_tmp[j] = string[j];
            }
            for(j = i; j < size - wide; j++)
            {
                swap(string_tmp, j, j + wide);
                if(depth + test(size, string_tmp) < depth_limit)
                    rec(size, string_tmp, depth + 1, depth_limit, found, used);
            }
        }
    }
}

int main()
{
    int amount;
    int number = 1;
    while(1)
    {
        scanf("%d", &amount);
        if(amount == 0)
            break;
        int i;
        int paragraph[10];
        for(i = 0; i < amount; i++)
            scanf("%d", &paragraph[i]);

        int found = 0;
        int cnt = 0;
        for(; found == 0; cnt++)
        {
            int used[450000] = {0};
            rec(amount, paragraph, 0, cnt, &found, used);
        }
        printf("Case %d: %d\n", number++, cnt - 1);
    }
    return 0;
}
