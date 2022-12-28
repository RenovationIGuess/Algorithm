#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>

/*
++++++++++++++++++++++++++++++++++++++++++++++
Bai thi mon thuc hanh C Intro Viet Nhat
Ho va Ten: Nguyen Tung Lam
MSSV: 20204998
Dia chi thu dien tu: lam.nt204998@sis.hust.edu.vn
++++++++++++++++++++++++++++++++++++++++++++++
*/

void fix(char s[]);
bool isWhite(char c);
bool speC(char c);

void giaodien()
{
   printf("=============================================\n");
   printf("Bai thi mon thuc hanh C Intro Viet Nhat \n");
   printf("Ho va ten :   \n");
   printf("MSSV : \n");
   printf("1. Noi dung 1\n");
   printf("2. Noi dung 2\n");
   printf("3. Noi dung 3\n");
   printf("4. Noi dung 4\n");
   printf("=============================================\n");
}

void menu()
{
	
}

int main()
{
    char ch;
    do{
        giaodien();
        printf("Nhan so cau [1..4] de tiep tuc hoac phim 'k' de ket thuc : ");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch!='k');
    menu();
    return 0;
}

bool isWhite(char c) {
	return c == ' ' || c == '\t' || c == '\n'; 
	//true neu c la cac ky tu sau
}
bool speC(char c) { //special character
	return c == ':' || c == '[' || c == ']' || c == ';' || c == '/' || c == '.' 
	|| c == ',' || c == '!';
}
void fix(char s[]) {
	int i;
	//xoa dau
	while(isWhite(s[0]) || speC(s[0])) {
		strcpy(&s[0], &s[1]);
	}
	
	//xoa giua
	for(i = 0; i < strlen(s); ++i) {
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
	for(i = 0; i < strlen(s); ++i)
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
	for(i = 1; i < strlen(s); ++i)
	{
		if(s[i] == ' ')
			if(!isupper(s[i + 1]))
				s[i + 1] -= 32;
	}
}
