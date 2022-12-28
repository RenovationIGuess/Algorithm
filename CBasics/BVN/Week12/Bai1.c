#include<string.h>
#include<ctype.h>
#include "singlelist.h"

FILE *f, *f1;
int m_num;

void QuickSort(et *a, int l, int r)
{
    et tmp;
    et p = a[(l + r)/2];
    int i = l, j = r;
    while(i < j)
    {
        while(strcmp(a[i].model, p.model) < 0) i++;
        while(strcmp(a[j].model, p.model) > 0) j--;
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

int BSList(char *find, int cnt)
{
    int l = cnt, r = m_num - 1;
    int mid;
    int i, j;
    node *p = search;
    while(l <= r)
    {
        mid = (l + r) / 2;
        //printf("%d\n", mid);
        if(p == search)
        {
            for(i = cnt; i < mid; ++i)
                p = p->next;
        }
        else
        {
            for(i = l; i < mid; ++i)
                p = p->next;
        }
        //displayNode(p);
        j = strcmp(find, p->data.model);
        if(j == 0)
        {
            cur = p;
            update();
            return mid;
        }
        else if(j < 0)
        {
            r = mid - 1;
            p = search;
        }
        else 
        {
            l = mid + 1;
            p = p->next;
        }
    }
    return -1;
}

void DSingle()
{
    //printf("\nProcessing...\n");
    printf("\n%-5s%-20s%-25s%-25s%-20s\n", "", "Model", "Memory Space (GB)", "Screen Size (Inches)", "Price ($)");
    node *p = l;
    int i = 0;
    if(p == NULL)
    {
        printf("\nCon tro NULL!\n");
        return;
    }
    while(p != NULL)
    {
        printf("%-5d%-20s%-25.2f%-25.2f%-20.2f\n", i, p->data.model, p->data.ms, p->data.ss, p->data.price);
        i++;
        p = p->next;
    }
    //printf("\nReturning to main menu...\n");
}

void SingleLL(char *s)
{
    printf("\nProcessing...\n");
    if ((f = fopen(s, "rb")) == NULL) 
    {
        printf("Cannot open %s.", s);
        exit(1);
    }
    et *a = (et *)malloc(MAX * sizeof(et));
    fseek(f, 0, SEEK_END);
    m_num = ftell(f) / sizeof(et);  
    int i = 0, num;
    fseek(f, 0, SEEK_SET);
    num = fread(a, sizeof(et), m_num, f);
    QuickSort(a, 0, m_num - 1);
    l = createNode(a[0]);
    cur = l;
    prev = NULL;
    for(i = 1; i < m_num; ++i)
    {
        InsertAfterCur(a[i]);
    }
    DSingle();
    fclose(f);
}

//Move to front
void Func1(char *s)
{
    char c;
    et tmp;
    char *find = (char *)malloc(MAX * sizeof(char));
    //Func1(s, a);
    SingleLL(s);
    search = l;
    int cnt = 0;
    //displayNode(search);
    do
    {
        printf("\nEnter name you want to find: ");
        fflush(stdin); gets(find);
        if(BSList(find, cnt) >= 0)
        {
            //displayNode(cur);
            tmp = cur->data;
            if(cur == l)
            {
                search = search->next;
                //displayNode(search);
            }
            else if(cur == search)
            {
                search = search->next;
                //displayNode(search);
                deleteMiddle();
                InsertAtHead(tmp);
            }
            else
            {
                //displayNode(search);
                deleteMiddle();
                InsertAtHead(tmp);
            }
            DSingle();
            cnt++;
        }
        else printf("\nNot found!\n");
        if(cnt == m_num) 
        {
            printf("\nAll person has been found!\n");
            break;
        } 
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');
    //printf("\nSuccess!\n");
}

void Func2(char *s)
{
    char c;
    et tmp;
    char *find = (char *)malloc(MAX * sizeof(char));
    //Func1(s, a);
    SingleLL(s);
    search = l;
    //int cnt = 0;
    do
    {
        printf("\nEnter name you want to find: ");
        fflush(stdin); gets(find);
        if(BSList(find, 0) >= 0)
        {
            if(cur != l)
            {
                tmp = cur->data;
                cur->data = prev->data;
                prev->data = tmp;
            }
            DSingle();
            //cnt++;
        }
        else printf("\nNot found!\n");

        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');
}

int BSList2(char *find)
{
    int left = 0, r = m_num - 1;
    int mid;
    int i, j;
    node *p = l;
    while(left <= r)
    {
        mid = (left + r) / 2;
        //printf("%d\n", mid);
        if(p == l)
        {
        for(i = 0; i < mid; ++i)
            p = p->next;
        }
        else
        {
            for(i = left; i < mid; ++i)
                p = p->next;
        }
        displayNode(p);
        j = strcmp(find, p->data.model);
        if(j == 0)
        {
            cur = p;
            update();
            return mid;
        }
        else if(j < 0)
        {
            r = mid - 1;
            p = l;
        }
        else 
        {
            left = mid + 1;
            p = p->next;
        }
    }
    return -1;
}

int SeqSearch(char *find)
{
    node *p = l;
    while(p != NULL)
    {
        if(strcmp(find, p->data.model) == 0)
        {
            cur = p;
            update();
            return 1;
        }
        p = p->next;
    }
    return 0;
}

void Func3(char *s)
{
    char c;
    et tmp;
    char *find = (char *)malloc(MAX * sizeof(char));
    //Func1(s, a);
    SingleLL(s);
    search = l;
    //int cnt = 0;
    node *p = l;
    //int i;
    while(p != NULL)
    {
        p->count = 0;
        p = p->next;
    }
    do
    {
        printf("\nEnter name you want to find: ");
        fflush(stdin); gets(find);
        if(SeqSearch(find))
        {
            cur->count++;
            //displayNode(cur);
            if(cur != l)
            {
                while(prev != l && cur->count > prev->count)
                {
                    p = l;
                    while(p->next != prev)
                    {
                        p = p->next;
                    }
                    //displayNode(p);
                    prev->next = cur->next;
                    cur->next = prev;
                    p->next = cur;
                    prev = p;
                    //displayNode(prev);
                }
                if(prev == l && cur->count > prev->count)
                {
                    prev->next = cur->next;
                    cur->next = prev;
                    l = cur;
                }
            }
            printf("\n%-5s%-20s%-25s%-25s%-20s%-10s\n", "", "Model", "Memory Space (GB)", "Screen Size (Inches)", "Price ($)", "Count");
            p = l;
            int i = 0;
            if(p == NULL)
            {
                printf("\nCon tro NULL!\n");
                return;
            }
            while(p != NULL)
            {
                printf("%-5d%-20s%-25.2f%-25.2f%-20.2f%-10d\n", i, p->data.model, p->data.ms, p->data.ss, p->data.price, p->count);
                i++;
                p = p->next;
            }
            //cnt++;
        }
        else printf("\nNot found!\n");

        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');
}

void Menu(char *s)
{
    int opt;
    do
    {
        printf("\n1. Move to front\n2. Tranpose\n3. Counter\n4. Quit\n");
        printf("\nEnter your option: ");
        fflush(stdin); scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                Func1(s);
                break;
            case 2:
                Func2(s);
                break;
            case 3: 
                Func3(s);
                break;
            case 4:
                printf("\nThank you!\n");
                break;
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while(opt != 4);
}

int main(int argc, char *argv[])
{
    Menu(argv[1]);
    return 0;
}