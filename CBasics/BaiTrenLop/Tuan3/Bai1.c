#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 1001

void RnW(FILE *fin1, FILE *fin2, FILE *fout)
{
    char s1[MAX];
    char s2[MAX];
    while((fgets(s1, MAX, fin1)) != NULL)
    {
        fputs(s1, fout);
        printf("%s", s1);
        while((fgets(s2, MAX, fin2)) != NULL)
        {
            fputs(s2, fout);
            printf("%s", s2);
            break;
        }
    }
    while(fgets(s2, MAX, fin2) != NULL)
    {
        fputs(s2, fout);
        printf("%s", s2);
    }
}

/*void print(FILE *f)
{
    while(fscanf())
}*/

int main(int argc, char *argv[])
{
    if(argc != 5)
    {
        printf("WRONG SYNTAX!\n");
        printf("SYNTAX: merge <file1> <file2> <file3>.\n");
        return 1;
    }   
    FILE *f1, *f2, *f3;
    if(strcmp("merge", argv[1]) == 0)
    {
        //file1
        if((f1 = fopen(argv[2], "r")) == NULL)
        {
            printf("Cannot open file.\n");
            return 1;
        }
        //file2
        else if((f2 = fopen(argv[3], "r")) == NULL)
        {
            printf("Cannot open file.\n");
            return 1;
        }
        //file3
        else if((f3 = fopen(argv[4], "w")) == NULL)
        {
            printf("Cannot open file.\n");
            return 1;
        }
        else 
        {
            RnW(f1, f2, f3);
            fclose(f1);
            fclose(f2);
            fclose(f3);
            return 0;
        }
    }
    else
    {
        printf("WRONG SYNTAX!\n");
        printf("SYNTAX: merge <file1> <file2> <file3>.\n");
        return 1;
    }
}