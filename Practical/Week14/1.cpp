#include<stdio.h>
typedef struct Date {
	unsigned char day; 
	unsigned char month;
	int year;
	} date_t; 
Date get() {
	Date tmp;
	do {
		printf("The day between 1 and 31: "); scanf("%u", &tmp.day);
	} while((tmp.day < 1 || tmp.day > 31));
	do {
		printf("The month between 1 and 12: "); scanf("%u", &tmp.month);
	} while(tmp.month < 1 || tmp.month > 12);
	do {
		printf("The year between 1 and 10000: "); scanf("%d", &tmp.year);
	} while(tmp.year < 1 || tmp.year > 10000);
	return tmp;
}
int datecmp(Date d1, Date d2) {
	if(d1.year < d2.year) return -1;
	else if(d1.year > d2.year) return 1;
	else {
		if(d1.month < d2.month) return -1;
		else if(d1.month > d2.month) return 1;
		else {
			if(d1.day < d2.day) return -1;
			else if(d1.day > d2.day) return 1;
			else return 0;
		}
	}
}
int main() {
	Date d1, d2;
	int m;
	printf("Enter first date: \n"); d1 = get();
	printf("Enter second date: \n"); d2 = get();
	m = datecmp(d1, d2);
	if(m == 0) printf("Two dates are identical.\n");
	else if(m == 1) printf("%d/%d/%d is after %d/%d/%d.\n", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
	else printf("%d/%d/%d is before %d/%d/%d.\n", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
	return 0;
}
