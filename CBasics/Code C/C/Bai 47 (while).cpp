#include<stdio.h>
int main() {
	int i = 1;
	while (i <= 100) {
		if (i % 2 == 0) {
			continue; // Lenh continue va break khac nhau o cho: neu break thi dung han, continue thi ko khoa man => skip chu khong dung han (needs fixing)
		}
		i++;	
		printf("%d ", i);	
			
	}
	return 0;
}
