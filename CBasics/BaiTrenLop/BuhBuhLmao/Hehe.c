//#include<stdio.h>
#include<string.h>
#include<ctype.h>
//#include<stdlib.h>
#include "singlel.h"
//#include "search.h"
//#include "doublel.h"
//#include "stacklist.h"
//#include "Sort.h"
//#include "QueueList.h"

FILE *f, *f1;
int m_num;

void QuickSort(et *a, int l, int r)
{
    et tmp;
    et p = a[(l + r)/2];
    int i = l, j = r;
    while(i < j)
    {
        while(strcmp(a[i].name, p.name) < 0) i++;
        while(strcmp(a[j].name, p.name) > 0) j--;
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

int SelfOrg(char *s, et *a, int n)
{
    int i, j;
    et tmp;
    for(i = 0; i < n; ++i)
    {
        if(strcmp(s, a[i].name) == 0)
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

int SelfOrganize(char *s)
{
    node *tmp = search;
    while(tmp != NULL)
    {
        if(strcmp(tmp->data.name, s) == 0)
        {
            cur = tmp;
            update();
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int BinSearch(et *a, char *s, int size)
{
    int mid, l = 0, r = size - 1;
    while(l <= r)
    {
        mid = (r + l)/2;
        //printf("%d\n", mid);
        if(strcmp(a[mid].name, s) == 0)
        {
            return mid;
        }
        else if(strcmp(a[mid].name, s) > 0)
        {
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return -1;
}

int BinarySearch(et *a, char *s, int l, int r)
{
    if(l > r) return -1;
    int mid = (l + r) / 2;
    if(strcmp(a[mid].name, s) < 0) return BinarySearch(a, s, mid + 1, r);
    else if(strcmp(a[mid].name, s) > 0)
    {
        return BinarySearch(a, s, l, mid - 1);
    }
    else return mid;
    return -1;
}

// Queue
struct Node_t
{
    et Element;
    struct Node_t *next;
};
typedef struct Node_t node_t;
typedef node_t* Position;
typedef struct 
{
    Position front, rear;
} queue;

void MakeNull(queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

int IsEmpty(queue *q)
{
    return q->front == NULL;
}

void EnQueue(et x, queue *q)
{
    node_t *tmp = (node_t *)malloc(sizeof(node_t));
    if(q->front == NULL)
    {
        q->front = tmp;
        q->rear = tmp;
    }
    else
    {
        q->rear->next = tmp;
        q->rear = q->rear->next;
    }
    q->rear->Element = x;
}

et Dequeue(queue *q)
{
    if(IsEmpty(q))
    {
        printf("\nQueue is empty!\n");
    }
    else
    {
        node_t *tmp = q->front;
        et e = tmp->Element;
        if(q->front == q->rear)
        {
            free(tmp);
            free(q->rear);
            MakeNull(q);
            return e;
        }
        else
        {
            q->front = q->front->next;
            free(tmp);
            return e;
        }
    }
}

int BSQueue(char *search, queue *q)
{
	int first = 0;
	int last = 9;
	int mid;
	int i, k;
	int result = -1;
	while (last >= first && result == -1)
	{
		mid = (first + last) / 2;
		for (i = 0; i < mid; ++i)
			EnQueue(Dequeue(q), q);
		k = strcmp(search, q->front->Element.name); 
		if (k == 0)
		{
			result = mid;
		}
		else if (k < 0)
			last = mid - 1;
		else first = mid + 1;
		for(i = mid; i < 10; ++i)
		    EnQueue(Dequeue(q), q);
	}
	return result;
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
        j = strcmp(find, p->data.name);
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

void DArray(et *a)
{
    int i;
    printf("\n%-5s%-25s%-25s%-25s\n", "", "Name", "Telephone", "E-mail Address");
    for(i = 0; i < m_num; ++i)
    {
        printf("%-5d%-25s%-25s%-25s\n", i, a[i].name, a[i].telephone, a[i].email);
    }
}

void Func1(char *s, char *s1, et *a)
{
    printf("\nProcessing...\n");
    if ((f = fopen(s, "rb")) == NULL) 
    {
        printf("Cannot open %s.", s);
        exit(1);
    }
    else if ((f1 = fopen(s1, "wb")) == NULL)
    {
        printf("Cannot open %s.", s1);
        exit(1);
    }
    fseek(f, 0, SEEK_END);
    m_num = ftell(f) / sizeof(et);  
    int i = 0, num;
    fseek(f, 0, SEEK_SET);
    num = fread(a, sizeof(et), m_num, f);
    //printf("\nNumber of phone models: %d.\n", m_num);
    QuickSort(a, 0, m_num - 1);
    DArray(a);

    char c;
    et *tmp = (et *)malloc(1 * sizeof(et));
    char *find = (char *)malloc(MAX * sizeof(char));
    do
    {
        printf("\nEnter name you want to find: ");
        fflush(stdin); gets(find);
        i = BinSearch(a, find, m_num);
        //i = BinarySearch(a, find, 0, m_num - 1);
        //printf("\n%d\n", i);
        if(i != -1)
        {
            printf("\nInfomation:\n");
            printf("\n%-5s%-25s%-25s%-25s\n", "", "Name", "Telephone", "E-mail Address");
            printf("%-5d%-25s%-25s%-25s\n", i, a[i].name, a[i].telephone, a[i].email);
            tmp[0] = a[i];
            num = fwrite(tmp, sizeof(et), 1, f1);
            printf("\nWritten value: %d\n", num); 
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
    
    fclose(f);
    fclose(f1);
    printf("\nSuccess!\n");
}

void DSingle()
{
    //printf("\nProcessing...\n");
    printf("\n%-5s%-25s%-25s%-25s\n", "", "Name", "Telephone", "E-mail Address");
    node *p = l;
    int i = 0;
    if(p == NULL)
    {
        printf("\nCon tro NULL!\n");
        return;
    }
    while(p != NULL)
    {
        printf("%-5d%-25s%-25s%-25s\n", i, p->data.name, p->data.telephone, p->data.email);
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

/*void DDouble(doublelist *root)
{
    printf("\nProcessing...\n");
    printf("\n%-5s%-20s%-25s%-25s%-20s\n", "", "Model", "Memory Space(GB)", "Screen Size(inches)", "Price($)");
    node *p = *root;
    if(p == NULL)
    {
        printf("\nDanh sach rong!\n");
        return;
    }
    int i = 0;
    while(p != NULL)
    {
        printf("%-5d%-20s%-25.2f%-25.2f%-20.2f\n", i, p->data.model, p->data.ms, p->data.ss, p->data.price);
        i++;
        p = p->next;
    }
    printf("\nReturning to main menu...\n");
}

void DoubleLL(char *s, doublelist *root, doublelist *cur, doublelist *tail)
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
    printf("\nNumber of phone models: %d.\n", m_num);
    for(i = 0; i < m_num; ++i)
    {
        InsertAfterCurrent(a[i], root, tail, cur);
    }
    DDouble(root);
    fclose(f);
    printf("\nSuccess!\n");
} */

void Func2(char *s, et *a)
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

void Func3(char *s, queue *q)
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

    for(i = 0; i < m_num; ++i)
    {
        EnQueue(a[i], q);
    }
    /*i = 0;
    printf("\n%-5s%-25s%-25s%-25s\n", "", "Name", "Telephone", "E-mail Address");
    while(!IsEmpty(q))
    {
        et tmp = Dequeue(q);
        printf("%-5d%-25s%-25s%-25s\n", i, tmp.name, tmp.telephone, tmp.email);
        i++;
    } */

    char c;
    char *find = (char *)malloc(MAX * sizeof(char));
    do
    {
        printf("\nEnter name you want to find: ");
        fflush(stdin); gets(find);
        //i = BinSearch(a, find, m_num);
        //i = BinarySearch(a, find, 0, m_num - 1);
        i = BSQueue(find, q);
        //printf("\n%d\n", i);
        if(i != -1)
        {
            printf("\nInfomation:\n");
            printf("\n%-5s%-25s%-25s%-25s\n", "", "Name", "Telephone", "E-mail Address");
            printf("%-5d%-25s%-25s%-25s\n", i, a[i].name, a[i].telephone, a[i].email);
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
    
    fclose(f);
    printf("\nSuccess!\n");
}

void Func4(char *s1)
{
    et tmp;
    char c;
    queue q;
    MakeNull(&q);
    int cnt = 0, i = 0;
    et *save = (et *)malloc(sizeof(et));
    do
    {
        printf("\nPerson number %d:\n", cnt + 1);
        ReadNode(&tmp);
        if(cnt < 10)
        {
            EnQueue(tmp, &q);
            cnt++;
        }
        else
        {
            save[i] = Dequeue(&q);
            EnQueue(tmp, &q);
            i++;
            cnt++;
        }
        
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');

    int j;
    if(cnt == 10) printf("\nQueue has 10 elements\n");
    else if(cnt > 10)
    {
        printf("\n%-5s%-25s%-25s%-25s\n", "", "Name", "Telephone", "E-mail Address");
        for(j = 0; j < i; ++j)
        {
            printf("%-5d%-25s%-25s%-25s\n", j, save[j].name, save[j].telephone, save[j].email);
        }
        if ((f = fopen(s1, "wb")) == NULL) 
        {
            printf("Cannot open %s.", s1);
            exit(1);
        }
        int num = fwrite(save, sizeof(et), i, f);
        printf("\nWritten value: %d\n", num);
    }
    else
    {
        j = 0;
        printf("\nIn queue:\n");
        printf("\n%-5s%-25s%-25s%-25s\n", "", "Name", "Telephone", "E-mail Address");
        while(!IsEmpty(&q))
        {
            tmp = Dequeue(&q);
            printf("%-5d%-25s%-25s%-25s\n", j, tmp.name, tmp.telephone, tmp.email);
            j++;
        } 
    }
}

//, doublelist *root, doublelist *cur, doublelist *tail
void Menu(et *a, char *s, char *s1, queue *q)
{
    int opt;
    do
    {
        printf("\n1. Implement using array\n2. Implement using list\n3. Implement using queue\n4. Queue solving\n5. Quit");
        printf("\nEnter your option: ");
        fflush(stdin); scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                Func1(s, s1, a);
                break;
            case 2:
                Func2(s, a);
                break;
            case 3: 
                MakeNull(q);
                Func3(s, q);
                break;
            case 4:
                Func4(s1);
                break;
            case 5:
                printf("\nThank you!\n");
                break;
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while(opt != 5);
}

int main(int argc, char *argv[])
{
    //doublelist root = NULL, cur = NULL, tail = NULL;
    // array of structure - double ll
    if(argc != 3)
    {
        printf("\nMissing file's name!\n");
        return 1;
    }
    et *a = (et *)malloc(MAX * sizeof(et));
    queue q;
    MakeNull(&q);
    //, &root, &cur, &tail
    Menu(a, argv[1], argv[2], &q);
    //FreeList(&root);
    FreeList();
    free(a);
    return 0;
}