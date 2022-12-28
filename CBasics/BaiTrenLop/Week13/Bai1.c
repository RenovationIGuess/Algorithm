#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256

int m_num;

struct element_type 
{
    char name[31];
    char telephone[12];
    char email[31];
};

typedef struct element_type ElmType;
#include "BTree.h"

void DArray(ElmType *a)
{
    int i;
    printf("\n%-5s%-25s%-25s%-25s\n", "", "Name", "Telephone", "E-mail Address");
    for(i = 0; i < m_num; ++i)
    {
        printf("%-5d%-25s%-25s%-25s\n", i, a[i].name, a[i].telephone, a[i].email);
    }
} 

void InorderPrint(treetype t)
{
    if(t != NULL)
    {
        InorderPrint(t->left);
        //ElmType tmp = t->element;
        printf("%-25s%-25s%-25s\n", t->element.name, t->element.telephone, t->element.email);
        //printf("%-25s%-25s%-25s\n", tmp.name, tmp.telephone, tmp.email);
        InorderPrint(t->right);
    }
}

int main(int argc, char *argv[])
{
    FILE *f, *f1;
    ElmType *a = (ElmType *)malloc(MAX * sizeof(ElmType));
    if ((f = fopen(argv[1], "rb")) == NULL) 
    {
        printf("Cannot open %s.", argv[1]);
        //exit(1);
        return 1;
    }
    else if ((f1 = fopen(argv[2], "wb")) == NULL)
    {
        printf("Cannot open %s.", argv[2]);
        //exit(1);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    m_num = ftell(f) / sizeof(ElmType);  
    int i = 0, num;
    fseek(f, 0, SEEK_SET);
    num = fread(a, sizeof(ElmType), m_num, f);
    DArray(a);
    treetype t;
    MakeNullTree(&t);
    for(i = 0; i < m_num; ++i)
    {
        InsertNode(a[i], &t);
    }
    char *s = (char *)malloc(MAX * sizeof(char));
    printf("\nEnter email to search: ");
    fflush(stdin); gets(s);
    treetype res = Search(s, t);
    if(res != NULL) 
    {
        printf("%-25s%-25s%-25s\n\n", res->element.name, res->element.telephone, res->element.email);
        DeleteNode(res->element, &t);
    }
    else printf("\nNot found!\n");
    InorderPrint(t);
    //printf("%-25s%-25s%-25s\n", t->right->element.name, t->right->element.telephone, t->right->element.email);
    free(a);
    free(s);
    fclose(f);
    fclose(f1);
    return 0;
}
