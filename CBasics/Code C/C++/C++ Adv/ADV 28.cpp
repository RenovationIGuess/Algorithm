#include<iostream>
using namespace std;
struct Student {
	string name;
	int age;
	void display() {
		cout << "Name: " << name << endl << "Age: " << age << endl;
	}
};
int main() {
	int n;
	cin >> n;
	Student* a = new Student[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i].name >> a[i].age;
	}
	for (int i = 0; i < n; i++) {
		a[i].display(); //phuong thuc display de hien thi
	}
	delete[]a;
	return 0;
}
