#include <stdio.h>

int GetCount(int H, int W, int N) {

	int A = 1, B = 1, count = 1;
	if (H * W < N || H < 0 || W >99 || N<0 || H>N) return 0;

	while (1) { // 601
		if (N == count) {
			printf("\n%d번째 손님은 %d%02d%호\n\n", count,A, B);
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

	printf("손님 몇 팀을 받을 예정인가요? :");
	scanf_s("%d%*c", &T);

	for (int x = 0; x < T; x++) {
		printf("건물의 층수:");
		scanf_s("%d%*c", &H);
		printf("각층의 호수:");
		scanf_s("%d%*c", &W);
		printf("몇 번째 손님인가요?:");
		scanf_s("%d%*c", &N);

		GetCount(H, W, N);
	}

	return 0;
}