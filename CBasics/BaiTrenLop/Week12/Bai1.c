#include<stdio.h>
//#include "singlelist.h"
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct element_type 
{
    int key;
};

typedef struct element_type et;

void swap(et *a, et *b)
{
    et tmp = *a;
    *a = *b;
    *b = tmp;
}

void QuickSort(et a[], int l, int r)
{
    int p = a[(l + r)/2].key;
    int i = l, j = r;
    while(i < j)
    {
        while(a[i].key < p) i++;
        while(a[j].key > p) j--;
        if(i <= j)
        {
            swap(&a[i], &a[j]);
            i++; j--;
        }
    }
    if(i < r) QuickSort(a, i, r);
    if(j > l) QuickSort(a, l, j);
}

int BinSearch(et *a, int key, int size)
{
    int mid, l = 0, r = size - 1;
    while(l <= r)
    {
        mid = (r + l)/2;
        //printf("%d\n", mid);
        if(a[mid].key == key)
        {
            return mid;
        }
        else if(a[mid].key > key)
        {
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return -1;
}

void Req1(et *a, et *b, int n, int m)
{
    int i, j, cnt = 0;
    int *check = (int *)malloc(m * sizeof(int));
    for(i = 0; i < m; ++i)
    {
        check[i] = 0;
    }
    for(i = 0; i < n; ++i)
    {
        if(j = BinSearch(b, a[i].key, m))
        {
            printf("\n%d is not in list 2\n", a[i].key);
            cnt++;
        }
        else
        {
            check[j] = 1;
        }
    }
    printf("\nNumber of elements not in list 2: %d\n", cnt);
    /*
    for(i = 0; i < m; ++i)
    {
        if(!check[i])
        {
            printf("\n%d is not in list 1\n", b[i].key);
        }
    }*/
}

void Req2(et *a, et *b, int n, int m)
{
    QuickSort(a, 0, n);
    QuickSort(b, 0, m);
    int i, j;
    i = j = 0;
    while(i < n && j < m)
    {
        if(a[i].key < b[j].key)
        {
            printf("\n%d is not in list 2\n", a[i].key);
            i++;
        }
        else if(a[i].key == b[j].key)
        {
            i++; j++;
        }
    }
}

void print(et *a, int n)
{
    int i;
    for(i = 0; i < n; ++i)
    {
        printf("%d ", a[i].key);
    }
}

int main()
{
    int value;
    int n, m;
    printf("\nEnter list 1 number of element: ");
    fflush(stdin);
    scanf("%d", &n);
    printf("\nEnter list 2 number of element: ");
    fflush(stdin);
    scanf("%d", &m);
    et *a = (et *)malloc(n * sizeof(et));
    et *b = (et *)malloc(m * sizeof(et));
    srand((int)time(0));
    int i;
    for(i = 0; i < n; ++i)
    {
        value = rand();
        a[i].key = value;
    }

    //srand((int)time(0));
    for(i = 0; i < m; ++i)
    {
        value = rand();
        b[i].key = value;
    }
    //Req1(a, b, n, m);
    Req2(a, b, n, m);
    free(a);
    free(b);
    return 0;
}