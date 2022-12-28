#include<iostream> 
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int** arr; //Khai bao con tro cap 2 (con tro tro toi con tro) =))
	arr = new int* [n]; //Cap phat vung nho dong cho mang 1 chieu cac con tro kieu int*
	//arr la mang gom n phan tu, moi phan tu la mot con tro kieu int*
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m]; //Cap vung nho dong cho n mang 1 chieu m phan tu
	}
	/*Mang 2 chieu co the hieu la mang mot chieu cac con tro va cac con tro nay tro toi phan
	tu dau tien cua mang duoc cap phat dong => cap phat dong cho mang 2 chieu thuc ra la cap 
	phat dong cho mang mot chieu
	- Buoc dau la khai bao 1 con tro cap 2 => Cap phat cho con tro cap 2 n con tro cap 1 => cap phat cho con tro 
	cap 1 m phan tu voi con tro cap 1 dung de duyet mang (... de bo sung) */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j]; //Nhap du lieu cac phan tu trong mang
		}
	}
	
	for (int i = 0; i < n; i++) {
		int a = 0;/*Khai bao tong cua cac phan tu theo hang cua mang (cau lenh dat trong cau lenh for duyet hang vi moi lan
		vong lap lap lai thi gia tri a se t.u vs tong hang do, neu a o ngoai vong lap for thi no <=> tong hang 1 + tong hang 2 + tong hang 3 r in ra <=> sai! */
		for (int j = 0; j < m; j++) {
			a += arr[i][j];		
		}
		cout << a << endl; /*De bai yeu cau hien thi tong cua cac hang trong mang nen dong lenh hien thi gia 
		tri cua a phai duoc dat trong vong lap for duyet hang i <=> het hang 1 den hang 2 ... */
	}
	for (int i = 0; i < n; i++) {
		delete[]arr[i];
	}
	//Cau lenh tren la cau lenh giai phong bo nho cua mang 1 chieu (cu phap khai bao: delete[] ten_mang)
	delete[]arr; //Giai phong bo nho cho mang cac con tro 
	return 0;
}
