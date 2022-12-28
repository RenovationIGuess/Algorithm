#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 105
void Solve(FILE *fin, FILE *fout)
{
    char s[MAX];
    while((fgets(s, MAX, fin)) != NULL)
    {
        fprintf(fout, "%d %s", strlen(s) - 1, s);
    }
}

int main(int argc, char *argv[])
{
    //if(argc)
    FILE *f, *f1;
    //char *filePath;
    //char filename[] = 
    if((f = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open file!\n");
        return 1;
    }
    else if((f1 = fopen(argv[2], "w")) == NULL)
    {
        printf("Cannot open file!\n");
        return 1;
    }
    else
    {
        Solve(f, f1);
        fclose(f);
        fclose(f1);
        return 0;
    }
}