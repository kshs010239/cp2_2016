#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int Case;
    cin >> Case;
    while(Case--)
    {
        int n, m, s, t;
        scanf("%d %d %d %d", &n, &m, &s, &t);
        s--;
        t--;
        int h[n];
        for(int i = 0; i < n; i++)
            scanf("%d", h + i);
        vector<int> d;
        d.resize(n);
        for(int i = 0; i < n; i++)
        {
            d[i] = (1 << 30);
        }
        d[s] = 0;
        vector< vector<int> > path;
        path.resize(n);
        for(int i = 0; i < m; i++)
        {
            int start, end, w;
            scanf("%d %d %d", &start, &end, &w);
            start--;
            end--;
            path[start].push_back(end);
            path[start].push_back(w - h[start] + h[end]);
            path[end].push_back(start);
            path[end].push_back(w - h[end] + h[start]);
        }
        
        
        
        int max = (1 << 30);
        int min = 0;
        while(max > min)
        {
            
            vector<int> d2 = d;
            int mid = (max + min) / 2;
            queue<int> q;
            q.push(s);
            int inQ[n];
            for(int i = 0; i < n; i++) inQ[i] = 0;
            inQ[s] = 1;
            int flag = 0;
            while(!q.empty())
            {
                int start = q.front();
                q.pop();
                inQ[start] = 0;
                for(int i = 0; i < path[start].size(); i += 2)
                {
                    int end = path[start][i], w = path[start][i + 1];
                    if(d2[end] > d2[start] + w && d2[start] + w <= mid && d2[start] <= mid)
                    {
                        if(end == t)
                            flag = 1;
                        d2[end] = d2[start] + w;
                        if(inQ[end] == 0)
                        {
                            inQ[end] = 1;
                            q.push(end);
                        }
                    }
                }
                if(flag)
                    break;
            }
            if(flag)
                max = mid;
            else
                min = mid + 1;
        }
        printf("%d\n", max);
    }
    return 0;
}