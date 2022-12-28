#include<stdio.h>
#include<stdlib.h>
#include "Sort.h"

typedef int ElementType;

//Sequential Search
int LinearSearch(ElementType a[], int n, ElementType x)
{
    int k = 0;
    while(a[k] != x && k < n)
    {
        k++;
    }
    if(k < n) return k;
    return -1;
}

int LinearSentinel(ElementType a[], int n, ElementType x)
{
    int k = 0; 
    a[n] = x;
    while(a[k] != x)
    {
        k++;
    }
    return k - 1;
}

//Self organizing search
int Search(int key, int a[], int n)
{
    int i, j;
    int tmp;
    for(i = 0; i < n; ++i)
    {
        if(key == a[i])
        {
            if(i > 0)
            {
                tmp = a[i];
                for(j = i; j > 0; --j) a[j] = a[j - 1];
                a[0] = tmp;
            }
            return i;
        }
    }
    return -1;
}

int Transpose(int key, int a[], int n)
{
    int i;
    int tmp;
    for(i = 0; i < n; ++i)
    {
        if(key == a[i])
        {
            if(i > 0)
            {
                tmp = a[i];
                a[i] = a[i - 1];
                a[--i] = tmp;
            }
            return i;
        }
    }
    return -1;
}

int BinSearch(int a[], int target, int size)
{
    int mid, l = 0, r = size - 1;
    while(l <= r)
    {
        mid = (r + l)/2;
        if(a[mid] == target)
        {
            return mid;
        }
        else if(target < a[mid])
        {
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return -1;
}

int BinarySearch(ElementType a[], ElementType x, int l, int r)
{
    if(l > r) return -1;
    int mid = (l + r) / 2;
    if(a[mid] < x) return BinarySearch(a, x, mid + 1, r);
    else if(a[mid] > x)
    {
        return BinarySearch(a, x, l, mid - 1);
    }
    else return mid;
    return -1;
}

/*int main()
{
    int n;
    printf("\nEnter n: ");
    fflush(stdin); scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    int i;
    printf("\nEnter arrays elements:\n");
    for(i = 0; i < n; ++i)
    {
        fflush(stdin);
        scanf("%d", &a[i]);
    }
    QuickSort(a, 0, n - 1);
    printf("\nAfter sorted:\n");
    for(i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    int val;
    printf("\nEnter value to find: ");
    fflush(stdin); scanf("%d", &val);
    //int res = BinSearch(a, val, n);
    int res = BinarySearch(a, val, 0, n - 1);
    if(res != -1)
    {
        printf("\nPosition has your value: %d\n", res);
    }    
    else printf("\nNot found!\n");
    int res = Transpose(val, a, n);
    if(res == -1) printf("\nNot found!\n");
    else
    {
        printf("\nValue at: %d\nThe array:\n", res);
        for(i = 0; i < n; ++i)
        {
            printf("%d ", a[i]);
        }
    }
    free(a);
    return 0;
}*/