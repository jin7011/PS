#include <stdio.h>
#include <string>

void SetA(char pa[][4], char* pA, int num) {

	for (int x = 0; x < 3; x++) {
		pa[num][x] = *pA;
		*pA = pa[num][x]+1;
	}

}

void SetA2(char pa[][4], char* pA, int num) {

	for (int x = 0; x < 4; x++) {
		pa[num][x] = *pA;
		*pA = pa[num][x] + 1;
	}

}

int Find_GetT(char pa[][4], char pstr) {

	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 4; x++) {
			if (pa[y][x] == pstr)
			return y + 3;
		}
	}
	return 0;
}

int main() {

	char a[10][4];
	char A[2] = "A";
	char S[1000001] = { 0 };

	for (int y = 0; y < 5; y++) {
		SetA(a, A, y);
	}

	for (int y = 5; y < 9; y++) {
		if (y % 2 != 0)
			SetA2(a, A, y);
		else
			SetA(a, A, y);
	}

	printf("입력:");
	scanf_s("%s", S,sizeof(S));

	int total = 0;

	for (int x = 0; S[x] != NULL; x++) {
		total = total + Find_GetT(a, (char)S[x]);
	}
	// char[]을 매개변수로 넘기면 char*로 받기어렵다
	// char[]을 매개변수로 넘기면 걍 char로 편하게 받자
	printf("%d", total);

	return 0;
}