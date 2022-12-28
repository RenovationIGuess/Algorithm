#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define MAX 256

int stu_num;
FILE *f;

int isWhite(char c) {
	return c == ' ' || c == '\t' || c == '\n'; 
	//true neu c la cac ky tu sau
}
int speC(char c) { //special character
	return c == ':' || c == '[' || c == ']' || c == ';' || c == '/' || c == '.' 
	|| c == ',' || c == '!';
}
void fix(char *s) {
	//xoa dau
	while(isWhite(s[0]) || speC(s[0])) {
		strcpy(&s[0], &s[1]);
	}
	
	//xoa giua
	for(int i = 0; i < strlen(s); ++i) {
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
	
	//cho an toan :v
	//chuyen thanh ' '
	for(int i = 0; i < strlen(s); ++i)
	{
		if(isWhite(s[i]) || speC(s[i]) && s[i] != ' ')
			s[i] = ' ';
	} 
	 
	//xoa cuoi
	while(isWhite(s[strlen(s) - 1]) || speC(s[strlen(s) - 1])) {
		strcpy(&s[strlen(s) - 1], &s[strlen(s)]);
	}
	
	//in hoa ky tu dau
	if(!isupper(s[0])) s[0] -= 32;
	for(int i = 1; i < strlen(s); ++i)
	{
		if(s[i] == ' ')
			if(!isupper(s[i + 1]))
				s[i + 1] -= 32;
	}
}

struct student
{
    char name[MAX];
};

typedef struct student ElmType;

#include "BTree2.h"

void Display(treetype t)
{
    if(t != NULL)
    {
        Display(t->left);
        printf("%s\n", t->element.name);
        Display(t->right);
    }
}

void CreateTree(char *s, treetype *t)
{
    if((f = fopen(s, "r")) == NULL)
    {
        printf("\nCannot open file %s!\n", s);
        exit(1);
    }
    ElmType *cop = (ElmType *)malloc(MAX * sizeof(ElmType));
    int i = 0, j;
    char c;
    do
    {
        j = 0;
        while((c = fgetc(f)) != '\n' && c != EOF)
        {
            cop[i].name[j] = c;
            j++;
        }
        cop[i].name[j] = '\0';
        InsertNode(cop[i], t);
        i++; 
        if(feof(f)) break;
    } while(1);

    char *find = (char *)malloc(MAX * sizeof(char));
    char opt;
    do
    {
        printf("\nStudent list:\n");
        Display(*t);
        printf("\nEnter name to search: ");
        fflush(stdin); gets(find);
        treetype res = Search(find, *t);
        if(res != NULL)
        {
            printf("%s\n", res->element.name);        
        }
        else printf("\nNot found!\n");
        printf("\nDo you want to continue [y/n]: ");
        fflush(stdin); scanf("%c", &opt);
        while(opt != 'y' && opt != 'n')
        {
            printf("\nInvalid! Enter again: ");
            fflush(stdin); scanf("%c", &opt);
        }
    } while (opt == 'y');
    
    fclose(f);
    free(s);
}

typedef struct nodeType *treetype;

int main(int argc, char *argv[])
{
    treetype t;
    MakeNullTree(&t);
    CreateTree(argv[1], &t);
    return 0;
}