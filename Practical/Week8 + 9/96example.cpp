#include<stdio.h>
double celsius(double f);
int main() {
double fahr = 0;
printf("Fahrenheit\tCelsius\n");
while (fahr < 21) {
printf("%6.1f\t%6.1f\n", fahr, celsius(fahr));
fahr += 1;
}
return 0;
}
double celsius(double f) {
return 5 * (f - 32) / 9;
}
