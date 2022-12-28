//#include "QueueList.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "singlel.h"
/*struct element_type 
{
    char model[31];
    // ms - memory space
    float ms;
    // ss - screen size 
    float ss;
    //char price[31];
    float price;
};

typedef struct element_type et; */

struct Node_t
{
    et Element;
    struct Node_t *next;
};
typedef struct Node_t node_t;
typedef node_t* Position;
typedef struct 
{
    Position front, rear;
} queue;

void MakeNull(queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

int IsEmpty(queue *q)
{
    return q->front == NULL;
}

void EnQueue(et x, queue *q)
{
    node_t *tmp = (node_t *)malloc(sizeof(node_t));
    if(q->front == NULL)
    {
        q->front = tmp;
        q->rear = tmp;
    }
    else
    {
        q->rear->next = tmp;
        q->rear = q->rear->next;
    }
    q->rear->Element = x;
}

et Dequeue(queue *q)
{
    if(IsEmpty(q))
    {
        printf("\nQueue is empty!\n");
    }
    else
    {
        node_t *tmp = q->front;
        et e = tmp->Element;
        if(q->front == q->rear)
        {
            free(tmp);
            free(q->rear);
            MakeNull(q);
            return e;
        }
        else
        {
            q->front = q->front->next;
            free(tmp);
            return e;
        }
    }
}

int main()
{
    et tmp;
    char c;
    queue q;
    MakeNull(&q);
    int cnt = 0, i = 0;
    et *save = (et *)malloc(sizeof(et));
    do
    {
        printf("\nModel number %d:\n", cnt + 1);
        ReadNode(&tmp);
        if(cnt < 10)
        {
            EnQueue(tmp, &q);
            cnt++;
        }
        else
        {
            save[i] = Dequeue(&q);
            EnQueue(tmp, &q);
            i++;
            cnt++;
        }
        
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');

    int j;
    /*if(cnt >= 10)
    {
        printf("\n%-5s%-20s%-25s%-25s%-20s\n", "", "Model", "Memory Space(GB)", "Screen Size(inches)", "Price($)");
        for(j = 0; j < i; ++j)
        {
            printf("%-5d%-20s%-25.2f%-25.2f%-20.2f\n", j, save[j].model, save[j].ms, save[j].ss, save[j].price);
        }
    }*/
    j = 0;
    printf("\nIn queue:\n");
    printf("\n%-5s%-20s%-25s%-25s%-20s\n", "", "Model", "Memory Space(GB)", "Screen Size(inches)", "Price($)");
    while(!IsEmpty(&q))
    {
        tmp = Dequeue(&q);
        printf("%-5d%-20s%-25.2f%-25.2f%-20.2f\n", j, tmp.model, tmp.ms, tmp.ss, tmp.price);
        j++;
    } 
    //printf("\n%d\n", IsEmpty(&q));
    return 0;
}