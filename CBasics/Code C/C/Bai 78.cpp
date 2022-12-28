#include<stdio.h>
//Duoi day la cach dau ham co gia tri tra ve, cac bai truoc la ham khong co gia tri tra ve
/* Ham khong co gia tri tra ve duoc khai bao = tu khoa "void", cac ham nay duoc su dung de thuc thi cac doan code trong than ham va khong can lay ra ket qua sau khi thuc thi xog
 * Ham co gia tri tra ve khac voi ham tren o cho la cac ham dang nay sau khi thuc thi cac doan code thi se tra ve mot ket qua
 VD:
 #include<stdio.h>

// Khai báo hàm sum v?i ki?u tr? v? là int và d?u vào là s? n
int sum(int n) {
	// Bi?n luu tr? t?ng các s? t? 1 t?i n
	int add = 0;
	// Tính t?ng các s? t? 1 t?i n và luu vào bi?n add
	for (int i = 1; i <= n; i++) {
		add += i;
	}
	// Tr? v? add (gán k?t qu? c?a hàm sum cho add)
	return add;
}

int main() {
	// Hi?n th? giá tr? c?a hàm sum v?i các d?u vào khác nhau ra màn hình
	printf("%d %d %d", sum(3), sum(4), sum(5));
	return 0;
}
- Trong vi du tren ham sum() duoc khai bao voi tu khoa int nen se co kieu tra ve la mot so nguyen
- De tra ve mot ket qua cho ham dung cau lenh "return"
- Do sum la ham co gia tri tra ve la mot so nguyen nen ta co the su dung ham nay nhu 1 so nguyen (VD: gan int a = sum(..); printf("%d", sum(..))..)
- Ham se ket thuc ngay khi gap cau lenh return nen phai de y */
int sum(int arr[], int n) {
	int lam = 0;
	for (int i = 0; i < n; i++) {
		lam += arr[i]; 
	}
	return lam;
}
int main() {
	int n;
	int arr[n];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d", sum(arr, n));
	return 0;
}

