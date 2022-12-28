#include<stdio.h> 
#include<stdlib.h>

void RnW(FILE *fin, FILE *fout)
{
    int c;
    while((c = fgetc(fin)) != EOF)
    {
        fputc(c, fout);
        putchar(c);
    }
}

int main()
{
    FILE *fptr1, *fptr2;
    char filename1[] = "lab1.txt";
    char filename2[] = "lab1w.txt";
    if((fptr1 = fopen(filename1, "r")) == NULL)
    {
        printf("Cannot open %s.\n", filename1);
        return 1;
    }
    else if((fptr2 = fopen(filename2, "w")) == NULL)
    {
        printf("Cannot open %s.\n", filename2);
        return 1;
    } 
    else
    {
        RnW(fptr1, fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
    return 0;
}