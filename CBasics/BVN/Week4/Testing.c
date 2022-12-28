/*#include<stdlib.h>
#include<stdio.h>

int main()
{
    FILE *f, *f1;
    char s[150];
    f = fopen("Hello.txt", "r");
    f1 = fopen("Hi.txt", "w");
    char c;
    while((c = fgetc(f)) != EOF)
    {
        fputc(c, f1);
    }
    fseek(f, 0, SEEK_SET);
    while((fgets(s, 100, f)) != NULL)
    {
        fputs(s, f1);
    }
    return 0;
} */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#define MAX 1001

FILE *f1, *f2;

void copy_by_line()
{
    //char *s = (char *)malloc(sizeof(char) * MAX);
    char s[MAX];
    while((fgets(s, MAX, f1)) != NULL)
    {
        //fprintf(fout, "%s", s);
        printf("%s", s);
        fputs(s, f2);
    }
    printf("\n");
    //free(s);
}

void copy_by_char()
{
    char c;
    while((c = fgetc(f1)) != EOF)
    {
        //fprintf(fout, "%c", c);
        printf("%c", c);
        fputc(c, f2);
    }
    printf("\n");
}

void copy_by_block()
{
    int optional_size;
    //char *s = (char *)malloc(MAX * sizeof(char));
    char s[MAX];
    printf("Enter optional size: ");
    fflush(stdin);
    scanf("%d", &optional_size);
    int num;
    while(fread(s, sizeof(char), optional_size, f1))
    {
        printf("%s", s);
        fwrite(s, sizeof(char), optional_size, f2);
    }
    //free(s);
    printf("\n");
}

void Menu()
{
    printf("\nCopy Menu: \n\n");
    char c; //lua chon
    do
    {
        int selection; // chuc nang
        clock_t t;
        double time_taken;
        fseek(f1, 0, SEEK_SET);  
        printf("1. Copy by character.\n2. Copy by line.\n3. Copy by block - optional size.\n\n");
        printf("Enter your option: ");
        fflush(stdin);
        scanf("%d", &selection);
        switch(selection)
        {
            case 1:
                t = clock();
                printf("\nProcessing...\n");
                copy_by_char();
                t = clock() - t;
                time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
                printf("Copy by character took %f seconds to execute.\n", time_taken);
                break;
            case 2:
                t = clock();
                printf("\nProcessing...\n");
                copy_by_line();
                t = clock() - t;
                time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
                printf("Copy by line took %f seconds to execute.\n", time_taken);
                break;
            case 3:
                t = clock();
                printf("\nProcessing...\n");
                copy_by_block();
                t = clock() - t;
                time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
                printf("Copy by block took %f seconds to execute.\n", time_taken);
                break;
            default:
                printf("\nInvalid!\n");
                break;
        }        
        printf("\nBan co muon tiep tuc [y/n]? ");
        fflush(stdin);
        scanf("%c", &c);
        printf("\n");
        // dinh vi lai con tro file                                           
    } while(c == 'y');
}

int main(int argc, char *argv[])
{
    
    if((f1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open %s.\n", argv[1]);
        return 1;
    }
    else if((f2 = fopen(argv[2], "w")) == NULL)
    {
        printf("Cannot open %s.\n", argv[2]);
        return 1;
    }
    else
    {
        Menu();
        printf("Thank you for using!\n");
        fclose(f1);
        fclose(f2);
        return 0;
    }
}