#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>

void QuickSort(int *a, int l, int r)
{
    int tmp;
    int p = a[(l + r)/2];
    int i = l, j = r;
    while(i < j)
    {
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if(i <= j)
        {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++; j--;
        }
    }
    if(i < r) QuickSort(a, i, r);
    if(j > l) QuickSort(a, l, j);
}

int Sequential(int *a, int n, int find)
{
    int i = 0;
    while(a[i] != find && i < n) i++;
    if(i < n) return i;
    return -1;
}

int Sentinel(int *a, int n, int find)
{
    int i = 0; a[n] = find;
    while(a[i] != find) i++;
    if(i == n) return -1;
    return i;
}

int BinSearch(int *a, int find, int size)
{
    int mid, l = 0, r = size - 1;
    while(l <= r)
    {
        mid = (r + l)/2;
        if(a[mid] == find)
        {
            return mid;
        }
        else if(a[mid] > find)
        {
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return -1;
}

void Menu()
{
    char c;
    clock_t start, end;
    double time_used;
    do
    {
        int n;
        printf("\nEnter arrays size: ");
        fflush(stdin); scanf("%d", &n);
        int *a = (int *)malloc(n * sizeof(int));
        //int ascend;
        int i;
        for(i = 0; i < n; ++i)
        {
            a[i] = 2 * i + 3;
            //if(i < 10) printf("%d ", a[i]);
        }
        printf("\nCreate array success!\n");
        int opt, find, res;
        printf("\nEnter value to find: ");
        fflush(stdin); scanf("%d", &find);
        do
        {
            printf("\n1. Sequential\n2. Sequential with Sentinel\n3. Binary Search\n4. Quit\n");
            printf("\nEnter your option: ");
            fflush(stdin); scanf("%d", &opt);
            switch(opt)
            {
                case 1:
                    start = clock();
                    res = Sequential(a, n, find);
                    if(res >= 0)
                    {
                        printf("\nThe value was found at position number: %d", res);
                    }
                    else printf("\nNot found!\n");
                    end = clock();
                    time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 
                    printf("\nThe execution time: %f\n", time_used);
                    break;
                case 2:
                    start = clock();
                    res = Sentinel(a, n, find);
                    if(res >= 0)
                    {
                        printf("\nThe value was found at position number: %d", res);
                    }
                    else printf("\nNot found!\n");
                    end = clock();
                    time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 
                    printf("\nThe execution time: %f\n", time_used);; 
                    break;
                case 3: 
                    start = clock();
                    //QuickSort(a, 0, n);
                    res = BinSearch(a, find, n);
                    if(res >= 0)
                    {
                        printf("\nThe value was found at position number: %d", res);
                    }
                    else printf("\nNot found!\n");
                    end = clock();
                    time_used = ((double) (end - start)) / CLOCKS_PER_SEC; 
                    printf("\nThe execution time: %f\n", time_used);
                    break;
                case 4:
                    printf("\nThank you!\n");
                    break;
                default:
                    printf("\nInvalid!\n");
                    break;
            }
        } while(opt != 4);

        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
        free(a);
    } while (c == 'y');
}

int main()
{
    Menu();
    return 0;
}