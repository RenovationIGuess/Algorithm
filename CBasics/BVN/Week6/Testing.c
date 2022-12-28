#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 501


//dem so bytes
long long ByteNum(FILE *f)
{
    fseek(f, 0, SEEK_SET);
    char s[MAX];
    long long num = 0;
    while((fgets(s, MAX, f)) != NULL)
    {
        num += strlen(s);
    }
    return num;
}

//dem so dong
long long LineNum(FILE *f)
{
    fseek(f, 0, SEEK_SET);
    char s[MAX];
    long long num = 0;
    while((fgets(s, MAX, f)) != NULL)
    {
        num++;
    }
    return num;
}

int main(int argc, char *argv[])
{
    //f - .txt, f1 - .dat
    FILE *f, *f1;

    if((f = fopen(argv[1], "r")) == NULL)
    {
        printf("\nCannot open %s!\n\n", argv[1]);
        return 1;
    }
    else
    {
        //fseek(f, 0, SEEK_END);
        //int size = ftell(f);
        int i;
        //so dong
        long long line = LineNum(f);
        printf("\nSo dong: %d.\n", line);
        long long size = ByteNum(f);
        printf("\nSo dong: %d.\n", size);
        
        fseek(f, 0, SEEK_SET);

        //cpd
        char **a = (char **)malloc(size * sizeof(char));
        for(i = 0; i < line; ++i) 
        {
            a[i] = (char *)malloc(MAX * sizeof(char));
        }

        //long cnt = 0;
        for(i = 0; i < line; ++i)
        {
            fgets(a[i], MAX, f);
            printf("%d - %s", i + 1, a[i]);
            fwrite(a[i], sizeof(char), MAX, f1);
            //cnt++;
        }

        //printf("\nWriten value: %d.\n", cnt);

        //giai phong bo nho
        for(i = 0; i < line; ++i)
        {
            free(a[i]);
        }
        free(a);
        fclose(f);
        return 0;
    }
}