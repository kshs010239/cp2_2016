#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

void trans(char &tmp)
{
    if(tmp <= 'Z' && tmp >= 'A')
        tmp = tmp - 'A';
    else
        tmp = tmp - 'a' + 26;
}


int main()
{
    int n;
    int cnt = 1;
    while(1)
    {
        scanf("%d", &n);
        if(n == -1)
            break;
        vector<int> path[52];
        int amount = 0;
        for(int i = 0; i < n; i++)
        {
            char start, end;
            cin >> start >> end;
            trans(start);
            trans(end);
            path[start].push_back(end);
            path[end].push_back(start);
        }

        for(int i = 0; i < 52; i++)
            if(!path[i].empty())
                amount++;
        int goods;
        char start, end;
        cin >> goods >> start >> end;
        trans(start);
        trans(end);
        int d[52];
        for(int i = 0; i < 52; i++)
            d[i] = 0x7FFFFFFF;
        d[end] = goods;
        for(int i = 0; i < amount; i++)
            for(int j = 0; j < 52; j++)
                for(int k = 0; k < path[j].size(); k++)
                {
                    int tmp = (j < 26 ? (d[j] + ((d[j] + 18) / 19)) : (d[j] + 1));
                    if(d[path[j][k]] > tmp && tmp >= 0)
                        d[path[j][k]] = tmp;
                }
        printf("Case %d: %d\n", cnt++, d[start]);
    }
    return 0;
}
