#include<iostream>
#include<algorithm>
#include<queue>
#include<time.h>
#include<string>
using namespace std;

void InterchangeSort(int a[], int n) 
{
	for(int i = 0; i < n - 1; i++) 
		for(int j = i + 1; j < n; j++) 
			if(a[i] > a[j]) 
				swap(a[i], a[j]);
}

void BubbleSort(int a[], int n) 
{
	for(int i = 0; i < n - 1; i++) 
		for(int j = n - 1; j > i; j--) 
			if(a[j] < a[j - 1]) swap(a[j], a[j - 1]);
}

void InsertionSort(int a[], int n) {
	int p, x; //p - position
	for(int i = 1; i < n; i++) {
		x = a[i];
		p = i;
		while(p > 0 && x < a[p - 1]) {
			a[p] = a[p - 1];
			p--;
		}
		a[p] = x;
	}
}

void SelectionSort(int a[], int n) {
	int min; //chi so phan tu nho nhat trong day dag xet (xet tu chi so min tro di)
	for(int i = 0; i < n - 1; i++) {
		min = i;
		for(int j = i + 1; j < n; j++) {
			if(a[j] < a[min]) {
				min = j;
			}
		}
		if(min != i) swap(a[min], a[i]);
	}
}

void CountingSort(int a[], int n) {
	int output[n];
	int max = a[0], min = a[0];
	for(int i = 1; i < n; i++) {
		if(a[i] > max) {
			max = a[i];
		} else if(a[i] < min) {
			min = a[i]; 
		}
	}
	int k = max - min + 1; //so phan tu cua mang dem
	int count_array[k]; //mang dem
	fill_n(count_array, k, 0); //gan cho k phan tu trong mang tu (0 -> k - 1) = 0
	for(int i = 0; i < n; i++) {
		count_array[a[i] - min]++; //a[i] luon cho nhanh?
	}
	for(int i = 1; i < k; i++) {
		count_array[i] += count_array[i - 1];
	}
	for(int i = 0; i < n; i++) {
		output[count_array[a[i] - min]] = a[i];
		count_array[a[i]- min]--;
	}
	for(int i = 0; i < n; i++) {
		a[i] = output[i];
	}
}

void Merge(int a[], int const l, int const m, int const r) {
	//l - left, m - mid, r - right
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L = new int[n1];
	int *R = new int[n2];
	for(int i = 0; i < n1; i++) {
		L[i] = a[l + i];
	}
	for(int j = 0; j < n2; j++) {
		R[j] = a[m + 1 + j];
	}
	int i = 0, j = 0; //i - chi so bdau mang L, j - chi so bat dau mang 2
	int k = l; //khoi tao chi so bat dau cua mang luu ket qua
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			j++;
		}
		k++;
	} 
	while(i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}
	while(j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
	delete[]L;
	delete[]R;
}

void MergeSort(int a[], int l, int r) {
	if(l < r) {
		int m = l + (r - l)/2; 
		//van la (l + r)/2 nhung chong tran so khi l, r lon
		//goi de quy de chia doi tung mang
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		Merge(a, l, m, r);
	}
}
	
void Heapify(int a[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if(l < n && a[l] > a[largest]) largest = l;
	if(r < n && a[r] > a[largest]) largest = r;
	if(largest != i) {
		swap(a[i], a[largest]);
		Heapify(a, n, largest);
	}
}	
	
void HeapSort(int a[], int n) {
	/*
	priority_queue<int> q;
	for(int i = 0; i < n; i++) {
		q.push(-a[i]);
	}
	int i = 0;
	while(!q.empty()) {
		a[i] = -q.top(); q.push();
		i++;
	}
 	*/
 	for(int i = n/2 - 1; i >= 0; i--) {
 		Heapify(a, n, i);	
	}
	for(int i = n - 1; i > 0; i--) {
		swap(a[0], a[i]);
		Heapify(a, i , 0);
	}
}

int partition(int a[], int low, int high) {
	int pivot = a[high];
	int i = low - 1;
	for(int j = low; j <= high - 1; j++) {
		if(a[j] < pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[high]);
	return i + 1;
}

void QuickSort(int a[], int low, int high) {
	if(low < high) {
		int pi = partition(a, low, high);
		QuickSort(a, low, pi - 1);
		QuickSort(a, pi + 1, high);
	}
}

void Choose(int a[], int n) 
{
	int choose;
	string answer;
	
	cout << "Sorts algorithm: " << endl;
	do 
	{
		cout << "1. Interchange Sort" << endl 
			 << "2. Bubble Sort" << endl
			 << "3. Insertion Sort" << endl
			 << "4. Selection Sort" << endl
			 << "5. Counting Sort" << endl
			 << "6. Merge Sort" << endl
			 << "7. Heap Sort" << endl
			 << "8. Quick Sort" << endl;
		switch(choose) {
			case 1: 
				InterchangeSort(a, n);
				break;
			case 2: 
				BubbleSort(a, n);
				break;
			case 3: 
				InsertionSort(a, n);
				break;
			case 4: 
				SelectionSort(a, n);
				break;
			case 5:
				CountingSort(a, n);
				break;
			case 6:
				MergeSort(a, );
				break;
			case 7:
				HeapSort();
				break;
			case 8:
				QuickSort();
				break;
			default:
				cout << "Invalid!" << endl;
				break;
		}
		cout << "Continue? "; cin >> answer;
		//strcmp?
		while(answer != "Yes" && answer != "No") { 
			cout << "Invalid!" << endl << "Again: ";
			cin >> answer;
		}
	} while(answer == "Yes");
}

int main() 
{
	int n;
	int *a = new int[];
	return 0;
}
