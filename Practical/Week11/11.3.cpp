#include<stdio.h>
int main() {
	float a, b, c; 
	printf("Enter three numbers: "); scanf("%f%f%f", &a, &b, &c);
	float *p;
	printf("Here are the values of a, b, c: %.2f %.2f %.2f\n", a, b, c);
	p = &a; 
	*p += 100; 
	p = &b;
	*p += 100;
	p = &c;
	*p += 100;
	printf("Here are the values after + 100: %.2f %.2f %.2f\n", a, b, c);
	return 0;
}
