#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 1001

//APPEND
void A(FILE *fin, FILE *fout)
{
    char s[MAX];
    while(fgets(s, MAX, fin) != NULL)
    {
        fputs(s, fout);
        printf("%s\n", s);
    }
}

int main(int argc, char *argv[])
{
    FILE *fptr1, *fptr2;

    if(argc != 4)
    {
        printf("SYNTAX ERROR!.\n");
        printf("SYNTAX Guide: apd <file1> <file2>.\n");
        return 1;
    }

    if((fptr1 = fopen(argv[2], "r")) == NULL)
    {
        printf("Cannot open file %s.\n", argv[2]);
        return 1;
    }
    else if((fptr2 = fopen(argv[3], "a")) == NULL)
    {
        printf("Cannot open file %s.\n", argv[3]);
        return 1;
    }
    else
    {
        printf("\nWhat have appended: \n\n");
        A(fptr1, fptr2);
        printf("\nNow the files will be closed.\n");
        fclose(fptr1);
        fclose(fptr2);
    }

    return 0;
}