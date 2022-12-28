#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 301

typedef struct
{
    int no;
    char name[35];
    // phone number
    char pn[25];
    // student number
    char sn[51];
    float score;
} hs;

// so sinh vien
int stu_num;

void Text2Dat(hs *a, FILE *fin, FILE *fout)
{
    fseek(fin, 0, SEEK_SET);
    printf("\nDang thuc hien...\n");
    //char *s = (char *)malloc(sizeof(char));
    int num;
    int i = 0;
    printf("\nWhat have read:\n");
    while(fscanf(fin, "%d%s%s%s%f", &a[i].no, a[i].sn, a[i].name, a[i].pn, &a[i].score) != EOF)
    {
        printf("%-10d%-20s%-35s%-20s%-10.2f\n", a[i].no, a[i].sn, a[i].name, a[i].pn, a[i].score);
        i++;
    }
    stu_num = i;
    printf("\nNumber of student: %d.\n", stu_num);
    num = fwrite(a, sizeof(hs), i, fout);
    printf("\nThanh cong!\n");
}

void SnU(hs *a, FILE *fin)
{
    printf("\nDang thuc hien...\n");
    fseek(fin, 0, SEEK_SET);
    char sel;
    do
    {
        /*
        char *mssv = (char *)malloc(sizeof(char));
        printf("\nEnter student number you want to find: ");
        fflush(stdin);
        scanf("%s", mssv);
        int i, no;
        for(i = 0; i < stu_num; ++i)
        {
            if(strcmp(mssv, a[i].sn) == 0)
            {
                no = i;
                break;
            }
        }
        // tim theo ten theo sdt... :))
        */
        int no;
        printf("\nEnter student's no: ");
        fflush(stdin);
        scanf("%d", &no);
        while(no <= 0 || no > stu_num)
        {
            printf("\nNothing to search!\nEnter again: ");
            fflush(stdin);
            scanf("%d", &no);
        }
        if(fseek(fin, (no - 1) * sizeof(hs), SEEK_SET) != 0)
        {
            printf("\nSeek failed!\n");
            return;
        }

        printf("\nSearching student no %d...\n", no);
        printf("\n%-10s%-20s%-35s%-20s%-10s\n", "No", "Student_number", "First-name", "Phone_number", "Score");
        printf("%-10d%-20s%-35s%-20s%-10.2f\n", a[no - 1].no, a[no - 1].sn, a[no - 1].name, a[no - 1].pn, a[no - 1].score);

        char ans;
        printf("\nDo you want to update [y/n]: ");
        fflush(stdin);
        scanf("%c", &ans);
        int opt;
        if(ans == 'y')
        {
            //char ans2;
            do
            {
                //char *ans1 = (char *)malloc(sizeof(char));
                float score;
                char *sn = (char *)malloc(sizeof(char));
                char *name = (char *)malloc(sizeof(char));
                char *pn = (char *)malloc(sizeof(char));
                printf("\n1. Student number (sn)\n2. Name (n)\n3. Phone number (pn)\n4. Score (s)\n5. Quit\n");
                printf("\nEnter what you want to change: ");
                fflush(stdin);
                scanf("%d", &opt);
                switch(opt)
                {
                //if(strcmp("sn", ans1) == 0)
                //{
                    case 1:
                        //char *sn = (char *)malloc(sizeof(char));
                        printf("\nEnter new student number: ");
                        fflush(stdin);
                        //scanf("%s", a[no - 1].sn);
                        scanf("%s", sn);
                        strcpy(a[no - 1].sn, sn);
                        break;
                //}
                //else if(strcmp("n", ans1) == 0)
                //{
                    case 2:
                        //char *name = (char *)malloc(sizeof(char));
                        printf("\nEnter new student name: ");
                        fflush(stdin);
                        //scanf("%s", a[no - 1].name);
                        scanf("%s", name);
                        strcpy(a[no - 1].name, name);
                        break;
                //}
                //else if(strcmp("pn", ans1) == 0)
                //{
                    case 3:
                        //char *pn = (char *)malloc(sizeof(pn));
                        printf("\nEnter new student phone number: ");
                        fflush(stdin);
                        //scanf("%s", a[no - 1].pn);
                        scanf("%s", pn);
                        strcpy(a[no - 1].pn, pn);
                        break;
                //}
                //else if(strcmp("s", ans1) == 0)
                //{
                    case 4:
                        //float score;
                        printf("\nEnter new student score: ");
                        fflush(stdin);
                        //scanf("%f", a[no - 1].score);
                        scanf("%f", &score);
                        a[no - 1].score = score;
                        break;
                    case 5:
                        break;
                    default:
                        printf("\nInvalid!\n");
                        break;
                //}
                }
                /*printf("\nDo you want to change more [y/n]: ");
                fflush(stdin);
                scanf("%c", &ans2);*/
            } while(opt != 5);
        }
        printf("\nDo you want to search more [y/n]: ");
        fflush(stdin);
        scanf("%c", &sel);
    } while(sel == 'y');

    //fseek(fin, (no - 1) * sizeof(hs), SEEK_SET);
    fseek(fin, 0, SEEK_SET);
    int num = fwrite(a, sizeof(hs), stu_num, fin);
    printf("\nThanh cong!\n");
}

void Display(hs *a, FILE *fin)
{
    printf("\nDang thuc hien...\n");
    int num;
    //char *s = (char *)malloc(sizeof(char));
    //hs *b = (hs *)malloc(sizeof(hs));
    //hs *b;
    int i;

    fseek(fin, 0, SEEK_SET);
    num = fread(a, sizeof(hs), stu_num, fin);

    printf("\n%-10s%-20s%-35s%-20s%-10s\n", "No", "Student_number", "First-name", "Phone_number", "Score");
    for(i = 0; i < num; ++i)
    {
        printf("%-10d%-20s%-35s%-20s%-10.2f\n", a[i].no, a[i].sn, a[i].name, a[i].pn, a[i].score);
    } 
    //printf("%-10d%-20s%-35s%-20s%-10.2f\n", b->no, b->sn, b->name, b->pn, b->score);
    printf("\nThanh cong!\n");
}

void menu(hs *a, FILE *fin, FILE *fout)
{
    printf("\nMenu:\n\n");
    //char c;
    int opt;
    int cnt = 0;
    do
    {
        printf("1. Text2Dat\n2. Display Dat file\n3. Search and Update\n4. Quit\n\nEnter your option: ");
        fflush(stdin);
        scanf("%d", &opt);
        switch(opt)
        {
            case 1: 
                Text2Dat(a, fin, fout);
                cnt++;
                break;
            case 2:
                if(cnt == 0)
                {
                    printf("\nUse 1 first!\n");
                }
                else
                {
                    Display(a, fout);
                }
                break;
            case 3:
                if(cnt == 0)
                {
                    printf("\nUse 1 first!\n");
                }
                else
                {
                    SnU(a, fout);
                }
                break;
            case 4:
                printf("\nThank You!\n");
                return;
            default:
            printf("\nInvalid!\n");
                break;
        }
        /*printf("\nDo you want to continue [y/n]: ");
        fflush(stdin);
        scanf("%c", &c);*/
        printf("\n");
    } while(1);//while(c == 'y');
}

int main(int argc, char *argv[])
{
    FILE *f1, *f2;
    if((f1 = fopen(argv[1], "r")) == NULL)
    {
        printf("\nCannot open %s!\n", argv[1]);
        return 1;
    }
    else if((f2 = fopen(argv[2], "w+b")) == NULL)
    {
        printf("\nCannot open %s!\n", argv[2]);
        return 1;
    }
    else
    {
        // cap phat dong
        hs *a = (hs *)malloc(sizeof(hs) * MAX);
        printf("\nProcessing...\n");
        menu(a, f1, f2);
        printf("\nComplete running!\n");
        fclose(f1);
        fclose(f2);
        free(a);
        return 0;
    }
}