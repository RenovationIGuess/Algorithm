#include<stdio.h>
#include<stdlib.h>
//#include<time.h>

//dem so danh ba
int m_num;

/*int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
} */

typedef struct element_type et;

struct Node
{
    et data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node node;
typedef node* doublelist;
//doublelist root, tail, cur;

void ReadNode(et *a)
{
    
}

//Tao node
node *MakeNewNode(et x)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = x;
    tmp->next = NULL;
    tmp->prev = NULL; 
    return tmp;
}

void MakeNullList(doublelist *root, doublelist *tail, doublelist *cur)
{
    (*root) = NULL;
    (*tail) = NULL;
    (*cur) = NULL;
}

int isEmpty(doublelist root)
{
    return (root == NULL);
}

//Input
void InsertAtHead(et x, doublelist *root, doublelist *tail, doublelist *cur)
{
    node *tmp = MakeNewNode(x);
    if(*root == NULL)
    {
        *root = *tail = *cur = tmp;
        return;
    }
    tmp->next = *root;
    (*root)->prev = tmp;
    *root = tmp;
    *cur = *root; 
}

void InsertAtTail(et x, doublelist *root, doublelist *tail, doublelist *cur)
{
    node *tmp = MakeNewNode(x);
    /*if(*root = NULL)
    {
        *root = *cur = *tail = tmp;
    }*/
    if(*tail == NULL)
    {
        *root = *cur = *tail = tmp;
        return;
    }
    (*tail)->next = tmp;
    tmp->prev = *tail;
    *tail = tmp;
    *cur = *tail;
}

void InsertAfterCurrent(et x, doublelist *root, doublelist *tail, doublelist *cur)
{
    node *tmp = MakeNewNode(x);
    if(*root == NULL)
    {
        *root = *tail = *cur = tmp;
        return;
    }
    /*else if(*cur == NULL)
    {
        printf("\nCurrent pointer is NULL!\n");
        return;
    }*/
    else
    {
        /*if(*cur == *tail) InsertAtTail(x, root, tail, cur);
        else
        {*/
            tmp->next = (*cur)->next;
            if((*cur)->next != NULL) (*cur)->next->prev = tmp;
            else *tail = tmp;
            (*cur)->next = tmp;
            tmp->prev = *cur;
            *cur = tmp;
        //}
    }
}

void InsertBeforeCurrent(et x, doublelist *root, doublelist *tail, doublelist *cur)
{
    node *tmp = MakeNewNode(x);
    if(*root == NULL)
    {
        *root = *tail = *cur = tmp;
        return;
    }
    else if(*cur == NULL)
    {
        printf("\nCurrent pointer is NULL!\n");
        return;
    }
    else
    {
        if(*cur == *root) InsertAtHead(x, root, tail, cur);
        else
        {
            tmp->next = (*cur);
            /*if((*cur) != NULL) (*cur)->prev = tmp;
            else *tail = tmp;*/
            tmp->prev = (*cur)->prev;
            (*cur)->prev->next = tmp;
            (*cur)->prev = tmp;
            *cur = tmp;
        }
    }
}

void InsertAtPosition(int posi, et x, doublelist *root, doublelist *tail, doublelist *cur)
{
    *cur = *root;
    int i;
    if(posi <= 0) 
    {
        InsertAtHead(x, root, tail, cur);
        return;
    }
    for(i = 0; i < posi - 1; ++i)
    {
        if((*cur)->next != NULL) *cur = (*cur)->next;
    }
    InsertAfterCurrent(x, root, tail, cur);
}

//delete a node pointed by p
void DeleteList(doublelist p, doublelist *root, doublelist *tail, doublelist *cur)
{
    if(*root == NULL)
    {
        printf("\nList's empty!\n");
    }
    else
    {
        if(p == *root) *root = (*root)->next;
        else
        {
            p->prev->next = p->next;
        }
        if(p->next != NULL) p->next->prev = p->prev;
        else *tail = p->prev;
        *cur = p->prev;
        free(p);
    }
}

//Delete
void DeleteHead(doublelist *root, doublelist *cur)
{
    if(*root == NULL)
    {
        printf("\nList's empty!\n");
    }
    else
    {
        node *p = *root; 
        *root = (*root)->next;
        *cur = *root;
        free(p);
    }
}

void DeleteTail(doublelist *root, doublelist *tail, doublelist *cur)
{
    node *del = *tail;
    if(del == NULL)
    {
        printf("\nTail's empty!\n");
        return;
    }
    *tail = (*tail)->prev;
    if(*tail == NULL)
    {
        *root = NULL;
    }
    else (*tail)->next = NULL;
    free(del);
    *cur = *tail;
}

void DeleteCurrent(doublelist *root, doublelist *tail, doublelist *cur)
{
    if(*root == NULL)
    {
        printf("\nNothing to delete!\n");
        return;
    }
    else if(*cur == NULL)
    {
        printf("\nCurrent pointer is NULL!\n");
        return;
    }
    else
    {
        if(*cur == *root) DeleteHead(root, cur);
        else if(*cur == *tail) DeleteTail(root, tail, cur);
        else
        {
            node *tmp = *cur;
            //*cur = (*cur)->next;
            if((*cur)->next != NULL) 
            {
                (*cur)->next->prev = (*cur)->prev;
                (*cur)->prev->next = (*cur)->next;
            }
            else *tail = (*cur)->prev;
            (*cur) = (*cur)->prev;
            free(tmp);
        }
    }
}

void DeleteAfterCurrent(doublelist *root, doublelist *tail, doublelist *cur)
{
    if(*root == NULL)
    {
        printf("\nNothing to delete!\n");
        return;
    }
    else if(*cur == NULL)
    {
        printf("\nCurrent pointer is NULL!\n");
        return;
    }
    else
    {
        node *tmp = (*cur)->next;
        //*cur = (*cur)->next;
        if(tmp == NULL)
        {
            //DeleteTail(root, tail, cur);
            printf("\nNothing to delete!\n");
        }
        else
        {
            if(tmp->next != NULL)
            {
                (*cur)->next = tmp->next;
                tmp->next->prev = *cur;
            }
            else *tail = *cur;
            free(tmp);
        }
    }
}

void DeleteBeforeCurrent(doublelist *root, doublelist *tail, doublelist *cur)
{
    if(*root == NULL)
    {
        printf("\nNothing to delete!\n");
        return;
    }
    else if(*cur == NULL)
    {
        printf("\nCurrent pointer is NULL!\n");
        return;
    }
    else
    {
        node *tmp = (*cur)->prev;
        if(tmp->prev != NULL)
        {
            tmp->prev->next = *cur;
            (*cur)->prev = tmp->prev;
        }
        else *root = *cur;
        free(tmp);
    }
}

void DeleteAtPosition(int posi, doublelist *root, doublelist *tail, doublelist *cur)
{
    *cur = *root;
    int i;
    if(posi <= 0) 
    {
        DeleteHead(root, cur);
        return;
    }
    else if(posi >= m_num - 1)
    {
        DeleteTail(root, tail, cur);
        return;
    } 
    for(i = 0; i < posi - 1; ++i)
    {
        if((*cur)->next != NULL) *cur = (*cur)->next;
    }
    DeleteAfterCurrent(root, tail, cur);
}

void displayNode(node *x)
{
    if(x == NULL)
    {
        printf("\nCon tro loi - NULL!\n");
        return;
    }
    et tmp = x->data;
    //printf("%-20s%-25.2f%-25.2f%-20.2f\n", tmp.model, tmp.ms, tmp.ss, tmp.price);
}

//duyet list tu tail
void TraverseTail(node *tail)
{
    node *p;
    for(p = tail; p != NULL; p = p->prev)
    {
        displayNode(p);
    }
}

void Reverse(doublelist *root)
{
    node *temp = NULL; 
    node *cur = *root;
      
    while (cur != NULL)
    {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;             
        cur = cur->prev;
    }     

    //if(temp != NULL)
    *root = temp->prev;
}    

void FreeList(doublelist *root)
{
    node *p = *root;
    while(p != NULL)
    {
        *root = (*root)->next;
        free(p);
        p = *root;
    }
}