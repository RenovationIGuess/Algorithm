#include<stdio.h>
#include<stdlib.h>
#define MAX 151

typedef struct
{
    char name[41];
    char tel[31];
    char email[41];
} add;

int main(int argc, char *argv[])
{
    FILE *f;
    //pa - phone address
    //add *pa = (add *)malloc(sizeof(add));
    add pa[MAX];
    int i, n, num;
    printf("How many contacts do you want to enter (<20)? ");
    fflush(stdin);
    scanf("%d", &n);
    for(i = 0; i < n; ++i)
    {
        printf("Name: ");
        fflush(stdin);
        scanf("%s", pa[i].name);
        printf("Tel: ");
        fflush(stdin);
        scanf("%s", pa[i].tel);
        printf("Email: ");
        fflush(stdin);
        scanf("%s", pa[i].email);
        printf("\n");
    }
    printf("\n");
    if((f = fopen("phonebook.dat", "w+b")) == NULL)
    {
        printf("Cannot open file!\n\n");
        return 1;
    }

    num = fwrite(pa, sizeof(add), n, f);
    printf("fwrite return code = %d.\n\n", num);
    fclose(f);
    
    if((f = fopen("phonebook.dat", "rb")) == NULL)
    {
        printf("Cannot open file!\n\n");
        return 1;
    }

    num = fread(pa, sizeof(add), n, f);
    printf("fread return code = %d.\n\n", num);
    printf("%-25s%-25s%-25s\n\n", "Name", "Tel", "Email");
    for(i = 0; i < n; ++i)
    {
        printf("%-25s%-25s%-25s\n", pa[i].name, pa[i].tel, pa[i].email);
    }
    fclose(f);
    //free(pa);
    return 0;
}