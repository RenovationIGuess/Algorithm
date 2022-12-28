#include<stdio.h>
long salary(int hour) {
	if (hour >= 10 && hour <= 40) {
		return hour*15000;
	} else if (hour > 40 && hour <= 65) {
		return 40*15000 + (hour - 40)*1.5*15000; 
	}
}
int main() {
	printf("Welcome to salary calculating system! ^_^\n");
	printf("Basic Salary\tBasic hrs/week\tExtra(WH > 40)\n");
	printf("15000\t\t40\t\t1.5/h\n");
	int hour;
	printf("Enter your working hours: ");
	scanf("%d", &hour);
	while (hour < 10 || hour > 65) {
		printf("You have enter invalid hours! Try again: ");
		scanf("%d", &hour);
	}
	printf("Calculating...\n"); 
	printf("\n==========Loading==========\n\n");
	printf("Your salary is: %ld (O.O)\n", salary(hour));
	printf("Thankyou for using our service >.< ~!");
	return 0;
}
