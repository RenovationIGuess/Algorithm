#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#define MAX 251

typedef struct
{
    char name[41];
    char tel[31];
    char email[41];
} p;
// p - phonebook :))

/*void ReadF(p *a, FILE *f, int so)
{
    fseek(f, 0, SEEK_SET);
    int num = fread(a, sizeof(p), so, f);
    printf("\nValue have read: %d.\n", num);
    int i;
    printf("\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
    for(i = 0; i < num; ++i)
    {
        printf("%-30s%-30s%-30s\n", a[i].name, a[i].tel, a[i].email);
    }
} */

void Spl(p *a, int split_num, FILE *f1, FILE *f2, FILE *f3)
{
    fseek(f1, 0, SEEK_END);
    int i;

    //printf("\nSize of struct: %d.\n\nFile pointer is at: %d.\n", sizeof(p), ftell(f1));
    int n = (ftell(f1) / sizeof(p));
    if(split_num > n)
    {
        printf("\nNumber of contact in file: %d.\n", n);
        printf("\nYour split num: %d.\n=> ERROR!\n", split_num);
        return;
    }
    fseek(f1, 0, SEEK_SET);

    a = (p *)realloc(a, sizeof(p) * split_num);

    int num = fread(a, sizeof(p), split_num, f1);
    //printf("\nValue have read: %d.\n", num);

    /*printf("\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
    for(i = 0; i < num; ++i)
    {
        printf("%-30s%-30s%-30s\n", a[i].name, a[i].tel, a[i].email);
    }*/

    int res = fwrite(a, sizeof(p), num, f2);
    //printf("\nWriten value: %d.\n", res);

    //fseek(f2, 0, SEEK_SET);
    //ReadF(a, f2, num);

    fseek(f2, 0, SEEK_END);
    int size1 = ftell(f2) / sizeof(p);
    //printf("\nFile 1 size: %d.\n", size1);

    fseek(f2, 0, SEEK_SET);
    num = fread(a, sizeof(p), res, f2);
    //printf("\nValue have read: %d.\n", res);

    printf("\nWhats include in file 1:\n");
    printf("\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
    for(i = 0; i < num; ++i)
    {
        printf("%-30s%-30s%-30s\n", a[i].name, a[i].tel, a[i].email);
    }

    a = (p *)realloc(a, sizeof(p) * (n - split_num));

    num = fread(a, sizeof(p), n - split_num, f1);
    //printf("\nValue have read: %d.\n", num);
    
    /*printf("\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
    for(i = 0; i < num; ++i)
    {
        printf("%-30s%-30s%-30s\n", a[i].name, a[i].tel, a[i].email);
    } */

    res = fwrite(a, sizeof(p), num, f3);
    //printf("\nWriten value: %d.\n", res);

    //fseek(f3, 0, SEEK_SET);
    //ReadF(a, f3, num);
    //printf("\nChecking:\n");

    fseek(f3, 0, SEEK_END);
    int size2 = ftell(f3) / sizeof(p);
    //printf("\nFile 2 size: %d.\n", size2);

    fseek(f3, 0, SEEK_SET);
    num = fread(a, sizeof(p), res, f3);
    //printf("\nValue have read: %d.\n", num);

    printf("\nWhats include in file 2:\n");
    printf("\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
    for(i = 0; i < num; ++i)
    {
        printf("%-30s%-30s%-30s\n", a[i].name, a[i].tel, a[i].email);
    }
}

int main(int argc, char *argv[])
{
    FILE *f1, *f2, *f3;
    int split_num;
    if(argc != 5)
    {
        printf("\nERROR SYNTAX!\n");
        printf("SYNTAX: filesplit <filename> <split_number> <filename1> <filename2>.\n\n");
        return 1;
    }
    if((f1 = fopen(argv[1], "rb")) == NULL)
    {
        printf("\nCannot open %s!\n\n", argv[1]);
        return 1;
    }
    else if((f2 = fopen(argv[3], "wb+")) == NULL)
    {
        printf("\nCannot open %s!\n\n", argv[3]);
        return 1;
    }
    else if((f3 = fopen(argv[4], "wb+")) == NULL)
    {
        printf("\nCannot open %s!\n\n", argv[4]);
        return 1;
    }
    else
    {
        split_num = atoi(argv[2]);
        printf("\nProcessing...\n");
        p *a = (p *)malloc(sizeof(p) * MAX);
        Spl(a, split_num, f1, f2, f3);
        //fseek(f1, 0, SEEK_SET);
        printf("\nClosing...!\n\n");
        free(a);
        fclose(f1);
        fclose(f2);
        fclose(f3);
        return 0;
    }
}