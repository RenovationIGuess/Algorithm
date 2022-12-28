#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 256

FILE *f;

struct item
{
    //tu tieng anh
    char name[MAX];
    //des vn
    char vn[MAX];
    //synonym
    char syno[MAX];
    //example
    char exam[MAX];
};

typedef struct item ElmType;
#include "Tree1.h"

void Display(treetype t)
{
    if(t != NULL)
    {
        Display(t->left);
        printf("%-30s%-30s%-30s%-50s\n", t->element.name, t->element.vn, t->element.syno, t->element.exam);
        Display(t->right);
    }
}

void Create(char *s, treetype *t)
{
    if((f = fopen(s, "r")) == NULL)
    {
        printf("\nCannot open file %s!\n", s);
        exit(1);
    }
    ElmType Input;
    while(fscanf(f, "%s%s%s%s", Input.name, Input.vn, Input.syno, Input.exam) != EOF)
    {
        InsertNode(Input, t);
    }
    fclose(f);
}

void Func1(treetype *t)
{
    int i = 0;
    char opt;
    char *find = (char *)malloc(MAX * sizeof(char));
    do
    {
        printf("\nWords list:\n");
        printf("\n%-30s%-30s%-30s%-50s\n\n", "English Word", "Description", "Synonyms", "Example sentences");
        Display(*t);
        printf("\nEnter word to find: ");
        fflush(stdin); gets(find);
        treetype res = Search(find, *t);
        if(res != NULL)
        {
            printf("\nWord information:\n");
            printf("\n%-30s%-30s%-30s%-50s\n", "English Word", "Description", "Synonyms", "Example sentences");
            printf("%-30s%-30s%-30s%-50s\n", res->element.name, res->element.vn, res->element.syno, res->element.exam);
        }
        else printf("\nNot found!\n");
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &opt);
        while(opt != 'y' && opt != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &opt);
        }
    } while (opt == 'y');
}

void Func2(treetype *t)
{
    ElmType add;
    char opt;
    printf("\nEnter english word: ");
    fflush(stdin); gets(add.name);
    printf("\nEnter description in vietnamese: ");
    fflush(stdin); gets(add.vn);
    printf("\nDo you want to enter synonyms [y/n]: ");
    fflush(stdin); scanf("%c", &opt);
    while(opt != 'y' && opt != 'n')
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin); scanf("%c", &opt);
    }
    if(opt == 'y')
    {
        printf("\nEnter synonyms: ");
        fflush(stdin); gets(add.syno);
    }
    else add.syno[0] = '\0';
    printf("\nDo you want to enter examples [y/n]: ");
    fflush(stdin); scanf("%c", &opt);
    while(opt != 'y' && opt != 'n')
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin); scanf("%c", &opt);
    }
    if(opt == 'y')
    {
        printf("\nEnter example sentence: ");
        fflush(stdin); gets(add.exam);
    }
    else add.exam[0] = '\0';
    InsertNode(add, t);
    printf("\nSuccess! Return to menu...\n");
}

void Func3(treetype *t)
{
    char *del = (char *)malloc(MAX * sizeof(char));
    char opt;
    do
    {
        printf("\nWords list:\n");
        printf("\n%-30s%-30s%-30s%-50s\n\n", "English Word", "Description", "Synonyms", "Example sentences");
        Display(*t);
        printf("\nEnter word to delete: ");
        fflush(stdin); gets(del);
        treetype res = Search(del, *t);
        if(res != NULL)
        {
            printf("\nWord information:\n");
            printf("\n%-30s%-30s%-30s%-50s\n", "English Word", "Description", "Synonyms", "Example sentences");
            printf("%-30s%-30s%-30s%-50s\n", res->element.name, res->element.vn, res->element.syno, res->element.exam);
            DeleteNode(del, t);
            printf("\nDelete successful!\n");
        }
        else printf("\nNot found!\n");
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &opt);
        while(opt != 'y' && opt != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &opt);
        }
    } while (opt == 'y');
}

void Func4(char *s, treetype t)
{
    if((f = fopen(s, "w")) == NULL)
    {
        printf("\nCannot open file %s!\n", s);
        exit(1);
    }
    treetype p = t;
    while(t)
    {
        if(t->left == NULL)
        {
            fprintf(f, "%-30s%-30s%-30s%-50s\n", t->element.name, t->element.vn, t->element.syno, t->element.exam);
            t = t->right;
        }
        else
        {
            p = t->left;
            while(p->right && p->right != t)
            {
                p = p->right;
            }
            if(p->right == NULL)
            {
                p->right = t;
                t = t->left;
            }
            else
            {
                p->right = NULL;
                fprintf(f, "%-30s%-30s%-30s%-50s\n", t->element.name, t->element.vn, t->element.syno, t->element.exam);
                t = t->right;
            }
        }
    }
    printf("\nSuccess! Return to menu...\n");
    fclose(f);
}

void Menu(char *s, treetype *t)
{
    int opt;
    printf("\nMenu:\n");
    Create(s, t);
    do
    {
        printf("\n1. Searching\n2. Adding\n3. Delete\n4. Save data\n5. Quit\n");
        printf("\nEnter your option: ");
        fflush(stdin); scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            Func1(t);
            break;
        case 2:
            Func2(t);
            break;
        case 3:
            Func3(t);
            break;
        case 4:
            Func4(s, *t);
            break;
        case 5:
            printf("\nThank you!\n");
            break;
        default:
            break;
        }
    } while (opt != 5);
}

int main(int argc, char *argv[])
{
    treetype t;
    MakeNullTree(&t);
    Menu(argv[1], &t);
    return 0;
}