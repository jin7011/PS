#include <iostream>

using namespace std;

int n = 0;
int tri[501][501];

int max(int a, int b) {
	if (a < b) return b;
	else return a;
}

void func(int n) {

	//dp
	for(int y=0; y<n;y++)
		for (int x = 0; x < y + 1; x++) {

			if (y > 0) { //첫번째 항은 하나니까 그대로
				if (x == 0)
					tri[y][0] += tri[y - 1][0];
				else if (x == y)
					tri[y][x] += tri[y - 1][x - 1];
				else
					tri[y][x] += max(tri[y - 1][x - 1], tri[y - 1][x]);
				
			}
		}
}

int main() {

	cin >> n;
	int b = 0;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < x + 1; y++)
			cin >> tri[x][y];

	func(n);

	for (int x = 0; x < n - 1; x++)
		b = max(b,max(tri[n - 1][x], tri[n - 1][x + 1]));

	cout << b;

	return 0;
}  