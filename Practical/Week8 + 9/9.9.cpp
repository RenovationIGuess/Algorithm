#include<stdio.h>
#include <stdbool.h> 
bool isLeapYear(int y);
int main() {
	int y; //year
	printf("Enter year = "); scanf("%d", &y);
	if(isLeapYear(y) == true) {
		printf("%d is LeapYear!", y);
	} else printf("%d is not LeapYear!", y);
	return 0;
}
bool isLeapYear(int y) {
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
		return true;
	} else return false;
	//return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}

