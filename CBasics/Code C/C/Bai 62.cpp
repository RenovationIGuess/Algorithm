/* Xau string (str): ban chat la 1 mang cac ky tu duoc luu tru tren cac o nho lien tiep va ket thuc = ky tu '\0'
Ta co the khoi tao gia tri cho xau giong nhu cho mang:
- char str[] = "abcd";
- char str[50] = "abcd";
- char str[] = {'a', 'b', 'c', 'd', '\0'};
- char str[5] = {'a', 'b', 'c', 'd', '\0'};
De nhap du lieu va hien thi xau ra man hinh dung dinh dang %s, VD:
#include<stdio.h>

int main() {
	// Khai báo xâu str, xâu str luu tr? du?c 99 ph?n t?
	char str[100];
	// Nh?p d? li?u vào xâu str
	scanf("%s", str);
	// Hi?n th? xâu str ra màn hình
	printf("%s", str);
	return 0;
}
Doan code tao tren tao ra xau str luu tru duoc 99 ky tu (khong phai 100 do ky tu cuoi cung cua 1 xau luon la '\0'), tinh tu 1 -> 99, '\0', de trong dau nhay don
Luu y: khi nhap du lieu cho xau thi khong dung toan tu & trong ham scanf */
#include<stdio.h>
int main() {
	char str[100];
	scanf("%s", str);
	printf("%s", str);
	return 0;
}

