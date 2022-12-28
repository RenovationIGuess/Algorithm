#include<stdio.h>
#include<string.h>
void lam(char s[100]) { //Haqm co the dai dien cho 1 doan code va vi the ta chi can khai bao dai dien va goi may ham ra
	scanf("%s", s);
	for (int i = 0; i <= strlen(s); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 32;
		}
	}
	printf("%s\n", s);
}
int main() {
	char s1[100], s2[100], s3[100];
	scanf("%s%s%s", s1, s2, s3);
	lam(s1);
	lam(s2);
	lam(s3);
	return 0;
}
