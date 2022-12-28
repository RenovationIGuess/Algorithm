#include<stdio.h>
int main() {
    int a[1000]; //Khai bao mang 1 chieu: day so a
	int n, k, x; //Khai bao 3 so nguyen lan luot la n, k , x
    scanf("%d", &n); //Nhap tu ban phim 3 so nguyen
    for (int i = 0; i < n; i++) { //Nhap cac phan tu cua day tu a[0] den a[n - 1] (n phan tu)
        scanf("%d", &a[i]); 
    }
    scanf("%d%d", &k, &x);
    for (int i = n; i >= k + 1; i--) { // Vong lap nay co nghia la
        a[i] = a[i - 1]; /*Khi chen 1 phan tu vao day so VD: chen x vao giua phan tu a[3] va a[4] (<=> k = 4) nghia la khi do x se la phan tu so 4 (a[4]) con a[4] da tro thanh a[5]
        Chinh vi vay o day o chon vong lap chay tu n tro ve 0 voi i >= k + 1, tuc la khi do a[k + 1] = a[k] tuong tu nhu a[4] = a[5] o tren con cac phan tu a[k - 1] tro di se khong anh huong do ta chen x vao vi tri cua a[k] */
    }
    //O day int i = n chu khong phai n - 1 la do ta da day chi so ung voi phan tu trong day len 1 <=> n - 1 + 1 = n
    a[k] = x; // Sau khi day chi so cua cac phan tu tu a[k] len a[k + 1], tu la vi tri a[k] dang rong do bay gio trong day chi so la: a[0] ... a[k - 1] ? a [k + 1] .. a[n]
    n++; // n tang len 1 do bay h day a co n + 1 phan tu a[0] -> a[n]
    /* Y nghia cua don 10 - 14: De bai yeu cau chung ta chen phan tu vao day, dieu do tuong duong voi so phan tu trong day + 1
    - Chen phan tu x vao day o truoc phan tu co chi so k va sau phan tu co chi so k + 1: a[k - 1] x a[k]
    - De lam duoc nhu yeu cau tren ta phai gan cho a[i] = a[i - 1] va chon vong lap cho hop li:
    Luu y ve cach chon vong lap:
    Neu vong lap cua ta nhu sau:
    for (int i = k+1; i <= n; i++){
		a[i] = a[i-1];
	}
	a[k] = x;
	n++;
	Vong lap nay co nghia la: voi i chay tu k + 1 den n thi a[k + 1] = a[k] voi i tang dan, nhung dieu nay se dan den viec gia tri cua bi mat di
	Cu the: a[4] = a[3], sau do ta lai gan a[5] = a[4] (do trong vong lap nay gia tri i tang dan) thi khi do gia tri cua a[4] cu se khong con do a[4] khi do dang = a[3]
	Hay hieu tong quat neu ta cho vong lap voi gia tri i tang dan thi vi tri a[k + 1] se mat di, tuc la nhu o tren a[4] da mat gia tri 
	*** Vi vay, ta se cho vong lap voi i giam tu n -> k + 1, nhu vay cac phan tu o vi tri n - 1 -> k se duoc bao toan va chi so cua no + 1 (do a[n] = a[n - 1] voi a[n] chua ro??? simply changing the numbers of pt)
	*/
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
