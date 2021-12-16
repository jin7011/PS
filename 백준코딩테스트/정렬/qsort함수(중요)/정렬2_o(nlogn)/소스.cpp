#include <stdio.h>
#include <memory>
int partition(int a[], int index, int pivot) {

	int temp = 0;

	for (int x = index; x < pivot ; x++)
		if (a[x] <= a[pivot]) {
			temp = a[x];
			a[x] = a[index];
			a[index] = temp;
			index++;
		}
	
		temp = a[pivot];
		a[pivot] = a[index];
		a[index] = temp;


	return index;
}

void qsort(int a[],int start,int end) {

	int index = 0;

	if (start < end) {
		index = partition(a, start, end);
		qsort(a, 0, index - 1);
		qsort(a, index + 1, end);
	}
	else
		return;

}

int main() {

	int T = 5; scanf_s("%d", &T);
	int *a ;

	a = (int*)malloc(sizeof(int) * T);

	for (int x = 0; x < T; x++)
		scanf_s("%d", &a[x],sizeof(a));

	qsort(a, 0, T-1);
	
	for (int x = 0; x < T; x++)
		printf("%d ", a[x]);

	return 0;
}