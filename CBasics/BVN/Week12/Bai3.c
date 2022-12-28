#include "BTree.h"

void Menu()
{
    char c;
    do
    {
        int n;
        treetype t;
        MakeNullTree(&t);
        printf("\nEnter number of tree node: ");
        fflush(stdin); scanf("%d", &n);
        int i, value;
        for(i = 0; i < n; ++i)
        {  
            printf("\nNode %d: ", i + 1);
            fflush(stdin); scanf("%d", &value);
            InsertNode(value, &t);
        }
        printf("\nCreate tree success!\n");
        int opt, res;
        do
        {
            printf("\n1. Height of the tree\n2. Number of leaf\n3. Number of internal nodes\n4. Number of right children\n5. Exit\n");
            printf("\nEnter your option: ");
            fflush(stdin); scanf("%d", &opt);
            switch(opt)
            {
                case 1:
                    printf("\nThe height of the tree: %d\n", treeLv(t));
                    break;
                case 2:
                    printf("\nNumber of leafs: %d\n", nb_leaf(t));
                    break;
                case 3: 
                    printf("\nNumber of internal nodes: %d\n", nb_internal(t));
                    break;
                case 4:
                    printf("\nNumber of right children: %d\n", nb_right(t));
                    break;
                case 5:
                    printf("\nThank you!\n");
                    break;
                default:
                    printf("\nInvalid!\n");
                    break;
            }
        } while(opt != 5);

        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &c);
        while(c != 'y' && c != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &c);
        }
    } while (c == 'y');
}

int main()
{
    Menu();
    return 0;
}