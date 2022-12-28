//Cach 1
#include<stdio.h>
int main() {
	char str[100];
	scanf("%s", str);
	int a = 0; //a la gia tri hien thi do dai cua xau (min = 0)
	while (str[a] != '\0') { //Ky tu thu a khac '\0' thi thuc hien doan code trong {}
		a++;
	}
	printf("%d", a);
	return 0;
}
