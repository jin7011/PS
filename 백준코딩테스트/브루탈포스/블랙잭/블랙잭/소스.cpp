#include <stdio.h>
#include <string.h>

void Sort(int* output) {

	int temp = 0;

	for(int x =0; output[x+1] != 0;x++)
		for (int y = x + 1; output[y] != 0; y++) {
			if (output[x] < output[y]) {
				temp = output[x];
				output[x] = output[y];
				output[y] = temp;
			}
		}

}
int Set(int n, int m, int* input,int* output) {

	int sum = 0;
	int k = 0;

	for(int x =0; input[x+3] != 0; x++)
		for(int y = x+1; input[y+2] != 0; y++)
			for (int z = y + 1; input[z] != 0; z++) {
				sum = input[x] + input[y] + input[z];
				if (sum == m) {
					return sum;
				}
				else if (sum < m) {
					output[k] = sum;
					k++;
				}
			}

	Sort(output);
	return output[0];
}


int main() {

	int input[100] = { 0, }, output[100] = { 0, };
	int m=0, n=0;
	scanf_s("%d%d", &n, &m);

	for (int x = 0; x < n; x++)
		scanf_s("%d",&input[x]);

	printf("%d", Set(n,m,input,output));

	return 0;
}