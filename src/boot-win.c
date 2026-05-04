#include "boot.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#include <mmsystem.h>
#endif

//boot V0.4

/************************
*   boot=0 加載PRO版
*   boot=1 普通版
*   boot=2 重新boot
*************************/

void boot(int *boot)
{
    srand(time(NULL));

    char c[50]; //用戶輸入
    int ll = 0; //計算進度條
    int lll = 0; //輔助計算進度條
    char load[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; //進度條
    char *bootlog[8] = {"/boot/efi/EFI/BOOT/gugugaga.efi", "/opt/cliAI/zhengdeai.gguf", "/opt/cli/language/chinese", "/opt/cli/language/chinese", "/etc/java/java-25-openjdk/java-25-openjdk/lib/security/blocked.certs", "/boot/loader/entries/43da0b07e9154fcdbcdf35574ba502b7-0-rescue.conf", "/root/a-file/I-dont-know-the-meaning-of-this-file.txt", "/boot/efi/EFI/BOOT/BOOTX64.EFI"};
/*  ^                     ^
*   |                     |
* 這不是正經的喔       非正式啟動日誌   
*****************************************/
    printf("load Model PRO?(y/n)\n");
    fgets(c, 50, stdin);
    c[strcspn(c, "\n")] = '\0';

//主程序
    if(strchr(c, 'y') != NULL && strchr(c, 'n') != NULL)
    {
        printf("huh?\n");
        sleep(1);
        *boot = 2;
    }

    else if(strchr(c, 'y') != NULL)
    {
        *boot = 2;
        puts("No you can't");
    }

    else if(strchr(c, 'n') != NULL)
    {
        int li = 0;
        if(strchr(c, 'y') != NULL)
        {
            *boot = 0;
        }
        else
        {
            *boot = 1;
        }

        for(int i = 0; i <= 100;)
        {
            printf("%s\n", bootlog[rand() % 8]);
            usleep(10000);

            printf("loading...%d%%", i);
            if(ll > 0)
            {
                load[(ll - 1)] = '=';
            }

            printf("{");
            for(int j = 0; j <10; j++)
            {
                printf("%c", load[j]);
            }
            printf("}");
            fflush(stdout);

            if(li >= 5)
            {
                i++;
                lll++;
                if(lll > 9)
                {
                    ll++;
                    lll = 0;
                }
            }
            li++;
            usleep(30000);
            printf("\r");
        }
    }
    else
    {
        *boot = 2;
    }
}
