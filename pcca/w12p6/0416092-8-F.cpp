#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


void rec(vector<int> connection[], int size[], int used[], int max, int dot)
{
    if(used[dot])
        return;
    used[dot] = 1;
    for(int i = 0; i < (int)connection[dot].size(); i++)
    {
        if(--size[connection[dot][i]] <= max)
            rec(connection, size, used, max, connection[dot][i]);
    }
}

int cmp(const void* a, const void* b)
{
    return ((pair<int, int>*)a)->second > ((pair<int, int>*)b)->second? 1 : -1;
}

int test(pair<int, int> pairs[], vector<int> connection[], int n, int max)
{
    int size[n], used[n];
    for(int i = 0; i < n; i++)
    {
        used[i] = 0;
        size[i] = connection[i].size();
    }
    for(int i = 0; i < n; i++)
    {
        if(size[pairs[i].first] > max)
            return 0;
        rec(connection, size, used, max, pairs[i].first);
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, e;
        cin >> n >> e;
        vector<int> connection[n];
        int* connect = new int[n];
        for(int i = 0; i < n; i++)
            connect[i] = 0;
        for(int i = 0; i < e; i++)
        {
            int tmp1, tmp2;
            scanf("%d %d", &tmp1, &tmp2);
            connect[std::min(tmp1, tmp2)]++;
            connection[tmp1].push_back(tmp2);
            connection[tmp2].push_back(tmp1);
        }
        int max = 0;
        for(int i = 0; i < n; i++)
        {
            if(connect[i] > max)
                max = connect[i];
        }
        printf("%d ", max);
        delete connect;

        pair<int, int> pairs[n];
        for(int i = 0; i < n; i++)
        {
            pairs[i].first = i;
            pairs[i].second = connection[i].size();
        }
        qsort(pairs, n, sizeof(pairs[0]), cmp);

        int min = 0;
        while(max > min)
        {
            int mid = (max + min) / 2;
            if(test(pairs, connection, n, mid))
            {
                max = mid;
            }
            else
            {
                min = mid + 1;
            }
        }
        printf("%d\n", min);
    }
    return 0;
}
