#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int n;
char map[200][200];
int cnt[500] = { 0 };

void func(int size, int x, int y) {

	
	if (size == 1) {
		cout << map[x][y];
		return;
	}

	int flag = 0;

	for (int i = x; i < x + size; i++) {
		if (flag == 1)
			break;
		for (int j = y; j < y + size; j++) {
			if (map[i][j] != map[x][y]) {
				flag = 1;
				break;
			}
		}
	}

	if (flag == 0) {
		cout << map[x][y];
	return;
	}

	cout << '(';
	for (int q = x; q < x + size; q += size / 2)
		for (int w = y; w < y + size; w += size / 2) {
			func(size / 2, q, w);
		}
	cout << ')';
}

int main() {

	cin >> n;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			cin >> map[x][y];

	func(n, 0, 0);

	return 0;

}