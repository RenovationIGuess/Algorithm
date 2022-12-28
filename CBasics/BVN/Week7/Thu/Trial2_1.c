#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 121

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
//l - tree/ list/ root, cur - con trỏ hiện tại, prev - con trỏ trước cur
node *l, *cur, *prev;

node *createNode(p x)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->next = NULL;
    tmp->phone = x;
    return tmp;
}

/*void addEle(p x)
{
    node *tmp = createNode(x);
    l->next = tmp;
    return tmp;
} */

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

void reverseList()
{
    node *p = l;
    node *tsugi, *pre;
    tsugi = pre = NULL;
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

void InsertAtHead(p x)
{
    //node *tmp = createNode(x);
    node *tmp = (node *)malloc(sizeof(node));
    tmp->phone = x;
    tmp->next = l;
    l = tmp;
    cur = l;
    //prev = NULL;
}

void InsertAfterCur(p x)
{
    node *tmp = createNode(x);
    if(cur == NULL) return;
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
}

void InsertBeforeCur(p x)
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
}

//cập nhật con trỏ prev nếu cur != l
void update()
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
void FreeList()
{
    node *p = l;
    while(p != NULL)
    {
        l = l->next;
        free(p);
        p = l;
    }
}

//file.text
void Func1(p *a, FILE *f)
{
    printf("\nProcessing...\n");
    fseek(f, 0, SEEK_SET);

    int i = 0;
    //printf("\nWhat have read:\n\n");
    while(fscanf(f, "%s%f%f%f", a[i].model, &a[i].ms, &a[i].ss, &a[i].price) != EOF)
    {
    //printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
    InsertAtHead(a[i]);
    i++;
    }
    reverseList();
    // Số Model đọc được
    m_num = i;
    printf("\nSo Model hien co: %d.\n", m_num);
    printf("\nSuccess!\n");
}

// file.dat
void Func2(p *a, FILE *f)
{
    printf("\nProcessing...\n");
    fseek(f, 0, SEEK_END);
    int cnt = ftell(f) / sizeof(p);
    printf("\nSo mau dien thoai: %d.\n", cnt);
    m_num = cnt;
    rewind(f);

    int i = 0, num;
    
    num = fread(a, sizeof(p), m_num, f);
    printf("\nRead Value: %d.\n", num);

    l = createNode(a[0]);
    //node *p = l;
    for(i = 1; i < num; ++i)
    {
        printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
        InsertAfterCur(a[i]);
    }
    printf("\nSuccess!\n");
}

//Display List
void Func3()
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
void Func4()
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
void Func5()
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
        p = p->next;
    }
    if(check == 0) printf("\nKhong co mau nao co price <= value!\n");

    printf("\nSuccess!\n");
}

//Export to dat, f ở đây là PhoneDB.dat
void Func6(p *a, FILE *f)
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
void Func7_1()
{
    printf("\nProcessing...\n");
    p add;
    printf("\nHay nhap thong tin muon them:\n");
    ReadNode(&add);
    InsertAfterCur(add);
    m_num++;
    printf("\nSuccess!\n");
}

//Insert before
void Func7_2()
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
    InsertBeforeCur(add);
    m_num++;
    printf("\nSuccess!\n");
}

// Manual Insertion
void Func7()
{
    printf("\nProcessing...\n");
    //option - lựa chọn
    int opt;
    do
    {
        printf("\n1. Insert After Current Position\n2. Insert Before Current Position\n3. Exit\n");
        printf("\nCurrent pointer is now at:\n");
        printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
        displayNode(cur);
        printf("\nPrevious pointer is now at:\n");
        printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
        displayNode(prev);
        printf("\nEnter option: "); fflush(stdin); scanf("%d", &opt);
        switch(opt)
        {
            case 1: 
                Func7_1();
                break;
            case 2: 
                Func7_2();
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

void Menu(p *a, FILE *fin, FILE *fout)
{
    printf("\nMenu:\n");
    //đếm việc nhập chức năng 1 và 2
    int cnt = 0;
    int i;
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
                    FreeList();
                    //Func3();
                }
                //Func1(a, fin);
                printf("\nProcessing...\n");
                fseek(fin, 0, SEEK_SET);

                i = 0;
                //printf("\nWhat have read:\n\n");
                while(fscanf(fin, "%s%f%f%f", a[i].model, &a[i].ms, &a[i].ss, &a[i].price) != EOF)
                {
                    //printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
                    InsertAtHead(a[i]);
                    i++;
                }
                reverseList();
                // Số Model đọc được
                m_num = i;
                printf("\nSo Model hien co: %d.\n", m_num);
                printf("\nSuccess!\n");
                cnt++;
                break;
            case 2:
                //Import from dat
                if(cnt != 0)
                {
                    FreeList();
                    //Func3();
                }
                //Func2(a, fout);
                printf("\nProcessing...\n");
                fseek(fout, 0, SEEK_END);
                int cnt = ftell(fout) / sizeof(p);
                printf("\nSo mau dien thoai: %d.\n", cnt);
                m_num = cnt;
                rewind(fout);

                i = 0;
                int num;
                num = fread(a, sizeof(p), m_num, fout);
                printf("\nRead Value: %d.\n", num);

                l = createNode(a[0]);
                //node *p = l;
                for(i = 1; i < num; ++i)
                {
                    printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
                    InsertAfterCur(a[i]);
                }
                printf("\nSuccess!\n");
                cnt++;
                break;
            case 3:
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                //Display List
                Func3();
                break;
            case 4:
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                //Search phone by model
                Func4();
                break;
            case 5:
                //Search phone which the price is under
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                Func5();
                break;
            case 6: 
                //Export to dat
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                Func6(a, fout);
                break;
            case 7: 
                //Manual Insertion
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                Func7();
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
    else if((f2 = fopen(argv[2], "rb+")) == NULL)
    {
        printf("\nCannot open %s!\n", argv[2]);
        return 1;
    }
    else
    {
        // cap phat dong
        p *a = (p *)malloc(sizeof(p));
        //node *l = (node *)malloc(sizeof(node));
        //node *l = NULL;
        printf("\nOpening...\n");
        prev = cur = NULL;
        //Menu(a, f1, f2);
        free(a);
        //free(l);
        fclose(f1);
        fclose(f2);
        return 0;
    }
}

/*printf("\nMenu:\n");
        //đếm việc nhập chức năng 1 và 2
        int cnt = 0;
        int i;
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
                    FreeList();
                    //Func3();
                }
                //Func1(a, fin);
                printf("\nProcessing...\n");
                fseek(f1, 0, SEEK_SET);

                i = 0;
                //printf("\nWhat have read:\n\n");
                while(fscanf(f1, "%s%f%f%f", a[i].model, &a[i].ms, &a[i].ss, &a[i].price) != EOF)
                {
                    //printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
                    InsertAtHead(a[i]);
                    i++;
                }
                reverseList();
                // Số Model đọc được
                m_num = i;
                printf("\nSo Model hien co: %d.\n", m_num);
                printf("\nSuccess!\n");
                cnt++;
                break;
            case 2:
                //Import from dat
                if(cnt != 0)
                {
                    FreeList();
                    //Func3();
                }
                //Func2(a, fout);
                printf("\nProcessing...\n");
                fseek(f2, 0, SEEK_END);
                int cnt = ftell(f2) / sizeof(p);
                printf("\nSo mau dien thoai: %d.\n", cnt);
                m_num = cnt;
                rewind(f2);

                i = 0;
                int num;
                num = fread(a, sizeof(p), m_num, f2);
                printf("\nRead Value: %d.\n", num);

                l = createNode(a[0]);
                //node *p = l;
                for(i = 1; i < num; ++i)
                {
                    printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
                    InsertAfterCur(a[i]);
                }
                printf("\nSuccess!\n");
                cnt++;
                break;
            case 3:
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                //Display List
                Func3();
                break;
            case 4:
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                //Search phone by model
                Func4();
                break;
            case 5:
                //Search phone which the price is under
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                Func5();
                break;
            case 6: 
                //Export to dat
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                Func6(a, f2);
                break;
            case 7: 
                //Manual Insertion
                if(cnt == 0)
                {
                    printf("\nChoose 1/2 first!\n");
                    break;
                }
                Func7();
                break;
            case 8: 
                //Quit
                printf("\nThank you!\n");
                return 0;
            default:
                printf("\nInvalid!\n");
                break;
            }
        } while(1);

        printf("\nComplete running!\n\n");
*/