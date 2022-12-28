#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<bool.h>

int check(char *s)
{
    int len = strlen(s) / 2;
    int i;
    for(i = 0; i < len; ++i)
    {
        if(s[i] != s[strlen(s) - 1 - i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char *s = (char *)malloc(sizeof(char));
    printf("Nhap xau: ");
    fflush(stdin);
    gets(s);
    if(check(s)) printf("Xau doi xung.\n");
    else printf("Xau khong doi xung.\n");
    free(s);
    return 0;
}