#include<string.h>
#include<stdlib.h>
#include<stdio.h>

//Sua loi xau
int isWhite(char c) {
	return c == ' ' || c == '\t' || c == '\n'; //true neu c la cac ky tu sau
}

int speC(char c) { //special character
	return c == ':' || c == '[' || c == ']' || c == ';' || c == '/' || c == '.' 
	|| c == ',' || c == '!';
}

void fix(char s[]) {
	while(isWhite(s[0]) || speC(s[0])) {
		strcpy(&s[0], &s[1]);
	}
	for(int i = 0; i < strlen(s); i++) {
		if(isWhite(s[i]) && isWhite(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		} else if(isWhite(s[i]) && speC(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		} else if(speC(s[i]) && isWhite(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		} else if(speC(s[i]) && speC(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		}
	}
	while(isWhite(s[strlen(s) - 1]) || speC(s[strlen(s) - 1])) {
		strcpy(&s[strlen(s) - 1], &s[strlen(s)]);
	}
}

/*void res(char s[]) { //res - reset
	int len = strlen(s);
	for(int i = 0; i < len; i++) {
		if(isWhite(s[i]) && isWhite(s[i + 1])) {
			for(int j = i + 1; j < len; j++) {
				s[j] = s[j + 1];
			}
			i--;
			len--;
		} else if(isWhite(s[i]) && speC(s[i + 1])) {
			for(int j = i; j < len; j++) {
				s[j] = s[j + 1];
			}
			i--;
			len--;
		}
	}
} */

//typedef int ElmType;
typedef struct nodeType
{
    ElmType element;
    struct nodeType *left, *right;
} node_Type;

typedef struct nodeType *treetype;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void MakeNullTree(treetype *t)
{
    (*t) = NULL;
}

int EmptyTree(treetype t)
{
    return t == NULL;
}

treetype LeftChild(treetype n)
{
    if(n != NULL) return n->left;
    else return NULL;
}

treetype RightChild(treetype n)
{
    if(n != NULL) return n->right;
    else return NULL;
}

node_Type *create_node(ElmType NewData)

{
    node_Type *n;
    n = (node_Type *)malloc(sizeof(node_Type));
    if(n != NULL)
    {
        n->left = NULL;
        n->right = NULL;
        n->element = NewData;
    }
    return n;
}

int IsLeaf(treetype n)
{
    if(n != NULL)
    {
        return (LeftChild(n) == NULL) && (RightChild(n) == NULL);   
    }
    else return -1;
}

int nb_nodes(treetype t)
{
    if(EmptyTree(t)) return 0;
    else return 1 + nb_nodes(LeftChild(t)) + nb_nodes(RightChild(t));
}

treetype createfrom2(ElmType v, treetype l, treetype r)
{
    treetype n = (node_Type*)malloc(sizeof(node_Type));
    n->element = v;
    n->left = l;
    n->right = r;
    return n;
}

treetype Add_right(treetype *tree, ElmType NewData)
{
    node_Type *NewNode = create_node(NewData);
    if(NewNode == NULL) return NewNode;
    if(*tree == NULL)
    {
        *tree = NewNode;
    }
    else
    {
        node_Type *Rnode = *tree;
        while(Rnode->right != NULL)
        {
            Rnode = Rnode->right;
        }
        Rnode->right = NewNode;
    }
    return NewNode;
}

treetype Add_left(treetype *tree, ElmType NewData)
{
    node_Type *NewNode = create_node(NewData);
    if(NewNode == NULL) return NewNode;
    if(*tree == NULL)
    {
        *tree = NewNode;
    }
    else
    {
        node_Type *LNode = *tree;
        while(LNode->left != NULL)
        {
            LNode = LNode->left;
        }
        LNode->left = NewNode;
    }
    return NewNode;
}

/*treetype Search(char *x, treetype t)
{
    if(t == NULL) return NULL;
    else if(strcmp(t->element.freq, x) == 0) return t;
    else if(strcmp(t->element.freq, x) < 0) return Search(x, t->right);
    else return Search(x, t->left);
} */

void InsertNode(ElmType x, treetype *t)
{
    if(*t == NULL)
    {
        *t = (node_Type *)malloc(sizeof(node_Type));
        (*t)->element = x;
        (*t)->left = (*t)->right = NULL;
    }
    else if(x.freq < (*t)->element.freq) InsertNode(x, &(*t)->left);
    else if(x.freq > (*t)->element.freq) InsertNode(x, &(*t)->right);
    else
    {
        if(strcmp(x.value, (*t)->element.value) < 0) InsertNode(x, &(*t)->left);
        else if(strcmp(x.value, (*t)->element.value) > 0) InsertNode(x, &(*t)->right);
    }
}

int nb_leaf(treetype t)
{
    if(EmptyTree(t)) return 0;
    if(IsLeaf(t)) return 1;
    return nb_leaf(t->left) + nb_leaf(t->right);
}

int treeLv(treetype t)
{
    if(EmptyTree(t)) return -1;
    if(IsLeaf(t)) return 0;
    return 1 + max(treeLv(t->left), treeLv(t->right));
}

/*void Preorder(treetype t)
{
    if(t != NULL)
    {
        printf("%d "), t->element;
        Preorder(t->left);
        Preorder(t->right);
    }
}

void Inorder(treetype t)
{
    if(t != NULL)
    {
        Inorder(t->left);
        printf("%d ", t->element);
        Inorder(t->right);
    }
}

void Postorder(treetype t)
{
    if(t != NULL)
    {
        Postorder(t->left);
        Postorder(t->right);
        printf("%d ", t->element);
    }
} */

/*ElmType DeleteMin(treetype *t)
{
    ElmType k;
    if((*t)->left == NULL)
    {
        k = (*t)->element;
        (*t) = (*t)->right;
        return k;
    }
    else return DeleteMin(&(*t)->left);
}

void DeleteNode(char *x, treetype *t)
{
    if((*t) != NULL)
    {
        if(strcmp(x, (*t)->element.freq) < 0) DeleteNode(x, &(*t)->left);
        else if(strcmp(x, (*t)->element.freq) > 0) DeleteNode(x, &(*t)->right);
        else if(IsLeaf((*t)))
        {
            (*t) = NULL;
        }
        else if((*t)->left == NULL) (*t) = (*t)->right;
            
        else if((*t)->right == NULL) (*t) = (*t)->left;
        else (*t)->element = DeleteMin(&(*t)->right);
    }
} */

void FreeTree(treetype *t)
{
    if(*t != NULL)
    {
        FreeTree(&(*t)->left);
        FreeTree(&(*t)->right);
        free(*t);
    }
}