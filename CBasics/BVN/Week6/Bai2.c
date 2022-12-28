#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 1001

int Find(char *s, int p)
{
    if(isupper(s[p])) return p;
    if(p == strlen(s) - 1) return -1;
    Find(s, p + 1);
}

int main()
{
    char *s = (char *)malloc(MAX * sizeof(char));
    printf("\nEnter the string: ");
    fflush(stdin); gets(s);
    int res = Find(s, 0);
    if(res != -1)
        printf("\nVi tri in hoa dau tien: %d - ky tu: %c.\n\n", res + 1, s[res]);
    else printf("\nKhong co ky tu in hoa trong xau.\n\n");
    free(s);
    return 0;
}