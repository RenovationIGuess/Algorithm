#include<iostream> 
using namespace std;
int main() {
	int n, type, cnt[5]; cin >> n;
	for(int i = 1; i <= 5; i++) cnt[i] = 0; //set up mang voi cac gia tri dem i <=> type
	for(int i = 1; i < n; i++) {
		cin >> type;
		cnt[type]++;
	} //Tao vong lap de nhap loai chim dong thoi dem luon so lan xuat hien
	int temp = cnt[1], max = 1; //Tao bien de sap xep: temp = temporary
	for(int i = 1; i <= 5; i++) {
		for(int j = i+ 1; j <= 5; j++) {
			if (cnt[j] > temp) {
				temp = cnt[j];
				max = j;
			}
		}
	}
	cout << max; /*Vong lap nay co the xu li ca truong hop i = j do neu i = j <=> cnt[i] = cnt[j]
	thi phan trong if se khong duoc thuc hien va no tiep xuc xet. */
	return 0;
}


