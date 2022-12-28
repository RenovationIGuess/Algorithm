#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256

typedef struct
{
    char model[31];
    // ms - memory space
    float ms;
    // ss - screen size 
    float ss;
    //char price[31];
    float price;
} p; //p - phone

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

            printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
            for(i = 0; i < num; ++i)
            {
                printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
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