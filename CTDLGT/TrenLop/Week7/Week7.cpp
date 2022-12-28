#include<iostream>
#include<ctime>
#include<cstdlib>
//#include<time.h>
#define MAX 256

using namespace std;

struct node
{
    int data; 
    node *left;
    node *right;
};

int stk[MAX], top;

//insert
node *insert(node *t, int x)
{
    if(t == NULL)
    {
        node *tmp = new node;
        tmp->data = x;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;
    }
    else
    {
        if(x == t->data) return NULL;
        if(x < t->data)
        {
            t->left = insert(t->left, x);
        }
        //else if(x > t->data)
        else
        {
            t->right = insert(t->right, x);
        }
    }
}

//kiem tra la
bool isLeafNode(node *l)
{
    return (l->left == NULL && l->right == NULL);
}

//trai nhat
node *LeftMostChild(node *t)
{
    node *tmp = t;
    while(tmp->left != NULL)
    {
        tmp = tmp->left;
    }
    return tmp;
}

//dem so la
int cntLeaf(node *t)
{
    if(t == NULL) return 0;
    if(isLeafNode(t)) return 1;
    return cntLeaf(t->left) + cntLeaf(t->right);
}

//dem do sau
int treeLevel(node *t)
{
    if(t == NULL) return -1;
    if(isLeafNode(t)) return 0;
    return 1 + max(treeLevel(t->left), treeLevel(t->right));
}

//tim node
node *find(node *t, int v)
{
    if(t == NULL) return NULL;
    if(t->data == v) return t;
    if (t->data > v)
        return find(t->left, v);
    //if(t->data < v) 
    return find(t->right, v);
    //return NULL;
}

//tim node cha
node *parent(node *t, int r)
{
    if(t == NULL) return NULL;
    if(t->left->data == r || t->right->data == r) return t;
    //else if(t->right->data == r) return t;
    if(r < t->data) return parent(t->left, r);
    //else if(r > t->data) 
    return parent(t->right, r);
}

void DestroyTree(node *t)
{
    if(t)
    {
        DestroyTree(t->left);
        DestroyTree(t->right);
        delete t;
    }
}

//FaR1 la truong hop 1 cho truong hop node can xoa co 2 node con
//nut the co data min cua cay con ben phai r
void FaR1(node *t, node *r)
{
    //neu chua phai trai nhat cua cay t dang xet <=> khac NULL
    if(t->left)
    {
        FaR1(t->left, r);
    }
    else
    {
        r->data = t->data;
        r = t;
        t = t->right;
    }
}

//truong hop 2 nut the la nut co data max cua cay ben trai r
void FaR2(node *t, node *r)
{
    if(t->right)
    {
        FaR2(t->right, r);
    }
    else
    {
        r->data = t->data;
        r = t;
        t = t->left;
    }
}

//xoa phan tu khoi cay
/*node *remove(node *t, int v)
{
    if(t)
    {
        if(v > t->data)
            remove(t->right, v);
        else if(v < t->data)
            remove(t->left, v);
        //khi da tro den node can xoa
        else
        {
            node *tmp = t;
            if(isLeafNode(t))
            {
                t = NULL;
            }
            else if(!t->left)
                t = t->right;
            else if(!t->right)
                t = t->left;
            else
            {
                FaR1(t->right, tmp);
                //FaR2(t->left, tmp);
            }
            delete t;
        }
        return t;
    }
} */

//tim node co gia tri lon nhat
node *FindMax(node *t)
{
	node *p = t;
    while(p->right != NULL) p = p->right;
    return p;
}

//tim node co gia tri nho nhat
node *FindMin(node *t)
{
	node *p = t;
    while(p->left != NULL) p = p->left;
    return p;
}

node *del(node *t, int key)
{
	if(t == NULL) return t;
	else if(key < t->data) t->left = del(t->left, key);
	else if(key > t->data) t->right = del(t->right, key);
	else
	{
		if(t->left == NULL && t->right == NULL)
		{
			delete t;
			t = NULL;
		}
		else if (t->left == NULL)
		{
			node *tmp = t;
			t = t->right;
			delete tmp;
		}
		else if (t->right == NULL)
		{
			node *tmp = t;
			t = t->left;
			delete tmp;
		}
		else
		{
			node *tmp = FindMax(t->left);
			t->data = tmp->data;
			t->left = del(t->left, tmp->data);
			/*
			node *tmp = FindMin(t->right);
			t->data = tmp->data;
			t->right = del(t->right, tmp->data);
			*/
		}
	}
	return t;
} 

int cntNode(node *t)
{
	if(t == NULL) return 0;
	return cntNode(t->left) + cntNode(t->right) + 1;
}

//tien tien to
void TienTT(node *t)
{
    if(t != NULL)
    {
        cout << t->data << " ";
        TienTT(t->left);
        TienTT(t->right);
    }
}

//NLR
void TienTu(node *t)
{
    node *p;
    while(t)
    {
        if(t->left == NULL)
        {
            cout << t->data << " ";
            t = t->right;
        }
        else
        {
            p = t->left;
            while(p->right && p->right != t)
            {
                p = p->right;
            }
            if(p->right == NULL)
            {
                p->right = t;
                cout << t->data << " ";
                t = t->left;
            }
            else
            {
                p->right = NULL;
                
                t = t->right;
            }
        }
    }
    cout << endl;
} 

//trung tien to
void TrungTT(node *t)
{
    if(t != NULL)
    {
        TrungTT(t->left);
        cout << t->data << " ";
        TrungTT(t->right);
    }
}

//trung tu
void TrungTu(node *t)
{
    node *p;
    while(t)
    {
        if(t->left == NULL)
        {
            cout << t->data << " ";
            t = t->right;
        }
        else
        {
            p = t->left;
            while(p->right && p->right != t)
            {
                p = p->right;
            }
            if(p->right == NULL)
            {
                p->right = t;
                t = t->left;
            }
            else
            {
                p->right = NULL;
                cout << t->data << " ";
                t = t->right;
            }
        }
    }
    cout << endl;
}

//hau tien to
void HauTT(node *t)
{
    if(t != NULL)
    {
        HauTT(t->left);
        HauTT(t->right);
        cout << t->data << " ";
    }
}

node *pop(node *p)
{
	int ch;
	ch = stk[top - 1];
	if (p->data == ch)
	{
		top--;
		return p;
	}
	if (p->data > ch)
		pop(p->left);
	else
		pop(p->right);
}

//Left -> Right -> Node: LRN
void HauTu(node *root) 
{
	node *p;
	p = root;
	top = 0;
 
	while (1)
	{
		while (p != NULL)
		{
			stk[top] = p->data;
			top++;
			if (p->right != NULL)
				stk[top++] = -p->right->data;
			p = p->left;
		}
		
		while (stk[top - 1] > 0 || top == 0)
		{
			if (top == 0)
				return;
			
			printf("%d ", stk[top - 1]);
			p = pop(root);
		}
		
		if (stk[top - 1] < 0)
		{
			stk[top - 1] = -stk[top - 1];
			p = pop(root);
		}
	}
}

bool checkAvl(node *t)
{
	if(t == NULL) return true;
	if(abs(treeLevel(t->left) - treeLevel(t->right)) > 1) return false;
	return checkAvl(t->left) && checkAvl(t->right);
}

node *TurnLeft(node *a)
{
    node *b = a->right;
    node *c = b->left;
    a->right = c;
    b->left = a;
    return b;
}

node *TurnRight(node *a)
{
    node *b = a->left;
    node *d = b->right;
    a->left = d;
    b->right = a;
    return b;
}

node *AVL(node *t)
{
    if(abs(treeLevel(t->left) - treeLevel(t->right)) > 1)
    {
        if(treeLevel(t->left) > treeLevel(t->right))
        {
            node *p = t->left;
            if(treeLevel(p->left) >= treeLevel(p->right))
            {
                t = TurnRight(t);
            }
            else 
            {
                t->left = TurnLeft(t->left);
                t = TurnRight(t);
            }
        }
        else
        {
            node *p = t->right;
            if(treeLevel(p->right) >= treeLevel(p->left))
            {
                t = TurnLeft(t);
            }
            else
            {
                t->right = TurnRight(t->right);
                t = TurnLeft(t);
            }
        }
    }
    if(t->left != NULL) t->left = AVL(t->left);
    if(t->right != NULL) t->right = AVL(t->right);
    return t;
}

int main()
{
	srand((int)time(0));
    int n, x;
    cout << "\nNhap so phan tu (n): ";
    cin >> n;
    node *t = NULL;
    for(int i = 1; i <= n; ++i)
    {
    	cout << "\nNhap gia tri phan tu " << i << ": ";
        cin >> x;
        t = insert(t, x);
    }
    /*
    cout << "\nDuyet Tien Tu:\n";
    TienTu(t);
    cout << "\nDuyet Trung Tu:\n";
    TrungTu(t);
    cout << "\nDuyet Hau Tu:\n";
    HauTu(t);
    cout << endl; */
    return 0;
}

/*void HauTu(node *t)
{
	node *p;
	node *root = t;
	//Right Most Child
	node *rmc = FindMax(t);
    while(t)
    {
        if(t->left == NULL)
        {
            cout << t->data << " ";
            t = t->right;
        }
        else
        {
            p = t->left;
            while(p->right && p->right != t)
            {
                p = p->right;
            } 
            if(p->right == NULL)
            {
            	
            	if(p == rmc)
				{
					p->right = root;
					t = t->left;
				}
            	else if(isLeafNode(p) && p->data > t->left->data)
            	{
            		p->right = t->left;
                	t = t->left;
                	
				}
				else if(isLeafNode(p) && p->data < t->data)
				{
					p->right = t;
					t = t->left;
				}
                else if(!isLeafNode(p))
                {
                	p->right = t->right;
                	t = t->left;
				}
				
            }
            else
            {
                p->right = NULL;
                cout << t->data << " ";
                t = t->right;
            }
            
        }
    }
    cout << endl;
} */

/*  cout << "\nSo la trong BST: " << cntLeaf(t) << endl;
    cout << "\nDo sau: " << treeLevel(t) + 1 << endl;
    cout << "\nCac node co trong BST hien gio:\n";
    TrungTu(t);
    //TrungTT(t);
    cout << "\nNode co gia tri max: " << FindMax(t)->data << endl;
    cout << "\nNode co gia tri min: " << FindMin(t)->data << endl;
    
    int fi;
    cout << "\nNhap gia tri node muon tim: ";
    cin >> fi;
	cout << "\nNode da tim duoc: " << find(t, fi)->data << endl;
	cout << "\nNode cha cua node muon tim: " << parent(t, fi)->data << endl;
    int val;
    cout << "\nNhap node muon xoa: ";
    cin >> val;
    //t = remove(t, val);
    t = del(t, val);
    cout << "\nBST sau khi xoa:\n";
    TrungTu(t); */
