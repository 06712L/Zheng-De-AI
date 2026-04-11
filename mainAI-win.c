#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
//windows
#ifdef _WIN32
#include <windows.h>
#define clear cls
#endif

//Zheng De AI V0.1 windows

/*AI說話函數*/
void aiprintf(char c[500])
{
    printf("AI:");
    fflush(stdout);

    for(int i = 0; i < strlen(c); i++)
    {
        printf("%c", c[i]);
        fflush(stdout);
        usleep(100000);
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
            usleep(100000);
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
            else if (!strcmp(c, "關於你"))
            {
                strcpy(aic, "我是正德AI,由06712L開發");
                aiprintf(aic);
            }
            else
            {
                printf("我不道啊\n");
            }
            quiets = rand() % 101;
            if(quiets >= 0 && quiets <= 98)
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