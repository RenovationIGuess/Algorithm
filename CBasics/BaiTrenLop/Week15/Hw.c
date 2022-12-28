/*#include<stdio.h>
#include<stdlib.h>
#include<math.h> */
#include "Sort.h"
#include<time.h>
#define SIZE 2000000

int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

void Func1(int *a)
{
    
    int i;
    for(i = 0; i < SIZE; ++i)
    {
        a[i] = random(1, SIZE);
        //if(i < 100) printf("%d ", a[i]);
    }
    printf("\nCreate success!\n");
    
}

void Func2(int *a)
{
    int *b = (int *)malloc(SIZE * sizeof(int));
    int i;
    for(i = 0; i < SIZE; ++i)
    {
        b[i] = a[i];
    }
    InsertionSort(b, SIZE);
    free(b);
}

void Func3(int *a)
{
    int *b = (int *)malloc(SIZE * sizeof(int));
    int i;
    for(i = 0; i < SIZE; ++i)
    {
        b[i] = a[i];
    }
    SelectionSort(b, SIZE);
    free(b);
}

void Func4(int *a)
{
    int *b = (int *)malloc(SIZE * sizeof(int));
    int i;
    for(i = 0; i < SIZE; ++i)
    {
        b[i] = a[i];
    }
    BubbleSort(b, SIZE);
    free(b);
}

void Func5(int *a)
{
    int *b = (int *)malloc(SIZE * sizeof(int));
    int i;
    for(i = 0; i < SIZE; ++i)
    {
        b[i] = a[i];
    }
    heapSort(b, SIZE);
    free(b);
}

void Menu(int *a)
{
    int opt, cnt = 0;
    double time_spent;
    clock_t begin;
    clock_t end;
    do
    {
        printf("\n1. Create dataset\n2. Insertion Sort\n3. Selection Sort\n4. Bubble Sort\n5. Heap Sort\n6. Quit");
        printf("\nEnter your selection: ");
        fflush(stdin); scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                if(cnt == 0) cnt = 1;
                Func1(a);
                break;
            case 2:
                if(cnt == 0) 
                {
                    printf("\nCreate array first!\n");
                    break;
                }
                time_spent = 0.0;
                begin = clock();
                Func2(a);
                end = clock();
                time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
                printf("\nThe execution time is %.30f seconds\n", time_spent);
                break;
            case 3:
                if(cnt == 0) 
                {
                    printf("\nCreate array first!\n");
                    break;
                }
                time_spent = 0.0;
                begin = clock();
                Func3(a);
                end = clock();
                time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
                printf("\nThe execution time is %.30f seconds\n", time_spent);
                break;
            case 4:
                if(cnt == 0) 
                {
                    printf("\nCreate array first!\n");
                    break;
                }
                time_spent = 0.0;
                begin = clock();
                Func4(a);
                end = clock();
                time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
                printf("\nThe execution time is %.30f seconds\n", time_spent);
                break;
            case 5:
                if(cnt == 0) 
                {
                    printf("\nCreate array first!\n");
                    break;
                }
                time_spent = 0.0;
                begin = clock();
                Func5(a);
                end = clock();
                time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
                printf("\nThe execution time is %.30f seconds\n", time_spent);
                break;
            case 6:
                printf("\nThank you!\n");
                break;
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while (opt != 6);
    
}

int main()
{
    srand((int)time(0));
    int *a = (int *)malloc(SIZE * sizeof(int));
    Menu(a);
    free(a);
    return 0;
}