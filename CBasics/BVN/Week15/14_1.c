#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define B
//typedef KeyType;

typedef struct Node
{
    KeyType Key;
    Node *next;
};
typedef Node* Position;
typedef Position Dictionary[B];

Dictionary D;

void MakeNullSet()
{
    int i;
    for(i = 0; i < B; ++i)
    {
        D[i] = NULL;
    }
}

int Search(KeyType X)
{
    Position P;
    int found = 0;
    P = D[H(X)];
    while((P != NULL) && !found)
    {
        if(P->Key == X) found = 1;
        else P = P->next;
    }
    return found;
}

void InsertSet(KeyType X)
{
    int Bucket;
    Position P;
    if(!Member(X, D))
    {
        Bucket = H(X);
        P = D[Bucket];
        D[Bucket] = (node *)malloc(sizeof(node));
        D[Bucket]->Key = X;
        D[Bucket]->next = P;
    }
}