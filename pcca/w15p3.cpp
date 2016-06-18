#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void mul(vector< vector < int > >& city1, vector< vector < int > > city2)
{
    int size = city1.size();
    vector< vector < int > > tmp;
    tmp.resize(size);
    for(int i = 0; i < size; i++)
    {
        tmp[i].resize(size);
        for(int j = 0; j < size; j++)
        {
            tmp[i][j] = 0;
            for(int k = 0; k < size; k++)
            {
                if(city1[i][k] != 0 && city2[k][j] != 0)
                    tmp[i][j] = std::max(tmp[i][j], city1[i][k] + city2[k][j]);
            }
        }
    }
    city1 = tmp;
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        vector< vector < int > > city;
        city.resize(n);
        for(int i = 0; i < n; i++)
        {
            city[i].resize(n);
            for(int j = 0; j < n; j++)
                city[i][j] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            int start, end, w;
            scanf("%d %d %d", &start, &end, &w);
            if(city[start - 1][end - 1] < w || city[start - 1][end - 1] == 0)
                city[start - 1][end - 1] = w;
        }
        vector< vector < int > > base, matrix;
        base = matrix = city;
        k--;
        while(k > 0)
        {
            if(k % 2)
            {
                mul(matrix, base);
                k--;
            }
            else
            {
                mul(base, base);
                k /= 2;
            }
        }
        for(int i = 0; i < q; i++)
        {
            int start, end;
            scanf("%d %d", &start, &end);
            printf("%d\n", matrix[start - 1][end - 1]);
        }
    }
}
