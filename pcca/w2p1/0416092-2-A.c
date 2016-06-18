#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    while(scanf("%d", &n) && n)
    {
        while(1)
        {
            int perm[n], perm_index = n - 1, stk_ent[n], ent_index = n - 1, stk_sta[n], sta_index = -1;
            for(i = 0; i < n; i++)
                stk_ent[i] = n - i;
            scanf("%d", &perm[n - 1]);
            if(perm[n - 1] == 0)
                break;
            for(i = n - 2; i >= 0; i--)
            {
                scanf("%d", &perm[i]);
            }

            while(perm_index != -1)
            {
                if(ent_index < -1)
                    break;
                if(sta_index == -1 || stk_sta[sta_index] != perm[perm_index])
                {
                    stk_sta[++sta_index] = stk_ent[ent_index--];
                }
                else
                {
                    sta_index--;
                    perm_index--;
                }
            }
            if(perm_index == -1)
                puts("Yes");
            else
                puts("No");
        }
        puts("");
    }
    return 0;
}
