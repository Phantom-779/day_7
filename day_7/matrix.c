#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS

int fillMatrD(int** arr, int str, int stolb);
int fillMatrS(int* arr, int str, int stolb);
void showMatrD(int** arr, int str, int stolb);
void showMatrS(int* arr, int str, int stolb);

void staticArray(int* arr, int row, int col);
void firstDinamic(int row, int col);
void secondDinamic(int row, int col);
void therdDinamic(int row, int col);


int main(void) {
	///
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((12 << 4)));
	///
	int sposob, row, col;
	int arr[100][100];
	printf("1 - static\n2 - 1st dinamic(single allocation)\n3 - 2nd dinamic\n3 - 3rd dinamic\n");
	printf("enter 'memAlloc method', 'row', 'col' ");
	if (scanf_s("%d %d %d", &sposob, &row, &col) != 3) printf("n/a"); //? x > 0 
	else {
		if (row > 100 || row < 1 || col > 100 || col < 1) sposob = 0;
		switch (sposob)
		{
		case 1:
			staticArray(arr, row, col);
			break;
		case 2:
			firstDinamic(row, col);
			break;
		case 3:
			secondDinamic(row, col);
			break;
		case 4:
			therdDinamic(row, col);
			break;
		default:
			printf("n/a");
			break;
		}
	}
	
}
void therdDinamic(int row, int col) {
	int** p_arr = malloc(row * sizeof(int*));
	int* val_arr = malloc(row * col * sizeof(int));

	for (int i = 0; i < row; i++) {
		p_arr[i] = val_arr + col * i;
	}

	fillMatrD(p_arr, row, col);
	showMatrD(p_arr, row, col);

	free(val_arr);
	free(p_arr);
}
void secondDinamic(int row, int col) {
	int** p_arr = malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++) {
		p_arr[i] = malloc(col * sizeof(int));
	}

	fillMatrD(p_arr, row, col);
	showMatrD(p_arr, row, col);

	for (int i = 0; i < row; i++) free(p_arr[i]);
	free(p_arr);
}
void firstDinamic(int row, int col) {
	int** fristDinamic = malloc(row * col * sizeof(int) + row * sizeof(int*));
	int* ptr = (int*)(fristDinamic + row);
	for (int i = 0; i < row; i++) {
		fristDinamic[i] = ptr + row * i;
	}	fillMatrD(fristDinamic, row, col);
	showMatrD(fristDinamic, row, col);
	free(fristDinamic);
}
void staticArray(int* arr, int row, int col) {
	fillMatrS(arr, row, col);
	showMatrS(arr, row, col);
}


void showMatrD(int** arr, int str, int stolb) {
	for (int i = 0; i < str; i++) {
		for (int j = 0; j < stolb; j++) {
				printf("%d", arr[i][j]);
				if (j < stolb - 1) printf(" ");
		}
		if (i < str - 1) printf("\n");
	}
}
void showMatrS(int* arr, int str, int stolb) {
	for (int i = 0; i < str; i++) {
		for (int j = 0; j < stolb; j++) {
			printf("%d", arr[i * stolb + j]);
			if (j < stolb - 1) printf(" ");
		}
		if (i < str - 1) printf("\n");
	}
}

int fillMatrD(int** arr, int str, int stolb) {
	for (int i = 0; i < str; i++) {
		for (int j = 0; j < stolb; j++) {
			if (scanf_s("%d", &arr[i][j]) != 1)
				return 1;
		}
	}
	return 0;
}
int fillMatrS(int* arr, int str, int stolb) {
	for (int i = 0; i < str; i++) {
		for (int j = 0; j < stolb; j++) {
			if (scanf_s("%d", &arr[i * stolb + j]) != 1)
				return 1;
		}
	}
	return 0;
}