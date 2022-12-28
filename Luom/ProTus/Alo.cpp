#include<stdio.h>
int main() {
	int n, p, min; //Tao mang de nhap cay, khai bao mang cnt - count gom n phan tu - tac dung de dem bac cua 1 dinh
	/* So lan xuat hien cua dinh khi nhap = so bac cua dinh VD: 0 2 0 3 <=> 0 xuat hien 2 lan, bac = 2 */
	/* Cay gom n dinh voi nhan cua dinh chay tu 0 - (n - 1), co n cap canh khi nhap */
	//Input la so canh => so dinh la n + 1
	//Bien p co tac dung: de khi thoat ra vong lap j ta co the tuong tac voi tree[j][0/1]
	scanf("%d", &n);
	int tree[n][2], cnt[n + 1];
	for (int i = 0; i <= n; i++) cnt[i] = 0; //Tao vong lap gan cho bac ban dau cua cac dinh = 0
	for (int j = 0; j < n; j++) {						//1 cay n dinh thi co n - 1 canh 
								//Nhap nhan cho dinh, moi lan nhap nhan so bac tang 1
			scanf("%d %d", &tree[j][0], &tree[j][1]);
			cnt[tree[j][0]]++;
			cnt[tree[j][1]]++;
	}
	for (int j = 0; j < n; j++) {
		printf("%d %d\n", tree[j][0], tree[j][1]);
	}
	return 0;
}
