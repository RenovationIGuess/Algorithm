/* Ham de quy la ham goi toi chinh no
Cu phap
void ten_ham() {
	...
	ten_ham();
	...
}
Do tinh chat tu goi lai chinh no nen de trnah viec ham de quy chay khong bao gio dung ta luon can co diem dung (don gian la toi 1 luc nao do ham de quy se k goi chinh no nua)
VD: factorial(5)
= 5 * factorial(4)
= 5 * 4 * factorial(3)
= 5 * 4 * 3 * factorial(2)
= 5 * 4 * 3 * 2 * factorial(1)
= 5 * 4 * 3 * 2 * 1
= 120
ví d? v? hàm d? quy tính t?ng các s? t? 1 t?i n:

#include<stdio.h>

int sumOfArray(int n) {
    if (n == 0) return 0;
    return n + sumOfArray(n - 1);
}

int main() {
    printf("%d", sumOfArray(10));
    return 0;
} */
#include<stdio.h>
int lam(int n) {
	if (n == 0) return 1;
	return n * lam(n - 1); 
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", lam(n));
	return 0;
}
