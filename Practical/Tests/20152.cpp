#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct {
	int id;
	char name[30];
	int x, y;
	int r;
	float dist;
} station;

station list[50];
int n, cnt;

void insert();
void extra();
void print1();
void cal(station *pt);
void print2();
void sort();

int check(int u, int v) {
	int i;
	if(v == 0) return 1;
	for(i = 0; i < v; i++) {
		if(list[i].id == u) return 0;
	}
	return 1;
}

void getinf(station *ps, int u) {
	printf("Enter ID: "); 
	scanf("%d", &ps->id);
	while(check(ps->id, u) == 0) {
		printf("Invalid! Try again: ");
		scanf("%d", &ps->id);
	}
	fflush(stdin);
	printf("Name (max 30 characters): "); gets(ps->name);
	while(strlen(ps->name) > 30) {
		printf("Invalid! Try again: ");
		fflush(stdin);
		gets(ps->name);
	}
	printf("Enter cordination: \n");
	printf("X: "); scanf("%d", &ps->x);
	printf("Y: "); scanf("%d", &ps->y);
	printf("Enter radius [1;100]: "); scanf("%d", &ps->r);
	while(ps->r < 1 || ps->r > 100) {
		printf("Invalid! Try again: ");
		scanf("%d", &ps->r);
	}
}
void display(station *ps) {
	printf("%-6d%-30s(%d, %d)\t%-15d\n", ps->id, ps->name, ps->x, ps->y, ps->r);
}

void menu() {
	int func, con;
	printf("Here is list of services: \n");
	printf("Please choose of these below: \n");
	do {
		printf("(1). Insert.\t\t(2). Add insert.\n(3). Check list.\t(4). Calculate distance.\n(5). Exit\n");
		printf("Enter the service you want: "); scanf("%d", &func);
		while(func < 1 || func > 5) {
			printf("Invalid service, try again: "); 
			scanf("%d", &func);
		}	
		switch(func) {
			case 1:
				insert();
				break;
			case 2:
				if(cnt == 0) {
					printf("No information! Choose 1 first!");
					break;
				}
				extra();
				break;
			case 3: 
				if(cnt == 0) {
					printf("No information! Choose 1 first!");
					break;
				}
				print1();
				break;
			case 4: 
				if(cnt == 0) {
					printf("No information! Choose 1 first!");
					break;
				}
				print2();
				break;
			case 5: 
				printf("\nThank you for using our services!\n");
				exit(0);
			default:
				printf("Invalid number! Please try again: ");
				break;		
		}
		printf("\nDo you want to continue (1). Yes/ (2). No: ");
		scanf("%d", &con);
		while(con < 1 || con > 2) {
			printf("Invalid! Try again: ");
			scanf("%d", &con);
		}
	} while(con == 1);
	printf("\nThank you for using our services!\n");
}

void insert() {
	int i;
	cnt++;
	printf("\nEnter number of station captain: "); scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("\nStation captain %d: \n", i + 1);
		getinf(&list[i], i);	
	}
}
 
void extra() {
	int e, i; //extra
	cnt++;
	printf("\nEnter extra number of SC: "); 
	fflush(stdin);
	scanf("%d", &e);
	while(n + e > 50)
	{
		printf("Invalid! Try again: ");
		fflush(stdin);
		scanf("%d", &e);
	}
	n += e;
	for(i = n - e; i < n; i++) {
		printf("\nStation captain %d: \n", i + 1);
		getinf(&list[i], i);
	}
}

void print1() {
	int i;
	printf("\n%-6s%-30s%s\t%s\n", "ID", "Ho ten", "Toa do", "Ban kinh");
	for(i = 0; i < n; i++) {
		display(&list[i]);	
	}
}

void print2() {
	int i, j;
	for(i = 0; i < n; i++) {
		cal(&list[i]);
	}
	printf("\nNew list:\n");
	printf("\n%-6s%-30s%s\t%s\t%s\n", "ID", "Ho ten", "Toa do", "Ban kinh", "Khoang cach");
	for(i = 0; i < n; i++) {
		printf("%-6d%-30s(%d, %d)\t%d\t\t%.2f\n", list[i].id, list[i].name, list[i].x, list[i].y, list[i].r, list[i].dist);
	}
	station tmp;
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			if(list[i].dist < list[j].dist) {
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
	printf("\nList after sorted: \n");
	printf("\n%-6s%-30s%s\t%s\t%s\n", "ID", "Ho ten", "Toa do", "Ban kinh", "Khoang cach");
	for(i = 0; i < n; i++) {
		printf("%-6d%-30s(%d, %d)\t%d\t\t%.2f\n", list[i].id, list[i].name, list[i].x, list[i].y, list[i].r, list[i].dist);
	}
}

void cal(station *pt) {
	pt->dist = sqrt(pow(pt->x, 2) + pow(pt->y, 2));
}
int main() {
	menu();
	return 0;
}

