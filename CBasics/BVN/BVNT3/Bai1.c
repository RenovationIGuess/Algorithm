#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//#include<conio.h>
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

void A4(FILE *fin)
{
    char s[MAX];
    int cnt = 0;
    int page = 1;
    while((fgets(s, MAX, fin)) != NULL)
    {
        if(cnt == 0) printf("Page %d:\n", page);
        printf("%s", s);
        cnt++;
        if(cnt == 24)
        {
            cnt = 0;
            page++;
            printf("\n");
            char c;
            printf("Press any key to continue: ");
            fflush(stdin);
            scanf("%c", &c);
            //getch();
            printf("\n\n"); 
            /*char c;
            printf("Do you want to continue [y/n]: ");
            fflush(stdin);
            scanf("%c", &c);
            if(c == 'n') 
            {
                printf("Closing file...\n\n");
                break;
            }
            else if(c == 'y')
            {
                printf("Next page...\n\n");
            } 
            else
            {
                printf("Invalid! Only y/n.\nEnter again: ");
                fflush(stdin);
                scanf("%c", &c);
                printf("\n");
            }*/
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *f;
    if(argc == 3)
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
                A3(f);
                fclose(f);
                return 0;
            }
        }
        else
        {
            printf("ERROR!\nSYNTAX:\n");
            printf("1. cat <filename>.\n");
            printf("2. cat <filename> -p.\n");
            return 1;
        }
    }
    else if(argc == 4)
    {
        if(strcmp(argv[1], "cat") == 0 && strcmp(argv[3], "-p") == 0)
        {
            if((f = fopen(argv[2], "r")) == NULL)
            {
                printf("Cannot open file.\n");
                return 1;
            }
            else
            {
                A4(f);
                fclose(f);
                return 0;
            }
        }
        else
        {
            printf("ERROR!\nSYNTAX:\n");
            printf("1. cat <filename>.\n");
            printf("2. cat <filename> -p.\n");
            return 1;
        }
    }
    else 
    {
        printf("ERROR!\nSYNTAX:\n");
        printf("1. cat <filename>.\n");
        printf("2. cat <filename> -p.\n");
        return 1;
    }
}