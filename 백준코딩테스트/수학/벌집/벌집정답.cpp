#include <stdio.h>

int main() {

	int input=0;
	int range = 1;
	int cnt = 1;
	int tmp = 1;

	scanf_s("%d", &input);


	while (1) {
		if (range >= input) break;
	
		tmp = 6 * cnt; // 1 -> 6 -> 12 -> 18
		range = range + tmp; // 1 -> 7 -> 19
		cnt++; // 1->2->3

	}

	printf("%d", cnt);

	return 0;

}