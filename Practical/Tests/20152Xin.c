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

char s[55][50];
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

void create(station *ps, int u)
{
	int cnt1 = 0, cnt2 = 0, tmp1 = ps->x, tmp2 = ps->y;
	int a = ps->x;
	int b = ps->y;
	while(tmp1 > 0)
	{
		tmp1 /= 10;
		cnt1++;
	} cnt1--;
	while(tmp2 > 0)
	{
		tmp2 /= 10;
		cnt2++;
	} cnt2--;
	s[u][0] = '(';
	int i = 1;
	if(ps->x < 0) 
	{
		s[u][i] = '-';
		i++;
	}
	int k = i + cnt1;
	int tmp5 = k;
	while(cnt1 > 0)
	{
		int tmp3 = cnt1, tmp4 = 1;
		while(tmp3 > 0)
		{
			tmp4 *= 10;
			tmp3--;
		}
		s[u][k] = a % tmp4 + '0';
		a /= 10;
		cnt1--;
		k--;
	}
	s[u][i] = a + '0';
	i = tmp5;
	i++;
	s[u][i] = ',';
	i++;
	if(ps->y < 0)
	{
		s[u][i] = '-';
		i++;
	}
	int j = i + cnt2;
	int tmp6 = j;
	while(cnt2 > 0)
	{
		int tmp3 = cnt2, tmp4 = 1;
		while(tmp3 > 0)
		{
			tmp4 *= 10;
			tmp3--;	
		}
		s[u][j] = b % tmp4 + '0';
		b /= 10;
		cnt2--;
		j--;
	}
	s[u][i] = b + '0';
	i = tmp6;
	i++;
	s[u][i] = ')';
}

void getinf(station *ps, int u) {
	printf("Enter ID: "); 
	fflush(stdin);
	scanf("%d", &ps->id);
	while(check(ps->id, u) == 0) {
		printf("Invalid! Try again: ");
		fflush(stdin);
		scanf("%d", &ps->id);
	}
	printf("Name (max 30 characters): "); 
	fflush(stdin);
	gets(ps->name);
	while(strlen(ps->name) > 30) {
		printf("Invalid! Try again: ");
		fflush(stdin);
		gets(ps->name);
	}
	printf("Enter cordination: \n");
	printf("X: ");
	fflush(stdin); 
	scanf("%d", &ps->x);
	printf("Y: ");
	fflush(stdin); 
	scanf("%d", &ps->y);
	printf("Enter radius [1;100]: ");
	fflush(stdin); 
	scanf("%d", &ps->r);
	while(ps->r < 1 || ps->r > 100) {
		printf("Invalid! Try again: ");
		fflush(stdin);
		scanf("%d", &ps->r);
	}
}

void display(station *ps, int u) {
	printf("%-6d%-30s%-15s%-15d\n", ps->id, ps->name, s[u], ps->r);
}

void menu() {
	int func;
	printf("Here is list of services: \n");
	printf("Please choose of these below: \n");
	do {
		printf("(1). Insert.\t\t(2). Add insert.\n(3). Check list.\t(4). Calculate distance.\n(5). Exit\n");
		printf("Enter the service you want: "); 
		fflush(stdin);
		scanf("%d", &func);
		while(func < 1 || func > 5) {
			printf("Invalid service, try again: "); 
			fflush(stdin);
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
				break;
			default:
				printf("Invalid number! Please try again: ");
				break;		
		}
	} while(func != 5);
}

void insert() {
	int i;
	cnt++;
	printf("\nEnter number of station captain: "); 
	fflush(stdin);
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("\nStation captain %d: \n", i + 1);
		getinf(&list[i], i);
		create(&list[i], i);	
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
	for(i = n - e; i < n; ++i) {
		printf("\nStation captain %d: \n", i + 1);
		getinf(&list[i], i);
		create(&list[i], i);
	}
}

void print1() {
	int i;
	printf("\n%-6s%-30s%-15s%-10s\n", "ID", "Ho ten", "Toa do", "Ban kinh");
	for(i = 0; i < n; i++) {
		display(&list[i], i);	
	}
}

void print2() {
	int i, j;
	for(i = 0; i < n; i++) {
		cal(&list[i]);
	}
	
	printf("\nNew list:\n");
	printf("\n%-6s%-30s%-15s%-10s%-10s\n", "ID", "Ho ten", "Toa do", "Ban kinh", "Khoang cach");
	
	for(i = 0; i < n; i++) 
		printf("%-6d%-30s%-15s%-10d%-10.2f\n", list[i].id, list[i].name, s[i], list[i].r, list[i].dist);
	
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
	printf("\n%-6s%-30s%-15s%-10s%-10s\n", "ID", "Ho ten", "Toa do", "Ban kinh", "Khoang cach");
	for(i = 0; i < n; i++) {
		printf("%-6d%-30s%-15s%-10d%-10.2f\n", list[i].id, list[i].name, s[i], list[i].r, list[i].dist);
	}
}

void cal(station *pt) {
	pt->dist = sqrt(pow(pt->x, 2) + pow(pt->y, 2));
}
int main() {
	menu();
	return 0;
}

