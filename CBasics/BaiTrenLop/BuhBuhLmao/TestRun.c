#include<stdio.h>
#include<math.h>
#include "Sort.h"
#include<stdlib.h>
#include<time.h>

int random(int Min, int Max)
{
    return Min + rand() % (Max - Min + 1);
}

//Building max heap
void Heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && a[l] > a[largest])
        largest = l;
    if(r < n && a[r] > a[largest])
        largest = r;
    if(largest != i);
    {
        swap(&a[i], &a[largest]);
        Heapify(a, n, largest);
    }
}

//7. Heap Sort
void HeapSort(int a[], int n)
{
    int i;
    for(i = n/2 - 1; i >= 0; --i)
    {
        Heapify(a, n, i);
    }
    for(i = n - 1; i >= 0; --i)
    {
        swap(&a[0], &a[i]);
        //printArray(a, n);
        Heapify(a, i, 0);
    }
}

int main()
{
    //srand((int)time(0));
    int n;
    printf("\nEnter n: ");
    fflush(stdin); scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    int i;
    for(i = 0; i < n; ++i)
    {
        //a[i] = random(1, 20);
        scanf("%d", &a[i]);
    }
    printf("\nOrigin Array:\n");
    printArray(a, n);
    printf("\nAfter Sorted Array:\n");
    //BubbleSort(a, n);
    //InsertionSort(a, n);
    //SelectionSort(a, n);
    //MergeSort(a, 0, n - 1);
    //ShellSort(a, n);
    //QuickSort(a, 0, n - 1);
    //HeapSort(a, n);
    heapSort(a, n);
    printArray(a, n);
    free(a);
    return 0;
}