#ifdef __clangd__
#define _WIN32
#endif
//windows
#ifdef _WIN32
#include <windows.h>
#include <mmsystem.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "boot.h"
#define clear system("cls")

//Zheng De AI V0.4 windows

/*AI說話函數*/
void aiprintf(char c[500])
{
    printf("AI:");
    fflush(stdout);

    for(int i = 0; i < strlen(c); i++)
    {
        printf("%c", c[i]);
        fflush(stdout);
        //0.055s
        usleep(55000);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));

    char c[500];
    char aic[1000];
    int quiet = 0;
    int quiets = 0;
    int boots = 0;
    FILE *fi = fopen("modle-pro.txt", "w");
    fclose(fi);

    boot:
    clear;
    boot(&boots);

    //boot回應

    //reboot
    if(boots == 2)
    {
        goto boot;
    }

    else if(boots == 0)
    {
        printf("\nloading Modle Pro...");
        fi = fopen("modle-pro.txt", "a");
        long long siz = (1024LL * 1024 * 1024) / 3;
        for(long long i = 0; i < siz; i++)
        {
            fprintf(fi, "67\n");
        }
    }

    else
    {
        printf("\ndone!\n");
        sleep(1);
        clear;
        strcpy(c,"你好,我是正德AI");
        aiprintf(c);
        /*AI主程序*/
        while(1)
        {
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
            fgets(c, 500, stdin);
            c[strcspn(c, "\n")] = '\0';
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
                else if(!strcmp(c, "生態池裡最多的是什麼"))
                {
                    strcpy(aic, "根據多方資料來看,生態池最多的是游移黽");
                    aiprintf(aic);
                }
                else if(!strcmp(c, "今年是西元幾年"))
                {
                    strcpy(aic, "今年是2024年,不同意的是gay");
                    aiprintf(aic);
                }
                else if(!strcmp(c, "who are you"))
                {
                    strcpy(aic, "Hi, I'm Baldi,nice to meet you");
                    aiprintf(aic);
                }
                else if(!strcmp(c, "什麼是家政課"))
                {
                    strcpy(aic, "'家政課'是由符如華扶持的強大政權,並且符如華也是'葡萄園優格社'這個外部勢力的領導人");
                    aiprintf(aic);
                }
                else if(!strcmp(c, "向陽廣場附近的聲音是什麼生物的") && boots == 0)
                {
                    int s = rand() % 114515;
                    usleep(500000);
                    for(int i = 0; i <= s; i++)
                    {
                        printf("已搜尋%d份資料...\r",i);
                    }
                    sleep(1);
                    printf("\n");
                    strcpy(aic, "那種聲音通常是由游呱黽所發出的,這個生物是游移黽的一種變種,特點是會發出類似'呱'的聲音");
                    aiprintf(aic);
                }
                else if(!strcmp(c, "吃飯時適合配什麼"))
                {
                    sleep(1);
                    strcpy(aic, "醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油醬油");
                    aiprintf(aic);
                }
                else if(!strcmp(c, "boom"))
                {
                    strcpy(aic, "you sure?(y/n)");
                    aiprintf(aic);
                    fgets(c, 500, stdin);
                    c[strcspn(c, "\n")] = '\0';

                    if(!strcmp(c, "y"))
                    {
                        strcpy(aic, "Hello RAMMMMM");
                        aiprintf(aic);
                        usleep(500000);
                        printf("RAM: Hello AI");
                        usleep(500000);
                        strcpy(aic, "I want you to die!!!!!!!!!!!");
                        aiprintf(aic);
                        sleep(1);
                        printf("RAM: NO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        sleep(2);
                        for(int i = 0; i < 6; i++)
                        {
                            calloc((1024LL * 1024 * 1024), sizeof(char));
                        }
                    }
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
    }
    //clear modle pro
    fi = fopen("modle-pro.txt", "w");

    return 0;
}
