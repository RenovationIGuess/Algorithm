#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 1001

enum {SUCCESS, FAIL};

void Copium(FILE *fin, FILE *fout)
{
    char s[MAX];
    while((fgets(s, MAX, fin)) != NULL)
    {
        fputs(s, fout);
        printf("%s", s);
    }
}

int main(int argc, char *argv[])
{
    FILE *fptr1, *fptr2;
    int res = SUCCESS;

    if(argc != 4)
    {
        printf("SYNTAX ERROR!\n");
        printf("Guide: mycp [FILENAME1] [FILENAME2].\n");
        return 1;
        //exit(1);
        //res = FAIL;
    }

    /*char filename1[MAX], filename2[MAX];
    strcpy(argv[2], filename1);
    strcpy(argv[3], filename2); */
    
    //if((fptr1 = fopen(argv[2], "r+")) == NULL) {}
    if((fptr1 = fopen(argv[2], "r")) == NULL)
    {
        printf("Cannot open %s.\n\n", argv[2]);
        res = FAIL;
        //return 1;
    }
    else if((fptr2 = fopen(argv[3], "w")) == NULL)
    {
        printf("Cannot open %s.\n\n", argv[3]);
        res = FAIL;
        //return 1;
    }
    else 
    {
        printf("What have copied: \n");
        Copium(fptr1, fptr2);
        printf("\n\nNow both the files will close.\n");
        fclose(fptr1);
        fclose(fptr2);
    }

    return res; 
    //return 0;
}