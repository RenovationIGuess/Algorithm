#include<stdio.h>
int main() {
	int arr[] = {1, 2, 3 , 4};
	for(int i = 0; i < 4; i++) {
		printf("alo alo ");
		for(int i = 0; i < 4; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	return 0; 
}
