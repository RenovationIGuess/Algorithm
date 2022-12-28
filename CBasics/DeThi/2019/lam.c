#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1001

FILE *f;

struct Noun
{
    char value[30];
    int freq;
};
typedef struct Noun ElmType;

#include "tree.h"

int divide(char c)
{
    return c == ',' || c == '\'' || c == '\"';
}

int sentenceEnd(char c)
{
    return c == '.' || c == '!' || c == '?';
}

int special(char c)
{
    return c == ' ' || c == ',' || c == '\'' || c == '\"' || c == '.' || c == '!' || c == '?';
}

int ischar(char c)
{
    return (c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a') || ('0' <= c && c <= '9');
}

void getInputfromKeyboard(char *filename)
{
    if((f = fopen(filename, "w")) == NULL)
    {
        printf("\nCannot open file %s!\n", filename);
        return;
    }
    char c;
    int i, runtime = 0;
    char *s = (char *)malloc(MAX * sizeof(char));
    while(1)
    {
        i = 0;
        printf("\nEnter the string: ");
        scanf("%c", &c);
        if(c == '\n' && runtime == 0) 
        {
            scanf("%c", &c);
            runtime++;
        }
        while(c != '\n')
        {
            s[i] = c;
            i++;
            scanf("%c", &c);
        }
        s[i] = '\0';
        if(i == 0) break;
        //printf("%s - %d\n", s, strlen(s));
        fprintf(f, "%s", s);
    }
    fclose(f);
}

char *loadContentfromFile(char *filename)
{
    if((f = fopen(filename, "r")) == NULL)
    {
        printf("\nCannot open file %s!\n", filename);
        exit(1);
    }
    int i = 0;
    char c;
    char *s = (char *)malloc(MAX * sizeof(char));
    do
    {
        fscanf(f, "%c", &c);
        if(feof(f)) break;
        while(!feof(f))
        {
            s[i] = c;
            //printf("%c", s[i]);
            i++;
            fscanf(f, "%c", &c);
        }
        s[i] = '\0';
        if(feof(f)) break;
    } while (1);
    fclose(f);
    return s;
}

void standardizeSentence(char *s)
{
    int i;
    while(isWhite(s[0])) 
    {
		strcpy(&s[0], &s[1]);
	}
	for(i = 0; i < strlen(s); i++) {
		if(isWhite(s[i]) && isWhite(s[i + 1])) 
        {
			strcpy(&s[i], &s[i + 1]);
			i--;
		} 
        /*else if(isWhite(s[i]) && divide(s[i + 1])) 
        {
			strcpy(&s[i], &s[i + 1]);
			i--;
		} */
        else if((s[i] == ',' || sentenceEnd(s[i])) && isWhite(s[i + 2])) 
        {
			strcpy(&s[i + 1], &s[i + 2]);
			i--;
		}
        else if(isWhite(s[i]) && (sentenceEnd(s[i + 1]) || s[i + 1] == ',')) 
        {
			strcpy(&s[i], &s[i + 1]);
			i--;
		}
	}
    //printf("Lan 1: %s\n", s);
    int mark = 0;
    for(i = 0; i < strlen(s); ++i)
    {
        if(s[i] == '\'' || s[i] == '\"')
        {
            if(mark == 0) 
            {
                if(isWhite(s[i + 1]))
                {
                    strcpy(&s[i + 1], &s[i + 2]);
                    //i--;
                }
                mark = 1;
            } 
            else 
            {
                if(isWhite(s[i - 1]))
                {
                    strcpy(&s[i - 1], &s[i]);
                    //i--;
                }
                mark = 0;
            }
        }
    }
	while(isWhite(s[strlen(s) - 1])) {
		strcpy(&s[strlen(s) - 1], &s[strlen(s)]);
	}
    //printf("Lan 2: %s\n", s);
}

void reset(char *s)
{
    int i;
    while(s[0] != '\0')
    {
        strcpy(&s[0], &s[1]);
    }
}

void func3(char *str)
{
    char *content = (char *)malloc(MAX * sizeof(char));
    strcpy(content, str);
    //standardizeSentence(content);
    int res = 0, i; //tra ve so cau
    char *sentence = (char *)malloc(MAX * sizeof(char));
    int cnt = 0; //chi so index
    for(i = 0; i < strlen(content); ++i)
    {
        if(sentenceEnd(content[i]))
        {
            sentence[cnt] = content[i];
            cnt++;
            sentence[cnt] = '\0';
            standardizeSentence(sentence);
            printf("%s\n", sentence);
            //strcpy(sentence, "\0");
            reset(sentence);
            cnt = 0;
        }
        else
        {
            sentence[cnt] = content[i];
            //printf("%c - %d\n", sentence[cnt], cnt);
            cnt++;
        }
    }
    //free(sentence);
}

int counSentences(char *str)
{
    char *content = (char *)malloc(MAX * sizeof(char));
    strcpy(content, str);
    standardizeSentence(content);
    int res = 0, i; //tra ve so cau
    char *sentence = (char *)malloc(MAX * sizeof(char));
    int cnt = 0; //chi so index
    for(i = 0; i < strlen(content); ++i)
    {
        if(sentenceEnd(content[i]))
        {
            sentence[cnt] = content[i];
            cnt++;
            sentence[cnt] = '\0';
            standardizeSentence(sentence);
            if(strlen(sentence) > 3) res++;
            //strcpy(sentence, "\0");
            reset(sentence);
            cnt = 0;
        }
        else
        {
            sentence[cnt] = content[i];
            cnt++;
        }
    }
    //free(sentence);
    return res;
}

int countWords(char *str)
{
    char *content = (char *)malloc(MAX * sizeof(char));
    strcpy(content, str);
    //standardizeSentence(content);
    int res = 0, i, j; //tra ve ket qua
    char *sentence = (char *)malloc(MAX * sizeof(char));
    int cnt = 0; //chi so index
    for(i = 0; i < strlen(content); ++i)
    {
        if(sentenceEnd(content[i]))
        {
            sentence[cnt] = content[i];
            cnt++;
            standardizeSentence(sentence);
            for(j = 0; j < strlen(sentence); ++j)
            {
                if(sentence[j] == ' ') res++;
            }
            res++;
            reset(sentence);
            cnt = 0;
            //strcpy(sentence, "\0");
        }
        else
        {
            sentence[cnt] = content[i];
            cnt++;
        }
    }
    return res;
}

void func4(char *str)
{
    int opt;
    do
    {
        printf("\n1. Dem so cau\n2. Dem so tu\n3. Thoat\n");
        printf("\nEnter your option: "); 
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nSo cau trong van ban: %d\n", counSentences(str));
            break;
        case 2:
            printf("\nSo tu trong van ban: %d\n", countWords(str));
            break;
        case 3:
            printf("\nQuitting...\n");
            break;
        default:
            printf("\nInvalid!\n");
            break;
        }
    } while (opt != 3);
}

int isNoun(char *word)
{
    int i;
    for(i = 0; i < strlen(word); ++i)
    {
        if(word[i] >= 'A' && word[i] <= 'Z') return 1;
    }
    return 0;
}

int find(char *s, ElmType *a, int num)
{
    int i;
    for(i = 0; i < num; ++i)
    {
        if(strcmp(s, a[i].value) == 0) return i;
    }
    return -1;
}

treetype extractNouns(char *str)
{
    char *content = (char *)malloc(MAX * sizeof(char));
    strcpy(content, str);
    standardizeSentence(content);
    //printf("%s\n", content);
    treetype p;
    ElmType *tmp = (ElmType *)malloc(256 * sizeof(ElmType));
    MakeNullTree(&p);
    int i, j, k = 0, cnt = 0, start = 0, end, posi; 
    //start - bdau xau, end - kthuc, posi - vi tri xet

    for(i = 0; i <= strlen(content); ++i)
    {
        if(special(content[i]) && ischar(content[i + 1]) || content[i] == '\0')
        {
            end = i - 1;
            while(special(content[end])) end--;
            for(j = start; j <= end; ++j)
            {
                tmp[k].value[cnt] = content[j];
                cnt++;
            }
            tmp[k].value[cnt] = '\0';
            if(isNoun(tmp[k].value))
            {
                posi = find(tmp[k].value, tmp, k);
                if(posi == -1)
                {
                    tmp[k].freq = 1;
                    k++;
                }
                else tmp[posi].freq++;
            }
            strcpy(tmp[k].value, "\0");
            start = i + 1;
            cnt = 0;
        }
    }
    for(i = 0; i < k; ++i)
    {
        //printf("%s - %d\n", tmp[i].value, tmp[i].freq);
        InsertNode(tmp[i], &p);
    }
    return p;
}

void showNounStatis(treetype t)
{
    if(t != NULL)
    {
        showNounStatis(t->left);
        printf("%s - %d\n", t->element.value, t->element.freq);
        showNounStatis(t->right);
    }
}

void menu(char *filename, treetype *t)
{
    int opt;
    //read from file
    char *rff = (char *)malloc(MAX * sizeof(char));
    do
    {
        printf("\n1. Nhap du lieu va ghi file\n2. Doc du lieu tu file\n3. Chuan hoa cau\n4. Thong ke so luong cau, tu\n5. Thong ke\n6. Thoat\n");
        printf("\nEnter your option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            getInputfromKeyboard(filename);
            printf("\nGhi vao file thanh cong!\n");
            break;
        case 2:
            strcpy(rff, loadContentfromFile(filename));
            printf("\nDoan van ban da doc: %s\n", rff);
            printf("\nDoc tu file thanh cong!\n");
            break;
        case 3:
            printf("\nCac cau trong van ban:\n");
            func3(rff);
            break;
        case 4:
            func4(rff);
            break;
        case 5:
            (*t) = extractNouns(rff);
            printf("\nSo luong ten rieng trong van ban: %d\n", nb_nodes(*t));
            showNounStatis(*t);
            break;
        case 6:
            printf("\nQuitting...\n");
            break;
        default:
            printf("\nInvalid!\n");
            break;
        }
    } while (opt != 6);
}

int main(int argc, char *argv[])
{
    treetype t;
    MakeNullTree(&t);
    menu(argv[1], &t);
    MakeNullTree(&t);
    FreeTree(&t);
    return 0;
}
