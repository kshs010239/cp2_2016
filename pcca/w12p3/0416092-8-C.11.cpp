#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

set<int> BFS(vector<int> path[], int n, int &cnt)
{
    queue<int> q;
    set<int> p[n];
    int used[n];
    int next[n];
    int size[n];
    int amount = n;
    for(int i = 0; i < n; i++)
    {
        used[i] = 0;
        next[i] = 0;
        size[i] = path[i].size();
    }

    for(int i = 0; i < n; i++)
    {
        if(path[i].size() == 1)
        {
            q.push(i);
            p[0].insert(i);
        }
    }
    next[0] = q.size();
    int current;
    while(!q.empty())
    {
        if(!next[cnt])
        {
            cnt++;
            if(amount == 2)
            {
                return p[cnt++];
            }
            else if(amount == 1)
            {
                return p[cnt];
            }
        }
        amount--;
        current = q.front();
        used[current] = 1;

        for(int i = 0; i < path[current].size(); i++)
        {
            int tmp = path[current][i];
            size[tmp]--;
            if(!used[tmp] && size[tmp] < 2)
            {
                q.push(tmp);
                next[cnt + 1]++;
                p[cnt + 1].insert(tmp);
            }
        }

        q.pop();
        next[cnt]--;
    }
    return p[cnt];
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n == 1)
        {
            printf("%d %d\n%d\n", 1, 0, 1);
        }
        vector<int>* path = new vector<int>[n];
        int tmp1, tmp2;
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d %d", &tmp1, &tmp2);
            tmp1--;
            tmp2--;
            path[tmp1].push_back(tmp2);
            path[tmp2].push_back(tmp1);
        }
        int cnt = 0;
        set<int> p = BFS(path, n, cnt);
        printf("%d %d\n", p.size(), cnt - 1);
        auto it = p.begin();
        printf("%d", *(it++) + 1);
        for(; it != p.end(); it++)
            printf(" %d", *it + 1);
        puts("");
        delete[] path;
    }
    return 0;
}
