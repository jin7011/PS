#include <stdio.h>
#include <math.h>

void move(int n, int from,int to) {

	int middle = 6 - from - to;

	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	if (n >= 2) {
		move(n - 1, from, middle);
		move(1, from, to);
		move(n-1, middle, to);

	}


}

int main() {



	int input = 0;
	scanf_s("%d", &input);
	printf("%d\n", (int)pow(2,input) - 1);
	move(input, 1,3); // 1 3 넣어야 middle이 2가 나오니까 일단 1 3

}