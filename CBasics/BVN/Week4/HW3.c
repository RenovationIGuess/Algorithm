#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#define MAX 1001

void copy_by_line(FILE *fin, FILE *fout)
{
    //char *s = (char *)malloc(sizeof(char) * MAX);
    char s[MAX];
    while((fgets(s, MAX, fin)) != NULL)
    {
        //fprintf(fout, "%s", s);
        printf("%s", s);
        fputs(s, fout);
    }
    printf("\n");
    //free(s);
}

void copy_by_char(FILE *fin, FILE *fout)
{
    char c;
    while((c = fgetc(fin)) != EOF)
    {
        //fprintf(fout, "%c", c);
        printf("%c", c);
        fputc(c, fout);
    }
    printf("\n");
}

void copy_by_block(FILE *fin, FILE *fout)
{
    int optional_size;
    printf("Enter optional size: ");
    fflush(stdin);
    scanf("%d", &optional_size);
    char *s = (char *)malloc((optional_size + 5) * sizeof(char));
    //char s[MAX];
    int num;

    while(!feof(fin))
    {
        num = fread(s, sizeof(char), optional_size, fin);
        s[num * sizeof(char)] = '\0';
        printf("%s", s);
        fwrite(s, sizeof(char), optional_size, fout);
    }

    free(s);
    printf("\n");
}

void Menu(FILE *fin, FILE *fout)
{
    printf("\nCopy Menu: \n\n");
    char c; //lua chon
    int selection; // chuc nang
    
    clock_t t;
    do
    {
        double time_taken;
        printf("1. Copy by character.\n2. Copy by line.\n3. Copy by block - optional size.\n\n");
        printf("Enter your option: ");
        fflush(stdin);
        scanf("%d", &selection);
        switch(selection)
        {
            case 1:
                t = clock();
                printf("\nProcessing...\n");
                copy_by_char(fin, fout);
                t = clock() - t;
                time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
                printf("\nCopy by character took %f seconds to execute.\n", time_taken);
                break;
            case 2:
                t = clock();
                printf("\nProcessing...\n");
                copy_by_line(fin, fout);
                t = clock() - t;
                time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
                printf("\nCopy by line took %f seconds to execute.\n", time_taken);
                break;
            case 3:
                t = clock();
                printf("\nProcessing...\n");
                copy_by_block(fin, fout);
                t = clock() - t;
                time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
                printf("\nCopy by block took %f seconds to execute.\n", time_taken);
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
        fseek(fin, 0, SEEK_SET);                                             
    } while(c == 'y');
}

int main(int argc, char *argv[])
{
    FILE *f1, *f2;
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
        Menu(f1, f2);
        printf("Thank you for using!\n");
        fclose(f1);
        fclose(f2);
        return 0;
    }
}