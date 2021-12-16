#include <stdio.h>

int Set(int input) {

	int a = 2;
	int b = 8;
	

	for (int x = 1; x < 100; x++) {
		a = a + 6 * (x); //2
		b = b + 6 * (x+1); //20 x = 2부터 시작할거임.
		
		if (input == 1)
			return 1;
		else if (input >= 2 && input < 8)
			return 2;
		else if (input >= a && input < b)
			return x + 2;

	}

}

int main() {

	int input = 0;
	int resault = 0;

	printf("input:");
	scanf_s("%d%*c", &input);

	resault = Set(input);

	printf("%d", resault);

	return 0;
}