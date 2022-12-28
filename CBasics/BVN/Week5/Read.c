#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256

typedef struct
{
    char name[41];
    char tel[31];
    char email[41];
} p;
// p - phonebook :))

int main(int argc, char *argv[])
{
    FILE *f;
    char c;
    char *s = (char *)malloc(sizeof(char) * MAX);
    p *a = (p *)malloc(sizeof(p) * MAX);

    printf("\nProcessing...\n");
    do
    {
        printf("\nEnter file_name you want to read: ");
        fflush(stdin); gets(s);
        if((f = fopen(s, "rb")) == NULL)
        {
            printf("\nCannot open %s.\n", s);
            //return 1;
        }
        else
        {
            int num = fread(a, sizeof(p), MAX, f);
            int i;

            printf("\n%-30s%-30s%-30s\n", "Name", "Tel", "Email");
            for(i = 0; i < num; ++i)
            {
                printf("%-30s%-30s%-30s\n", a[i].name, a[i].tel, a[i].email);
            }
        }
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin);
        scanf("%c", &c);
    } while(c == 'y');
    printf("\nClosing...\n");
    free(s);
    free(a);
    fclose(f);
    return 0;
}