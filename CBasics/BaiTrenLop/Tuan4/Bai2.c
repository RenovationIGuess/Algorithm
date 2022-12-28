#include<stdio.h>
#include<stdlib.h>
#define MAX 150

void RnWBin(FILE *fin, FILE *fout)
{
    int num;
    char s[MAX];
    while(!feof(fin))
    {
        num = fread(s, sizeof(char), MAX, fin);
        s[num * sizeof(char)] = '\n';
        printf("%s", s);
        fwrite(s, sizeof(char), num, fout);
    }
}

int main(int argc, char *argv[])
{
    FILE *f1, *f2;
    if((f1 = fopen("lab1.txt", "r")) == NULL)
    {
        printf("Cannot open file!\n\n");
        return 1;
    }
    else if((f2 = fopen("lab1a.txt", "w")) == NULL)
    {
        printf("Cannot open file!\n\n");
        return 1;
    }
    else
    {
        RnWBin(f1, f2);
        fclose(f1);
        fclose(f2);
        return 0;
    }
}