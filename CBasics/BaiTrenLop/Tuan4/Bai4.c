#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 151

typedef struct
{
    char name[20];
    char tel[11];
    char email[25];
} add;

int main(int argc, char *argv[])
{
    FILE *f;
    int i, n, num;
    int b, e;
    //pa - phone address
    //b - begin, e - end

    if((f = fopen("phonebook.dat", "r+b")) == NULL)
    {
        printf("Cannot open file!\n\n");
        return 1;
    }

    //khai bao dong
    add *pa = (add *)malloc((e - b + 1) * sizeof(add));

    if(pa == NULL)
    {
        printf("Memory allocation failed!\n\n");
        return 1;
    }

    //Nhap diem bat dau - ket thuc
    printf("Enter begin - end: ");
    fflush(stdin);
    scanf("%d %d", &b, &e);

    if(fseek(f, (b - 1) * sizeof(add), SEEK_SET) != 0)
    {
        printf("Seek failed!\n\n");
        return 1;
    }

    num = fread(pa, sizeof(add), e - b + 1, f);

    printf("%-25s%-25s%-25s\n\n", "Name", "Tel", "Email");      
    for(i = 0; i < e - b + 1; ++i)
    {
        printf("%-25s%-25s%-25s\n", pa[i].name, pa[i].tel, pa[i].email);
    }
    
    //modify
    strcpy(pa[0].name,"ChikaCuaLamHi");
    strcpy(pa[0].tel,"485735489");
    strcpy(pa[0].email,"loveChikaIchiban");

    //dua lai con tro file ve vi tri bat dau
    fseek(f, (b - 1) * sizeof(add), SEEK_SET);
    //thay doi noi dung - modify
    num = fwrite(pa, sizeof(add), e - b + 1, f);

    //dua lai con tro file ve vi tri ban dau 
    fseek(f, 0, SEEK_SET);

    //reset lai bo nho cho mang dong
    pa = (add *)realloc(pa, MAX * sizeof(add));

    //doc file
    num = fread(pa, sizeof(add), MAX, f);
    printf("\n");

    //Output
    printf("%-25s%-25s%-25s\n\n", "Name", "Tel", "Email");
    for(i = 0; i < num; ++i)
    {
        printf("%-25s%-25s%-25s\n", pa[i].name, pa[i].tel, pa[i].email);
    } 
    fclose(f);
    free(pa);
    return 0;
}