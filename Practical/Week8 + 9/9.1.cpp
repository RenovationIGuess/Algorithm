#include<stdio.h>
double KineticEnergy(double m, double v) {
	return m*v*v/2;
}
int main() {
	double m, v;
	do {
		printf("Enter mass: "); scanf("%lf", &m);
		printf("Enter speed: "); scanf("%lf", &v);
	} while ((m <= 0) || (v < 0));
	printf("Your result is: %.2lf", KineticEnergy(m, v));
	return 0;
}
