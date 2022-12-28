#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Error! FORM: replicate <STRING> <NUMBER>.\n\n");
        return 1;
    }
    int n;
    char a[MAX];
    int i;
    strcpy(a, argv[1]);
    n = atoi(argv[2]);
    for(i = 0; i < n; ++i)
    {
        printf("%s", a);
    }
    return 0;
}