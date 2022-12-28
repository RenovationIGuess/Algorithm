#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 501

//dem so bytes
long long ByteNum(FILE *f)
{
    fseek(f, 0, SEEK_SET);
    char s[MAX];
    long long num = 0;
    while((fgets(s, MAX, f)) != NULL)
    {
        num += strlen(s);
    }
    return num;
}

//dem so dong
long long LineNum(FILE *f)
{
    fseek(f, 0, SEEK_SET);
    char s[MAX];
    long long num = 0;
    while((fgets(s, MAX, f)) != NULL)
    {
        num++;
    }
    return num;
}

void Read2(FILE *f, int line, char **a, int size)
{
    fseek(f, 0, SEEK_SET);

    //b - begin, e - end
    int b, e, i;

    fseek(f, 0, SEEK_SET);

    printf("\nEnter begin: "); fflush(stdin); scanf("%d", &b);
    while(b <= 0)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin);
        scanf("%d", &b);
    }

    printf("\nEnter end: "); fflush(stdin); scanf("%d", &e);
    while(e <= b || e > line)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin);
        scanf("%d", &e);
    }
    
    //dem so byte - cnt1 -> dinh vi con tro file 
    //cnt2 - dem so byte tu b -> e
    //e - b + 1 la so dong
    long cnt1 = 0, cnt2 = 0;
    //tim den vi tri b - 1
    for(i = 0; i < b - 1; ++i)
    {
        cnt1 += strlen(a[i]);
    }

    for(i = b - 1; i < e; ++i)
    {
        //printf("%s", a[i]);
        cnt2 += strlen(a[i]);
    }

    char **c = (char **)malloc(sizeof(char *) * size);
    for(i = 0; i < line; ++i)
    {
        c[i] = (char *)malloc(MAX * sizeof(char));
    }

    
    for(i = 0; i < line; ++i)
    {
        //printf("\nftell = %d.\n", ftell(f));
        int ans = fread(c[i], sizeof(char), MAX, f);
        c[i][ans * sizeof(char)] = '\0';
        //printf("%s", c[i]);
    }
    printf("\nResult:\n\n");

    for(int i = b - 1; i < e; ++i)
    {
        printf("%d - %s", i + 1, c[i]);
    }

    for(i = 0; i < line; ++i)
    {
        free(c[i]);
    }
    free(c);
}

void Read3(FILE *f, char **a, long long end)
{
    //b - begin, e - end
    int b, e, i;

    fseek(f, 0, SEEK_SET);

    printf("\nEnter begin: "); fflush(stdin); scanf("%d", &b);
    while(b <= 0)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin);
        scanf("%d", &b);
    }

    printf("\nEnter end: "); fflush(stdin); scanf("%d", &e);
    while(e <= b || e > end)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin);
        scanf("%d", &e);
    }
    
    //dem so byte - cnt1 -> dinh vi con tro file 
    //cnt2 - dem so byte tu b -> e
    //e - b + 1 la so dong
    long cnt1 = 0, cnt2 = 0;
    //tim den vi tri b - 1
    for(i = 0; i < b - 1; ++i)
    {
        cnt1 += strlen(a[i]);
    }
    //printf("\nb position's bytes: %d", cnt1);

    for(i = b - 1; i < e; ++i)
    {
        //printf("%s", a[i]);
        cnt2 += strlen(a[i]);
    }
    //printf("\nb - 1 -> e bytes: %d.\n", cnt2);

    char *s = (char *)malloc(MAX * sizeof(char));

    fseek(f, cnt1 * sizeof(char), SEEK_SET);
    //printf("\nFile pointer is at: %d.\n", ftell(f));

    int ans = 0;
    //printf("\nRead value: %d.\n", ans);

    for(i = 0; i < e - b + 1; ++i)
    {
        ans = fread(s, sizeof(char), MAX, f);
        s[ans * sizeof(char)] = '\0';
        printf("%d - %s", i + b, s);
    }

    free(s);
} 

void Read(FILE *f, char **a, long long end)
{
    //b - begin, e - end
    int b, e, i;

    fseek(f, 0, SEEK_SET);

    printf("\nEnter begin: "); fflush(stdin); scanf("%d", &b);
    while(b <= 0)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin);
        scanf("%d", &b);
    }

    printf("\nEnter end: "); fflush(stdin); scanf("%d", &e);
    while(e <= b || e > end)
    {
        printf("\nInvalid! Enter again: ");
        fflush(stdin);
        scanf("%d", &e);
    }
    
    //dem so byte - cnt1 -> dinh vi con tro file 
    //cnt2 - dem so byte tu b -> e
    //e - b + 1 la so dong
    long cnt1 = 0, cnt2 = 0;
    //tim den vi tri b - 1
    for(i = 0; i < b - 1; ++i)
    {
        cnt1 += strlen(a[i]);
    }
    //printf("\nb position's bytes: %d", cnt1);

    for(i = b - 1; i < e; ++i)
    {
        //printf("%s", a[i]);
        cnt2 += strlen(a[i]);
    }
    //printf("\nb - 1 -> e bytes: %d.\n", cnt2);

    //luu 
    char **c = (char **)malloc((cnt2 + 2) * sizeof(char *));
    for(i = 0; i < e - b + 1; ++i)
    {
        c[i] = (char *)malloc(MAX * sizeof(char));
    }

    fseek(f, cnt1 * sizeof(char), SEEK_SET);
    //printf("\nFile pointer is at: %d.\n", ftell(f));

    int ans = 0;
    //printf("\nRead value: %d.\n", ans);

    for(i = 0; i < e - b + 1; ++i)
    {
        //printf("\nftell = %d.\n", ftell(f));
        ans = fread(c[i], sizeof(char), MAX, f);
        //ans = fread(c[i], sizeof(char), MAX, f);
        printf("\nstrlen(c[%d] = %d\n", i, strlen(c[i]));
        //cnt1 += strlen(c[i]);
        //fseek(f, (cnt1 + strlen(c[i])) * sizeof(char), SEEK_SET);
        //printf("\nftell = %d.\n", ftell(f));
        //printf("\nReadValue: %d.\n", ans);
        c[i][ans * sizeof(char)] = '\0';
        printf("%d - %s", i + b, c[i]);
        //printf("%s", a[i + b - 1]);
    }

    //giai phong
    for(i = 0; i < e - b + 1; ++i)
    {
        free(c[i]);
    }
    free(c);
} 

int main(int argc, char *argv[])
{
    //f - .txt, f1 - .dat
    FILE *f, *f1;

    if((f = fopen(argv[1], "r")) == NULL)
    {
        printf("\nCannot open %s!\n\n", argv[1]);
        return 1;
    }
    else if((f1 = fopen(argv[2], "wb+")) == NULL)
    {
        printf("\nCannot open %s!\n\n", argv[2]);
        return 1;
    } 
    else
    {
        printf("\nProcessing...\n");
        //fseek(f, 0, SEEK_END);
        //int size = ftell(f);
        int i;
        //so dong
        long long line = LineNum(f);
        printf("\nSo dong: %d.\n", line);

        //so byte <=> so ky tu
        long long size = ByteNum(f);
        printf("\nSo byte: %d.\n", size);
        
        fseek(f, 0, SEEK_SET);

        //cpd
        char **a = (char **)malloc(size * sizeof(char *));
        for(i = 0; i < line; ++i) 
        {
            a[i] = (char *)malloc(MAX * sizeof(char));
        }

        int cnt = 0;
        for(i = 0; i < line; ++i)
        {
            fgets(a[i], MAX, f);
            //printf("%d - %s", i + 1, a[i]);
            cnt = fwrite(a[i], sizeof(char), MAX, f1);
            //cnt++;
        }

        //printf("\nWriten value: %d.\n", cnt);

        char sel;
        do
        {
            //Read(f1, a, line);
            //Read3(f1, a, line);
            Read2(f1, line, a, size);
            printf("\nDo you want to continue [y/n]: ");
            fflush(stdin);
            scanf("%c", &sel);
            while(sel != 'n' && sel != 'y')
            {
                printf("\nInvalid! Enter again: ");
                fflush(stdin);
                scanf("%c", &sel);
            }
        } while (sel == 'y'); 
        
        printf("\nClosing...\n");
        //giai phong bo nho
        for(i = 0; i < line; ++i)
        {
            free(a[i]);
        }
        free(a);
        fclose(f);
        fclose(f1);
        return 0;
    }
}