#include <stdio.h>

int Sort(int a[],int len) {

	int temp = 0;

	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {

			if (a[i] > a[j]) {

				temp = a[i];
				a[i] = a[j];
				a[j] = temp;

			}
		}
	}
	return a[0];

}

int main() {

	int x=0, y=0, w=0, h=0;
	int r = 0;

	printf("x,y,w,h\n:");
	scanf_s("%d%d%d%d", &x, &y, &w, &h);
	int a[4] = { x,y,w - x,h - y };

	r = Sort(a,4);

	printf("%d\n", r);

	return 0;
}