#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void rec(vector<int> pairs[], int used[], int loc[], int& disable, int& one, int& two, int value)
{
    if(disable || used[value])
        return;
    used[value] = 1;
    int pos;
    for(pos = 0; pos < (int)pairs[value].size(); pos++)
    {
        int& a = loc[value];
        int tmp = pairs[value][pos];
        int& b = loc[tmp];
        if(a == b  && a != 0)
        {
            disable = 1;
            return;
        }
        else if(a == b)
        {
            a = 1;
            one++;
            b = 2;
            two++;
        }
        else if(a != 0 && b == 0)
        {
            if(a == 1)
            {
                b = 2;
                two++;
            }
            else
            {
                b = 1;
                one++;
            }
        }
        rec(pairs, used, loc, disable, one, two, pairs[value][pos]);
    }
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    int tmp = a.first - a.second;
    int tmp2 = b.first - b.second;
    if(tmp < 0)
        tmp *= -1;
    if(tmp2 < 0)
        tmp2 *= -1;
    return tmp > tmp2? 1 : -1;
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
        if(n == 0)
        {
            cout << 0 << endl;
            continue;
        }
        vector<int> pairs[n];
        for(i = 0; i < m; i++)
        {
            int tmp1, tmp2;
            scanf("%d %d", &tmp1, &tmp2);
            tmp1--;
            tmp2--;
            pairs[tmp1].push_back(tmp2);
            pairs[tmp2].push_back(tmp1);
        }
        int loc[n];
        int used[n];
        for(i = 0; i < n; i++)
        {
            loc[i] = 0;
            used[i] = 0;
        }
        int disable = 0;
        int total = 0;
        vector<int> dif;
        for(i = 0; i < n; i++)
        {
            int one = 0, two = 0;
            rec(pairs, used, loc, disable, one, two, i);
            if(disable)
                break;
            if(one == 0)
                continue;
            if(two > one)
            {
                int tmp = one;
                one = two;
                two = tmp;
            }
            total += one + two;
            dif.push_back(one - two);
        }
        if(disable)
        {
            puts("-1");
            continue;
        }

        int DP[1000] = {0};
        if(!dif.empty())
        {
            DP[500 + dif[0]] = 1;
            DP[500 - dif[0]] = 1;
        }
        for(i = 1; i < dif.size(); i++)
        {
            vector<int> pos;
            for(int j = 0; j < 1000; j++)
            {
                if(DP[j])
                {
                    pos.push_back(j);
                }
            }
            for(int j = 0; j < pos.size(); j++)
                DP[pos[j]] = 0;
            for(int j = 0; j < pos.size(); j++)
            {
                DP[pos[j] + dif[i]] = 1;
                DP[pos[j] - dif[i]] = 1;
            }
        }

        if(dif.empty())
        {
            printf("%d\n", (n + 1) / 2);
        }
        else
        {
            int mid = 500;
            for(i = 0; i < 500; i++)
            {
                if(DP[mid + i] || DP[mid - i])
                {
                    break;
                }
            }
            int d = i;
            printf("%d\n", std::max((total + d) / 2, (n + 1) / 2));
        }
    }
    return 0;
}
