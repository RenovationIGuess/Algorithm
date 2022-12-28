#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10

int n;
int cnt = 0, cnt2 = 0;

typedef struct {
	char hoten[30];
	int diem[5] ;
} ketquathidau;

ketquathidau vdv[MAX];

int check(char s[]) {
	int i;
	for(i = 1; i < strlen(s); i++) {
		if(isupper(s[i]) != 0 && isspace(s[i - 1]) == 0) {
			return 0;
		}
	}
	return 1;
}

void getinf(ketquathidau *p) {
	printf("Ten van dong vien: "); 
	fflush(stdin); 
	gets(p->hoten);
	while(check(p->hoten) == 0) {
		printf("\nTen khong hop le!\n");
		printf("Nhap lai: ");
		fflush(stdin); 
		gets(p->hoten);
	}
}

void dangky() {
	cnt++;
	printf("\nSo van dong vien dang ky: "); 
	fflush(stdin); 
	scanf("%d", &n);
	while(n < 0 || n > MAX) {
		printf("\nSo van dong vien khong hop le!\n");
		printf("\nHay nhap lai: ");
		fflush(stdin);
		scanf("%d", &n);
	}
	int i;
	for(i = 0; i < n; i++) {
		printf("\nThong tin van dong vien thu %d: \n", i + 1);
		getinf(&vdv[i]);
	}
	printf("\n%-10s%-35s\n", "STT", "Ho va ten");
	for(i = 0; i < n; i++) {
		printf("%-10d%-35s\n", i + 1, vdv[i].hoten);
	}
}

void getpt(ketquathidau *p) {
	int i;
	for(i = 0; i < 5; i++) {
		printf("Diem lan %d: ", i + 1); 
		fflush(stdin); 
		scanf("%d", &p->diem[i]);
		while(p->diem[i] < 0 || p->diem[i] > 10) {
			printf("Diem khong hop le!\n");
			printf("Nhap lai: "); 
			fflush(stdin); 
			scanf("%d", &p->diem[i]);
		}
	}
}

void thidau() {
	cnt2++;
	int i, j;
	for(i = 0; i < n; i++) {
		printf("\nDiem cua van dong vien thu %d: \n", i + 1);
		getpt(&vdv[i]);
	}
	printf("\n%-30s%-10s%-10s%-10s%-10s%-10s\n", "Ho va ten", "1", "2", "3", "4", "5"); 
	for(i = 0; i < n; i++) {
		printf("%-30s", vdv[i].hoten);
		for(j = 0; j < 4; j++) {
			printf("%-10d", vdv[i].diem[j]);
		} printf("%-10d\n", vdv[i].diem[4]);
	}
}

void xephang() {
	int i, j;
	int tong[MAX];
	for(i = 0; i < MAX; i++) {
		tong[i] = 0;
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < 5; j++) {
			tong[i] += vdv[i].diem[j];
		}
	}
	int tmp;
	ketquathidau tmp1;
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			if(tong[i] < tong[j]) {
				tmp = tong[i];
				tong[i] = tong[j];
				tong[j] = tmp;
				tmp1 = vdv[i];
				vdv[i] = vdv[j];
				vdv[j] = tmp1;
			}
		}
	}
	char rank[3][10] = {"Gold", "Silver", "Bronze"};
	printf("\n%-30s%-10s%s\n", "Ho va ten", "Hchuong", "Diem");
	if(n < 3) {
		for(i = 0; i < n; i++) {
			printf("%-30s%-10s%d\n", vdv[i].hoten, rank[i], tong[i]);
		}
	} else {
		for(i = 0; i < 3; i++) {
			printf("%-30s%-10s%d\n", vdv[i].hoten, rank[i], tong[i]);
		}
	}
}

int count[MAX];

int check(ketquathidau *p) {
	int i, j;
	for(i = 0; i < n; i++) {
		count[i] = 0;
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < 5; j++) {
			if(p->diem[j] == 10) {
				++count[i];
				if(count[i] == 3) return 1;
			}
			else count[i] = 0;
		}
	}
	return 0;
}

int check1() {
	int i;
	for(int i = 0; i < n; i++) {
		if(count[i] == 3) return 1;
	}
	return 0;
}

void sieuxathu() {
	int i, j;
	if(check1() == 1) {
		printf("\nNhung van dong vien \"Sieu xa thu\": \n");
		for(i = 0; i < n; i++) {
			if(check(&vdv[i]) == 1) {
				printf("%-30s", vdv[i].hoten);
				for(j = 0; j < 4; j++) {
					printf("%-10d", vdv[i].diem[j]);
				} printf("%-10d\n", vdv[i].diem[4]);	
			}
		}	
	} else printf("\nKhong co van dong vien \"Sieu xa thu\" nao!\n");
}

void menu() {
	int func, cont;
	printf("Chuong trinh gom cac chuc nang: \n"); 
	do {
		printf("\n(1). Dang ky van dong vien.\n(2). Thi dau.\n(3). Xep hang.\n(4). Sieu xa thu.\n(5). Thoat chuong trinh.\n");
		printf("\nHay chon chuc nang: "); fflush(stdin); scanf("%d", &func);
		switch(func) {
			case 1:
				dangky();
				break;
			case 2:
				if(cnt == 0) {
					printf("Hay dang ky thi dau truoc!\n");
					break;
				}
				thidau();
				break;
			case 3:  
				if(cnt == 0) {
					printf("Hay dang ky thi dau truoc!\n");
					break;
				}
				if(cnt2 == 0) {
					printf("Hay thi dau truoc!\n");
					break;
				}
				xephang();
				break;
			case 4: 
				if(cnt == 0) {
					printf("Hay dang ky thi dau truoc!\n");
					break;
				}
				if(cnt2 == 0) {
					printf("Hay thi dau truoc!\n");
					break;
				}
				sieuxathu();
				break;
			case 5: 
				printf("\nCam on da su dung!\n");
				exit(0);
			default: 
				printf("Chuc nang ban nhap khong hop le!");
				break;
		}
		printf("\nBan co muon tiep tuc khong(1. Co - 2. Khong): "); scanf("%d", &cont);
	} while(cont == 1);
	printf("\nCam on da su dung!\n");
}

int main() {
	menu();
	return 0;
}
