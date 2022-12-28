#include<stdio.h>
void NumSort(int arr[]);
void OddSort(int arr[]);
int main() {
	int arr[10];
	for(int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
	NumSort(arr); 
	OddSort(arr); 
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
void NumSort(int arr[]) {
	int tmp1;
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (arr[i] < arr[j]) {
				tmp1 = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp1;
			}
		}
	}
}
void OddSort(int arr[]) {
	int tmp2;
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (arr[i] < arr[j] && (arr[i] % 2 != 0) && (arr[j] % 2 != 0)) {
				tmp2 = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp2;
			}
		}
	}
}
