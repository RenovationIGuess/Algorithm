#include <stdio.h>
double circumference(double r) {
	return 2 * r * 3.14;
}
double area(double r) {
	return 3.14 * r * r;
}
int main() {
	double r;
	scanf("%lf", &r);
	printf("%.2f\n", circumference(r));
	printf("%.2f\n", area(r));
	return 0;
}
