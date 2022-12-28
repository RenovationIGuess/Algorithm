#include<stdio.h>
#include<stdlib.h>
#define MAX 256

typedef int ElementType;
typedef struct 
{
    ElementType Elements[MAX];
    int front, rear;
} Queue;

void MakeNull(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int EmptyQueue(Queue q)
{
    return q.front == -1;
}

int FullQueue(Queue q)
{
    return (q.rear == MAX - 1);
    //return (q.rear - q.front + 1) == MAX
    // return (q.rear - q.front + 1) % MAX == 0
}

void EnQueue(ElementType x, Queue *q)
{
    if(!FullQueue(*q))
    {
        if(EmptyQueue(*q)) q->front = 0;
        q->rear = q->rear + 1;
        q->Elements[q->rear] = x;
    }
    else printf("\nQueue is full!\n");
}

ElementType DeQueue(Queue *q)
{
    ElementType e;
    if(!EmptyQueue(*q))
    {
        e = q->Elements[q->front];
        q->front = q->front + 1;
        if(q->front > q->rear)
        {
            MakeNull(q);
        }
        return e;
    }
    else printf("\nQueue is empty!\n");
}

/*void EnQueue(ElementType X,Queue *Q)
{ 
    if (!Full_Queue(*Q))
    {
        if (Empty_Queue(*Q)) Q->Front=0;
        Q->Rear=(Q->Rear+1) % MaxLength; 
        Q->Elements[Q->Rear]=X;
    } else printf("Queue is full!"); 
} */


/*ElementType DeQueue(Queue *Q)
{
    ElementType e;	
    if (!Empty_Queue(*Q))
    { 
        e=Q->Elements[Q->Front];
        if (Q->Front==Q->Rear) 
        {
            MakeNullQueue(Q);
        }
        else Q->Front=(Q->Front+1) % MaxLength; 
        return e;
    } 
    else printf("Queue is empty!"); 
} */
