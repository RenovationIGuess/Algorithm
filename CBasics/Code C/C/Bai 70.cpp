#include<stdio.h>
#include<string.h>
int main() {
	char s[100];
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') { //Neu s[i] thuoc chu cai in thuong tu a -> z
			s[i] += 32; //Tuong duong s[i] = s[i] + 32
		}
	}
	printf("%s", s); //Hien thi xau
	return 0;
}
