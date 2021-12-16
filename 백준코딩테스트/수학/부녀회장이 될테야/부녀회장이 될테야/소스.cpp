#include <stdio.h>

int GetSum(int n ,int k) {

	int sum = 0;
	int a[100] = { 0,1,2,3 };

	if (n > 14 || k > 14) return 0;
	for (int x = 1; x <= k; x++) a[x] = a[x-1]+1;

	for (int y = 1; y <= n; y++) { //층수 1층부터
		for (int x = 1; x < k; x++) { //호수 2호부터 1호는 무조건 1이니까
			a[x + 1] = a[x] + a[x + 1];
		}
	}
	printf("\n\n%d\n\n", a[k]);
}

int main() {

	int n = 1, k = 3;
	int T = 1;

	printf("몇 개가 궁금하니?:");
	scanf_s("%d%*c", &T);

	for (int x = 0; x < T; x++) {
		printf("층과 호수:");
		scanf_s("%d%*c%d%*c", &n, &k);

		GetSum(n, k);
	}

	return 0;
}

