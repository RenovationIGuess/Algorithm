#include "DoubleL.h"
#define MAX 256
int main()
{
    FILE *f;
    if((f = fopen("PhoneDB.dat", "rb")) == NULL)
    {
        printf("\nCannot open!\n");
        return 1;
    }
    else
    {
        doublelist root, cur, tail;
        et *a = (et *)malloc(MAX * sizeof(et));
        fseek(f, 0, SEEK_END);
        int cnt = ftell(f) / sizeof(et);
        rewind(f);
        int num = fread(a, sizeof(et), cnt, f);
        int i;
        root = MakeNewNode(a[0]);
        //displayNode(root);
        cur = tail = root;
        for(i = 1; i < num; ++i)
        {
            InsertAfterCurrent(a[i], &root, &tail, &cur);
            //InsertAtTail(a[i], &root, &tail, &cur);
        }

        printf("\n%-5s%-20s%-25s%-25s%-20s\n", "", "Model", "Memory Space(GB)", "Screen Size(inches)", "Price($)");
        node *p = root;
        i = 0;
        while(p != NULL)
        {
            printf("%-5d%-20s%-25.2f%-25.2f%-20.2f\n", i, p->data.model, p->data.ms, p->data.ss, p->data.price);
            i++;
            p = p->next;
        }
        DeleteTail(&root, &tail, &cur);
        p = root;
        i = 0;
        printf("\n");
        while(p != NULL)
        {
            printf("%-5d%-20s%-25.2f%-25.2f%-20.2f\n", i, p->data.model, p->data.ms, p->data.ss, p->data.price);
            i++;
            p = p->next;
        }
        free(a);
        FreeList(&root);
        fclose(f);
    }    
    return 0;
}