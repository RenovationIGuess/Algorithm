#include<stdio.h>
int main() {
	int n; //Khai bao so nguyen n
	scanf("%d", &n); //Nhap tu ban phim
	int arr[n]; //Khai bao mang gom n phan tu
	for (int i = 0; i < n; i++) { //Tao vong lap nhap tu ban phim n phan tu tinh tu 0
		scanf("%d", &arr[i]); //Nhap tu ban phim	
	}
	int k; //Khai bao so nguyen k
	scanf("%d", &k); //Nhap tu ban phim
	int l = 0; //So phan tu co the = 0, gan gia tri ban dau
	for (int i = 0; i < n; i++) { //Tao vong lap de ktra dieu kien
		if (arr[i] == k) {
			l++; //Moi lan dieu kien trong () cua if thoa man thi l = l + 1
		}
		
	}
	printf("%d", l);
	return 0;
}
