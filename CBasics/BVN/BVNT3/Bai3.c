#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 151

typedef struct
{
    int No;
    char name[MAX];
    //size_t
    //student number
    char SN[MAX];
    //phone number
    char PN[MAX];
    float score;
} Hs;

Hs stu[MAX];

void RnW(FILE *fin, FILE *fout)
{
    int i = 0;
    while((fscanf(fin ,"%d%s%s%s", &stu[i].No, stu[i].SN, stu[i].name, stu[i].PN)) != EOF)
    {
        i++;
    }
    //so luong sv trong danh sach
    //int num = i;
    //reset
    int j;
    printf("\nHay nhap diem cho cac sinh vien:\n\n");
    for(j = 0; j < i; ++j)
    {
        printf("Student No.%d score: ", stu[j].No);
        fflush(stdin);
        scanf("%f", &stu[j].score);
    }
    
    int k;
    fprintf(fout, "%-10s%-20s%-35s%-20s%-10s\n", "No", "Student_number", "First-name", "Phone_number", "Score");
    for(k = 0; k < i; ++k)
    {
        fprintf(fout, "%-10d%-20s%-35s%-20s%-10.2f\n", stu[k].No, stu[k].SN, stu[k].name, stu[k].PN, stu[k].score);
    }
}

int main(int argc, char *argv[])
{
    FILE *f1, *f2;
    if((f1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open file!\n");
        return 1;
    }
    else if((f2 = fopen(argv[2], "w")) == NULL)
    {
        printf("Cannot open file!\n");
        return 1;
    }
    else
    {
        printf("Reading Information:...\n\n");
        RnW(f1, f2);
        printf("\nComplete! Closing files...\n");
        fclose(f1);
        fclose(f2);
        return 0;
    }
}