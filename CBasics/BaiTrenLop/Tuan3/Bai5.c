#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum{MAX_LEN = 80};

int main()
{
    int num;
    FILE *f;
    char fn[] = "haiku.txt";
    char s[MAX_LEN + 1];
    if((f = fopen(fn, "r")) == NULL)
    {
        printf("Cannot open file!\n");
        return 1;
    } 
    
    num = fread(s, sizeof(char), MAX_LEN, f);
    s[num * sizeof(char)] = '\0';
    printf("%s", s);
    fclose(f);
}