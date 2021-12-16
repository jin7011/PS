#include <stdio.h>
#include <memory>

void competition(int a[], int start, int middle, int end) {

	int k = 0;
	int b[100] = { 0, };
	int j = middle + 1;
	int i = start;

	//한쪽이 전멸할 때까지
	while (i <= middle && end >= j) { //mid가 가운데 있다면
		if (a[i] <= a[j]) {
			b[k] = a[i];
			k++;
			i++;
		}
		else {
			b[k] = a[j];
			k++;
			j++;
		}
	}
	//왼쪽이 살아있다면
	while (i <= middle) {
		b[k] = a[i];
		k++;
		i++;
	}
	// 오른쪽이 살아있다면
	while (j <= end) {
		b[k] = a[j];
		k++;
		j++;
	}
	k--;
	while (k>=0) {
		a[start + k] = b[k];
		k--;
	}

}

void merge(int a[], int start, int end) {

	int middle = (start + end) / 2;

	if (start < end) {
		merge(a, start, middle);
		merge(a, middle + 1, end);
		competition(a, start, middle, end);
	}
	else return;
}

int main(){


	int n = 0; scanf_s("%d", &n);
	int* a;

	a = (int*)malloc(sizeof(int) * n);

	for (int x = 0; x < n; x++)
		scanf_s("%d", &a[x],sizeof(a));

	merge(a, 0, n-1);

	for (int x = 0; x < n; x++)
		printf("%d", a[x]);

	return 0;
}