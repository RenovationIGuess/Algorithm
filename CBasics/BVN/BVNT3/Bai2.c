#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAX 151

void Encrypt(FILE *fin, int offset)
{
    int i;
    char s[MAX];
        while((fgets(s, MAX, fin)) != NULL)
        {
            for(i = 0; i < strlen(s); ++i)
            {
                if(s[i] >= 'a' && s[i] <= 'z')
                {
                    if(s[i] + offset > 'z')
                    {
                        s[i] = 'a' + (offset - ('z' - s[i])) - 1;
                    }
                    else
                    {
                        s[i] += offset;
                    }
                }
                if(s[i] >= 'A' && s[i] <= 'Z')
                {
                    if(s[i] + offset > 'Z')
                    {
                        s[i] = 'A' + (offset - ('Z' - s[i])) - 1;
                    }
                    else
                    {
                        s[i] += offset;
                    }
                }
            }
            printf("%s", s);
        }
    //Neu offset qua lon (> 2.25 se khong hoat dong) => su dung lap den khi s[i] thuoc [a; z] hoac [A, Z]
}

void Decrypt(FILE *fin, int offset)
{
    int i;
    char s[MAX];
    if(offset <= 26)
    {
        while((fgets(s, MAX, fin)) != NULL)
        {
            for(i = 0; i < strlen(s); ++i)
            {
                if(s[i] >= 'a' && s[i] <= 'z')
                {
                    if(s[i] - offset < 'a')
                    {
                        s[i] = 'z' - (offset - (s[i] - 'a')) + 1;
                    }
                    else
                    {
                        s[i] -= offset;
                    }
                }
                if(s[i] >= 'A' && s[i] <= 'Z')
                {
                    if(s[i] - offset < 'A')
                    {
                        s[i] = 'Z' - (offset - (s[i] - 'A')) + 1;
                    }
                    else
                    {
                        s[i] -= offset;
                    }
                }
            }
            printf("%s", s);
        }
    }
    else
    {
        while((fgets(s, MAX, fin)) != NULL)
        {
            for(i = 0; i < strlen(s); ++i)
            {
                if(s[i] >= 'a' && s[i] <= 'z')
                {
                    //if(s[i] - offset < 'a')
                    //{
                        s[i] = 'z' - (offset - (s[i] - 'a')) + (offset - 25 + 1);
                    //}
                    /*else
                    {
                        s[i] -= offset;
                    } */
                }
                if(s[i] >= 'A' && s[i] <= 'Z')
                {
                    //if(s[i] - offset < 'A')
                    //{
                        s[i] = 'Z' - (offset - (s[i] - 'A')) + (offset - 25 + 1);
                    //}
                    /*else
                    {
                        s[i] -= offset;
                    } */
                }
            }
            printf("%s", s);
        }
    }
    //Neu offset qua lon (> 2.25 se khong hoat dong) => su dung lap den khi s[i] thuoc [a; z] hoac [A, Z]
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("ERROR! SYNTAX:\n");
        printf("<filename> <addition offset>.\n");
        return 1;
    }
    else
    {
        FILE *f;
        int a_o = atoi(argv[2]);
        if(a_o < 0) 
        {
            printf("Invalid offset! Must >= 0\n");
            return 1;
        }
        if((f = fopen(argv[1], "r")) == NULL)
        {
            printf("Cannot open file!\n");
            return 1;
        }
        else
        {
            printf("Encrypt:\n");
            Encrypt(f, a_o);
            printf("\n");
            fseek(f, 0, SEEK_SET);
            printf("Decrypt:\n");
            Decrypt(f, a_o);
            fclose(f);
            return 0;
        }
    }
}