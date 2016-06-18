#include <stdio.h>
#include <stdlib.h>

int main()
{
    while(1)
    {
        char cases[100];
        scanf("%s", cases);
        getchar();
        if(cases[0] == 'e' && cases[1] == 'n' && cases[2] == 'd' && cases[3] == '\0')
            break;
        short int map[10] = {0};
        int i;
        short int map_temp[10] = {0};
        for(i = 0; i < (1 << 10); i++)
        {
            int j;
            for(j = 0; j < 10; j++)
            {
                if(i & (1 << j))
                {
                    puts("!");
                    map_temp[0] = (map_temp[0] ^ (7 << (j - 1)));
                }
            }
            for(j = 0; j < 10; j++)
            {
                if(map_temp[0] & (1 << j))
                    printf("1");
                else
                    printf("0");
            }
            puts("");
            map_temp[0] = map[0];
        }
        for(i = 0; i < 10; i++)
        {
            int j;
            for(j = 0; j < 10; j++)
            {
                char temp = getchar();
                if(temp == 'O')
                    map[i] += 1 << j;
            }
            getchar();
            printf("%d\n", map[i]);
        }
    }

    return 0;
}
