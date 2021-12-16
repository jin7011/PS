#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int map[2200][2200];
int n;
int temp;
int a=0, b=0, c=0;

void func(int size, int x, int y) {

	int temp = map[x][y];

	if (size == 1) {
		if (map[x][y] == -1)
			a++;
		else if (map[x][y] == 0)
			b++;
		else if (map[x][y] == 1)
			c++;
		return;
	}

	int flag = 0;

	for (int i = x; i < x + size; i++) {
		if (flag == 1)
			break;
		for (int j = y; j < y + size; j++) {
			if (map[i][j] != temp) {
				flag = 1;
				break;
			}
		}
	}

	if (flag == 0) {
		if (map[x][y] == -1)
			a++;
		else if (map[x][y] == 0)
			b++;
		else if (map[x][y] == 1)
			c++;
		return;
	}

	for (int q = x; q < x + size; q += size / 3)
		for (int w = y; w < y + size; w += size / 3)
			func(size / 3, q, w);

}

int main() {

	cin >> n;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			cin >> map[x][y];

	func(n, 0, 0);

	cout << a << '\n';
	cout << b << '\n';
	cout << c << '\n';

	return 0;
}