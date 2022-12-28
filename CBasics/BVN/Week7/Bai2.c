#include<stdio.h>
#define _GNU_SOURCE
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 121

//char *strcasestr(const char *haystack, const char *needle);

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
FILE *f, *f1;

node *createNode(p x)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->next = NULL;
    tmp->phone = x;
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

void printList()
{
    node *p = l;
    //int i = 1;
    if(p == NULL) 
    {
        printf("\nCon tro NULL!\n");
        return;
    }
    while(p != NULL)
    {
        //for(i = 0; i < num; ++i)
        displayNode(p);
        //printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
        p = p->next;
        //i++;
    }
    //printf("\n");
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

char* strcasestr(const char* haystack, const char* needle) {
    /* Edge case: The empty string is a substring of everything. */
    if (!needle[0]) return (char*) haystack;

    /* Loop over all possible start positions. */
    for (size_t i = 0; haystack[i]; i++) {
        int matches = 1;
        /* See if the string matches here. */
        for (size_t j = 0; needle[j]; j++) {
            /* If we're out of room in the haystack, give up. */
            if (!haystack[i + j]) return NULL;

            /* If there's a character mismatch, the needle doesn't fit here. */
            if (tolower((unsigned char)needle[j]) != 
                tolower((unsigned char)haystack[i + j])) {
                matches = 0;
                break;
            }
        }
        if (matches) return (char *)(haystack + i);
    }
    return NULL;
}

void Func1(char *s1)
{
    printf("\nProcessing...\n");
    if((f = fopen(s1, "r")) == NULL)
    {
        printf("\nCannot open %s!\n", s1);
        return;
    }
    p *a = (p *)malloc(MAX * sizeof(p));
    fseek(f, 0, SEEK_SET);

    int i = 0;
    prev = cur = NULL;
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
    fclose(f);
    printf("\nSuccess!\n");
}

void Func2(char *s2)
{
    printf("\nProcessing...\n");
    if ((f1 = fopen(s2, "rb")) == NULL) 
    {
        printf("Cannot open %s.", s2);
        exit(1);
    }
    p *a = (p *)malloc(MAX * sizeof(p));
    fseek(f1, 0, SEEK_END);
    //printf("\nCon tro file dag o: %d; Gia tri struct: %d.\n", ftell(f1), sizeof(p));
    printf("\nSo mau dien thoai: %d.\n", ftell(f1) / sizeof(p));
    m_num = ftell(f1) / sizeof(p);  
    //rewind(f);

    int i = 0, num;
    fseek(f1, 0, SEEK_SET);
    num = fread(a, sizeof(p), m_num, f1);
    printf("\nRead Value: %d.\n", num);
    //rewind(f);
    l = createNode(a[0]);
    cur = l;
    prev = NULL;
    //displayNode(cur);
    for(i = 1; i < m_num; ++i)
    {
        //printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
        InsertAfterCur(a[i]);
        //displayNode(cur);
    }
    fclose(f1);
    printf("\nSuccess!\n");
}

//Display List
void Func3()
{
    printf("\nProcessing...\n");
    printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
    node *p = l;
    if(p == NULL)
    {
        printf("\nCon tro NULL!\n");
        return;
    }
    while(p != NULL)
    {
        displayNode(p);
        p = p->next;
    }
    printf("\nReturning to main menu...\n");
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
            if(strcasestr(p->phone.model, mod) != NULL)
            {
                found++; 
                if(found == 1) printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
                displayNode(p);
                //break;
            }
            p = p->next;
        }

        if(found == 0) printf("\nNon - existed!\n");

        printf("\nDo you want to continue searching [y/n]: ");
        fflush(stdin);
        scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while(c == 'y');

    printf("\nReturning to main menu...\n");
}

// Tìm những điện thoại có giá nhỏ hơn value đã nhập
void Func5()
{
    printf("\nProcessing...\n");

    int value, check;
    char c;
    do
    {
        printf("\nEnter value: ");
        fflush(stdin); scanf("%d", &value);
        node *p = l;
        //Kiểm tra xem có mẫu nào nhỏ hơn không?
        check = 0;
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

        printf("\nDo you want to continue searching [y/n]: ");
        fflush(stdin);
        scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');
    
    printf("\nReturning to main menu...\n");
}

//Export to dat, f ở đây là PhoneDB.dat, s2 là argv[2]
void Func6(char *s2)
{
    printf("\nProcessing...\n");
    if ((f1 = fopen(s2, "wb")) == NULL) 
    {
        printf("Cannot open %s.", s2);
        exit(1);
    }
    p *a = (p *)malloc(MAX * sizeof(p));
    node *root = l;
    int num;
    fseek(f1, 0, SEEK_SET);
    //biến kiểu p để lưu cho vào file.dat
    printf("\nSo model hien tai: %d.\n", m_num);
    int i = 0;
    //printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
    while(root != NULL)
    {
        a[i] = root->phone;
        //displayNode(p);
        //printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
        i++;
        root = root->next;
    }
    num = fwrite(a, sizeof(p), i, f1);
    printf("\nWriten Value: %d.\n", num);
    printf("\nReturning to main menu...\n");
    //fseek(f, 0, SEEK_SET);
    /*num = fread(a, sizeof(p), i, f);
    printf("\nRead Value: %d.\n", num);
    for(i = 0; i < num; ++i)
    {
        printf("%-20s%-25.2f%-25.2f%-20.2f\n", a[i].model, a[i].ms, a[i].ss, a[i].price);
    } */
    //fseek(f, 0, SEEK_SET);
    //fwrite(a, sizeof(p), m_num, f);
    fclose(f1);
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
        update();
        InsertBeforeCur(add);
    }
    else if (cur == l) 
    {
        InsertAtHead(add);
    }
    m_num++;
    printf("\nSuccess!\n");
}

// Manual Insertion
void Func7()
{
    printf("\nProcessing...\n");
    //option - lựa chọn
    int opt, vitri;
    char ok;
    do
    {
        printf("\n1. Insert After Current Position\n2. Insert Before Current Position\n3. Exit\n");
        printf("\nCurrent pointer is now at:\n");
        printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
        displayNode(cur);
        printf("\nPrevious pointer is now at:\n");
        printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
        displayNode(prev);

        printf("\nDo you want to change current pointer? [y/n]: ");
        fflush(stdin); scanf("%c", &ok);
        while(ok != 'y' && ok != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &ok);
        }
        if(ok == 'y')
        {
            printf("\nNhap vi tri muon thay doi: ");
            fflush(stdin); scanf("%d", &vitri);
            while(vitri <= 0 || vitri > m_num)
            {
                printf("\nInvalid! Enter again: ");
                fflush(stdin); scanf("%d", &vitri);
            }
            int i;
            node *p = l;
            for(i = 0; i < vitri - 1; ++i)
            {
                p = p->next;
            }
            cur = p;
            update();
            printf("\nCurrent pointer is now at:\n");
            printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
            displayNode(cur);
            printf("\nPrevious pointer is now at:\n");
            printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
            displayNode(prev);
        }
        printf("\n1. Insert After Current Position\n2. Insert Before Current Position\n3. Exit\n");
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
                //printf("\nBack to main Menu...\n");
                break;
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while (opt != 3);
    
    printf("\nReturning to main menu...\n");
}

void Menu(char *s1, char *s2)
{
    printf("\nMenu:\n");
    printf("\n⣿⣿⣿⣿⣿⢻⣿⣿⣿⣿⣿⣿⣆⠻⡫⣢⠿⣿⣿⣿⣿⣿⣿⣿⣷⣜⢻⣿        ⣿⣆⠱⣝⡵⣝⢅⠙⣿⢕⢕⢕⢕⢝⣥⢒⠅⣿⣿⣿⡿⣳⣌⠪⡪⣡⢑\n");
    printf("⣿⣿⡏⣿⣿⣨⣝⠿⣿⣿⣿⣿⣿⢕⠸⣛⣩⣥⣄⣩⢝⣛⡿⠿⣿⣿⣆⢝        ⣿⣿⣦⠹⣳⣳⣕⢅⠈⢗⢕⢕⢕⢕⢕⢈⢆⠟⠋⠉⠁⠉⠉⠁⠈⠼⢐\n");
    printf("⣿⣿⢡⣸⣿⣏⣿⣿⣶⣯⣙⠫⢺⣿⣷⡈⣿⣿⣿⣿⡿⠿⢿⣟⣒⣋⣙⠊        ⢰⣶⣶⣦⣝⢝⢕⢕⠅⡆⢕⢕⢕⢕⢕⣴⠏⣠⡶⠛⡉⡉⡛⢶⣦⡀⠐\n");
    printf("⣿⡏⡿⣛⣍⢿⣮⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿        ⡄⢻⢟⣿⣿⣷⣕⣕⣅⣿⣔⣕⣵⣵⣿⣿⢠⣿⢠⣮⡈⣌⠨⠅⠹⣷⡀\n");
    printf("⣿⢱⣾⣿⣿⣿⣝⡮⡻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⣋⣻⣿⣿⣿⣿        ⡵⠟⠈⢀⣀⣀⡀⠉⢿⣿⣿⣿⣿⣿⣿⣿⣼⣿⢈⡋⠴⢿⡟⣡⡇⣿⡇\n");
    printf("⢿⢸⣿⣿⣿⣿⣿⣿⣷⣽⣿⣿⣿⣿⣿⣿⣿⡕⣡⣴⣶⣿⣿⣿⡟⣿⣿⣿        ⠁⣠⣾⠟⡉⡉⡉⠻⣦⣻⣿⣿⣿⣿⣿⣿⣿⣿⣧⠸⣿⣦⣥⣿⡇⡿⣰\n");
    printf("⣦⡸⣿⣿⣿⣿⣿⣿⡛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⣿⣿⣿        ⢰⣿⡏⣴⣌⠈⣌⠡⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣬⣉⣉⣁⣄⢖⢕\n");
    printf("⢛⠷⡹⣿⠋⣉⣠⣤⣶⣶⣿⣿⣿⣿⣿⣿⡿⠿⢿⣿⣿⣿⣿⣿⣷⢹⣿⣿        ⢻⣿⡇⢙⠁⠴⢿⡟⣡⡆⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣵\n");
    printf("⣷⡝⣿⡞⣿⣿⣿⣿⣿⣿⣿⣿⡟⠋⠁⣠⣤⣤⣦⣽⣿⣿⣿⡿⠋⠘⣿⣿        ⣄⣻⣿⣌⠘⢿⣷⣥⣿⠇⣿⣿⣿⣿⣿⣿⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⡹⣿⡼⣿⣿⣿⣿⣿⣿⣿⣧⡰⣿⣿⣿⣿⣿⣹⡿⠟⠉⡀⠄⠄⢿⣿        ⢄⠻⣿⣟⠿⠦⠍⠉⣡⣾⣿⣿⣿⣿⣿⣿⢸⣿⣦⠙⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣽⣿⣼⣛⠿⠿⣿⣿⣿⣿⣿⣯⣿⠿⢟⣻⡽⢚⣤⡞⠄⠄⠄⢸⣿        ⡑⣑⣈⣻⢗⢟⢞⢝⣻⣿⣿⣿⣿⣿⣿⣿⠸⣿⠿⠃⣿⣿⣿⣿⣿⣿⡿\n");
    printf("                                    ⡵⡈⢟⢕⢕⢕⢕⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣿⣿⣿⣿⣿⠿⠋⣀\n");
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
                Func1(s1);
                cnt++;
                break;
            case 2:
                //Import from dat
                if(cnt != 0)
                {
                    FreeList();
                    //Func3();
                }
                Func2(s2);
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
                Func6(s2);
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
    /*if((f = fopen(argv[1], "r")) == NULL)
    {
        printf("\nCannot open %s!\n", argv[1]);
        return 1;
    }
    else if((f1 = fopen(argv[2], "rb+")) == NULL)
    {
        printf("\nCannot open %s!\n", argv[2]);
        return 1;
    }
    else
    { */
        printf("\nProcessing...\n");
        //p *a = (p *)malloc(MAX * sizeof(p));
        Menu(argv[1], argv[2]);
        printf("\n⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼      ⢹⡇⣿⣿⣿⠄⣞⣯⣷⣾⣿⣿⣧⡹⡆⡀⠉⢹⡌⠐⢿⣿⣿⣿⡞⣿⣿⣿\n");
        printf("⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻      ⣾⡇⣿⣿⡇⣾⣿⣿⣿⣿⣿⣿⣿⣿⣄⢻⣦⡀⠁⢸⡌⠻⣿⣿⣿⡽⣿⣿\n");
        printf("⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿      ⡇⣿⠹⣿⡇⡟⠛⣉⠁⠉⠉⠻⡿⣿⣿⣿⣿⣿⣦⣄⡉⠂⠈⠙⢿⣿⣝⣿\n");
        printf("⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏      ⠤⢿⡄⠹⣧⣷⣸⡇⠄⠄⠲⢰⣌⣾⣿⣿⣿⣿⣿⣿⣶⣤⣤⡀⠄⠈⠻⢮\n");
        printf("⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀      ⠄⢸⣧⠄⢘⢻⣿⡇⢀⣀⠄⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀⠄⢀\n");
        printf("⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇      ⠄⠈⣿⡆⢸⣿⣿⣿⣬⣭⣴⣿⣿⣿⣿⣿⣿⣿⣯⠝⠛⠛⠙⢿⡿⠃⠄⢸\n");
        printf("⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧      ⠄⠄⢿⣿⡀⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⡾⠁⢠⡇⢀\n");
        printf("⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇       ⠄⠄⢸⣿⡇⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⣫⣻⡟⢀⠄⣿⣷⣾\n");
        printf("⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿      ⠄⠄⢸⣿⡇⠄⠈⠙⠿⣿⣿⣿⣮⣿⣿⣿⣿⣿⣿⣿⣿⡿⢠⠊⢀⡇⣿⣿\n");
        printf("⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿      ⠒⠤⠄⣿⡇⢀⡲⠄⠄⠈⠙⠻⢿⣿⣿⠿⠿⠟⠛⠋⠁⣰⠇⠄⢸⣿⣿⣿\n");
        printf("⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿\n");
        printf("⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋\n");
        printf("⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉\n");
        //free(a);
        FreeList();
        //fclose(f);
        //fclose(f1);
        return 0;
    //}
}