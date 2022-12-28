#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct {
	char id[6];
	char name[31];
	float grade;
	char classment;
} student;
void print(student s) {
	printf("|ID\t|Name\t\t\t|Grade\t\t|Classment\t|\n");
	printf("|%s\t|%s\t|%1.1f\t\t|%c\t\t|\n", s.id, s.name, s.grade, s.classment);
}
int main() {
	int i, n;
	student std[MAX], tmp;
	printf("Enter the number of student (> 0): ");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		fflush(stdin);
		printf("ID: "); gets(std[i].id);
		printf("Name: "); gets(std[i].name);
		printf("Grade: "); scanf("%f", &std[i].grade);
		if(std[i].grade >= 9 && std[i].grade <= 10) {
			std[i].classment = 'A';
		} else if (std[i].grade >= 8 && std[i].grade < 9) {
			std[i].classment = 'B';
		} else if(std[i].grade >= 6.5 && std[i].grade < 8) {
			std[i].classment = 'C';
		} else std[i].classment = 'D';
	}
	for(i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(std[i].grade < std[j].grade) {
				student tmp = std[i];
				std[i] = std[j];
				std[j] = tmp; 
			}
		}
	}
	for(i = 0; i < n; i++) {
		print(std[i]);
	}
	return 0;
}
