#include<iostream>
using namespace std;
struct SinhVien {
	string name;
	int age, score;
};
int main() {
	int n;
	cin >> n;
	SinhVien *a = new SinhVien[n]; /*Cap phat dong cho mang co n phan tu 
	Cu phap: Kieu_du_lieu* ten_con_tro = new (toan tu) Kieu_du_lieu[so phan tu]; */
	//Duyet mang
	for (int i = 0; i < n; i++) {
		cin >> a[i].name >> a[i].age >> a[i].score;
	}
	//Khai bao phan tu de thuc hien ycbt (so sanh)
	SinhVien b = a[0]; //Kieu du lieu SinhVien, b = phan tu dau tien trong mang
	for (int i = 1; i < n; i++) { //Xet tu phan tu thu 2
		if (a[i].score > b.score) {
			b = a[i];
		}			 
	}
	cout << "Name: " << b.name << endl << "Age: " << b.age << endl << "Score: " << b.score;
	delete[] a;
	return 0;
}
