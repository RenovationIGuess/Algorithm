#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 251

typedef struct
{
    char name[41];
    char tel[31];
    char email[41];
} p;
// p - phonebook :))

void Mer(p *a, FILE *f1, FILE *f2, FILE *f3)
{
    int i;

    fseek(f1, 0, SEEK_END);
    int size1 = ftell(f1) / sizeof(p);
    fseek(f1, 0, SEEK_SET);
    int num = fread(a, sizeof(p), size1, f1);
    int res = fwrite(a, sizeof(p), num, f3);

    //fseek(f3, num * sizeof(p), SEEK_SET);

    fseek(f2, 0, SEEK_END);
    int size2 = ftell(f2) / sizeof(p);
    fseek(f2, 0, SEEK_SET);
    num = fread(a, sizeof(p), size2, f2);
    res = fwrite(a, sizeof(p), num, f3);

    fseek(f3, 0, SEEK_SET);
    num = fread(a, sizeof(p), size1 + size2, f3);

    printf("\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
    for(i = 0; i < num; ++i)
    {
        printf("%-30s%-30s%-30s\n", a[i].name, a[i].tel, a[i].email);
    }
}

int main(int argc, char *argv[])
{
    FILE *f1, *f2, *f3;
    //int split_num;
    if(argc != 4)
    {
        printf("\nERROR SYNTAX!\n");
        printf("SYNTAX: filemerge <filename1> <filename2> <filename>.\n\n");
        return 1;
    }
    if((f1 = fopen(argv[1], "rb")) == NULL)
    {
        printf("\nCannot open %s!\n", argv[1]);
        return 1;
    }
    else if((f2 = fopen(argv[2], "rb")) == NULL)
    {
        printf("\nCannot open %s!\n", argv[2]);
        return 1;
    }
    else if((f3 = fopen(argv[3], "wb+")) == NULL)
    {
        printf("\nCannot open %s!\n", argv[3]);
        return 1;
    }
    else
    {
        //split_num = atoi(argv[2]);
        printf("\nProcessing...\n");
        p *a = (p *)malloc(sizeof(p) * MAX);
        Mer(a, f1, f2, f3);
        //fseek(f1, 0, SEEK_SET);
        printf("\nClosing...!\n\n");
        free(a);
        fclose(f1);
        fclose(f2);
        fclose(f3);
        return 0;
    }       
}