#include "Sort.h"

int main()
{
    int a[11] = {11, 16, 12, 75, 51, 54, 5, 73, 36, 52, 98};
    int i, j;
    int n = sizeof(a) / sizeof(int);
    printf("\nTrang thai ban dau:\n");
    printArray(a, n);
    printf("\nSort:\n");
    //QuickSort(a, 0, n - 1);
    InsertionSort(a, n);
    //printArray(a, n);
    return 0;
}