#include<stdio.h>
double sum(double r) {
	scanf("%lf", &r);
	return r;
}
int main() {
	double r;
	printf("%lf", 2*3.14*sum(r));
	return 0;
}
