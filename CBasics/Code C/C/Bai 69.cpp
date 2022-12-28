/* Ve ban chat ky tu cung la 1 so nguyen, viec chuyen chu in thuong sang chu in hoa thuc chat la chuyen tu so nguyen nay sang so nguyen khac
- Trong ma ASCII, de hien thi gia tri nguyen cua 1 ky tu ta co the lam nhu sau:
#include<stdio.h>

int main() {
    printf("a = %d\n", 'a');
    printf("b = %d\n", 'b');
    printf("c = %d\n", 'c');
    printf("d = %d\n\n", 'd');
    printf("A = %d\n", 'A');
    printf("B = %d\n", 'B');
    printf("C = %d\n", 'C');
    printf("D = %d\n", 'D');
    return 0;
}
Va chuong trinh nay se hien thi ra gia tri nguyen ung voi chu cai do
***:  1) De chuyen tu chu in thuong sang in hoa, gia su gia tri nguyen cua chu in thuong la a, in hoa la b: a = b + 32 =>... */
#include<stdio.h>
#include<string.h>
int main() {
	char s[100];
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') { //Neu s[i] thuoc chu cai in thuong tu a -> z
			s[i] -= 32; //Tuong duong s[i] = s[i] - 32
		}
	}
	printf("%s", s); //Hien thi xau
	return 0;
}
