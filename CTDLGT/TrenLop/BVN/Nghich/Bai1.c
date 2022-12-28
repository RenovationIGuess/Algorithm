#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1001

void Wr(FILE *fin)
{
    char s[MAX];
    char res[MAX];
    int cnt = 0;
    //fseek(fin, 0, SEEK_SET);
    while((fgets(s, MAX, fin)) != NULL)
    {
        cnt++;
        res[cnt] = s[0];
        //printf("'%c'\n", res[cnt]);
    }
    
    //printf("%d\n", ftell(fin));
    //fseek(fin, 0, SEEK_SET);
    //printf("%d - %d\n", ftell(fin), cnt);

    for(int i = 1; i <= cnt; ++i)
    {
        //if((fgets(s, MAX, fin)) != NULL)
        //{
            //fgets(s, MAX, fin);
            fprintf(fin, "\n%c", res[i]);
            printf("%c\n", res[i]);
        //}
    } 
    //printf("%d\n", ftell(fin));
}

int main(int argc, char *argv[])
{
    FILE *file, *file1;
    if(argc != 2)
    {
        printf("\nERROR!\nSYNTAX: <file's path/location>.\n\n");
        return 1;
    }
    //const char *filePath;
    //strcpy(filePath, argv[1]);
    if((file = fopen(argv[1], "a+")) == NULL)
    {
        printf("\nCannot open this file.\n");
        return 1;
    }
    else 
    {
        printf("Processing: ...\n\n");
        //fseek(file, 0, SEEK_SET);
        Wr(file);
        printf("\nDone! Closing file...\n\n");
        fclose(file);
    }
    return 0;
}