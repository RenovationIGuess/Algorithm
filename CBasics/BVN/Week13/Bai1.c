#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256

FILE *f, *f1;

int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

struct Player
{
    char name[51];
    int set[7];
};

typedef struct Player ElmType;

#include "BTree1.h"

void MakeNull(treetype **t, int size)
{
    int i;
    for(i = 0; i < size; ++i)
    {
        MakeNullTree(&(*t)[i]);
        //printf("%d\n", EmptyTree((*t)[i]));
    }
}

void equal(treetype *t, ElmType x)
{
    (*t)->element = x;
}

void print(treetype t)
{
    int j;
    printf("%-25s", t->element.name);
    for(j = 1; j <= 5; ++j)
    {
        printf("%-3d", t->element.set[j]);
    }
    //printf("\n");
}

//a vong truoc / b vong sau / so phan tu cua vong truoc - player_num
void makeMatch(treetype **a, treetype **b, int player_num)
{   
    int i, j;
    for(i = 0; i < player_num; i += 2)
    {
        int winner = random(i, i + 1), lose;
        if(winner == i)
        {
            lose = i + 1;
        }
        else 
        {
            lose = i;
        }
        int lose_win_num = random(0, 2);
        if(lose_win_num == 0)
        {
            for(j = 1; j <= 3 + lose_win_num; ++j)
            {
                (*a)[winner]->element.set[j] = random(6, 7);
                if((*a)[winner]->element.set[j] == 7)
                {
                    (*a)[lose]->element.set[j] = random(5, 6);
                }
                else
                {
                    (*a)[lose]->element.set[j] = random(0, 4);
                }
            }
            for(j = 4; j <= 5; ++j)
            {
                (*a)[winner]->element.set[j] = (*a)[lose]->element.set[j] = 0;
            }
        }
        else if(lose_win_num == 1)
        {
            int lose_win_match = random(1, 3);
            for(j = 1; j <= 3 + lose_win_num; ++j)
            {
                if(j == lose_win_match)
                {
                    (*a)[lose]->element.set[j] = random(6, 7);
                    if((*a)[lose]->element.set[j] == 7)
                        (*a)[winner]->element.set[j] = random(5, 6);
                    else (*a)[winner]->element.set[j] = random(0, 4);
                }
                else
                {
                    (*a)[winner]->element.set[j] = random(6, 7);
                    if((*a)[winner]->element.set[j] == 7)
                    {
                        (*a)[lose]->element.set[j] = random(5, 6);
                    }
                    else
                    {
                        (*a)[lose]->element.set[j] = random(0, 4);
                    }
                }
            }
            (*a)[winner]->element.set[5] = (*a)[lose]->element.set[5] = 0;
        }
        else if(lose_win_num == 2)
        {
            int lose_win_match1 = (1, 2);
            int lose_win_match2 = random(3, 4);
            for(j = 1; j <= 3 + lose_win_num; ++j)
            {
                if(j == lose_win_match1 || j == lose_win_match2)
                {
                    (*a)[lose]->element.set[j] = random(6, 7);
                    if((*a)[lose]->element.set[j] == 7)
                        (*a)[winner]->element.set[j] = random(5, 6);
                    else (*a)[winner]->element.set[j] = random(0, 4);
                }
                else
                {
                    (*a)[winner]->element.set[j] = random(6, 7);
                    if((*a)[winner]->element.set[j] == 7)
                    {
                        (*a)[lose]->element.set[j] = random(5, 6);
                    }
                    else
                    {
                        (*a)[lose]->element.set[j] = random(0, 4);
                    }
                }
            }
        }
        (*b)[i / 2] = createfrom2((*a)[winner]->element, (*a)[winner], (*a)[lose]);
    }

    
}

void Out(treetype *first, treetype *quarter, treetype *semi, treetype *final, int start)
{
    printf("\n%-50s%-50s%-50s%-50s\n\n", "First-Round", "Second-Round", "Third-Round", "Fourth-Round");
    print(first[0 + start]); printf("\n");
    print(first[1 + start]); printf("%-10s", ""); print(quarter[0 + (start / 2)]); printf("\n");
    print(first[2 + start]); printf("%-10s", ""); print(quarter[1 + (start / 2)]); printf("\n");
    print(first[3 + start]); printf("%-60s", ""); print(semi[0 + (start / 4)]); printf("\n");
    print(first[4 + start]); printf("%-60s", ""); print(semi[1 + (start / 4)]); printf("\n");
    print(first[5 + start]); printf("%-10s", ""); print(quarter[2 + (start / 2)]); printf("\n");
    print(first[6 + start]); printf("%-10s", ""); print(quarter[3 + (start / 2)]); printf("\n");
    print(first[7 + start]); printf("%-110s", ""); print(final[0 + (start / 8)]); printf("\n");
    print(first[8 + start]); printf("%-110s", ""); print(final[1 + (start / 8)]); printf("\n");
    print(first[9 + start]); printf("%-10s", ""); print(quarter[4 + (start / 2)]); printf("\n");
    print(first[10 + start]); printf("%-10s", ""); print(quarter[5 + (start / 2)]); printf("\n");
    print(first[11 + start]); printf("%-60s", ""); print(semi[2 + (start / 4)]); printf("\n");
    print(first[12 + start]); printf("%-60s", ""); print(semi[3 + (start / 4)]); printf("\n");
    print(first[13 + start]); printf("%-10s", ""); print(quarter[6 + (start / 2)]); printf("\n");
    print(first[14 + start]); printf("%-10s", ""); print(quarter[7 + (start / 2)]); printf("\n");
    print(first[15 + start]); printf("\n");
}

void createTree(char *s, char *s1, treetype *t)
{
    if((f = fopen(s, "r")) == NULL)
    {
        printf("\nCannot open file %s!\n", s);
        exit(1);
    }
    else if((f1 = fopen(s1, "w")) == NULL)
    {
        printf("\nCannot open file %s!\n", s1);
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
        i++; 
        if(feof(f)) break;
    } while(1);

    int player_num = i;

    treetype *first = (treetype *)malloc(player_num * sizeof(treetype));
    MakeNull(&first, player_num);
    
    treetype *quarter = (treetype *)malloc((player_num / 2) * sizeof(treetype));
    MakeNull(&quarter, player_num / 2);

    treetype *semi = (treetype *)malloc((player_num / 4) * sizeof(treetype));
    MakeNull(&semi, player_num / 4);

    treetype *final = (treetype *)malloc((player_num / 8) * sizeof(treetype));
    MakeNull(&final, player_num / 8); 

    for(i = 0; i < player_num; i += 2)
    {
        int winner = random(i, i + 1), lose;
        if(winner == i)
        {
            lose = i + 1;
        }
        else 
        {
            lose = i;
        }
        int lose_win_num = random(0, 2);
        if(lose_win_num == 0)
        {
            for(j = 1; j <= 3 + lose_win_num; ++j)
            {
                cop[winner].set[j] = random(6, 7);
                if(cop[winner].set[j] == 7)
                {
                    cop[lose].set[j] = random(5, 6);
                }
                else
                {
                    cop[lose].set[j] = random(0, 4);
                }
            }
            for(j = 4; j <= 5; ++j)
            {
                cop[winner].set[j] = cop[lose].set[j] = 0;
            }
        }
        else if(lose_win_num == 1)
        {
            int lose_win_match = random(1, 3);
            for(j = 1; j <= 3 + lose_win_num; ++j)
            {
                if(j == lose_win_match)
                {
                    cop[lose].set[j] = random(6, 7);
                    if(cop[lose].set[j] == 7)
                        cop[winner].set[j] = random(5, 6);
                    else cop[winner].set[j] = random(0, 4);
                }
                else
                {
                    cop[winner].set[j] = random(6, 7);
                    if(cop[winner].set[j] == 7)
                    {
                        cop[lose].set[j] = random(5, 6);
                    }
                    else
                    {
                        cop[lose].set[j] = random(0, 4);
                    }
                }
            }
            cop[winner].set[5] = cop[lose].set[5] = 0;
        }
        else if(lose_win_num == 2)
        {
            int lose_win_match1 = (1, 2);
            int lose_win_match2 = random(3, 4);
            for(j = 1; j <= 3 + lose_win_num; ++j)
            {
                if(j == lose_win_match1 || j == lose_win_match2)
                {
                    cop[lose].set[j] = random(6, 7);
                    if(cop[lose].set[j] == 7)
                        cop[winner].set[j] = random(5, 6);
                    else cop[winner].set[j] = random(0, 4);
                }
                else
                {
                    cop[winner].set[j] = random(6, 7);
                    if(cop[winner].set[j] == 7)
                    {
                        cop[lose].set[j] = random(5, 6);
                    }
                    else
                    {
                        cop[lose].set[j] = random(0, 4);
                    }
                }
            }
        }
        first[i] = create_node(cop[i]);
        first[i + 1] = create_node(cop[i + 1]);
        quarter[i / 2] = createfrom2(cop[winner], first[i], first[i + 1]);
    }

    makeMatch(&quarter, &semi, player_num / 2);
    makeMatch(&semi, &final, player_num / 4);
    makeMatch(&final, &t, player_num / 8);

    if(player_num == 16)
    {
        Out(first, quarter, semi, final, 0);
        printf("\nAUOpen Champion:\n");
        printf("%-25s", (*t)->element.name);
        for(j = 1; j <= 5; ++j)
        {
            printf("%-3s", "*");
        } printf("\n");
    }
    else
    {
        int cnt = 0;
        while(cnt != player_num)
        {
            Out(first, quarter, semi, final, cnt);
            printf("\n");
            cnt += 16;
        }
        int go_bruh = player_num / 8;
        int index;
        for(i = 0; i < go_bruh; i += 2)
        {
            int cnt1 = 0, cnt2 = 0;
            for(j = 1; j <= 5; ++j)
            {
                if(final[i]->element.set[j] < final[i + 1]->element.set[j]) cnt2++;
                else cnt1++;
                if(cnt1 == 3)
                {
                    final[index] = final[i];
                    break;
                }
                else
                {
                    final[index] = final[i + 1];
                    break;
                }
            }
            index++;
        }
        go_bruh /= 2;
        while(go_bruh != 2)
        {
            makeMatch(&final, &final, go_bruh);
            go_bruh /= 2;
        }
        makeMatch(&final, &t, 2);
        printf("\nAUOpen Champion:\n");
        printf("%-25s", (*t)->element.name);
        for(j = 1; j <= 5; ++j)
        {
            printf("%-3s", "*");
        } printf("\n");
    } 

    /*free(cop);
    free(first);
    free(semi);
    free(quarter);
    free(final); */
}

int main(int argc, char *argv[])
{
    srand((int)time(0));
    treetype t;
    createTree(argv[1], argv[2], &t);
    return 0;
}