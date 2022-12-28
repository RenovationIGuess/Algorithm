#include <stdio.h>
#include<string.h>
#define Max 100
void nhapSv(int *Sv,int *count,char strSv[Max][31]);
void intenSv(int *Sv,char strSv[Max][31],char cpy[Max][31]);
void inHoten(int *Sv,char strSv[Max][31]);
void sapxep(int *Sv,char cpy[Max][31],char strSv[Max][31]);
int main() {
    int count=0;
    int Sv;
    int tieptuc;
    int choose;
    char strSv[Max][31];
    char cpy[Max][31];
    
    do{
        printf("========================================================\n");
        printf("Welcome to my menu.\n");
        printf("Please choose one of services below:\n");
        printf("1.Enter full name.\n");
        printf("2.Print out full name.\n");
        printf("3.Print out the name. \n");
        printf("4.Sort name.\n");
        printf("Choose service: ");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            nhapSv(&Sv,&count,strSv);
            break;
        case 2: 
            if(count==0) {printf("Please enter full name.\n");break;}
            inHoten(&Sv,strSv);
            break;
        case 3:
            if(count==0) {printf("Please enter full name.\n");break;}
            intenSv(&Sv,strSv,cpy);
            break;
        case 4: 
             if(count==0) {printf("Please enter full name.\n");break;}
             sapxep(&Sv,cpy,strSv);
             break;
        default:
            printf("You choose wrong, please choose again.\n");
            break;
        }
        printf("Do you want to continue our services? (1: Yes 2: No) : ");
        scanf("%d",&tieptuc);
    }while(tieptuc==1);
    printf("See you again. <3\n");
    printf("========================================================\n");
}
void nhapSv(int *Sv,int *count,char strSv[Max][31]) {
    int Sl;
    if(*count==0) {
        printf("Total numbers of student: ");
        scanf("%d",&*Sv);
        for(int i=0;i<*Sv;i++) {
            printf("Full name of student %d: ",i+1);
            fflush(stdin);
            gets(strSv[i]);         
        }
        *count=1;
    }
    else {
        printf("Add more students: ");
        scanf("%d",&Sl);
        int begin=*Sv;
        *Sv+=Sl;
        for (int i=begin;i<*Sv;i++) {
            printf("Full name of student %d: ",i+1);
            fflush(stdin);
            gets(strSv[i]);
           
        }
    }
}
void inHoten(int *Sv,char strSv[Max][31]) {
    int i;
    for(i=0;i<*Sv;i++) {
        printf("Full name of student %d: ",i+1);
        fflush(stdin);
        puts(strSv[i]);
    }
}
void intenSv(int *Sv,char strSv[Max][31],char cpy[Max][31]) {
    int m;
    for (m=0;m<*Sv;m++) {
        int len=strlen(strSv[m]);
        int i=len-1;
        int h=0;
        while(i>=0) {
            if (strSv[m][i]==' ') {
                for(int j=i+1;j<=len;j++) {
                    cpy[m][h]=strSv[m][j];h++;
                }
                break;
            }
            i--;
        }
    }
    for(m=0;m<*Sv;m++) {
        printf("Name of student %d: ",m+1);
        fflush(stdin);
        puts(cpy[m]);
    }
}
void sapxep(int *Sv,char cpy[Max][31],char strSv[Max][31]) {
    for (int m=0;m<*Sv;m++) {
        int len=strlen(strSv[m]);
        int i=len-1;
        int h=0;
        while(i>=0) {
            if (strSv[m][i]==' ') {
                for(int j=i+1;j<=len;j++) {
                    cpy[m][h]=strSv[m][j];h++;
                }
                break;
            }
            i--;
        }
    }
    char tmp[31];
    for (int i=0;i<*Sv;i++) {
        for(int j=i+1;j<*Sv;j++) {
            if(cpy[i][0]>cpy[j][0]) {
                strcpy(tmp,cpy[i]);
                strcpy(cpy[i],cpy[j]);
                strcpy(cpy[j],tmp);
            }
        }
    }
    printf("Sort name: \n");
    for (int i=0;i<*Sv;i++) {
        fflush(stdin);
        puts(cpy[i]);
    }
}
