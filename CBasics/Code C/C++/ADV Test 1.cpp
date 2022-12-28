//Dung ham sizeof() de lay ra kich thuoc cua 1 bien hoac 1 kieu du lieu
#include<iostream>
using namespace std;
int main() {
	char ch = 'a';
	char* p = (char*)&ch;
	cout << "Size of p: " << sizeof(p);
	return 0;
}
