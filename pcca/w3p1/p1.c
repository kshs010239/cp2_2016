#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main()
{
    register int i, a, b, c;

    int k2, n2;
    register int k, n;
    scanf("%d", &n2);
    n = n2;
    while(n--)
    {
        scanf("%d", &k2);
        k = k2;
        for(a = 0; a * a <= (k / 3) + 1; a++)
        {
            for(b = a; b * b < (k - a * a) / 2 + 1; b++)
            {
                c = (int)sqrt(k - a * a - b * b);
                if(k == c * c + a * a + b * b)
                    break;
            }
            if(k == c * c + a * a + b * b)
                    break;
        }
        if(k == a * a + b * b + c * c)
            printf("%d %d %d\n", a, b, c);
        else
            puts("-1");
    }
    return 0;
}
