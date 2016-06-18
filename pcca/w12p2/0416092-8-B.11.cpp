#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<iostream>

using namespace std;

void rec(int p[], vector<int> path[], int num, int used[], long long* value)
{
    if(used[num])
        return;
    (*value) += (long long)p[num];
    used[num] = 1;
    for(int i = 0; i < path[num].size(); i++)
    {
        rec(p, path, path[num][i], used, value);
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
        if(n == 0)
        {
            cout << 0 << endl;
            continue;
        }

        int* popularity = new int[n];
        int i;
        for(i = 0; i < n; i++)
            scanf("%d", popularity + i);
        vector<int> *path = new vector<int>[n];
        for(i = 0; i < 2 * m; i += 2)
        {
            int tmp1, tmp2;
            scanf("%d %d", &tmp1, &tmp2);
            tmp1--;
            tmp2--;
            path[tmp1].push_back(tmp2);
            path[tmp2].push_back(tmp1);
        }
        int* used = new int[n];
        for(i = 0; i < n; i++)
            used[i] = 0;
        long long sum = 0;
        for(i = 0; i < n; i++)
        {
            long long tmp = 0;
            rec(popularity, path, i, used, &tmp);
            if(tmp > sum)
                sum = tmp;
        }
        cout << sum << endl;
        delete[] popularity;
        delete[] path;
    }
}
