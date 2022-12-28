#include<stdio.h>
int main() {
	int s; //S: Service
	printf("Here are our services:\n");
	printf("1: Sum from 1 -> 10\t 2: insert point from [0;10]\t Others: Exit\n");
	printf("Please choose your service: ");
	scanf("%d", &s);
	
	if (s == 1) {
		int sum = 0;
		for (int i = 1; i <= 10; i++) {
			sum += i;
		}
		printf("Sum from 1 to 10 is: %d", sum);
	} else if (s == 2) {
		int p; //p: point
		printf("Enter your point: ");
		scanf("%d", &p);
		while (p < 0 || p > 10) {
				printf("Invalid number! Please enter again: ");
				scanf("%d", &p);
		}
	printf("The point you enter is: %d", p);
	} else {
		printf("Thank you for using nothing!");
	}
	return 0;
}
