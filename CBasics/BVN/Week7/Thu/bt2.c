#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 100;
FILE *fp1, *fp2, *fp3;
int n;
typedef struct
{
    char model[20];
    int memory;
    float size;
    float price;
} dt;

struct list_el
{
    dt addr;
    struct  list_el *next;
};

typedef struct list_el node_addr;

node_addr *root = NULL;

dt readNode() {
    dt tmp;
    printf("Nhap thong tin: \n");
    printf("Model: "); fflush(stdin); gets(tmp.model);
    printf("Memory Space: "); scanf("%d", &tmp.memory);
    printf("Screen Size: "); scanf("%f", &tmp.size);
    printf("Price: "); scanf("%f", &tmp.price);
    return tmp;
}

void InsertAtHead(dt a);
void InsertAtCur(dt a);
void Insert(dt a, int xx);
void Insert1(dt a, int xx);
void Insert2(dt a, int xx);
void printList();


void func1()
{
    while(root != NULL) {
        node_addr *new = root->next;
        free(root);
        root = new;
    }
    
    if ((fp1 = fopen("phoneDB.txt", "r")) == NULL) {
        printf("Cannot open %s.", "phoneDB.txt");
        exit(1);
    }

    dt *a;
    a = (dt *)malloc(MAX * sizeof(dt));

    if (a == NULL) {
        printf("Cannot allocate memory!\n\n");
        exit(1); 
    }

    //printf("%-15s%-20s%-30s%-15s \n", "Model", "Memory Space(GB)", "Screen Size(inches)", "Price");
    int i = 0;
    int numc = 0;
    while (fscanf(fp1, "%s%d%f%f", a[i].model, &a[i].memory, &a[i].size, &a[i].price) != EOF)
    {
        i++;
        numc++;
    }
    for(i = 0; i < numc; ++i) {
        InsertAtHead(a[i]);
    }
    fclose(fp1);
}

void func2()
{
    while(root != NULL) {
        node_addr *new = root->next;
        free(root);
        root = new;
    }
    int i;
    if ((fp2 = fopen("phoneDB.dat", "rb")) == NULL) {
        printf("Cannot open %s.", "phoneDB.dat");
        exit(1);
    }
    dt *a;
    a = (dt *)malloc(MAX * sizeof(dt));
    if (a == NULL) {
        printf("Cannot allocate memory!\n\n");
        exit(1); 
    }
    //printf("%-15s%-20s%-30s%-15s \n", "Model", "Memory Space(GB)", "Screen Size(inches)", "Price");
    int numc = fread(a, sizeof(dt), 50, fp2);

    for(i = 0; i < numc; ++i) {
        InsertAtCur(a[i]);
    }
    fclose(fp2);
}

void func3()
{
    printList();
}

void func4()
{
    char dtx[20];
    int tg, dd;
    tg = 1;
    dd = 0;
    while(tg == 1)
    {
        dd = 0;
        printf("Nhap mau dien thoai can tim kiem: ");
        fflush(stdin); gets(dtx);
        node_addr *p = root;
        while (p != NULL)
        {
            if (strstr(p->addr.model, dtx))
            {
                dd = 1;
                printf("%-15s%-20d%-30.2f%-15.2f \n\n", p->addr.model, p->addr.memory, p->addr.size, p->addr.price);
            }
            p = p->next;
        }
        if (!dd) {
            printf("Mau dien thoai khong ton tai.\n");
            printf("Xin vui long nhap lai.\n");
        }
        printf("Ban co muon tiep tuc tim kiem khong?\n "); 
        printf("Nhan 1 de tiep tuc: "); scanf("%d", &tg);
    }
}

void func5()
{
    float pri;
    int tg, dd;
    tg = 1;
    dd = 0;
    while(tg == 1)
    {
        dd = 0;
        printf("Nhap mau gia tri: "); scanf("%f", &pri);
        node_addr *p = root;
        while (p != NULL)
        {
            if (p->addr.price < pri)
            {
                dd = 1;
                printf("%-15s%-20d%-30.2f%-15.2f \n\n", p->addr.model, p->addr.memory, p->addr.size, p->addr.price);
            }
            p = p->next;
        }
        if (!dd) {
            printf("Khong co mau dien thoai nao co gia tri nho hon.\n");
            printf("Xin vui long nhap lai.\n");
        }
        printf("Ban co muon tiep tuc tim kiem khong?\n "); 
        printf("Nhan 1 de tiep tuc: "); scanf("%d", &tg);
    }
    
}

void func6()
{
    if ((fp3 = fopen("phone.dat", "wb")) == NULL) {
        printf("Cannot open %s.", "phone.dat");
        exit(1);
    }
    dt *a;
    a = (dt *)malloc(MAX * sizeof(dt));
    
    node_addr *iter = root;
    while(iter != NULL)
    {
        fwrite((void*)(&iter->addr), sizeof(char), sizeof(dt), fp3);
        iter = iter->next;
    }
    fclose(fp3);
}

void func7()
{
    int tg = 1;

    while (tg)
    {
        dt tmp;
        tmp = readNode();
        int cur;
        printf("Nhap vi tri con tro cur: "); scanf("%d", &cur);
        printf("Vi tri ban muon them vao: \n");
        printf("1/ Truoc con tro cur. \n 2/ Sau con tro cur.\n");
        int x;
        printf("Chon vi tri ban muon them vao: "); scanf("%d", &x);
        if (x == 1) {
            Insert1(tmp,cur);
            printf("\n");
        }
        if (x == 2)
        {
            Insert2(tmp, cur);
            printf("\n");
        }
        printf("Ban co muon tiep tuc khong: Co(1)/Khong(0):  "); scanf("%d", &tg);
    }


}

void menu()
{
    int func;
    int ttt = 0;
	printf("Chuong Trinh tuan 5: ");
	do 
	{
        printf("\n1. Import from .txt.\n2. Import from dat.\n3. Display List.\n4. Search phone by model.\n");
        printf("5. Search phone by price.\n6. Export to dat.\n7. Manual Insertion.\n8. Exit.\n");
		printf("Nhap Chuc Nang: ");
		fflush(stdin);
		scanf("%d", &func);
		while(func < 1 || func > 8)
		{
			printf("Khong Hop Le! Nhap Lai: ");
			fflush(stdin);
			scanf("%d", &func);
		}
		switch(func)
		{
			case 1: 
                func1();
                printf("\nImport from .txt success\n");
                break;
			case 2: 
                func2();
                printf("\nImport from .dat success\n");
                break;
			case 3: 
                func3();
                break;
            case 4: 
                func4();
                break;
            case 5: 
                func5();
                break;
			case 6: 
                func6();
                printf("\nExport to .dat success\n");
                break;
			case 7: 
                func7();
                break;
            case 8:
				printf("\nCam On Vi Da Su Dung!\n");
				break;
		}
	} while(func != 8);
}

int main()
{
    menu();
    return 1;
}

void InsertAtHead(dt a) {
    if( root == NULL){
		root = (node_addr *)malloc(sizeof(node_addr));
		memcpy((void *)&root->addr, (void * )&a, sizeof(dt));			
		return;
	}

    node_addr *iter;
    iter = (node_addr *)malloc(sizeof(node_addr));
    iter->next = root;
    memcpy((void *)&iter->addr, (void *)&a, sizeof(dt));	
    root = iter;	
}

void Insert1(dt a, int xx) {
	if( root == NULL){
		root = (node_addr *)malloc(sizeof(node_addr));
		memcpy((void *)&root->addr, (void * )&a, sizeof(dt));			
		return;
	}
	node_addr *iter = root;
	/*for(; iter->next != NULL; iter = iter->next)
		;*/
    while ((--xx) && iter->next != NULL)
    {
        iter = iter->next;
    }
    node_addr *new = iter->next;

	iter->next = (node_addr *)malloc(sizeof(node_addr));
    //iter->next = new;

    iter = iter->next;
    iter->next = new;
    memcpy((void *)&iter->addr, (void *)&a, sizeof(dt));		
}

void Insert2(dt a, int xx) {
	if( root == NULL){
		root = (node_addr *)malloc(sizeof(node_addr));
		memcpy((void *)&root->addr, (void * )&a, sizeof(dt));			
		return;
	}
	node_addr *iter = root;
	/*for(; iter->next != NULL; iter = iter->next)
		;*/
    while ((xx--) && iter->next != NULL)
    {
        iter = iter->next;
    }
    node_addr *new = iter->next;

	iter->next = (node_addr *)malloc(sizeof(node_addr));
    //iter->next = new;

    iter = iter->next;
    iter->next = new;
    memcpy((void *)&iter->addr, (void *)&a, sizeof(dt));		
}

void InsertAtCur(dt a){
	if( root == NULL){
		root = (node_addr *)malloc(sizeof(node_addr));
		memcpy((void *)&root->addr, (void * )&a, sizeof(dt));			
		return;
	}
	node_addr *iter = root;
	for(; iter->next != NULL; iter = iter->next)
		;
    
	iter->next = (node_addr *)malloc(sizeof(node_addr));
    iter = iter->next;
    memcpy((void *)&iter->addr, (void *)&a, sizeof(dt));		
}

void printList()
{
	node_addr *p = root;
    while ((p != NULL))
    {
        //printf("%-20s%-15s%-30s\n", p->addr.name, p->addr.tel, p->addr.email);
        printf("%-15s%-20d%-30.2f%-15.2f \n\n", p->addr.model, p->addr.memory, p->addr.size, p->addr.price);
        p = p->next;
    }
}

