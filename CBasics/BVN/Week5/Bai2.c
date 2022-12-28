#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 256

typedef struct
{
    char model[31];
    // ms - memory space
    float ms;
    // ss - screen size 
    float ss;
    char price[31];
} p; //p - phone

// number of model
int m_num;

void Func1(p *a, FILE *fin, FILE *fout)
{
    printf("\nProcessing...\n");
    fseek(fin, 0, SEEK_SET);
    int i = 0;
    printf("\nWhat have read:\n\n");
    while(fscanf(fin, "%s%f%f%s", a[i].model, &a[i].ms, &a[i].ss, a[i].price) != EOF)
    {
        printf("%-15s%-20.2f%-20.2f%-15s\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
        i++;
    }
    m_num = i;
    printf("\nSo Model hien co: %d.\n", m_num);
    int num = fwrite(a, sizeof(p), i, fout);
    printf("\nWriten value: %d.\n", num);
    printf("\nSuccess!\n");
}

void Func2_1(FILE *fin)
{
    // Full reading mode
    fseek(fin, 0, SEEK_SET);
    p *b = (p *)malloc(sizeof(p));
    int num = fread(b, sizeof(p), m_num, fin);
    printf("\nValue have read: %d.\n", num);
    int i;
    printf("\n%-15s%-20s%-20s%-15s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
    for(i = 0; i < num; ++i)
    {
        printf("%-15s%-20.2f%-20.2f%-15s\n", b[i].model, b[i].ms, b[i].ss, b[i].price);
    }
}

void Func2_2(FILE *fin)
{
    // Partial Reading Mode
    fseek(fin, 0, SEEK_SET);
    p *b = (p *)malloc(sizeof(p) * MAX);
    int i;
    // b - begin, e - end
    /*int b, e;
    printf("\nEnter beginning: ");
    fflush(stdin);
    scanf("%d", &b);
    printf("\nEnter end: ");
    fflush(stdin);
    scanf("%d", &e);
    fseek(fin, sizeof(p) * (b - 1), SEEK_SET);
    int num = fread(b, sizeof(p), e - b + 1, fin);
    
    printf("\n%-15s%-20s%-20s%-15s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
    for(i = 0; i < res; ++i)
    {
        printf("%-15s%-20.2f%-20.2f%-15s\n", b[i].model, b[i].ms, b[i].ss, b[i].price);
    } */

    // num - so records muon doc
    int opt, num, res;
    //starting position
    int begin;
    printf("\nSelect below:\n");
    do
    {
        printf("\n1. From the beginning\n2. From the end\n3. Exit\n");
        printf("\nEnter option: ");
        fflush(stdin);
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                printf("\nEnter number of records you want to read: ");
                fflush(stdin);
                scanf("%d", &num);
                printf("\nEnter starting position: ");
                fflush(stdin);
                scanf("%d", &begin);
                fseek(fin, (begin - 1) * sizeof(p), SEEK_SET);
                printf("\nNow the file pointer is at: %d.\n", ftell(fin));

                res = fread(b, sizeof(p), num, fin);
                printf("\nValue have read: %d.\n", res);
                
                printf("\n%-15s%-20s%-20s%-15s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
                for(i = 0; i < res; ++i)
                {
                    printf("%-15s%-20.2f%-20.2f%-15s\n", b[i].model, b[i].ms, b[i].ss, b[i].price);
                }
                break;
            case 2:
                printf("\nEnter number of records you want to read: ");
                fflush(stdin);
                scanf("%d", &num);
                printf("\nEnter starting position: ");
                fflush(stdin);
                scanf("%d", &begin);
                
                fseek(fin, - num + 1, SEEK_END);
                res = fread(b, sizeof(p), num, fin);
                printf("\nValue have read: %d.\n", res);

                printf("\n%-15s%-20s%-20s%-15s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
                for(i = 0; i < res; ++i)
                {
                    printf("%-15s%-20.2f%-20.2f%-15s\n", b[i].model, b[i].ms, b[i].ss, b[i].price);
                }
                break;
            case 3:
                break;
            
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while(opt != 3);
}

void Func2(p *a, FILE *fin)
{
    printf("\nProcessing...\n");
    printf("\nYou have 3 option:\n");
    int opt;
    do
    {
        printf("\n1. Full Reading Mode\n2. Partial Reading\n3. Exit\n");
        printf("\nEnter option: ");
        fflush(stdin);
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                Func2_1(fin);
                break;
            case 2:
                Func2_2(fin);
                break;
            case 3:
                break;
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while(opt != 3);
    printf("\nSuccess!\n");
}

void Func3(FILE *fin)
{
    printf("\nProcessing...\n");
    fseek(fin, 0, SEEK_SET);
    int cnt = 0, page = 1, i;
    p *b = (p *)malloc(sizeof(p));
    //p *b;
    /*while(!feof(fin))
    {
        cnt = fread(b, sizeof(p), 24, fin);
        printf("\nPage %d:\n", page);
        printf("\n%-15s%-20s%-20s%-15s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
        for(i = 0; i < cnt; ++i)
        {
            printf("%-15s%-20.2f%-20.2f%-15s\n", b[i].model, b[i].ms, b[i].ss, b[i].price);
        }
        page++;
    }*/
    int num = fread(b, sizeof(p), m_num, fin);
    printf("\nValue have read: %d.\n", num);
    for(i = 0; i < num; ++i)
    {
        if(cnt == 0)
        {
            printf("\nPage %d:\n", page);
            printf("\n%-15s%-20s%-20s%-15s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
        }
        printf("%-15s%-20.2f%-20.2f%-15s\n", b[i].model, b[i].ms, b[i].ss, b[i].price);
        cnt++;
        if(cnt == 24)
        {
            cnt = 0;
            page++;
            printf("\n");
        }
    }
    printf("\nSuccess!\n");
}

void Func4(FILE *fin)
{
    printf("\nProcessing...\n");
    // model
    char *mod = (char *)malloc(sizeof(char));
    p *b = (p *)malloc(sizeof(p));
    int num = fread(b, sizeof(p), m_num, fin);
    printf("\nValue have read: %d.\n", num);
    int i;
    char c;
    do
    {
        // luu vi tri model can tim
        int found;
        printf("\nEnter Phone Model you want to search: ");
        fflush(stdin);
        scanf("%s", mod); 
        for(i = 0; i < num; ++i)
        {
            if(strcmp(b[i].model, mod) == 0)
            {
                //found = i;
                printf("\n%-15s%-20s%-20s%-15s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
                printf("%-15s%-20.2f%-20.2f%-15s\n", b[i].model, b[i].ms, b[i].ss, b[i].price);
                break;
            }
        }
        printf("\nDo you want to continue searching [y/n]: ");
        fflush(stdin);
        scanf("%c", &c);
    } while(c == 'y');
    printf("\nSuccess!\n");
}

void Menu(p *a, FILE *fin, FILE *fout)
{
    printf("\nMenu:\n");
    int cnt = 0;
    do
    {
        // option
        int opt;
        printf("\n1. Import DB from text\n2. Import from DB\n3. Print All Database\n4. Search by phone by Phone Model\n5. Exit\n");
        printf("\nEnter option: ");
        fflush(stdin);
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                Func1(a, fin, fout);
                cnt++;
                break;
            case 2:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func2(a, fout);
                break;
            case 3:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func3(fout);
                break;
            case 4:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func4(fout);
                break;
            case 5:
                printf("\nThank you!\n");
                return;
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while(1);
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
        p *a = (p *)malloc(sizeof(p));
        printf("\nOpening...\n");
        Menu(a, f1, f2);
        printf("\nComplete running!\n");
        fclose(f1);
        fclose(f2);
        free(a);
        return 0;
    }
}