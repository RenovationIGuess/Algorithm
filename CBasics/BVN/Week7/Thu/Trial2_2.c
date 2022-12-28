#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 256

typedef struct
{
    char model[31];
    // ms - memory space
    float ms;
    // ss - screen size 
    float ss;
    //char price[31];
    float price;
} p; //p - phone

struct Node
{
    p phone;
    struct Node *next;
};

typedef struct Node node;

int m_num; // số mẫu đth
//l - tree/ list, cur - con trỏ hiện tại, prev - con trỏ trước cur
node *cur, *prev;

node *createNode(p x)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->next = NULL;
    tmp->phone = x;
    return tmp;
}

node *addEle(node *l, p x)
{
    node *tmp = createNode(x);
    l->next = tmp;
    return tmp;
}

void displayNode(node *x)
{
    if(x == NULL)
    {
        printf("\nCon tro loi - NULL!\n");
        return;
    }
    p tmp = x->phone;
    //printf("\n%-15s%-20s%-20s%-15s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
    printf("%-20s%-25.2f%-25.2f%-20.2f\n", tmp.model, tmp.ms, tmp.ss, tmp.price);
}

void reverseList(node *l)
{
    node *p = l;
    node *tsugi, *pre;
    tsugi = prev = NULL;
    while(p != NULL)
    {
        tsugi = p->next;
        p->next = pre;
        pre = p;
        p = tsugi;
    }
    l = pre;
    cur = l;
    prev = NULL;
}

node *InsertAtHead(node *l, p x)
{
    //node *tmp = createNode(x);
    node *tmp = (node *)malloc(sizeof(node));
    tmp->phone = x;
    tmp->next = l;
    l = tmp;
    cur = l;
    //prev = NULL;
    return l;
}

node *InsertAfterCur(node *l, p x)
{
    node *tmp = createNode(x);
    if(cur == NULL) return NULL;
    if(l == NULL)
    {
        l = tmp;
        cur = l;
        prev = NULL;
    }
    else
    {
        tmp->next = cur->next;
        cur->next = tmp;
        prev = cur;
        cur = cur->next;
    }
    return l;
}

node *InsertBeforeCur(node *l, p x)
{
    node *tmp = createNode(x);
    if(l == NULL)
    {
        l = tmp;
        cur = l;
        prev = NULL;
    }
    else
    {
        tmp->next = cur;
        prev->next = tmp;
        prev = tmp;
    }
    return l;
}

//cập nhật con trỏ prev nếu cur != l
void update(node *l)
{
    node *tmp = l;
    while(tmp != NULL && cur != NULL && tmp->next != cur)
    {
        tmp = tmp->next;
    }
    prev = tmp;
}

//Hàm lấy thông tin cho phone nhập từ người dùng
void ReadNode(p *a)
{
    printf("\nEnter Model: ");
    fflush(stdin); gets(a->model);
    printf("\nEnter memory space: "); 
    fflush(stdin); scanf("%f", &a->ms);
    printf("\nEnter screen size: ");
    fflush(stdin); scanf("%f", &a->ss);
    printf("\nEnter price: ");
    fflush(stdin); scanf("%f", &a->price);
}

//Xóa hết list
void FreeList(node *l)
{
    node *p = l;
    while(p != NULL)
    {
        l = l->next;
        free(p);
        p = l;
    }
}

//void create()

//Import from text - InsertAtHead
void Func1(node *l, p *a, FILE *fin)
{
    printf("\nProcessing...\n");
    fseek(fin, 0, SEEK_SET);

    int i = 0, j;
    //printf("\nWhat have read:\n\n");
    while(fscanf(fin, "%s%f%f%f", a[i].model, &a[i].ms, &a[i].ss, &a[i].price) != EOF)
    {
        //printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
        //l = InsertAtHead(l, a[i]);
        i++;
    }

    // Số Model đọc được
    m_num = i;
    printf("\nSo Model hien co: %d.\n", m_num);
    //Sử dụng InsertAtHead
    node *new = createNode(a[0]);
    node *p = new;
    for(i = 1; i < m_num; ++i)
    {
        p = addEle(p, a[i]);
        printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
    } 
    l = new;
    //reverseList(l); 
    //l = createNode(a[0]);
    //displayNode(l);
    printf("\nSuccess!\n");
}

//Import from dat - Insert after cur position
void Func2(node *l, p *a, FILE *fin)
{
    printf("\nProcessing...\n");
    fseek(fin, 0, SEEK_SET);

    int i = 0, num;
    
    num = fread(a, sizeof(p), m_num, fin);
    printf("\nRead Value: %d.\n", num);

    l = createNode(a[0]);
    node *p = l;
    for(i = 1; i < num; ++i)
    {
        p = InsertAfterCur(p, a[i]);
    }
    printf("\nSuccess!\n");
}

//Display List
void Func3(node *l)
{
    printf("\nProcessing...\n");
    printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
    node *p = l;
    while(p != NULL)
    {
        displayNode(p);
        p = p->next;
    }
    printf("\nSuccess!\n");
}

// Tìm kiếm theo Model
void Func4(node *l)
{
    printf("\nProcessing...\n");

    int i;
    char c;
    //char *mod = (char *)malloc(sizeof(char));
    char mod[MAX];
    do
    {
        // xem model can tim co ko
        int found = 0;
        
        printf("\nEnter Phone Model you want to search: ");
        fflush(stdin);
        scanf("%s", mod); 
        //gets(mod);
        printf("\nModel you have type: '%s'.\n", mod); 

        node *p = l;
        while(p != NULL)
        {
            if(strcasecmp(mod, p->phone.model) == 0)
            {
                found = 1; 
                printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
                displayNode(p);
                break;
            }
            else p = p->next;
        }

        if(found == 0) printf("\nNon - existed!\n");

        printf("\nDo you want to continue searching [y/n]: ");
        fflush(stdin);
        scanf("%c", &c);
    } while(c == 'y');

    printf("\nSuccess!\n");
}

// Tìm những điện thoại có giá nhỏ hơn value đã nhập
void Func5(node *l)
{
    printf("\nProcessing...\n");

    int value;
    printf("\nEnter value: ");
    fflush(stdin); scanf("%d", &value);
    node *p = l;
    //Kiểm tra xem có mẫu nào nhỏ hơn không?
    int check = 0;
    while(p != NULL)
    {
        if(p->phone.price <= value)
        {
            check++;
            if(check == 1)
                {printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");}
            displayNode(p);
        }
        else p = p->next;
    }
    if(check == 0) printf("\nKhong co mau nao co price <= value!\n");

    printf("\nSuccess!\n");
}

//Export to dat, f ở đây là PhoneDB.dat
void Func6(node *l, p *a, FILE *f)
{
    printf("\nProcessing...\n");
    fseek(f, 0, SEEK_SET);
    node *p = l;
    int num;
    //biến kiểu p để lưu cho vào file.dat
    int i = 0;
    while(p != NULL)
    {
        a[i] = p->phone;
        i++;
        p = p->next;
    }
    num = fwrite(a, sizeof(p), i, f);
    printf("\nSuccess!\n");
}

//Insert after 
void Func7_1(node *l)
{
    printf("\nProcessing...\n");
    p add;
    printf("\nHay nhap thong tin muon them:\n");
    ReadNode(&add);
    InsertAfterCur(l, add);
    m_num++;
    printf("\nSuccess!\n");
}

//Insert before
void Func7_2(node *l)
{
    printf("\nProcessing...\n");
    p add;
    printf("\nHay nhap thong tin muon them:\n");
    ReadNode(&add);
    //Nếu hiện tại cur khác l thì cập nhật con trỏ prev
    if(cur != l)
    {
        update(l);
    }
    InsertBeforeCur(l, add);
    m_num++;
    printf("\nSuccess!\n");
}

// Manual Insertion
void Func7(node *l)
{
    printf("\nProcessing...\n");
    //option - lựa chọn
    int opt;
    do
    {
        printf("\n1. Insert After Current Position\n2. Insert Before Current Position\n3. Exit\n");
        printf("\nEnter option: "); fflush(stdin); scanf("%d", &opt);
        switch(opt)
        {
            case 1: 
                Func7_1(l);
                break;
            case 2: 
                Func7_2(l);
                break;
            case 3: 
                printf("\nBack to main Menu...\n");
                break;
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while (opt != 3);
    
    printf("\nSuccess!\n");
}

//a - mảng lưu data, fin - file.text, fout - file.dat
void Menu(node *l, p *a, FILE *fin, FILE *fout)
{
    printf("\nMenu:\n");
    //đếm việc nhập chức năng 1 và 2
    int cnt = 0;
    do
    {
        // option
        int opt;
        printf("\n1. Import DB from text\n2. Import DB from dat\n3. Display List\n4. Search by phone by Phone Model\n5. Search phone has price under value inputted\n6. Export to dat\n7. Manual Insertion\n8. Quit\n");
        printf("\nEnter option: ");
        fflush(stdin);
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                //Import from text
                if(cnt != 0)
                {
                    FreeList(l);
                }
                Func1(l, a, fin);
                cnt++;
                break;
            case 2:
                //Import from dat
                if(cnt != 0)
                {
                    FreeList(l);
                }
                Func2(l, a, fout);
                cnt++;
                break;
            case 3:
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                //Display List
                Func3(l);
                break;
            case 4:
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                //Search phone by model
                Func4(l);
                break;
            case 5:
                //Search phone which the price is under
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                Func5(l);
                break;
            case 6: 
                //Export to dat
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                Func6(l, a, fout);
                break;
            case 7: 
                //Manual Insertion
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                Func7(l);
                break;
            case 8: 
                //Quit
                printf("\nThank you!\n");
                return;
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while(1);
}

int main(int argc, char *argv[])
{
    FILE *f1, *f2;
    // if((f1 = fopen("PhoneDB.txt", "r")) == NULL)
    if((f1 = fopen(argv[1], "r")) == NULL)
    {
        printf("\nCannot open %s!\n", argv[1]);
        return 1;
    }
    // else if((f2 = fopen("PhoneDB.dat", "w+b")) == NULL)
    else if((f2 = fopen(argv[2], "rb")) == NULL)
    {
        printf("\nCannot open %s!\n", argv[2]);
        return 1;
    }
    else
    {
        // cap phat dong
        p *a = (p *)malloc(sizeof(p));
        //node *l = (node *)malloc(sizeof(node));
        node *l = NULL;
        printf("\nOpening...\n");
        Menu(l, a, f1, f2);
        printf("\nComplete running!\n\n");
        free(a);
        free(l);
        fclose(f1);
        fclose(f2);
        return 0;
    }
}