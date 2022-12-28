/* Mang 2 chieu ban chat nhu 1 ma tran, VD: arr[i][j] co the hieu la phan tu o hang i cot j cua ma tran
	- Vay neu ta khai bao arr[n][m] tuc la ma tran n hang m cot
	- Cu phap khai bao int arr(bien co the khac)[?][?]; */
#include<stdio.h>
int main() {
	int n, m; //Khai bao 2 bien nguyen n, m
	scanf("%d%d", &n, &m); //Nhap tu ban phim
	int arr[n][m]; //Khai bao mang 2 chieu theo cu phap
	for (int i = 0; i < n; i++) { //Tao vong lap de nhap gia tri cua hang va cot
	/* Khi tao vong lap nhu vay, neu ta for cua i truoc j thi i se chay truoc j va nguoc lai
	Tuc la:
arr[0][0] = 
arr[0][1] = 
arr[0][2] =
arr[0][3] = 
arr[1][0] = 
arr[1][1] = 
arr[1][2] = 
arr[1][3] =
arr[2][0] = 
arr[2][1] = 
arr[2][2] = 
arr[2][3] = 
Hieu don gian la hang truoc thi se nhap gia tri theo hang, cot truoc thi vong lap cho nhap gia tri theo cot */
		for (int j = 0; j < m; j++) { 
			scanf("%d", &arr[i][j]); //Khi nhap gia tri quy luat se nhu tren
		}
	}
	int sum = 0; //Khai bao bien trung gian la tong
	for (int i = 0; i < n; i++) { //Tao vong lap de kiem tra
		for (int j = 0; j < m; j++) {
			sum += arr[i][j]; // <=> sum = sum + arr[i][j] Moi lan dieu kien lap thoa man thi + tiep
		}
	}
	printf("%d", sum); //Hien thi sum (dat o ngoai vi khong lq den vong lap)
	return 0;
}
