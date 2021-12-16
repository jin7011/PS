#include <stdio.h>

int main() {

	int A=3, B=1, V=5;
	int Day = 0;

	scanf_s("%d%d%d", &A, &B, &V);

	while (1) {

		V = V - A;
		Day++;
		if (V <= 0) {
			printf("%d", Day);
			return 0;
		}
	
		V = V + B;
	}

}