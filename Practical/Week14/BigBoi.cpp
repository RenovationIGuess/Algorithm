#include<stdio.h>
//#define _GNU_SOURCE
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 1000
int n, func, cnt;
//int strcasecmp(const char *s1, const char *s2);
//char *strcasestr (const char *big, const char *little); 
void fix(char s[]);
bool isWhite(char c);
bool speC(char c);
void res(char s[]);
struct ResInf { //restaurant information
	char Name[31];
	char Description[501];
	float Rating; //rating: [0;5]
	char Address[101];
	void GetInf() {
		fflush(stdin);
		printf("Enter Res's name: "); gets(Name);
		fflush(stdin);
		printf("Enter description: "); gets(Description);
		printf("Enter rating (from 1 to 5): "); scanf("%f", &Rating);
		while(Rating > 5 || Rating < 0) {
			printf("Invalid Rating number, enter again: ");
			scanf("%f", &Rating);
		}
		fflush(stdin);
		printf("Enter address: "); gets(Address);
	}
	void display() {
		fix(Name);
		printf("Name: %s\n", Name);
		res(Description);
		printf("Description: %s\n", Description);  
		printf("Rating: %.1f\n", Rating);
		res(Address);
		printf("Address: %s\n", Address);
	}
};	
ResInf Restaurant[MAX]; //Array of restaurant
char *strcasestr(const char *str, const char *pattern) {
    size_t i;

    if (!*pattern)
        return (char*)str;

    for (; *str; str++) {
        if (toupper((unsigned char)*str) == toupper((unsigned char)*pattern)) {
            for (i = 1;; i++) {
                if (!pattern[i])
                    return (char*)str;
                if (toupper((unsigned char)str[i]) != toupper((unsigned char)pattern[i]))
                    break;
            }
        }
    }
    return NULL;
}
void Insert() {
	int e; //extra
	if(cnt == 0) {
		printf("\nEnter number of restaurant: "); scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			printf("\nNha hang %d:\n", i + 1);
			Restaurant[i].GetInf();
		}
		++cnt;
	} else {
		printf("\nEnter number of extra restaurant: "); scanf("%d", &e);
		n += e; //n = n + e
		for(int i = n - e; i < n; i++) {
			printf("Nha hang %d:\n", i + 1);
			Restaurant[i].GetInf();
		}
	}
}
bool checkname(char const *s1, char const *s2) {
	int result = strcasecmp(s1, s2);
	if(result == 0) return true;
	else return false;
}
void Print() {
	for(int i = 0; i < n; i++) {
		printf("\nNha hang %d:\n", i + 1);
		Restaurant[i].display();
		//printf("\n");
	}
}
void Findname() {
	int m = 0; //h to check if there is any case that does not meet the request
	char resname[31]; 
	printf("\nEnter res'name you want to find: "); 
	fflush(stdin);
	gets(resname); 
	printf("\n");
	for(int i = 0; i < n; i++) {
		if(checkname(resname, Restaurant[i].Name)) {
			Restaurant[i].display();
			m++;
		}
	}
	if(m == 0) printf("Not found!\n");
}
bool checkdes(char const *s1, char const *s2) {
	char *look = strcasestr(s1, s2);
	if(look == NULL) return true;
	else return false; 
}
void Finddes() {
	int h = 0; //h to check if there is any case that does not meet the request
	char food[501];
	printf("\nEnter food's name you want to find: ");
	fflush(stdin); 
	gets(food);
	for(int i = 0; i < n; i++) {
		if(checkdes(food, Restaurant[i].Description)) {
			printf("Nha hang %d:\n", i + 1); Restaurant[i].display();
			h++;
		}
	}
	if(h == 0) printf("\nNot found!\n");
}
void sort() {
	ResInf tmp;
	int tmp1;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(Restaurant[i].Rating < Restaurant[j].Rating) {
				tmp = Restaurant[i];
				Restaurant[i] = Restaurant[j];
				Restaurant[j] = tmp;
				/*tmp1 = i;
				i = j; 
				j = tmp1; */
			}
		}
	}
	for(int i = 0; i < n; i++) {
		printf("\nNha hang %d: \n", i + 1);
		Restaurant[i].display();
		//printf("\n");
	}
}
void menu() {
	cnt = 0; int cont = 0, go; //count number of 1's appear times and to continue or not
	printf("Welcome to our service (>.<)!\n");
	do {
		printf("Please choose one of our services below:\n");
		printf("(1). Insert\t\t(2). Print\n(3). Find - Name\t(4). Find - Des\n(5). Sort\t\t(6). Exit\n");
		printf("Enter number of the service you want: "); 
		scanf("%d", &func);
		switch(func) {
			case 1:
				Insert();
				break;
			case 2: 
				if(cnt == 0) {
					printf("\nTo use this please choose 1 first!\n"); 
					break;
				}
				Print();
				break;
			case 3:
				if(cnt == 0) {
					printf("\nTo use this please choose 1 first!\n"); 
					break;
				}
				Findname();
				break;
			case 4: 
				if(cnt == 0) {
					printf("\nTo use this please choose 1 first!\n"); 
					break;
				}
				Finddes();
				break;
			case 5:
				if(cnt == 0) {
					printf("\nTo use this please choose 1 first!\n"); 
					break;
				}
				sort();
				break;
			case 6:
				printf("Are you sure you want to quit ((1). Yes - (2). No): ");
				scanf("%d", &cont);	
				while(cont != 1 && cont != 2) {
					printf("Only (1) or (2) is accepted, enter again: "); 
					scanf("%d", &cont);
				}
				break; 
			default:
				printf("Invalid number! Please try again:");
				break;
			}
			printf("\nDo you want to continue ((1).Yes - (2).No): ");
			scanf("%d", &go); printf("\n");
			while(go != 1 && go != 2) {
				printf("Only (1) or (2) is accepted, enter again: "); 
				scanf("%d", &go);
			}
	} while(cont == 1 || go == 1);
	printf("=============================================\n");
	printf("See you next time!\nSorry for not having what you want :<\n");
}

int main() {
	menu();
	return 0;
}

bool isWhite(char c) {
	return c == ' ' || c == '\t' || c == '\n'; //true neu c la cac ky tu sau
}
bool speC(char c) { //special character
	return c == ':' || c == '[' || c == ']' || c == ';' || c == '/' || c == '.' 
	|| c == ',' || c == '!';
}
void fix(char s[]) {
	while(isWhite(s[0]) || speC(s[0])) {
		strcpy(&s[0], &s[1]);
	}
	for(int i = 0; i < strlen(s); i++) {
		if(isWhite(s[i]) && isWhite(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		} else if(isWhite(s[i]) && speC(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		} else if(speC(s[i]) && isWhite(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		} else if(speC(s[i]) && speC(s[i + 1])) {
			strcpy(&s[i], &s[i + 1]);
			i--;
		}
	}
	while(isWhite(s[strlen(s) - 1]) || speC(s[strlen(s) - 1])) {
		strcpy(&s[strlen(s) - 1], &s[strlen(s)]);
	}
}
void res(char s[]) { //res - reset
	int len = strlen(s);
	for(int i = 0; i < len; i++) {
		if(isWhite(s[i]) && isWhite(s[i + 1])) {
			for(int j = i + 1; j < len; j++) {
				s[j] = s[j + 1];
			}
			i--;
			len--;
		} else if(isWhite(s[i]) && speC(s[i + 1])) {
			for(int j = i; j < len; j++) {
				s[j] = s[j + 1];
			}
			i--;
			len--;
		}
	}
}
