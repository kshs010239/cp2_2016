#include <stdio.h>
#include <stdlib.h>

int main()
{
    int priority[10001] = {0};
    int priority2[2500] = {0};
    int priority4[625] = {0};
    int priority5[125] = {0};
    int priority6[25] = {0};
    int priority7[5] = {0};
    while(1)
    {
        int temp;
        scanf("%d", &temp);
        if(temp > 0)
        {
            priority[temp]++;
            temp--;
            priority2[temp / 4]++;
            priority4[temp / 16]++;
            priority5[temp / 80]++;
            priority6[temp / 400]++;
            priority7[temp / 2000]++;
        }
        else if(temp == 0)
        {
            break;
        }
        else
        {
            if(temp == -1)
            {
                int cnt2, cnt4, cnt5, cnt6, cnt7, cnt;
                for(cnt7 = 0; cnt7 < 5; cnt7++)
                {
                    if(priority7[cnt7] > 0)
                        break;
                }
                if(cnt7 == 5)
                    continue;
                for(cnt6 = 5 * cnt7; cnt6 < 5 * cnt7 + 5; cnt6++)
                {
                    if(priority6[cnt6] > 0)
                        break;
                }
                for(cnt5 = 5 * cnt6; cnt5 < 5 * cnt6 + 5; cnt5++)
                {
                    if(priority5[cnt5] > 0)
                        break;
                }
                for(cnt4 = 5 * cnt5; cnt4 < 5 * cnt5 + 5; cnt4++)
                {
                    if(priority4[cnt4] > 0)
                        break;
                }
                for(cnt2 = 4 * cnt4; cnt2 < 4 * cnt4 + 4; cnt2++)
                {
                    if(priority2[cnt2] > 0)
                        break;
                }
                for(cnt = 4 * cnt2 + 1; cnt <= 4 * cnt2 + 4; cnt++)
                {
                    if(priority[cnt] > 0)
                        break;
                }
                printf("%d ", cnt);
                priority2[cnt2]--;
                priority4[cnt4]--;
                priority5[cnt5]--;
                priority6[cnt6]--;
                priority7[cnt7]--;
                priority[cnt]--;
            }
            else
            {
                int cnt2, cnt4, cnt5, cnt6, cnt7, cnt;
                for(cnt7 = 4; cnt7 >= 0; cnt7--)
                {
                    if(priority7[cnt7] > 0)
                        break;
                }
                if(cnt7 == -1)
                    continue;
                for(cnt6 = 5 * cnt7 + 4; cnt6 >= 5 * cnt7; cnt6--)
                {
                    if(priority6[cnt6] > 0)
                        break;
                }
                for(cnt5 = 5 * cnt6 + 4; cnt5 >= 5 * cnt6; cnt5--)
                {
                    if(priority5[cnt5] > 0)
                        break;
                }
                for(cnt4 = 5 * cnt5 + 4; cnt4 >= 5 * cnt5; cnt4--)
                {
                    if(priority4[cnt4] > 0)
                        break;
                }
                for(cnt2 = 4 * cnt4 + 3; cnt2 >= 4 * cnt4; cnt2--)
                {
                    if(priority2[cnt2] > 0)
                        break;
                }
                for(cnt = 4 * cnt2 + 4; cnt > 4 * cnt2; cnt--)
                {
                    if(priority[cnt] > 0)
                        break;
                }
                printf("%d ", cnt);
                priority2[cnt2]--;
                priority4[cnt4]--;
                priority5[cnt5]--;
                priority6[cnt6]--;
                priority7[cnt7]--;
                priority[cnt]--;
            }
        }
    }
    return 0;
}
