#include<stdio.h>
#include<stdlib.h>
#define MAX 256

//typedef int ElementType;
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

typedef struct element_type ElementType;

typedef struct Node
{
    ElementType Element;
    Node *next;
};
typedef Node* Position;
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

void EnQueue(ElementType x, queue *q)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
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

ElementType Dequeue(queue *q)
{
    if(IsEmpty(q))
    {
        printf("\nQueue is empty!\n");
    }
    else
    {
        node_t *tmp = q->front;
        ElementType e = tmp->Element;
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
