#include <stdio.h>
#include <memory>
#include <math.h>
typedef struct Data {
	int a;
	int b;
	int k;
}Data;

Data* Sort(Data* A,int len) {

	int temp = 0;

	for (int y = 0; y < len-1; y++) {
		for (int x = y+1; x < len - 1; x++) {
			if (A[y].k < A[x + 1].k) {
				temp = A[y].k;
				A[y].k = A[x + 1].k;
				A[x + 1].k = temp;
			}

		}
	}
	return A;
}

int GetN(int input) { //소수면 input반환 아니면 0반환

	if (input == 1) return 0;
	if (input == 2) return 2;

	for (int x = 2; x < input; x++) {
		if (input % 2 == 0) return 0;
	}
	return input;
}

int GetCount(int input) {

	int count = 0;

	if (input == 1) return 0;
	if (input == 2) return 1;

	for (int x = 2; x < input; x++) {
		if (GetN(x) > 0) count++;
	}
	return count;
}
//2~8까지 소수 모두 구한는 함수
void SetN(int input, int* a) {

	int k = 0;

	for (int x = 2; x < input; x++) {
		if (GetN(x) > 0) {
			a[k] = GetN(x);
			k++;
		}
	}

}

void Print(int input, int count, int* a) {
	int c = 0;
	int K[1000] = { 0 };
	Data A[1000] = { 0 };
	Data* Pa = NULL;

	for (int y = 0; y < count; y++) {
		for (int x = 0; x < count; x++) {
			K[c] = a[y] + a[x];
			if (input == K[c]) {
				K[c] = abs(a[y] - a[x]);
				A[c] = { a[y],a[x],K[c] };
				c++; //되는 것마다 K[c]에 일단 저장.

				//printf("\n%d = %d + %d\n\n", input, a[y], a[x]);
				//return 0;
			}
		}
	}

	Pa = Sort(A, c);
	printf("\n%d = %d + %d\n\n", input, Pa->a, Pa->b);

}

int main() {

	int input = 8,T=0; // 2 3 5 -> 3 + 5 
	int a[100000] = { 0 };
	int count = 0;

	printf("case:");
	scanf_s("%d%*c", &T);

	for (int x = 0; x < T; x++) {
		printf("input:");
		scanf_s("%d%*c", &input);
		if (input < 4 || input>10000 || input % 2 != 0) return 0; //4~1000까지의 짝수만 

		count = GetCount(input);
		SetN(input, a);
		Print(input, count, a);
	}

	return 0;
}