#include <stdio.h>

int F(int n) {

	if (n == 0) return 1;
	else
		return n*F(n - 1);

}

int main() {

	int n = 0;
	scanf_s("%d", &n);

	printf("%d", F(n));

}