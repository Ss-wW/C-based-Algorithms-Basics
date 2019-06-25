#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int len);
void sortProcess(int arr[], int len, int l, int r);
void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int len) {
	printf("mergeSort has arr as below\n");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	if (arr == NULL || len < 2) {
		return;
	}
	sortProcess(arr, len, 0, len - 1);
	return;
}

void sortProcess(int arr[], int len, int l, int r) {
	if (l == r) {
		return;
	}
	int mid = l + ((r - l) >> 1);
	sortProcess(arr, len, l, mid);
	sortProcess(arr, len, mid + 1, r);
	merge(arr, l, mid, r);
	return;
}


void merge(int arr[], int l, int m, int r) {
	printf("L = %d\nM = %d\nR =%d\n", l, m, r);
	int len = r - l + 1;
	int *help = (int*)malloc(len * sizeof(int));
	int i = 0;
	int p1 = l;
	int p2 = m + 1;
	int res = 0;
	while (p1 <= m && p2 <= r) {
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	while (p1 <= m) {
		help[i++] = arr[p1++];
	}
	while (p2 <= r) {
		help[i++] = arr[p2++];
	}
	for (i = 0; i < len; i++) {
		arr[l + i] = help[i];
	}
	printf("For the moment, arr is \n");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}


int main() {
	int a[] = { 9,4,8,5,7,3,6,2,1 };
	int len = sizeof(a) / sizeof(a[0]);
	mergeSort(a, len);
	printf("mergeSort Result:\n");
	for (int i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}