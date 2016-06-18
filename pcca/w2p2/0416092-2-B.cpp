#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
    int n, i;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        int r[10000];
        for(i = 0; i < n; i++)
        {
            scanf("%d", r + i);
        }

        sort(r, r + i);
        int s[10001];
        s[0] = 0;
        for(i = 0; i < n; i++)
        {
            s[i + 1] = s[i] + r[i];
        }
        for(i = n; i > 0; i--)
        {
            if(s[i] <= s[i - 1] * 2)
                break;
        }
        printf("%d\n", i);

    }
    return 0;
}
