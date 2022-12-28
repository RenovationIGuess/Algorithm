#include<stdio.h>
#include<math.h>
int solve(float *a, float *b, float *c, float &x1, float &x2) { //In: con tro + truyen tham chieu
	float delta = (*b)*(*b) - 4*(*a)*(*c);
	if (delta < 0) {
		x1 = x2 = 0.00;
		return 0;
	} else if (delta == 0) {
		x1 = x2 = -(*b)/(2*(*a));
		return 1;
	} else {
		delta = sqrt(delta);
		x1 = (-(*b) + delta)/(2*(*a));
		x2 = (-(*b) - delta)/(2*(*a));
		return 2;
	}
}
void calc(float *r) {
	float cc, vol; //cc: circumference, vol: volume
	cc = 2*3.14*(*r);
	vol = (4*3.14*(*r)*(*r))/3;
	printf("Circumference of the circle = %f\n", cc);
	printf("Volume of the globe = %f\n", vol);
}
int main() {
	int s; //s: services
	printf("This is our Menu (*_*):\n");
	do {
		printf("(1) Solve quadratic equation\t(2) Calculating Circumference of a circle and Volumn of globe\n");
		printf("Enter service: "); scanf("%d", &s);
		if (s == 1) {
			float a, b, c, x1, x2;
			printf("Enter a, b, c: "); scanf("%f%f%f", &a, &b, &c);
			if (a == 0) {
				do {
				printf("Invalid a, enter a again: "); scanf("%f", &a);
				} while (a == 0); //a != 0 thi nhap lai
			}
			int ns = solve(&a, &b, &c, x1, x2); //number of solutions - ns
			if (ns == 0) printf("Given equation has no solutions.\n");
			else if (ns == 1) printf("Given equation has one solution x = %.2f", x1);
			else printf("Given equation has 2 different solutions:\n x1 = %.2f\n x2 = %.2f\n", x1 , x2);
		}
		if (s == 2) {
			float r; 
			printf("Enter radius r = "); scanf("%f", &r);
			calc(&r);
		}
		/*if (s != 1 || s != 2) {
			printf("Do you really want to escape: "); scanf("%s", )
		}*/
	} while (s == 1 || s == 2);
	printf("Thank you! (^_^)");
	return 0;
}
