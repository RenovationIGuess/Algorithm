#include<stdio.h>
#include<math.h>
typedef struct {
	float re;
	float im;
} complex;
void sum(complex n1, complex n2) {
	float real = n1.re + n2.re;
	float imag = n1.im + n2.im;
	printf("Sums result: %.0f + %.0fi.\n", real, imag);
}
 
void minus(complex n1, complex n2) {
	float real = n1.re - n2.re;
	float imag = n1.im - n2.im;
	printf("Subtractions result: %.0f + %.0fi.\n", real, imag);
}

void multiply(complex n1, complex n2) {
	float real = n1.re*n2.im - n2.re*n1.im;
	float imag = n1.re*n2.im + n1.im*n2.re;
	printf("Multiplitions result: %.0f + %.0fi.\n", real, imag);
}

int main() {
	complex n1, n2;
	printf("N1 re: "); scanf("%f", &n1.re);
	printf("N1 im: "); scanf("%f", &n1.im);
	printf("N2 re: "); scanf("%f", &n2.re);
	printf("N2 im: "); scanf("%f", &n2.im);
	sum(n1, n2);
	minus(n1, n2);
	multiply(n1, n2);
	return 0;
}

