#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Cac thuat toan sap xep

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//tra ve vi tri cua phan tu min trong khoang tu posi -> n - 1
int FindMin(int a[], int posi, int n)
{
    int i, indexMin = posi;
    for(i = posi + 1; i < n; ++i)
    {
        if(a[indexMin] > a[i]) 
        {
            indexMin = i;
        }
    }
    return indexMin;
}

//Output ra mang
void printArray(int a[], int n)
{
    int i;
    for(i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//1. BubbleSort
void BubbleSort(int a[], int n)
{
    int i, j, check;
    for(i = n - 1; i >= 1; --i)
    {
        check = 1;
        for(j = 0; j < i; ++j)
        {
            if(a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                check = 0;
            }
        }
        printArray(a, n);
        if(check == 1) break;
    }
}

//2. InsertionSort
void InsertionSort(int a[], int n)
{
    int index, value;
    int i;
    for(i = 1; i < n; ++i)
    {
        index = i;
        value = a[i];
        while(index > 0 && a[index - 1] > value)
        {
            a[index] = a[index - 1];
            index--;
        }
        a[index] = value;
        printArray(a, n);
    }
}

//3. Selection Sort
void SelectionSort(int a[], int n)
{
    int indexMin;
    int i;
    for(i = 0; i < n; ++i)
    {
        indexMin = FindMin(a, i, n);
        if(i != indexMin)
        {
            swap(&a[i], &a[indexMin]);
            printArray(a, n);
        }
    }
}

//4. Merge Sort
//Ham gop lai
void Merge(int a[], int l, int m, int r)
{
    //l - left, m - mid, r - right
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(i = 0; i < n1; ++i)
    {
        L[i] = a[l + i];
    }
    for(j = 0; j < n2; ++j)
    {
        R[j] = a[m + j + 1];
    }
    i = j = 0;
    k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

//Merge Sort
void MergeSort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l)/2;
        //m = (l + r)/2;
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);
        Merge(a, l, m, r);
    }
}

//5. Shell Sort
void ShellSort(int a[], int n)
{
    int interval, i, j, tmp;
    for(interval = n/2; interval > 0; interval /= 2)
    {
        for(i = interval; i < n; ++i)
        {
            tmp = a[i];
            for(j = i; j >= interval && a[j - interval] > tmp; j -= interval)
            {
                a[j] = a[j - interval];
            }
            a[j] = tmp;
        }
    }
}

//6. Quick Sort
void QuickSort(int a[], int l, int r)
{
    int p = a[(l + r)/2];
    int i = l, j = r;
    while(i < j)
    {
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if(i <= j)
        {
            swap(&a[i], &a[j]);
            i++; j--;
        }
    }
    if(i < r) QuickSort(a, i, r);
    if(j > l) QuickSort(a, l, j);
}

//7. Heap Sort
  void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  // Main function to do heap sort
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        printArray(arr, n);
        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
  }

