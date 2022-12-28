/* cau lenh break la de dung mot vong lap
- Neu dat dong lenh nao len truoc break thi dong lenh do se duoc thuc hien truoc nen luu y khi lam bai */
#include<stdio.h>
int main() {
	int i = 1;
	while (i <= 100) {
		printf("%d ", i);
		if (i == 50) { // phai dung != (khac) va == (bang)
			break;
		}
		i++;
	}
	return 0;
}

