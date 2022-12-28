#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node
{
    int value;
    struct Node *next;
};

typedef struct Node node;

int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

/*void print(node *h)
{
    node *p = h;
    while(p != NULL)
    {
        printf("%d", p->value);
        p = p->next;
    }
}

void findLast(node *h)
{
    node *p = h;
    while(p != NULL)
    {
        if(p->next == NULL) return p;
        p = p->next;
    }
    return NULL;
}

node *makeNode(int x)
{
    node *p = new node;
    p->value = x; p->next = NULL;
    return p;
}

node *insertA(node *h, node *p, int x)
{
    if(p == NULL)
    {
        return h;
    }
    node *q = makenode(x);
    if(h == NULL)
    {
        return p;
    }
    q->next = p->next;
    p->next = q;
    return h;
} */

// Tao
node *createNode(int x)
{
    //node *temp = new node;
    node *temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    temp->value = x; 
    return temp;
}

// In
void printList(node *l)
{
	node *p = l;
	while (p != NULL)
    {
		printf("%d ", p->value);
		p = p->next;
	}
    printf("\n");
}

node *addElement(node *p, int x)
{
	node *temp = createNode(x);
	p->next = temp;
	return temp;
}

// Them
node *addHead(node *l, int x)
{
	//node *temp = new node;
    node *temp = (node *)malloc(sizeof(node));
	temp->value = x;
	temp->next = l;
	l = temp;
	return l;
}

node *addAt(node *l, int k, int x)
{
	node *p = l;
	for (int i = 0; i < k - 1; i++)
    {
		p = p->next;
	}
	//node *temp = new node;
    node *temp = (node *)malloc(sizeof(node));
	temp->value = x;
	temp->next = p->next;
    //node *temp = createNode(x);
	p->next = temp;
	return l;
}

node *addTail(node *l, int x)
{
	node *p = l;
	while (p->next != NULL)
    {
		p = p->next;
	}
	//node *temp = new node;
    node *temp = (node *)malloc(sizeof(node));
	temp->value = x;
	temp->next = NULL;
	p->next = temp;
	return l;
}

// Xoa
node *deleteHead(node *l)
{
	//node *p = l;
    if(l == NULL)
    {
        printf("\nNothing to delete!\n");
    }
    else
    {
        l = l->next;
    }
	//delete(l);
	return l;
}

node *deleteTail(node *l)
{
    if(l == NULL || l->next == NULL)
    {
        return deleteTail(l);
    }
	node *p = l;
	while (p->next->next != NULL)
    {
		p = p->next;
	}
    //p->next = p->next->next;
	//delete(p->next);
	p->next = NULL;
	return l;
}

node *deleteAt(node *l, int k)
{
	node *p = l;
	for (int i = 0; i < k-1; i++){
		p = p->next;
	}
	//node *temp = p->next;
	p->next = p->next->next;
	//delete(temp);
	return l;
}

// Tim kiem
node *getNode(node *l, int k)
{
	node *p = l;
	for (int i = 0; i < k; i++){
		p = p->next;
	}
	return p;
}

int main()
{
    srand((int)time(0));
    // x la gia tri
    int n, i, x, k, v;
    int rand;
    // rand - random so phan tu se xoa hoac them
    // n la so phan tu, i duyet for, x + v la gia tri, k la vi tri 

    printf("\nNhap n: ");
    fflush(stdin);
    scanf("%d", &n);
    printf("\n");

    x = random(1, n);
    node *l = createNode(x);
    node *p = l;

    // khoi tao danh sach
    for(i = 1; i < n; ++i)
    {
        x = random(1, n);
        p = addElement(p, x);
    }
    printList(l);

    // Xoa phan tu
    rand = random(1, n - 1);
    printf("\nXoa %d phan tu:\n", rand);
    for(i = 0; i < rand; ++i)
    {
        k = random(0, n - 1);
        printf("\nVi tri xoa: %d.\n", k);
        if (k == 0)
        {
		    l = deleteHead(l);
	    } else if (k == n - 1)
        {
		    l = deleteTail(l);
	    } else
        {
		    l = deleteAt(l, k);
	    }
        printList(l);
    }
    //In ra
    printf("\nSau khi xoa:\n");
    printList(l);

    //Them phan tu
    rand = random(1, n - 1);
    printf("\nThem %d phan tu:\n", rand);
    for(i = 0; i < rand; ++i)
    {
        k = random(0, n);
        v = random(1, n);
        printf("\nVi tri them: %d.\nGia tri them: %d.\n", k, v);
        if (k == 0)
        {
		    l = addHead(l, v);	
	    } else if (k == n)
        {
		    l = addTail(l, v);
	    } else
        {
	    	l = addAt(l, k, v);
    	}
        printList(l);
    }
    // In ra
    printf("\nSau khi them:\n");
    printList(l); 

    // Tim phan tu
    k = random(0, n - 1);
    p = getNode(l, k);
    printf("\nGia tri phan tu o vi tri %d: %d\n", k + 1, p->value);
    return 0;
}
