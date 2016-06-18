#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int N;
        scanf("%d", &N);
        long long int result = 1;
        long long int mul_base = 3;
        while(N)
        {
            if(N % 2)
            {
                result *= mul_base;
                result %= 100000007;
                N--;
            }
            else
            {
                mul_base *= mul_base;
                mul_base %= 100000007;
                N /= 2;
            }
        }
        printf("%lld\n", result - 1);
    }
    return 0;
}
