#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 101

typedef struct
{
    int ID;
    char name[MAX];
    long Price;
} pd;

pd Pro[MAX];

void Solve(FILE *fin)
{
    int i = 0;
    printf("%-10s%-30s%-20s\n", "No", "Product_Name", "Price");
    while((fscanf(fin, "%d\t%s\t%d", &Pro[i].ID, &Pro[i].name, &Pro[i].Price)) != EOF)
    {
        printf("%-10d%-30s%-20d\n", Pro[i].ID, Pro[i].name, Pro[i].Price);
        i++;
    }
}

int main(int argc, char *argv[])
{
    FILE *f, *f1;
    if((f = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }
    /*else if((f1 = fopen(argv[2], "w")) == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    } */
    else
    {
        Solve(f);
        fclose(f);
        //fclose(f1);
        return 0;
    }
}