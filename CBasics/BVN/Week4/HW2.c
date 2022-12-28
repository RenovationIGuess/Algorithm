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

void RnW(Hs *stu, FILE *fin, FILE *fout)
{
    int i = 0;
    while((fscanf(fin ,"%d%s%s%s", &stu[i].No, stu[i].SN, stu[i].name, stu[i].PN)) != EOF)
    {
        i++;
    }
    printf("So sinh vien hien tai: %d.\n\n", i);

    //so luong sv trong danh sach
    //int num = i;
    //reset

    char ans;
    printf("Ban co muon nhap them so sinh vien [y/n]: ");
    fflush(stdin);
    scanf("%c", &ans);
    if(ans == 'y')
    {
        int extra;
        printf("\nNhap so sinh vien muon them: ");
        fflush(stdin);
        scanf("%d", &extra);
        stu = (Hs *)realloc(stu, (i + extra + 1) * sizeof(Hs));
        printf("\nNhap thong tin cho sinh vien muon them:\n\n");
        int p;
        for(p = 0; p < extra; ++p)
        {
            printf("Thong tin sinh vien %d\n", i + p + 1);
            stu[i + p].No = i + p + 1;
            printf("Nhap ten: ");
            fflush(stdin);
            gets(stu[i + p].name);
            printf("Nhap MSSV: ");
            fflush(stdin);
            gets(stu[i + p].SN);
            printf("Nhap SDT: ");
            fflush(stdin);
            gets(stu[i + p].PN);
            printf("\n");
        }
        i += extra;
    }
    printf("So sinh vien hien tai: %d.\n", i);

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

    if(argc != 3)
    {
        printf("\nERROR!\nSYNTAX: <file_in> <file_out>.\n");
        return 1;
    }

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
        Hs *stu = (Hs *)malloc(MAX * sizeof(Hs));
        printf("Reading Information:...\n\n");
        RnW(stu, f1, f2);
        printf("\nComplete! Closing files...\n");
        fclose(f1);
        fclose(f2);
        free(stu);
        return 0;
    }
}