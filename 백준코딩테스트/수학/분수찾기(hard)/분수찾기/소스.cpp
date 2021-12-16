#include <stdio.h>

void Even(int input, int sum,int x) {// input = 7, sum = 10, x = 4

	int i = x, j = 1;
	int K = input - (sum - (x - 1));

	printf("%d/%d", j + K, i - K);

}

void Odd(int input, int sum, int x) {

	int i = 1, j = x;
	int K = input - (sum - (x - 1));

	printf("%d/%d", j - K, i + K);

}


int main() {

	int input = 0;
	int sum = 0;
	int x = 1;

	scanf_s("%d", &input);

	while(1){
		sum = sum + x;
		if (input <= sum) {
			switch (x % 2) { //10 % 2 = 0
			case 0:
				Even(input, sum, x);
				return 0;
			default:
				Odd(input, sum, x);
				return 0;
			}
		}
		x++;
	}
	


	return 0;
}