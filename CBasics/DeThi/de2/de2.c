#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 256

FILE *f;

typedef struct
{
    char username[35];
    char password[35];
    float pt;
} ElmType;

#include "tree.h"

int kiemtraspace(char *s)
{
    int i;
    for(i = 0; i < strlen(s); ++i)
    {
        if(s[i] == ' ') return 1;
    }
    return 0;
}

void tofile(treetype *t, ElmType sv)
{
    treetype p = *t;
    int cnt = 0;
    while(*t)
    {
        if((*t)->left == NULL)
        {
            if(strcmp((*t)->element.username, sv.username) == 0)
            {
                (*t)->element = sv;
            }
            fprintf(f, "%s\t%s\t%.2f\n", (*t)->element.username, (*t)->element.password, (*t)->element.pt);
            *t = (*t)->right;
        }
        else
        {
            p = (*t)->left;
            while(p->right && p->right != *t)
            {
                p = p->right;
            }
            if(p->right == NULL)
            {
                p->right = *t;
                *t = (*t)->left;
            }
            else
            {
                p->right = NULL;
                if(strcmp((*t)->element.username, sv.username) == 0)
                {
                    (*t)->element = sv;
                }
                fprintf(f, "%s\t%s\t%.2f\n", (*t)->element.username, (*t)->element.password, (*t)->element.pt);
                *t = (*t)->right;
            }
        }
    }
}

void Func3_1(treetype *t, char *s, ElmType *sv)
{
    if((f = fopen(s, "w")) == NULL)
    {
        printf("\nCannot open file %s!\n", s);
        return;
    }
    treetype p = *t;
    tofile(t, *sv);
    *t = p;
    //Inorder(*t);
    printf("\nDa ghi thanh cong! Tro ve main menu...\n");
    fclose(f);
}

void menu2(treetype *t, char *s, ElmType *sv)
{
    int opt, cnt;
    char *pw = (char *)malloc(MAX * sizeof(char));
    char *test = (char *)malloc(MAX * sizeof(char));
    do
    {
        printf("\n1. Xem diem\n2. Thay doi mat khau\n3. Ghi thong tin va thoat\n");
        printf("\nHay nhap lua chon: ");
        fflush(stdin); scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nDiem cua ban la: %.2f\n", sv->pt);
            break;
        case 2:
            printf("\nHay nhap mat khau moi: ");
            fflush(stdin); gets(pw);
            while(kiemtraspace(pw) == 1)
            {
                printf("\nKhong hop le! Hay nhap lai: ");
                fflush(stdin); gets(pw);
            }
                cnt = 0;
                printf("\nNhap lai mat khau lan 2: ");
                fflush(stdin); gets(test);
                while(kiemtraspace(test) == 1)
                {
                    printf("\nKhong hop le! Hay nhap lai: ");
                    fflush(stdin); gets(test);
                }
                while(strcmp(pw, test) != 0)
                {
                    cnt++;
                    if(cnt == 3)
                    {
                        printf("\nBan da nhap sai 2 lan! Dang thoat...\n");
                        break;
                    }
                    printf("\nBan da nhap sai! Hay nhap lai: ");
                    fflush(stdin); gets(test);
                }
            if(cnt != 3) 
            {
                strcpy(sv->password, pw);
                printf("\nThay doi mat khau thanh cong!\n");
            }
            break;
        case 3:
            Func3_1(t, s, sv);
            break;
        default:
            printf("\nKhong hop le!\n");
            break;
        }
    } while (opt != 3);
    
}

void func1(treetype *t)
{
    int cnt1;
    treetype find;
    //char *username = (char *)malloc(MAX * sizeof(char));
    //char *password = (char *)malloc(MAX * sizeof(char));
    //float pt;
    ElmType add;
        printf("\nUsername (khong chua dau cach \' \'): ");
        fflush(stdin); gets(add.username);
        cnt1 = 0;
        while(kiemtraspace(add.username) == 1 || strcmp("Admin", add.username) == 0 || (find = Search(add.username, *t)) != NULL)
        {
            cnt1++;
            if(cnt1 == 3)
            {
                printf("\nDa nhap sai 3 lan! Thoat chuong trinh...\n");
                exit(1);
            }
            printf("\nKhong hop le! Hay nhap lai: ");
            fflush(stdin); gets(add.username);
        }

        cnt1 = 0;
        printf("\nPassword (it nhat 6 ky tu va no space): ");
        fflush(stdin); gets(add.password);
        while(strlen(add.password) < 6 || kiemtraspace(add.password) == 1)
        {
            cnt1++;
            if(cnt1 == 3)
            {
                printf("\nDa nhap sai 3 lan! Thoat chuong trinh...\n");
                exit(1);
            }
            printf("\nKhong hop le! Hay nhap lai: ");
            fflush(stdin); gets(add.password);
        }
    printf("\nDiem [0; 10]: ");
    fflush(stdin); scanf("%f", &add.pt);
    while (add.pt < 0 && add.pt > 10)
    {
        printf("\nKhong hop le! Hay nhap lai: ");
        fflush(stdin); scanf("%f", &add.pt);
    }
    InsertNode(add, t);
    printf("\nThem thanh cong!\n");
}

void func2(treetype t)
{
    if(t != NULL)
    {
        func2(t->left);
        if(strcmp("Admin", t->element.username) != 0)
            printf("%-35s%-35s%-15.2f\n", t->element.username, t->element.password, t->element.pt);
        func2(t->right);
    }
}

void func3(treetype *t)
{
    int cnt1 = 0;
    char *username = (char *)malloc(MAX * sizeof(char));
        printf("\nUsername (khong chua dau cach \' \'): ");
        fflush(stdin); gets(username);
        while(kiemtraspace(username) == 1 || strcmp("Admin", username) == 0)
        {
            cnt1++;
            if(cnt1 == 3)
            {
                printf("\nDa nhap sai 3 lan! Thoat chuong trinh...\n");
                exit(1);
            }
            printf("\nKhong hop le! Hay nhap lai: ");
            fflush(stdin); gets(username);
        }
    treetype find = Search(username, *t);
    if(find != NULL)
    {
        printf("\n%-35s%-35s%-15s\n", "Username", "Password", "Diem");
        printf("%-35s%-35s%-15.2f\n", find->element.username, find->element.password, find->element.pt);
        DeleteNode(username, t);
        printf("\nXoa thanh cong!\n");
    }
    else printf("Khong tim thay sinh vien can xoa!\n");
}

void tofile1(treetype *t)
{
    treetype p = *t;
    int cnt = 0;
    while(*t)
    {
        if((*t)->left == NULL)
        {
            fprintf(f, "%s\t%s\t%.2f\n", (*t)->element.username, (*t)->element.password, (*t)->element.pt);
            *t = (*t)->right;
        }
        else
        {
            p = (*t)->left;
            while(p->right && p->right != *t)
            {
                p = p->right;
            }
            if(p->right == NULL)
            {
                p->right = *t;
                *t = (*t)->left;
            }
            else
            {
                p->right = NULL;
                fprintf(f, "%s\t%s\t%.2f\n", (*t)->element.username, (*t)->element.password, (*t)->element.pt);
                *t = (*t)->right;
            }
        }
    }
}

void func4(treetype *t, char *s)
{
    if((f = fopen(s, "w")) == NULL)
    {
        printf("\nCannot open file %s!\n", s);
        return;
    }
    treetype p = *t;
    tofile1(t);
    *t = p;
    //Inorder(*t);
    printf("\nDa ghi thanh cong! Tro ve main menu...\n");
    fclose(f);
}

void menu1(treetype *t, char *s)
{
    int opt;
    do
    {
        printf("\n1. Them 1 sinh vien\n2. In ra danh sach\n3. Xoa sinh vien\n4. Ghi thong tin va thoat\n");
        printf("\nHay nhap lua chon: ");
        fflush(stdin); scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            func1(t);
            break;
        case 2:
            printf("\n%-35s%-35s%-15s\n", "Username", "Password", "Diem");
            func2(*t);
            break;
        case 3: 
            func3(t);
            break;
        case 4:
            func4(t, s);
            break;
        default:
            printf("\nKhong hop le!\n");
            break;
        }

    } while (opt != 4);
    
}

void menu(treetype *t, char *s)
{
    if((f = fopen(s, "r")) == NULL)
    {
        printf("\nCannot open file %s!\n", s);
        return;
    }
    ElmType tmp;
    do
    {
        fscanf(f, "%s", tmp.username);
        fgetc(f);
        fscanf(f, "%s", tmp.password);
        fgetc(f);
        fscanf(f, "%f", &tmp.pt);
        //printf("%-35s%-35s%-15.2f\n", tmp.username, tmp.password, tmp.pt);
        InsertNode(tmp, t);
        if(feof(f)) break;
    } while(1);
    
    printf("\n%-35s%-35s%-15s\n", "Username", "Password", "Diem");
    Inorder(*t);

    int cnt = 0, cnt1;
    char *username = (char *)malloc(MAX * sizeof(char));
    char *password = (char *)malloc(MAX * sizeof(char));
    while(cnt < 3)
    {
        printf("\nUsername (khong chua dau cach \' \'): ");
        fflush(stdin); gets(username);
        cnt1 = 0;
        while(kiemtraspace(username) == 1)
        {
            cnt1++;
            if(cnt1 == 3)
            {
                printf("\nDa nhap sai 3 lan! Thoat chuong trinh...\n");
                exit(1);
            }
            printf("\nKhong hop le! Hay nhap lai: ");
            fflush(stdin); gets(username);
        }

        cnt1 = 0;
        printf("\nPassword (it nhat 6 ky tu va no space): ");
        fflush(stdin); gets(password);
        while(strlen(password) <= 6 || kiemtraspace(password) == 1)
        {
            cnt1++;
            if(cnt1 == 3)
            {
                printf("\nDa nhap sai 3 lan! Thoat chuong trinh...\n");
                exit(1);
            }
            printf("\nKhong hop le! Hay nhap lai: ");
            fflush(stdin); gets(password);
        }

        treetype find = Search(username, *t);
        if(find != NULL)
        {
            tmp = find->element;
            if(strcmp(password, tmp.password) == 0)
            {
                if(strcmp("Admin", tmp.username) == 0)
                {
                    printf("\nDang nhap thanh cong - menu admin!\n");
                    menu1(t, s);
                    break;
                }
                else 
                {
                    printf("\nDang nhap thanh cong - menu sinh vien!\n");
                    menu2(t, s, &tmp);
                    break;
                }
            }
        }
        else 
        {
            cnt++;
            printf("\nBan da nhap khong hop le lan %d!\n", cnt);
        }
    }
    fclose(f);
    if(cnt == 3) exit(1);
}

void main_menu(treetype *t, char *s)
{
    int opt;
    do
    {
        printf("\n1. Dang nhap\n2. Thoat\n");
        printf("\nHay nhap lua chon: ");
        fflush(stdin); scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                menu(t, s);
                break;
            case 2:
                printf("\nCam on va hen gap lai!\n");
                break;
            default:
                printf("\nKhong hop le!\n");
                break;
        }
    } while (opt != 2);
}

int main(int argc, char *argv[])
{
    treetype t;
    MakeNullTree(&t);
    main_menu(&t, argv[1]);
    MakeNullTree(&t);
    FreeTree(&t);
    return 0;
}