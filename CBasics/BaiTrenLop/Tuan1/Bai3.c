#include<stdio.h>
#include<string.h>
#define SIZE 1000

int main()
{
    char s[SIZE];
    fflush(stdin);
    gets(s);
    char a, b;
    scanf("%c %c", &a, &b);

    printf("Xau da nhap: %s\n", s);
    printf("2 ky tu da nhap: %c - %c\n", a, b);
    
    int i;
    for(i = 0; i < strlen(s); ++i)
    {
        if(s[i] == a) s[i] = b;
    }

    printf("Xau sau thay doi: %s\n", s);
    return 0;
}