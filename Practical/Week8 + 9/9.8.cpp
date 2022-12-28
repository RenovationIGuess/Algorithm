#include<stdio.h>
#include <stdlib.h>
void getJudgeData(double *s);
double findLowest(double s1, double s2, double s3, double s4, double s5);
double findHighest(double s1, double s2, double s3, double s4, double s5);
void calcScore(double s1, double s2, double s3, double s4, double s5);
int main() {
	double s1, s2, s3, s4, s5;
	getJudgeData(&s1);
	getJudgeData(&s2);
	getJudgeData(&s3);
	getJudgeData(&s4);
	getJudgeData(&s5);
	calcScore(s1, s2, s3, s4, s5);
	return 0;
}
void getJudgeData(double *s) {
	do {
		printf("Enter a judge's score: "); scanf("%f",s);
	} while (*s < 0 || *s > 10);
}
double findLowest(double s1, double s2, double s3, double s4, double s5) {
	double min = s1;
	if (s2 < min) min = s2;
	if (s3 < min) min = s3;
	if (s4 < min) min = s4;
	if (s5 < min) min = s5;
	return min;
}
double findHighest(double s1, double s2, double s3, double s4, double s5) {
	double max = s1;
	if (s2 > max) max = s2;
	if (s3 > max) max = s3;
	if (s4 > max) max = s4;
	if (s5 > max) max = s5;
	return max;
}
void calcScore(double s1, double s2, double s3, double s4, double s5) {
	double sum = s1 + s2 + s3 + s4 + s5;
	double max = findHighest(s1, s2, s3, s4, s5);
	double min = findLowest(s1, s2, s3, s4, s5);
	sum -= (max + min);
	printf("Max = %1.2f\n", max);
	printf("Min = %1.2f\n", min);
	printf("Final score: %1.2f\n", sum / 3);
}
