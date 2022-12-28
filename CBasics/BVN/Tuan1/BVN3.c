#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
//#define MAX 101
//const int MAX = 101;

int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

/*void Input(char s[MAX][MAX], int n)
{
	int i;
    for(i = 0; i < n; ++i)
    {
        fflush(stdin);
        gets(s[i]);
    }
} */

/*
void print(char s[MAX][MAX], int n)
{
	int i;
	for(i = 0; i < n; ++i)
	{
		printf("'%s'\n", s[i]);
	}
} 
*/

//n ^ m

long long Mult(int n, int m)
{
	if(m == 0) return 1;
	return n * Mult(n, m - 1);
}

int main()
{
    srand((int)time(0));

    int n, i;
    printf("Nhap so tu cho cac loai: ");
    fflush(stdin);
    scanf("%d", &n);
    printf("\n");

    char art[50][50], noun[50][50], verb[50][50], prep[50][50];
	
	printf("Nhap cac article: \n");
	for(i = 0; i < n; ++i)
    {
        fflush(stdin);
        gets(art[i]);
    }
	printf("\n");
	
	printf("Nhap cac noun: \n");
	for(i = 0; i < n; ++i)
    {
        fflush(stdin);
        gets(noun[i]);
    }
	printf("\n");
	
	printf("Nhap cac verb: \n");
	for(i = 0; i < n; ++i)
    {
        fflush(stdin);
        gets(verb[i]);
    }
    printf("\n");
    
    printf("Nhap cac prep: \n");
    for(i = 0; i < n; ++i)
    {
        fflush(stdin);
        gets(prep[i]);
    }
    printf("\n");
    
	/*
	//nhap du lieu
	printf("Nhap cac article: \n");
    Input(art, n);
    printf("\n");
    
    printf("Nhap cac noun: \n");
    Input(noun, n);
    printf("\n");
    
    printf("Nhap cac verb: \n");
    Input(verb, n);
    printf("\n");
    
    printf("Nhap cac prep: \n");
    Input(prep, n);
    printf("\n"); 
    */
    
    /*
    //kiem tra
    printf("Cac xau da nhap: \n\n");
    
    printf("Article: \n");
    print(art, n);
    printf("\n");
    
    printf("Noun: \n");
    print(noun, n);
    printf("\n");
    
    printf("Verb: \n");
    print(verb, n);
    printf("\n");
    
    printf("Preposition: \n");
    print(prep, n);
    printf("\n");
    */
	
	/*
    char art[5][10] = {"the", "a", "one", "some", "any"};
    char noun[5][10] = {"boy", "girl", "dog", "town", "car"};
    char verb[5][10] = {"drove", "jumped", "ran", "walked", "skipped"};
    char prep[5][10] = {"to", "from", "over", "under", "on"}; 
    */
    char s[1000];
	
	
	//long long LIMIT = Mult(5, 5);
	long long LIMIT = Mult(n, 5);
	printf("LIMIT = %d\n\n", LIMIT);
	
	
	/*
    for(i = 0; i < 10; ++i)
    {
		strcpy(s, "");
        strcat(s, art[random(0, 4)]);
        strcat(s, " ");
        strcat(s, noun[random(0, 4)]);
        strcat(s, " ");
        strcat(s, verb[random(0, 4)]);
        strcat(s, " ");
        strcat(s, prep[random(0, 4)]);
        strcat(s, " ");
        strcat(s, art[random(0, 4)]);
        strcat(s, " ");
        strcat(s, noun[random(0, 4)]);
        strcat(s, ".");
        if(s[0] >= 'a' && s[0] <= 'z') s[0] -= 32;
        printf("%s\n", s);
    } 
    */
    
    
    int num = n - 1;
    //chi so ky tu cuoi
    printf("Chi so ky tu cuoi: %d\n\n", num);
    printf("Cac xau co duoc: \n\n");
    
    /*
	for(i = 0; i < LIMIT; ++i)
    {
	}
	*/
    
    for(i = 0; i < LIMIT; ++i)
    {
		strcpy(s, "");
        strcat(s, art[random(0, num)]);
        strcat(s, " ");
        strcat(s, noun[random(0, num)]);
        strcat(s, " ");
        strcat(s, verb[random(0, num)]);
        strcat(s, " ");
        strcat(s, prep[random(0, num)]);
        strcat(s, " ");
        strcat(s, art[random(0, num)]);
        strcat(s, " ");
        strcat(s, noun[random(0, num)]);
        strcat(s, ".");
        if(s[0] >= 'a' && s[0] <= 'z') s[0] -= 32;
        printf("%s\n", s);
    } 
	
    return 0;
}
