#include <stdio.h>

int GetSum(int n ,int k) {

	int sum = 0;
	int a[100] = { 0,1,2,3 };

	if (n > 14 || k > 14) return 0;
	for (int x = 1; x <= k; x++) a[x] = a[x-1]+1;

	for (int y = 1; y <= n; y++) { //���� 1������
		for (int x = 1; x < k; x++) { //ȣ�� 2ȣ���� 1ȣ�� ������ 1�̴ϱ�
			a[x + 1] = a[x] + a[x + 1];
		}
	}
	printf("\n\n%d\n\n", a[k]);
}

int main() {

	int n = 1, k = 3;
	int T = 1;

	printf("�� ���� �ñ��ϴ�?:");
	scanf_s("%d%*c", &T);

	for (int x = 0; x < T; x++) {
		printf("���� ȣ��:");
		scanf_s("%d%*c%d%*c", &n, &k);

		GetSum(n, k);
	}

	return 0;
}

