#include<stdlib.h>
#include<stdio.h>
#include "GenSLL.h"
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
        p *a = (p *)malloc(MAX * sizeof(p));
        fseek(f, 0, SEEK_END);
        int cnt = ftell(f) / sizeof(p);
        rewind(f);
        int num = fread(a, sizeof(p), cnt, f);
        int i;
        l = createNode(a[0]);
        cur = l;
        prev = NULL;
        for(i = 1; i < num; ++i)
        {
            InsertAfterCur(a[i]);
        }
        /*printf("\nList ban dau:\n");
        printList();
        node *list1 = split(l, 2, 3);
        node *tmp = list1;
        printf("\nList 1:\n");
        while(tmp != NULL)
        {
            displayNode(tmp);
            tmp = tmp->next;
        }
        printf("\nList 2:\n");
        printList(); */
        /*node *tmp = l;
        tmp = insertAtPosition(tmp, a[0], 6);
        printf("\nAfter insert:\n");
        printList();
        tmp = l;
        tmp = deleteAtPosition(tmp, 6);
        printf("\nAfter delete:\n");
        printList();*/
        /*deleteHead();
        printf("\nAfter delete head:\n");
        printList();*/
        printf("\nCur pnt is now at:\n");
        displayNode(cur);
        deleteMiddle();
        printf("\nAfter delete cur pnt:\n");
        printList();
        /*deleteTail();
        printf("\nAfter delete tail:\n");
        printList();*/
        free(a);
        FreeList();
        fclose(f);
    }
}