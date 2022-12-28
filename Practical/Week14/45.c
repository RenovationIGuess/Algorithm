#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct {
	int numerator;
	int denominator;
} fraction;
void fractionInput(fraction *ps); 
void fractionOutput (fraction ps); 
void fractionArrayInput(fraction dsps[], int n); 
void fractionArrayOutput(fraction dsps[], int n); 
int fractionCmp(fraction ps1, fraction ps2);
fraction inverse(fraction ps);
void inverseArray(fraction dsps[], int n); 
void printfrac(fraction k);
void simplify(fraction *k);
void fractionInput(fraction *ps) {
	int n, d;
	printf("Numerator: "); scanf("%d", &n);
	ps->numerator = n;
	do {
		printf("Denominator: "); scanf("%d", &d);
	} while(d == 0);
	ps->denominator = d;
}
void fractionOutput(fraction ps) {
	printf("%d/%d ", ps.numerator, ps.denominator);
}
void fractionArrayInput(fraction dsps[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("Data input for the %d - th fration: \n", i + 1);
		fractionInput(&dsps[i]);
	}
}
void fractionArrayOutput(fraction dsps[], int n) {
	int i;
	printf("Data output for the array of fration: \n");
	for(i = 0; i < n; i++) {
		printfrac(dsps[i]);
	}
	printf("\n");
}
fraction inverse(fraction ps) {
	fraction tmp;
	if(ps.numerator == 0) {
		printf("Can not have an inverse fration of 0!\n");
		exit(1);
	}
	tmp.numerator = ps.denominator;
	tmp.denominator = ps.numerator;
	return tmp;
}
int fractionCmp(fraction ps1, fraction ps2) {
	long smd = (ps1.numerator*ps2.denominator - ps2.numerator*ps1.denominator)*
	ps1.denominator*ps2.denominator;
	if(smd > 0) return 1;
	else if(smd < 0) return -1;
	else return 0;
}
void inverseArray(fraction dsps[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		dsps[i] = inverse(dsps[i]);
	}
}
int findUCLN(int a, int b) {
	if(b == 0) return a;
	return findUCLN(b, a % b);
}
void simplify(fraction *k) {
	int u = findUCLN(k->numerator, k->denominator);
	k->numerator /= u;
	k->denominator /= u;
}
void printfrac(fraction k) {
	simplify(&k);
	if(k.denominator == 1) printf("After simplified we have: %d\n", k.numerator);
	else printf("After simplified we have: %d/%d\n", k.numerator, k.denominator);
}
int main() {
	int n;
	fraction a[MAX], max, s, p;
	printf("Enter the number of fration: "); scanf("%d", &n);
	fractionArrayInput(a, n);
	fractionArrayOutput(a, n);
	printf("Inverse all fractions in the array.\n");
	inverseArray(a, n);
	fractionArrayOutput(a, n);
	printf("Enter first fration to compare: \n"); fractionInput(&s);
	printf("Enter second fraction to compare: \n"); fractionInput(&p);
	printf("\n");
	if(fractionCmp(s, p) == 0) {
		printf("Two fractions are equal.\n");
	} else if(fractionCmp(s, p) < 0) {
		fractionOutput(s); printf("is smaller than "); fractionOutput(p); printf("\n");
	} 
	fraction sum, multi, div;
	printf("\n");
	sum.numerator = s.numerator*p.denominator + s.denominator*p.numerator;
	sum.denominator = s.denominator*p.denominator;
	printf("Sum of two frations - "); printfrac(sum); 
	printf("\n");
	multi.numerator = s.numerator*p.numerator;
	multi.denominator = s.denominator*p.denominator;
	printf("Multiplition of two frations has the result - "); printfrac(multi);
	printf("\n");
	fraction tmp = inverse(p);
	div.numerator = s.numerator*tmp.numerator;
	div.denominator = s.denominator*tmp.denominator;
	printf("Division of two frations has the result - "); printfrac(div);
	printf("\n");
	printf("Enter the fraction you want to simplify: \n");
	fraction k; fractionInput(&k);
	printfrac(k);
	return 0;
}
