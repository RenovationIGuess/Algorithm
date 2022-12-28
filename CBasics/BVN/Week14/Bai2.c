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
    float point;
};

typedef struct student ElmType;

#include "B1.h"

void Display(treetype t)
{
    if(t != NULL)
    {
        Display(t->left);
        printf("%-35s%-10.2f\n", t->element.name, t->element.point);
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
    fseek(f, 0, SEEK_SET);

    ElmType *cop = (ElmType *)malloc(MAX * sizeof(ElmType));
    int i = 0;
    
    while(fscanf(f, "%s%f", cop[i].name, &cop[i].point) != EOF)
    {
        //printf("%-5d%-35s%-10.2f\n", i, cop[i].name, cop[i].point);
        InsertNode(cop[i], t);
        i++;
    }

    ElmType x;

    char opt;
    int option;
    do
    {
        printf("\nStudent list:\n");
        printf("\n%-35s%-10s\n\n", "Ho va Ten", "Diem");
        Display(*t);

        printf("\nEnter key's name: ");
        fflush(stdin); gets(x.name);
        /*while(Search(x.name, *t) == NULL)
        {
            printf("\nNon-existed! Enter again: ");
            fflush(stdin); gets(x.name);
        } */
        printf("\nEnter key's point: ");
        fflush(stdin); scanf("%f", &x.point);

        printf("\nChoose one below:\n");
        do
        {
            printf("\n1. Lower Than Key\n2. Higher Than Key\n3. Quit\n");
            printf("\nEnter your option: "); 
            fflush(stdin); scanf("%d", &option);
            switch(option)
            {
                case 1:
                    printf("\n%-35s%-10s\n\n", "Ho va Ten", "Diem");
                    printf("\nNumber of students: %d\n", LowerThankey(x, *t));
                    break;
                case 2:
                    printf("\n%-35s%-10s\n\n", "Ho va Ten", "Diem");
                    printf("\nNumber of students: %d\n", HigherThankey(x, *t));
                    break;
                case 3:
                    break;
            }
        } while (option != 3);
        
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

int main(int argc, char *argv[])
{
    treetype t;
    MakeNullTree(&t);
    CreateTree(argv[1], &t);
    return 0;
}