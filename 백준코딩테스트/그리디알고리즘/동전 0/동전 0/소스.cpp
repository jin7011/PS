#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[101] = { 0 };
int k = 0;
int index = 0;
int cashe = 0;

int func(int n) {

	for (int x = 1; x <= n; x++) {
		if (k / a[x] > 0) {
			index = x;
		}
	}

	for (int x = index; x>0; x--) {
		if (k == 0) break;

		if (k / a[x] > 0) {
			cashe += k / a[x];
			k %= a[x];
		}
	}

	return cashe;
}
int main() {

	cin >> n;
	cin >> k;
	a[0] = n;

	for (int x = 1; x <= n; x++) {
		cin >> a[x];
	}

	cout << func(n);

	return 0;
}