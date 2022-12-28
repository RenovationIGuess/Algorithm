#include<stdio.h>
int main() {
	int n; //Khai bao bien n: tuoi
	printf("Enter your age here: ");
	scanf("%d", &n);
	if (n < 18 && n > 0) {
		printf("Children");
	} else if (n >= 18 && n < 65) {
		printf("Adult");
	} else if (n >= 65) {
		printf("Old");
	} else {
		printf("The age you enter is not valid");
	}
	return 0;
}
