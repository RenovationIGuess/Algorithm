#include<stdio.h>
void EP(int p[], int n); //EP: Enter Points, n: number, p: array of point
float sum(int p[], int n);
int max(int p[], int n);
void smaller(int p[], int n);
int main() {
	int s, count = 0; //s: service, count: number of time user enter 1
	int n, p[1000]; 
	printf("Welcome to our service! Please choose one of these services below:\n");
	do {
		printf("1: Students points\t\t2: Sum\t\t3: Max\t\t4: points that < 4\t\t5: Exit\n");
		printf("Enter number of the service you want: "); scanf("%d", &s);
		if (s != 1 && count == 0) {
			printf("Please have info first, choose (1) or exit(5): ");
			scanf("%d", &s);
		}
		if (s == 1 && count == 0) {
			printf("Enter number of students: "); scanf("%d", &n);
			for (int i = 1; i <= n; i++) {
				printf("Enter student %d point: ", i); scanf("%d", &p[i]);
				if (p[i] > 10 || p[i] < 0) {
					printf("You entered wrong number! Enter again: "); scanf("%d", &p[i]);
				}
			}
			count++;
		} else if (s == 1 && count != 0) {
			int e; //extra
			printf("Enter extra students: "); scanf("%d", &e);
			n = n + e;
			for (int i = n - e + 1; i <= n; i++)  {
				printf("Enter student %d point: ", i); scanf("%d", &p[i]);
				if (p[i] > 10 || p[i] < 0) {
					printf("You entered wrong number! Enter again: "); scanf("%d", &p[i]);
				}
			}
		} 
		if (s == 2) {
			printf("The average point is: %.2f\n", sum(p, n));
		}
		if (s == 3) {
			printf("The highest point is: %d\n", max(p, n));
		}
		if (s == 4) {
			printf("Students who has point < 4:\n");
			smaller(p, n);
		}
	} while (s != 5);
	printf("Thank you!");
	return 0;
}
/*void EP(int p[], int n) {
	int e; //extra
	printf("Enter extra students: "); scanf("%d", &e);
	n = n + e;
	for (int i = n - e + 1; i <= n; i++)  {
		printf("Enter student %d point: ", i); scanf("%d", &p[i]);
		if (p[i] > 10 || p[i] < 0) {
			printf("You entered wrong number! Enter again: "); scanf("%d", &p[i]);
		}
	}
} */
float sum(int p[], int n) {
	float t = 0; //t: total
	for (int i = 1; i <= n; i++) {
		t += p[i];
	}
	return t/n;
}
int max(int p[], int n) {
	int h = p[1]; //h: highest
	for (int i = 1; i <= n; i++) {
		if (p[i] > h) {
			h = p[i];
		}
	}
	return h;
}
void smaller(int p[], int n) {
	bool check = false;
	for (int i = 1; i <= n; i++) {
		if (p[i] < 4) {
			check = true;
			printf("%d ", p[i]);
		} 
	} printf("\n");
	if (check == false) printf("No students have point < 4\n");
}


 
