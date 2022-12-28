#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Error!\n\n");
        return 1;
    }
    //char s[MAX];
    int i;
    for(i = argc - 1; i >= 1; --i)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");
    /*strcpy(s, argv[1]);
    int i;
    for(i = strlen(s) - 1; i >= 0; --i)
    {
        printf("%c", s[i]);
    }*/
    return 0;
}