//#include <stdio.h>
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//
//#define LEN 10
//#define _CRT_SECURE_NO_WARNINGS
//
//
//void showArr(int* arr, int length);
//void swap(int* arr, int i, int j);
//void sort(int* arr, int len);
//int findSmall(int* arr, int start, int end);
//int fill(int* arr, int len);
//
//int main(void) {
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//	int len = 0;
//	printf("enter arr len and arr ");
//	if (scanf_s("%d", &len) == 1) {
//		int *arr = malloc(sizeof(int) * len);;
//		if (fill(arr, len) != 1) {
//			sort(arr, len);
//			showArr(arr, len);
//		}
//		else printf("n/a");
//		free(arr);
//	}
//	else printf("n/a");
//}
//
//int fill(int* arr, int len) {
//	for (int i = 0; i < len; i++) {
//		if (scanf_s("%d", &arr[i]) != 1)
//			return 1;
//	}
//	return 0;
//}
//void sort(int* arr, int len) {
//	int start = 0;
//	for (int i = 0; i < len; i++) {
//		swap(arr, findSmall(arr, start, len), start);
//		start++;
//	}
//}
//int findSmall(int* arr, int start, int end) {
//	int min = arr[start];
//	int minId = start;
//	for (int i = start; i < end; i++) {
//		if (arr[i] < min) {
//			min = arr[i];
//			minId = i;
//		}
//	}
//	return minId;
//}
//void swap(int* arr, int i, int j) {
//	int temp = arr[i];
//	arr[i] = arr[j];
//	arr[j] = temp;
//}
//void showArr(int *arr, int length) {
//	for (int* p = arr; p - arr < length; p++) {
//		printf("%d ", *p);
//	}
//    printf("\n");
//}