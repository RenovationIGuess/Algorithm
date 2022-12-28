#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#define MAX 152

void A3(FILE *fin)
{
    char s[MAX];
    printf("All the content:\n");
    while((fgets(s, MAX, fin)) != NULL)
    {
        printf("%s", s);
    }
}

void A4(FILE *fin, int p)
{
    char s[MAX];
    int cnt = 0;
    int page = 1;
    if(p == 1)
    {
        while((fgets(s, MAX, fin)) != NULL)
        {
            if(cnt == 0) printf("Page %d:\n", page);
            printf("%s", s);
            cnt++;
            if(cnt == 24)
            {
                break;
            }
        }
    }
    else
    {
        while((fgets(s, MAX, fin)) != NULL)
        {
            //if(cnt == 0) printf("Page %d:\n", page);
            //printf("%s", s);
            cnt++;
            if(cnt == 24)
            {
                cnt = 0;
                page++;
                if(page == p) break;
            }
        }
        while((fgets(s, MAX, fin)) != NULL)
        {
            if(cnt == 0) printf("Page %d:\n", page);
            printf("%s", s);
            cnt++;
            if(cnt == 24)
            {
                break;
            }
        }
    }
    if(page < p)
    {
        printf("Page %d doesn't exist.\n", p);
    }
}

int main(int argc, char *argv[])
{
    FILE *f;
    if(argc == 3)
    {
        if(strcmp(argv[1] , "cat") == 0)
        {
            if((f = fopen(argv[2], "r")) == NULL)
            {
                printf("Cannot open file.\n");
                return 1;
            }
            else
            {
                A3(f);
                fclose(f);
                return 0;
            }
        }
        else
        {
            printf("ERROR!\nSYNTAX:\n");
            printf("1. cat <filename>.\n");
            printf("2. cat <filename> -p(page).\n");
            return 1;
        }
    }
    else if(argc == 4)
    {
        if(strcmp(argv[1], "cat") == 0)
        {
            if((f = fopen(argv[2], "r")) == NULL)
            {
                printf("Cannot open file.\n");
                return 1;
            }
            else
            {
                int page = argv[3][1] - '0';
                //printf("%d", page);
                A4(f, page);
                fclose(f);
                return 0;
            }
        }
        else
        {
            printf("ERROR!\nSYNTAX:\n");
            printf("1. cat <filename>.\n");
            printf("2. cat <filename> -p(page).\n");
            return 1;
        }
    }
    else 
    {
        printf("ERROR!\nSYNTAX:\n");
        printf("1. cat <filename>.\n");
        printf("2. cat <filename> -p(page).\n");
        return 1;
    }
}