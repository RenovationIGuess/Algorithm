#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256

//typedef int ElementType;

/*typedef struct
{
    int id;
    float memory;
    //int onqueue;
} ElementType; */

struct Node_t
{
    ElementType Element;
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

int size(queue *q)
{
    int cnt = 0;
    Position tmp = q->front;
    while(tmp != q->rear)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt + 1;
}

ElementType top(queue *q)
{
    return q->front->Element;
}

void EnQueue(ElementType x, queue *q)
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

/*int BSQueue(char *search, queue *q)
{
	int first = 0;
	int last = 9;
	int mid;
	int i, k;
	int result = -1;
	while (last >= first && result == -1)
	{
		mid = (first + last) / 2;
		for (i = 0; i < mid; ++i)
			EnQueue(Dequeue(q), q);
		k = strcmp(search, q->front->Element.name); 
		if (k == 0)
		{
			result = mid;
		}
		else if (k < 0)
			last = mid - 1;
		else first = mid + 1;
		for(i = mid; i < 10; ++i)
		    EnQueue(Dequeue(q), q);
	}
	return result;
} */