#include<stdio.h>
#include<string.h>
#define SIZE 1000
int main()
{
    char s[SIZE];
    fflush(stdin);
    gets(s);

    int cnt[SIZE] = {0};
    int i;

    for(i = 0; i < strlen(s); ++i)
    {
        cnt[s[i]]++;
    }

    for(i = 65; i <= 90; ++i)
    {
        if(cnt[i] != 0)
        printf("The letter \'%c\' appears %d time(s).\n", (char)i, cnt[i]);
    }

    for(i = 97; i <= 122; ++i)
    {
        if(cnt[i] != 0)
        printf("The letter \'%c\' appears %d time(s).\n", (char)i, cnt[i]);
    }

    return 0;
}