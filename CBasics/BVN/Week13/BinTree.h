#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define COUNT 10

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

treetype Search(char *x, treetype t)
{
    if(t == NULL) return NULL;
    else if(strcmp(t->element.model, x) == 0) return t;
    else if(strcmp(t->element.model, x) < 0) return Search(x, t->right);
    else return Search(x, t->left);
}

void InsertNode(ElmType x, treetype *t)
{
    if(*t == NULL)
    {
        *t = (node_Type *)malloc(sizeof(node_Type));
        (*t)->element = x;
        (*t)->left = (*t)->right = NULL;
    }
    else if(strcmp(x.model, (*t)->element.model) < 0) InsertNode(x, &(*t)->left);
    else if(strcmp(x.model, (*t)->element.model) > 0) InsertNode(x, &(*t)->right);
    //else return t;
}

int nb_leaf(treetype t)
{
    if(EmptyTree(t)) return 0;
    if(IsLeaf(t)) return 1;
    return nb_leaf(t->left) + nb_leaf(t->right);
}

int nb_internal(treetype t)
{
    if(EmptyTree(t)) return 0;
    if(IsLeaf(t)) return 0;
    return 1 + nb_internal(t->left) + nb_internal(t->right);
}

int nb_right(treetype t)
{
    if(EmptyTree(t)) return 0;
    if(t->right != NULL)
    {
        return 1 + nb_right(t->right) + nb_right(t->left);
    }
    else
    {
        return nb_right(t->left);
    } 
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

int checkAVL(treetype t)
{
    if(t == NULL) return 1;
    if(abs(treeLv(t->left) - treeLv(t->right)) > 1) return 0;
    return checkAVL(t->left) && checkAVL(t->right);
}

node_Type *TurnRight(node_Type *a)
{
    node_Type *b = a->left;
    node_Type *d = b->right;
    a->left = d;
    b->right = a;
    return b;
}

node_Type *TurnLeft(node_Type *a)
{
    node_Type *b = a->right;
    node_Type *d = b->left;
    a->right = d;
    b->left = a;
    return b;
}

void UpdateAVL(treetype *t)
{
    if(abs(treeLv((*t)->left) - treeLv((*t)->right)) > 1)
    {
        
    }
}

ElmType DeleteMin(treetype *t)
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
        if(strcmp(x, (*t)->element.model) < 0) DeleteNode(x, &(*t)->left);
        else if(strcmp(x, (*t)->element.model) > 0) DeleteNode(x, &(*t)->right);
        else if(IsLeaf((*t)))
        {
            (*t) = NULL;
        }
        else if((*t)->left == NULL) (*t) = (*t)->right;
            
        else if((*t)->right == NULL) (*t) = (*t)->left;
        else (*t)->element = DeleteMin(&(*t)->right);
    }
} 

void ReadNode(ElmType *a)
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

void PrettyPrint(treetype t, int space)
{
    if(t == NULL) return;
    space += COUNT;
    PrettyPrint(t->right, space);
    printf("\n");
    int i;
    for(i = COUNT; i < space; ++i)
    {
        printf(" ");
    }
    printf("%d\n", t->element);
    PrettyPrint(t->left, space);
}

/*void PrettyPrint(treetype t, char *prefix)
{
    char *prefixend = prefix + strlen(prefix);
    if(t != NULL)
    {
        printf("%04d", t->element);
        if(t->left != NULL)
        {
            if(t->right == NULL)
            {
                printf("\304");
                strcat(prefix, "     ");
            }
            else 
            {
                printf("\302");
                strcat(prefix, "\263    ");
            }
            PrettyPrint(t->left, prefix);
            *prefixend = '\0';
            if(t->right != NULL) 
            {
                if(t->left != NULL)
                {
                    printf("\n%s, prefix");
                    printf("\300");
                }
            }
            else printf("\304");
            strcat(prefix, "    ");
            PrettyPrint(t->right, prefix);
        }
    }
}*/

void FreeTree(treetype t)
{
    if(t != NULL)
    {
        FreeTree(t->left);
        FreeTree(t->right);
        free(t);
    }
}