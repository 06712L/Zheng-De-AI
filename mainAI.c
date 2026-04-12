#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

//Zheng De AI V0.2 linux

/*AI說話函數*/
void aiprintf(char c[500])
{
    printf("AI:");
    fflush(stdout);

    for(int i = 0; i < strlen(c); i++)
    {
        printf("%c", c[i]);
        fflush(stdout);
        //0.75s
        usleep(75000);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));

    char c[500];
    char aic[1000];
    system("clear");

    /*假加載*/
    for(int i = 0; i < 101; i++)
    {
        printf("loading...%d%%\r", i);
        fflush(stdout);
        if(i != 99)
        {
            //0.95s
            usleep(95000);
        }
        else
        {
            sleep(10);
        }
    }
    printf("\ndone!\n");
    sleep(1);
    system("clear");
    strcpy(c,"很高興被載入");
    aiprintf(c);
    sleep(2);
    /*AI主程序*/
    while(1)
    {
        int quiet = 0;
        int quiets = 0;
        if(quiet == 0)
        {
        printf("安靜模式:否\n");
        }
        else
        {
            printf("安靜模式:是\n");
        }
        printf("user:");
        fflush(stdout);
        scanf("%s",c);
        //退出保險請打114514專線
        if (!strcmp(c, "退出") || !strcmp(c, "quit"))
            {
                printf("正在退出...\n");
                sleep(5);
                break;
            }
        /*如果不是安靜模式*/
        if(!quiet)
        {
            if(!strcmp(c, "關於校長的頭"))
            {
            strcpy(aic, "校長的頭為經典的地中海，需避免直視否則易被閃瞎");
                aiprintf(aic);
            }
            else if(!strcmp(c, "關於校長"))
            {
                strcpy(aic, "他是我們的太陽!");
                aiprintf(aic);
            }
            //new
            else if(!strcmp(c, "中原在哪"))
            {
                strcpy(aic, "來自中原的一群夥伴,結廬東南山");
                aiprintf(aic);
            }
            else if (!strcmp(c, "關於你"))
            {
                strcpy(aic, "我是正德AI,由06712L開發");
                aiprintf(aic);
            }
            //new
            else if(!strcmp(c, "生態池裡最多的是什麼"))
            {
                strcpy(aic, "根據多方資料來看,生態池最多的是游移憫");
                aiprintf(aic);
            }
            //new
            else if(!strcmp(c, "今年是西元幾年"))
            {
                strcpy(aic, "今年是2024年,不同意的是gay");
                aiprintf(aic);
            }
            //new
            else if(!strcmp(c, "who are you"))
            {
                strcpy(aic, "Hi, I'm Baldi,nice to meat you");
                aiprintf(aic);
            }
            else
            {
                printf("我不道啊\n");
            }
            quiets = rand() % 101;
            if(quiets >= 0 && quiets <= 91)
            {
                quiet = 0;
            }
            else
            {
                quiet = 1;
            }
        }
    }
    return 0;
}