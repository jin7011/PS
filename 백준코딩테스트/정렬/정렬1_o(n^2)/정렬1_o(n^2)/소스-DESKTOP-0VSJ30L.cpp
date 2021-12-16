#include <stdio.h>
#include <memory>

void Sort(int* n,int t) {

	int temp = 0;

	for(int y=0; y < t-1; y++)
		for (int x = y + 1; x < t; x++) {
			if (n[y] > n[x]) {
				temp = n[y];
				n[y] = n[x];
				n[x] = temp;
			}

		}

}

int main() {

	int T = 0; scanf_s("%d", &T);
	int* input = 0;

	input = (int*)malloc(sizeof(int) * T);

	for (int x = 0; x < T; x++) {
		scanf_s("%d", &input[x],sizeof(input));
	}

	Sort(input, T);

	for (int x = 0; x < T; x++)
		printf("%d\n", input[x]);

	return 0;
}