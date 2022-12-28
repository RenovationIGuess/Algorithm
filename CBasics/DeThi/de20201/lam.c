#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 41

FILE *f;

typedef struct
{
    char dd[45];
    int h, m;
} et;

#include "singlel.h"

void func2()
{
    char *vt = (char *)malloc(MAX * sizeof(char));
    char opt;
    int found;
    do 
    {
        printf("\nHay nhap ten dia diem (toi da 40 ky tu): ");
        fflush(stdin); gets(vt);
        while(strlen(vt) == 0 || strlen(vt) > 40)
        {
            printf("\nKhong hop le! Hay nhap lai: ");
            fflush(stdin); gets(vt);
        }
        node *p = l;
        found = 0;
        while(p != NULL)
        {
            if(strcmp(p->data.dd, vt) == 0)
            {
                //if(found == 0) printf("%-50s%-10s%-10s\n", "Dia diem", "Gio", "Phut");
                //printf("%-50s%-10d%-10d\n", p->data.dd, p->data.h, p->data.m);
                found++;
                if(found == 1) 
                {
                    if(p == l) printf("\n%d:%d", 0, 0);
                    else printf("\n%d:%d", p->data.h, p->data.m);
                }
                else printf(", %d:%d", p->data.h, p->data.m);
            }
            p = p->next;
        } 
        if(found == 0) printf("\nBan chua toi dia diem do trong ngay!\n");
        else printf("\n");
        printf("\nBan co muon tiep tuc [y/n]: ");
        fflush(stdin); scanf("%c", &opt);
        while(opt != 'y' && opt != 'n')
        {
            printf("\nKhong hop le! Nhap lai: ");
            fflush(stdin); scanf("%c", &opt);
        }
        if(opt == 'n') break;
    } while(1);
}

void func3()
{
    int gio, phut, found;
    char opt;
    do
    {
        found = 0;
        printf("\nHay nhap gio (int - [0;24)): ");
        fflush(stdin); scanf("%d", &gio);
        while(gio < 0 || gio >= 24)
        {
            printf("\nKhong hop le! Hay nhap lai: ");
            fflush(stdin); scanf("%d", &gio);
        }
        printf("\nHay nhap phut (int - [0;60)): ");
        fflush(stdin); scanf("%d", &phut);
        while(phut < 0 || phut >= 60)
        {
            printf("\nKhong hop le! Hay nhap lai: ");
            fflush(stdin); scanf("%d", &phut);
        }
        node *p = l;
        while(p != NULL)
        {
            printf("%s\n", p->data.dd);
            if(p == l)
            {
                if(gio < p->data.h)
                {
                    printf("\nDia diem cua ban tai thoi diem %d:%d la: %s\n", gio, phut, p->data.dd);
                    found = 1;
                    break;
                }
                //else continue;
            }
            if(p->next != NULL)
            {
                if(p->data.h <= gio && gio <= p->next->data.h)
                {
                    if(p->data.h == gio) 
                    {
                        if(p->data.h == p->next->data.h)
                        {
                            if(p->data.m <= phut && phut < p->next->data.m)
                            {
                                printf("\nDia diem cua ban tai thoi diem %d:%d la: %s\n", gio, phut, p->data.dd);
                            }
                            else 
                            {
                                p = p->next;
                                continue;
                            }
                        }
                        else 
                        {
                            if(p->data.m <= phut)
                            {
                                printf("\nDia diem cua ban tai thoi diem %d:%d la: %s\n", gio, phut, p->data.dd);
                            }
                        }                        
                    }
                    else if(p->next->data.h == gio)
                    {
                        if(p->next->data.m > phut)
                        {
                            printf("\nDia diem cua ban tai thoi diem %d:%d la: %s\n", gio, phut, p->data.dd);
                        }
                        else if (p->next->data.m == phut) 
                        {
                            printf("\nDia diem cua ban tai thoi diem %d:%d la: %s\n", gio, phut, p->next->data.dd);
                        }
                        else
                        {
                            p = p->next;
                            continue;
                        }
                    }
                    else if(p->data.h < gio && gio < p->next->data.h) 
                    {
                        printf("\nDia diem cua ban tai thoi diem %d:%d la: %s\n", gio, phut, p->data.dd);
                    }
                    found = 1; 
                    break;
                }
            }
            else
            {
                if(p->data.h <= gio)
                {
                    if(p->data.h == gio) 
                    {
                        if(p->data.m <= phut)
                        {
                            printf("\nDia diem cua ban tai thoi diem %d:%d la: %s\n", gio, phut, p->data.dd);
                        }
                    }
                    else if(p->data.h < gio)
                    {
                        printf("\nDia diem cua ban tai thoi diem %d:%d la: %s\n", gio, phut, p->data.dd);
                    }
                    found = 1; 
                    break;
                }
            }
            p = p->next;
        }
        if(found == 0) printf("\nKHONG tim thay lich su di chuyen!\n");
        printf("\nBan co muon tiep tuc [y/n]: ");
        fflush(stdin); scanf("%c", &opt);
        while(opt != 'y' && opt != 'n')
        {
            printf("\nKhong hop le! Nhap lai: ");
            fflush(stdin); scanf("%c", &opt);
        }
        if(opt == 'n') break;
    } while(1);
}

void func4()
{
    char *vt = (char *)malloc(MAX * sizeof(char));
    char opt;
    int gio, phut, found;
    do
    {
        found = 0;

        printf("\nHay nhap ten dia diem (toi da 40 ky tu): ");
        fflush(stdin); gets(vt);
        while(strlen(vt) == 0 || strlen(vt) > 40)
        {
            printf("\nKhong hop le! Hay nhap lai: ");
            fflush(stdin); gets(vt);
        }

        printf("\nHay nhap gio (int - [0;24]): ");
        fflush(stdin); scanf("%d", &gio);
        while(gio < 0 || gio >= 24)
        {
            printf("\nKhong hop le! Hay nhap lai: ");
            fflush(stdin); scanf("%d", &gio);
        }

        printf("\nHay nhap phut (int - [0;60]): ");
        fflush(stdin); scanf("%d", &phut);
        while(phut < 0 || phut >= 60)
        {
            printf("\nKhong hop le! Hay nhap lai: ");
            fflush(stdin); scanf("%d", &phut);
        }

        node *p = l;
        while(p != NULL)
        {
            if(p == l)
            {
                if(gio < p->data.h)
                {
                    printf("\nBan co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
                    found = 1;
                    break;
                }
                //else continue;
            }
            if(p->next != NULL)
            {
                if(p->data.h <= gio && gio <= p->next->data.h)
                {
                    if(strcmp(p->data.dd, vt) == 0)
                    {
                        if(p->data.h == gio) 
                        {
                            if(p->data.h == p->next->data.h)
                            {
                                if(p->data.m <= phut && phut < p->next->data.m)
                                {
                                    printf("\nBan co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
                                }
                                else break;
                            }
                            else
                            {
                                if(p->data.m <= phut)
                                {
                                    printf("\nBan co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
                                }
                            }
                        }
                        else if(p->next->data.h == gio)
                        {
                            if(p->next->data.m > phut)
                            {
                                printf("\nBan co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
                            }
                            else //if(p->next->data.m == phut)
                            {
                                //printf("\nLich su di chuyen cua ban OK!\n");
                                break;
                            }
                        }
                        else if(p->data.h < gio && gio < p->next->data.h) 
                        {
                            printf("\nBan co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
                        }
                        found = 1; 
                        break;
                    }
                }
            }
            else
            {
                if(p->data.h <= gio)
                {
                    if(strcmp(p->data.dd, vt) == 0)
                    {
                        if(p->data.h == gio)
                        { 
                            if(p->data.m <= phut)
                                printf("\nBan co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
                        }
                        else if(p->data.h < gio)
                            printf("\nBan co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
                        found = 1; 
                        break;
                    }
                }
            }
            //printf("%s\n", p->data.dd);
            p = p->next;
        }
        if(found == 0) printf("\nLich su di chuyen cua ban OK!\n");
        printf("\nBan co muon tiep tuc [y/n]: ");
        fflush(stdin); scanf("%c", &opt);
        while(opt != 'y' && opt != 'n')
        {
            printf("\nKhong hop le! Nhap lai: ");
            fflush(stdin); scanf("%c", &opt);
        }
        if(opt == 'n') break;
    } while(1);
}

void func1(char *s)
{
    if((f = fopen(s, "r")) == NULL)
    {
        printf("\nKhong the mo file %s!\n", s);
        return;
    }
    et create;
    printf("\nDu lieu doc duoc:\n");
    printf("%-50s%-10s%-10s\n", "Dia diem", "Gio", "Phut");
    do
    {
        fscanf(f, "%s", create.dd);
        fgetc(f);
        fscanf(f, "%d", &create.h);
        fgetc(f);
        fscanf(f, "%d", &create.m);
        printf("%-50s%-10d%-10d\n", create.dd, create.h, create.m);
        //InsertAfterCur(create);
        InsertAtHead(create);
        if(feof(f)) break;
    } while (1);
    reverseList();
    printf("\nTao danh sach lien ket don thanh cong!\n");
    //printList();
}

void menu(char *s)
{
    int opt;
    do
    {
        printf("\n=============================\n");
        printf("CHUONG TRINH TRUY VET COVID19\n");
        printf("1. Nap file log lich su di chuyen\n2. Tim kiem lich su di chuyen theo dia diem\n3. Tim kiem lich su di chuyen theo thoi gian\n4. Kiem tra truy vet moi nhat\n5. Thoat\n");
        printf("\nHay nhap lua chon: ");
        fflush(stdin); scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                func1(s);
                break;
            case 2:
                func2();
                break;
            case 3:
                func3();
                break;
            case 4:
                func4();
                break;
            case 5:
                printf("\nCam on va hen gap lai!\n");
                break;
            default:
                printf("\nKhong hop le!\n");
                break;
        }
    } while (opt != 5);
    
}

int main(int argc, char *argv[])
{
    l = cur = prev = NULL;
    menu(argv[1]);
    FreeList();
    return 0;
}