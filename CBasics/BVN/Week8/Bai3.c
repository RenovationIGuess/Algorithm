#define _GNU_SOURCE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "GenSLL.h"
#define MAX 256

//dieu khien file
FILE *f;
//dem so danh ba
int m_num;
//sublist 1
node *list1;

//Import from PhoneDB.dat (insert after cur)
void Func1(char *s)
{
    printf("\nProcessing...\n");
    if ((f = fopen(s, "rb")) == NULL) 
    {
        printf("Cannot open %s.", s);
        exit(1);
    }
    p *a = (p *)malloc(MAX * sizeof(p));
    fseek(f, 0, SEEK_END);
    m_num = ftell(f) / sizeof(p);  
    int i = 0, num;
    fseek(f, 0, SEEK_SET);
    num = fread(a, sizeof(p), m_num, f);
    l = createNode(a[0]);
    cur = l;
    prev = NULL;
    for(i = 1; i < m_num; ++i)
    {
        InsertAfterCur(a[i]);
    }
    fclose(f);
    printf("\nSuccess!\n");
}

//Display List - traverse
void Func2()
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

//Insert after 
void Func3_1()
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
void Func3_2()
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

//Add new phone (before/after)
void Func3()
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
                Func3_1();
                break;
            case 2: 
                Func3_2();
                break;
            case 3: 
                break;
            default:
                printf("\nInvalid!\n");
                break;
        }
    } while (opt != 3);
    
    printf("\nReturning to main menu...\n");
}

//Insert at position
void Func4()
{
    printf("\nProcessing:\n");
    //position
    int posi;
    printf("\nEnter position you want [0; %d]: ", m_num - 1);
    fflush(stdin); scanf("%d", &posi);
    while(posi < 0 || posi > m_num - 1)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin); scanf("%d", &posi);
    }
    p add;
    ReadNode(&add);
    node *tmp = l;
    if(posi == 0) InsertAtHead(add);
    else tmp = insertAtPosition(tmp, add, posi);
    m_num++;
    printf("\nSuccess! Use Function 2 to check.\n");
}

//Delete at position
void Func5()
{
    printf("\nProcessing:\n");
    int posi;
    printf("\nEnter position you want [0; %d]: ", m_num - 1);
    fflush(stdin); scanf("%d", &posi);
    while(posi < 0 || posi > m_num - 1)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin); scanf("%d", &posi);
    }
    if(posi == 0) deleteHead();
    else if(posi == m_num - 1) deleteTail();
    else 
    {
        node *tmp = l;
        tmp = deleteAtPosition(tmp, posi);
    }
    m_num--;
    printf("\nSuccess! Use Function 2 to check.\n");
}

//Delete current
void Func6()
{
    printf("\nProcessing:\n");
    int vitri;
    char ok;
    printf("\nCurrent pointer is now at:\n");
    printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
    displayNode(cur);
    printf("\nDo you want to change current pointer? [y/n]: ");
    fflush(stdin); scanf("%c", &ok);
    while(ok != 'y' && ok != 'n')
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin); scanf("%c", &ok);
    }
    if(ok == 'y')
    {
        printf("\nNhap vi tri muon thay doi [1; %d]: ", m_num);
        fflush(stdin); scanf("%d", &vitri);
        while(vitri <= 0 || vitri > m_num)
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%d", &vitri);
        }
        int i;
        node *tmp = l;
        for(i = 0; i < vitri - 1; ++i)
        {
            tmp = tmp->next;
        }
        cur = tmp;
        update();
        printf("\nCurrent pointer is now at:\n");
        printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
        displayNode(cur);
    }    
    deleteMiddle();
    m_num--;
    printf("\nSuccess! Use Function 2 to check.\n");
}

//Delete first
void Func7()
{
    printf("\nProcessing:\n");
    deleteHead();
    m_num--;
    printf("\nSuccess! Use Function 2 to check.\n");
}

// Tìm kiếm theo Model - Search and Update
void Func8()
{
    printf("\nProcessing...\n");
    int i;
    char c;
    char mod[MAX];
    do
    {
        // xem model can tim co ko
        int found = 0;
        printf("\nEnter Phone Model you want to search: ");
        fflush(stdin);
        gets(mod);
        node *p = l;
        while(p != NULL)
        {
            if(strcasecmp(p->phone.model, mod) == 0)
            {
                found = 1; 
                printf("\n%-20s%-25s%-25s%-20s\n", "Model", "Memory Space(GB)", "Screen Size (inches)", "Price");
                displayNode(p);
                ReadNode(&p->phone);
                break;
            }
            p = p->next;
        }
        if(found == 0) printf("\nNon - existed!\n");
        printf("\nDo you want to continue [y/n]: ");
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

//Divide and Extract
void Func9()
{
    printf("\nProcessing...\n");
    int n1, n2;
    printf("\nEnter start postion [0; %d]: ", m_num - 1);
    fflush(stdin); scanf("%d", &n1);
    while(n1 < 0 || n1 > m_num - 1)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin); scanf("%d", &n1);
    }
    printf("\nEnter number of element of sublist 1: ");
    fflush(stdin); scanf("%d", &n2);
    while(n2 <= 0 || n2 + n1 > m_num)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin); scanf("%d", &n2);
    }
    list1 = split(l, n1, n2);
    node *tmp = list1;
    printf("\nList 1:\n");
    while(tmp != NULL)
    {
        displayNode(tmp);
        tmp = tmp->next;
    }
    printf("\nList 2:\n");
    printList();
    m_num -= n2;
    printf("\nReturning to main menu...\n");
}

//reverse list - l
void Func10()
{
    printf("\nProcessing...\n");
    reverseList();
    printf("\nSuccess! Use Function 2 to check.\n");
}

//Export to dat - Save to file
void Func11(char *s)
{
    printf("\nProcessing...\n");
    if ((f = fopen(s, "wb")) == NULL) 
    {
        printf("Cannot open %s.", s);
        exit(1);
    }
    p *a = (p *)malloc(MAX * sizeof(p));
    node *root = l;
    int num;
    fseek(f, 0, SEEK_SET);
    //biến kiểu p để lưu cho vào file.dat
    int i = 0;
    while(root != NULL)
    {
        a[i] = root->phone;
        i++;
        root = root->next;
    }
    num = fwrite(a, sizeof(p), i, f);
    printf("\nSuccess! Returning to main menu...\n");
    fclose(f);
}

void Menu(char *s)
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
    //đếm việc nhập chức năng 1
    int cnt = 0;
    int i;
    do
    {
        // option
        int opt;
        printf("\n1. Import from PhoneDB.dat\n2. Display (traverse)\n3. Add new phone\n4. Insert at position\n5. Delete at position\n6. Delete current\n7. Delete first\n8. Search and update\n9. Divide and Extract (split)\n10. Reverse List\n11. Save to file\n12. Quit (free)\n");
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
                Func1(s);
                cnt++;
                break;
            case 2:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func2();
                break;
            case 3:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func3();
                break;
            case 4:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func4();
                break;
            case 5:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func5();
                break;
            case 6: 
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func6();
                break;
            case 7: 
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func7();
                break;
            case 8: 
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func8();
                break;
            case 9:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func9();
                break;
            case 10:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func10();
                break;
            case 11:
                if(cnt == 0)
                {
                    printf("\nChoose 1 first!\n");
                    break;
                }
                Func11(s);
                break;
            case 12: 
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
        printf("\nProcessing...\n");
        Menu(argv[1]);
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
        FreeList();
        return 0;
}