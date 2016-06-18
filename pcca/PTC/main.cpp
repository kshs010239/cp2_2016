#include <iostream>
#include <stdio.h>
#include <deque>

using namespace std;

int main()
{
    int n, l;
    while(scanf("%d %d", &n, &l) && n && l)
    {
        int* arr = new int[n];
        for(int i = 0; i < n; i++)
            scanf("%d", arr + i);
        deque<int> min_local;
        min_local.push_back(0);
        int max = 0x80000000;
        for(int i = 1; i < n; i++)
        {
            int tmp = min_local.front();
            if(tmp < i - l)
            {
                min_local.pop_front();
                if(min_local.empty() || arr[tmp + 1] < arr[min_local.front()])
                    min_local.push_front(tmp + 1);
            }
            tmp = min_local.front();
            if(arr[i] - arr[tmp] > max)
                max = (long long)arr[i] - arr[tmp];
            if(arr[i] < arr[i - 1])
            {
                while(!min_local.empty() && arr[i] < arr[min_local.back()])
                    min_local.pop_back();
                min_local.push_back(i);
            }
        }
        cout << max << endl;
        delete[] arr;
    }
    return 0;
}
