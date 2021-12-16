#include <stdio.h>
#include <iostream>
#include <memory>
void Swap(int &a, int &b) { int c = 0; c = a; a = b; b = c; }

void Print(int a[],int len) {

	for (int x = 0; x < len; x++) {
		printf("%d ", a[x]);
	}
	printf("\n");
}
void BubbleSort_B(int a[], int len) {

	for(int x =0;x<len-1;x++)
		for (int y = 0; y < len - 1 - x; y++) {
			if (a[y] < a[y + 1])
				Swap(a[y], a[y + 1]);
		}

}

void SelectSort_B(int a[], int len) {

	int max = 0;

	for (int x = 0; x < len - 1; x++) {
		max = x;
		for (int y = x + 1; y < len; y++) {
			if (a[max] < a[y])
				max = y;
		}
		Swap(a[max], a[x]);
	}
}

void BubbleSort_S(int a[], int len) {

	for(int x=0;x<len-1;x++)
		for (int y = 0; y < len - x-1; y++) {
			if (a[y] > a[y+1]) {
				Swap(a[y+1], a[y]);
				Print(a, len);
			}
			
		}
}

void SelectSort_S(int a[], int len) {

	int min = 0;

	for (int x = 0; x < len - 1; x++) {
		min = x;
		for (int y = x + 1; y < len; y++) {
			if (a[min] >= a[y]) {
				min = y;
			}
		}
		Swap(a[x], a[min]);
		Print(a, len);
	}
}

int main() {

	int input = 0;
	int len = 0;
	int* a = { 0};

	printf("수의 갯수:");
	scanf_s("%d", &len);

	a = (int*)malloc(sizeof(int) * len);

	printf("수를 차례대로 입력:");
	for (int x = 0; x < len; x++)
		scanf_s("%d", &a[x]);

	Print(a, len);

	printf("\n[1]BubbleSort [2]SelectSort [3]BubbleSort_B [4]SelecSort_B \n:");
	scanf_s("%d", &input);

	switch (input) {
	case 1:
		BubbleSort_S(a, len);
		break;
	case 2:
		SelectSort_S(a, len);
		break;
	case 3:
		BubbleSort_B(a, len);
		break;
	case 4:
		SelectSort_B(a, len);
		break;
	default:
		break;

	}

	printf("\n결과:");
	Print(a, len);

	return 0;


}