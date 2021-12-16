#include <iostream>

using namespace std;

int a[7] = { 0 };
bool b[8] = { 0 };

void func(int m, int n, int cnt) {

	if (cnt == m) {
		for(int x =0 ; x<m; x++)
		cout << a[x] << " ";
		cout << '\n';

		return;

	}

	for (int x = 1; x <= n; x++) {
		a[cnt] = x;
		func(m, n, cnt + 1);
	}

}

int main() {

	int n, m; cin >> n >> m;
	func(m, n, 0);

	return 0;
}