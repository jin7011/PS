#include <stdio.h>

int GetCount(int H, int W, int N) {

	int A = 1, B = 1, count = 1;
	if (H * W < N || H < 0 || W >99 || N<0 || H>N) return 0;

	while (1) { // 601
		if (N == count) {
			printf("\n%d��° �մ��� %d%02d%ȣ\n\n", count,A, B);
			return count;
		}
		if (A == H) {
			B++;
			A = 0;
		}
		count++;
		A++;

	}
}



int main(){

	int H = 6, W = 12;
	int T = 0, N=0;

	printf("�մ� �� ���� ���� �����ΰ���? :");
	scanf_s("%d%*c", &T);

	for (int x = 0; x < T; x++) {
		printf("�ǹ��� ����:");
		scanf_s("%d%*c", &H);
		printf("������ ȣ��:");
		scanf_s("%d%*c", &W);
		printf("�� ��° �մ��ΰ���?:");
		scanf_s("%d%*c", &N);

		GetCount(H, W, N);
	}

	return 0;
}