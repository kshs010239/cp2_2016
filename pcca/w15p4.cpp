#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

void square(int** matrix, int size)
{
    int** tmp = new int *[size];
    for(int i = 0; i < size; i++)
    {
        tmp[i] = new int[size];
        for(int j = 0; j < size; j++)
        {
            tmp[i][j] = matrix[i][j];
        }
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                if(matrix[i][k] != 0x7FFFFFFF && matrix[k][j] != 0x7FFFFFFF)
                    matrix[i][j] = std::min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    for(int i = 0; i < size; i++)
        delete[] tmp[i];
    delete tmp;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int** matrix = new int *[n];
        for(int i = 0; i < n; i++)
        {
            matrix[i] = new int[n];
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    matrix[i][j] = 0;
                else
                    matrix[i][j] = 0x7FFFFFFF;
            }
        }

        for(int i = 0; i < m; i++)
        {
            int start, end, w;
            scanf("%d %d %d", &start, &end, &w);
            start--;
            end--;
            if(matrix[start][end] > w)
            {
                matrix[start][end] = w;
            }
        }
        int amount = 0;
        int n_tmp = n;
        while(n_tmp != 1)
        {
            n_tmp /= 2;
            amount++;
        }
        while(amount--)
        {
            square(matrix, n);
        }
        int negCyc[n];
        for(int i = 0; i < n; i++)
        {
            if(matrix[i][i] < 0)
                negCyc[i] = 1;
            else
                negCyc[i] = 0;
        }
        
        int disconnect = 0, noshort = 0, hasshort = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0x7FFFFFFF)
                {
                    disconnect++;
                    continue;
                }
                int flag = 0;
                for(int k = 0; k < n; k++)
                {
                    if(matrix[i][k] != 0x7FFFFFFF && matrix[k][j] != 0x7FFFFFFF && negCyc[k])
                    {
                        noshort++;
                        flag = 1;
                        break;
                    }
                }
                if(!flag)
                {
                    hasshort++;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        printf("%d %d %d\n", disconnect, noshort, hasshort);
    }
    return 0;
}