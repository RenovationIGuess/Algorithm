#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 151

enum{SUCCESS, FAIL};

char *subStr(char *s1, int offset, int number)
{
    char *sub_str = (char *)malloc((number + 1) * sizeof(char));
    int i;
    for(i = 0; i < number; ++i)
    {
        sub_str[i] = s1[i + offset];
    }
    sub_str[number] = '\0';
    //free(sub_str);
    return sub_str;
}

int main(int argc, char *argv[])
{
    FILE *f;
    // char s[MAX];
    // offset - start, number - so ky tu
    int offset, number;
    char *s = (char *)malloc(MAX * sizeof(char));
    printf("Enter string: ");
    fflush(stdin);
    gets(s); 
    int str_index = strlen(s) - 1;
    
    printf("\nYour string length = %d and index_MAX = %d.\n", strlen(s), str_index);
    printf("\nEnter offset: ");
    fflush(stdin);
    scanf("%d", &offset);
    while(offset < 0 || offset > str_index)
    {
        printf("Invalid! Enter again: ");
        fflush(stdin);
        scanf("%d", &offset);
    }
    printf("String's chr at offset_index is: '%c'.\n", s[offset]);

    printf("\nEnter number of sub_str chr: ");
    fflush(stdin);
    scanf("%d", &number);
    while(number < 0 || number + offset - 1 > str_index)
    {
        printf("Invalid! Enter again: ");
        fflush(stdin);
        scanf("%d", &number);
    }
    
    printf("\nYour sub string is: \"%s\" (with offset = %d, number = %d).\n", subStr(s, offset, number), offset, number);
    free(s);
    return 0;
}