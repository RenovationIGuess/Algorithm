#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 256

FILE *f;
int m_num;

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

typedef struct element_type ElmType;

void swap(ElmType *a, ElmType *b)
{
    ElmType tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(ElmType arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && strcmp(arr[left].model, arr[largest].model) > 0)
        largest = left;
  
    if (right < n && strcmp(arr[right].model, arr[largest].model) > 0)
        largest = right;
  
    if (largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
  
void heapSort(ElmType arr[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void Solve(char *s)
{
    printf("\nProcessing...\n");
    if ((f = fopen(s, "rb")) == NULL) 
    {
        printf("Cannot open %s.", s);
        exit(1);
    }
    ElmType *a = (ElmType *)malloc(MAX * sizeof(ElmType));
    fseek(f, 0, SEEK_END);

    printf("\nSo mau dien thoai: %d.\n", ftell(f) / sizeof(ElmType));
    m_num = ftell(f) / sizeof(ElmType);  
    int i = 0, num;
    fseek(f, 0, SEEK_SET);
    num = fread(a, sizeof(ElmType), m_num, f);
    printf("\nBefore Sorted:\n");
    printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space (GB)", "Screen Size (Inches)", "Price ($)");
    for(i = 0; i < m_num; ++i)
    {
        printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
    }
    heapSort(a, m_num);
    printf("\nAfter Sorted:\n");
    printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space (GB)", "Screen Size (Inches)", "Price ($)");
    for(i = 0; i < m_num; ++i)
    {
        printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
    }
    fclose(f);
}

int main(int argc, char *argv[])
{
    Solve(argv[1]);
    return 0;
}