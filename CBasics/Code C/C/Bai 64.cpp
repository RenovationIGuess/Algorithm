#include<stdio.h>
int main() {
	int k;
	scanf("%d", &k);
	char str[100];
	scanf("%s", str);
	printf("%c", str[k-1]); //Xau ban chat la 1 mang cac ky tu nen ta co the lay ra phan tu thu k trong xau str = str(ten tu dat)[k-1], luu y la lay 1 ky tu nen dung toan tu %c
	return 0;
}
