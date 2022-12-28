#include "BTree.h"

int main()
{
    treetype t = NULL;
    int n;
    printf("\nEnter number of nodes: ");
    fflush(stdin); scanf("%d", &n);
    int i, x;
    for(i = 0; i < n; ++i)
    {
        printf("\nEnter element %d: ", i + 1);
        fflush(stdin); scanf("%d", &x);
        InsertNode(x, &t);
    }
    printf("\nNumber of successful inserted node: %d\n", nb_nodes(t));
    //Search(x, t);

    PrettyPrint(t, 0);
    return 0;
}