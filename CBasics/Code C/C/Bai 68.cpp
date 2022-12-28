#include<stdio.h>
#include<string.h>
int main() {
	char c;
	scanf("%c", &c);
	char s[100];
	scanf("%s", s);
	int a = -1;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == c) {
			a = i;
			break;
		}
	}
/* O day khai bao 1 bien a = -1 la cach ngan gon nhat, tao vong lap
Neu dieu kien trong () cua if thoa man thi a = i va su dung break; de khong thuc thi cac lenh phia duoi
Nguoc lai neu khong co phan tu s[i] nao thoa man thi lenh se khong bi dung va in ra a = -1 nhu yeu cau */
	printf("%d", a);
	return 0;
}
