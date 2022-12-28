#include<stdio.h>
int main() {
	char vtype; //Vehicle type
	float fee;
	int hours;
	do {
		printf("Enter your vehicle type (with C: car, B: bus, T: truck): ");
		scanf("%c", &vtype);
		if (vtype != 'C' || vtype != 'B' || vtype != 'T') {
			printf("Your vehicle type is invalid, please type again: ");
			scanf("%c", &vtype);
		}
	} while(vtype)
	printf("Enter your parking hours: ");
	scanf("%d", &hours);
	if (vtype == 'C') {
		if (hours > 0 && hours <= 2) {
			fee = hours*0.70; //Unit: $
		} else if (hours > 2) {
			fee = 2*0.70 + (hours - 2)*2.50;
		} 
	} else if (vtype == 'B') {
		if (hours > 0 && hours <= 2) {
			fee = hours*1.50; //Unit: $
		} else if (hours > 2) {
			fee = 2*1.50 + (hours - 2)*2.00;
		} 
	} else if (vtype == 'T') {
		if (hours > 0 && hours <= 1) {
			fee = 2.50; //Unit: $
		} else if (hours > 1) {
			fee = 2.50 + (hours - 1)*3.25;
		} 
	} else {
		printf("The vehicle type is invalid.\n");
	}
	printf("Your fee is: %.2lf$\n", fee);
	return 0;
}
