#include<stdio.h>
int checkdigit(int n, int k);
int main() {
	int n, k;
	printf("Enter number: "); scanf("%d", &n);
	printf("Enter size of number: "); scanf("%d", &k);
	if(checkdigit(n, k) == -1) {
		printf("The numbers of the number is invalid");
	} else if(checkdigit(n, k) == 1) {
		printf("All same");
	} else printf("Not all the same");
	return 0;
}
int checkdigit(int n, int k) {
	int digit; //phan tu cua n
	int count = 0; //dem so cua n
	int Even = 1, Odd = 1; //check chan le
	while (n > 0 && count <= k) {
		digit = n % 10;
		n = n/10;
		count++;
		if (digit % 2 == 0) {
			Even *= 1;
			Odd *= 0;
		} else {
			Even *= 0;
			Odd *= 1;
		}
	}
	if (count > k) return -1;
	if (Even || Odd) return 1;
	else return 0;  
}
