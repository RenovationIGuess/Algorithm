/* De kiem tra 2 xau co giong nhau hay khong ta khong dung toan tu == vi toan tu == se so sanh dia chi cua phan tu dau tien cua 2 dau
=> De kiem tra xem 2 xcau co giong nhau hay khong ta dung ham strcmp(...,...) trong thu vien string.h, ham nay se tra ve 0 neu 2 xau giong nhau va nguoc lai la 1 so khac 0 neu 2 ham khac nhau
(trong ... la ten dai dien xau)
*/
#include<stdio.h>
#include<string.h>
int main() {
	//Ten cua 2 nguoi la 1 xau
	char a[100];
	char b[100];
	scanf("%s%s", a, b); //Nhap 2 xau a truoc b sau
	if (strcmp(a, b) == 0) {
		printf("two people having the same name");
	} else {
		printf("two people don't have the same name");
	}
	return 0;
	
	
}
