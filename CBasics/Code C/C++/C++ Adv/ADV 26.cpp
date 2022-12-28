#include<iostream>
using namespace std;
struct Lam { //Khai bao struct student voi 2 thuoc tinh la name va age
	string name;
	int age;
}; //Co dau ;
int main() {
	//De truy xuat vao thuoc tinh cua 1 doi tuong kieu struct ta co the goi tendoituong.tenthuoctinh
	Lam a;
	cin >> a.name >> a.age;
	cout << "Name: " << a.name << endl << "Age: " << a.age;
	return 0;
}
