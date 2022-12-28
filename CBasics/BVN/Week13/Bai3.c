#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 256

FILE *f, *f1;
int m_num;

struct element_type 
{
    char model[31];
    // ms - memory space
    float ms;
    // ss - screen size 
    float ss;
    //char price[31];
    float price;
};

typedef struct element_type ElmType;

#include "BinTree.h"

void Inorder(treetype t)
{
    if(t != NULL)
    {
        Inorder(t->left);
        printf("%-20s%-25.2f%-25.2f%-20.2f\n", t->element.model, t->element.ms, t->element.ss, t->element.price);
        Inorder(t->right);
    }
}

void Func1(char *s1, treetype *t)
{
    printf("\nProcessing...\n");
    if((f = fopen(s1, "r")) == NULL)
    {
        printf("\nCannot open %s!\n", s1);
        return;
    }
    ElmType *a = (ElmType *)malloc(MAX * sizeof(ElmType));
    fseek(f, 0, SEEK_SET);

    int i = 0;
    while(fscanf(f, "%s%f%f%f", a[i].model, &a[i].ms, &a[i].ss, &a[i].price) != EOF)
    {
        InsertNode(a[i], t);
        i++;
    }
    m_num = i;
    printf("\nSo Model hien co: %d.\n", m_num);
    fclose(f);
    printf("\nSuccess!\n");
}

void Func2(char *s2, treetype *t)
{
    printf("\nProcessing...\n");
    if ((f1 = fopen(s2, "rb")) == NULL) 
    {
        printf("Cannot open %s.", s2);
        exit(1);
    }
    ElmType *a = (ElmType *)malloc(MAX * sizeof(ElmType));
    fseek(f1, 0, SEEK_END);

    printf("\nSo mau dien thoai: %d.\n", ftell(f1) / sizeof(ElmType));
    m_num = ftell(f1) / sizeof(ElmType);  
    int i = 0, num;
    fseek(f1, 0, SEEK_SET);
    num = fread(a, sizeof(ElmType), m_num, f1);
    for(i = 0; i < m_num; ++i)
    {
        InsertNode(a[i], t);
    }
    fclose(f1);
    printf("\nSuccess!\n");
}

void Func3(treetype *t)
{
    char c;
    do
    {
        ElmType add;
        ReadNode(&add);
        InsertNode(add, t);
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');
}

void Func4(treetype *t)
{
    char c, s[MAX];
    do
    {
        printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space (GB)", "Screen Size (Inches)", "Price ($)");
        Inorder(*t);
        printf("\nEnter models name: ");
        fflush(stdin); gets(s);
        treetype res = Search(s, (*t));
        if(res != NULL)
        {
            DeleteNode(s, t);
            printf("\nAfter delete:");
            printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space (GB)", "Screen Size (Inches)", "Price ($)");
            Inorder(*t);
        }
        else printf("\nNon-existed!\n");
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');
}

void Func5(treetype *t)
{
    char c, s[MAX];
    do
    {
        printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space (GB)", "Screen Size (Inches)", "Price ($)");
        Inorder(*t); 
        printf("\nEnter models name: ");
        fflush(stdin); gets(s);
        treetype res = Search(s, (*t));
        if(res != NULL)
        {
            /*printf("\nResult:");
            printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space (GB)", "Screen Size (Inches)", "Price ($)");
            printf("%-20s%-25.2f%-25.2f%-20.2f\n", res->element.model, res->element.ms, res->element.ss, res->element.price);*/
            printf("\nEnter updated information:\n");
            ReadNode(&res->element);
        }
        else printf("\nNon-existed!\n");
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');
}

void Func6(treetype *t)
{
    char c, s[MAX];
    do
    {
        printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space (GB)", "Screen Size (Inches)", "Price ($)");
        Inorder(*t); 
        printf("\nEnter models name: ");
        fflush(stdin); gets(s);
        treetype res = Search(s, (*t));
        if(res != NULL)
        {
            printf("\nResult:");
            printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space (GB)", "Screen Size (Inches)", "Price ($)");
            //Inorder(t);
            printf("%-20s%-25.2f%-25.2f%-20.2f\n", res->element.model, res->element.ms, res->element.ss, res->element.price);
        }
        else printf("\nNon-existed!\n");
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');
}

void Loop(treetype t, FILE *f)
{
    if(t != NULL)
    {
        Loop(t->left, f);
        ElmType *tmp = (ElmType *)malloc(sizeof(ElmType));
        tmp[0] = t->element;
        fwrite(tmp, sizeof(ElmType), 1, f);
        Loop(t->right, f);
    }
}

void Func8(char *s, treetype *t)
{
    printf("\nProcessing...\n");
    if ((f = fopen(s, "wb")) == NULL) 
    {
        printf("Cannot open %s.", s);
        exit(1);
    }
    ElmType *a = (ElmType *)malloc(MAX * sizeof(ElmType));
    int num;
    fseek(f, 0, SEEK_SET);
    Loop((*t), f);
    printf("\nSuccess! Returning to main menu...\n");
    fclose(f);
}

void Menu(treetype *t, char *s1, char *s2)
{
    printf("\nMenu:\n");
    int cnt = 0;
    int i;
    do
    {
        // option
        int opt;
        printf("\n1. Import from PhoneDB.txt\n2. Import from PhoneDB.dat\n3. Add new phone model\n4. Delete\n5. Update\n6. Searching\n7. Displaying\n8. Save to file.dat\n9. Quit (free)\n");
        printf("\nEnter option: ");
        fflush(stdin);
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                //Import from text
                if(cnt != 0)
                {
                    FreeTree((*t));
                    MakeNullTree(t);
                }
                Func1(s1, t);
                cnt++;
                break;
            case 2:
                if(cnt != 0)
                {
                    FreeTree((*t));
                    MakeNullTree(t);
                }
                Func2(s2, t);
                cnt++;
                break;
            case 3:
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                Func3(t);
                break;
            case 4:
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                Func4(t);
                break;
            case 5:
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                Func5(t);
                break;
            case 6: 
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                Func6(t);
                break;
            case 7: 
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space (GB)", "Screen Size (Inches)", "Price ($)");
                Inorder(*t);
                break;
            case 8: 
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                Func8(s2, t);
                break;
            case 9: 
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
    treetype t;
    MakeNullTree(&t);
    // 1 - text, 2 - dat
    Menu(&t, argv[1], argv[2]);
    return 0;
}