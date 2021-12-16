#include <stdio.h>
#include <memory>

typedef struct Data{
	int x,y;
int k = 1;
}Data;

void SetK(Data* pA, int N) {

	for(int i=0;i<N-1;i++)
		for (int j = i + 1; j < N; j++) {
			if (pA[i].x > pA[j].x&& pA[i].y > pA[j].y)
				pA[j].k++;
			else if (pA[i].x < pA[j].x&& pA[i].y < pA[j].y)
				pA[i].k++;
		}
}

int main() {

	int N = 0;
	scanf_s("%d", &N);
	Data* pA = (Data*)calloc(sizeof(Data) * N, 0);

	for (int i = 0; i < N; i++) pA[i].k = 1;

	for (int i = 0; i < N; i++)
		scanf_s("%d%d", &pA[i].x, &pA[i].y,sizeof(Data));

	SetK(pA, N);

	for (int i = 0; i < N; i++)
		printf("%2d", pA[i].k);

	return 0;
}