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

	printf("�Է�:");
	scanf_s("%s", S,sizeof(S));

	int total = 0;

	for (int x = 0; S[x] != NULL; x++) {
		total = total + Find_GetT(a, (char)S[x]);
	}
	// char[]�� �Ű������� �ѱ�� char*�� �ޱ��ƴ�
	// char[]�� �Ű������� �ѱ�� �� char�� ���ϰ� ����
	printf("%d", total);

	return 0;
}