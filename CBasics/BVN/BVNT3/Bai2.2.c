#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#define MAX 151

void Encrypt(FILE *fin, int key)
{
    int i;
    char s[MAX];
    while((fgets(s, MAX, fin)) == NULL)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            
        }
    }
}

void Decrypt(FILE *fin, int key)
{
    int i;
    char s[MAX];
    while((fgets()))
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