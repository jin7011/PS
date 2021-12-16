#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
int a[9];
bool visited[9];
int res[9];

void func(int fcnt) {

	if (fcnt == m) {
		for (int q = 0; q < m; q++)
			cout << res[q] << ' ';
		cout << '\n';
		return;
	}

	int k = 0;

	for (int x = 0; x < n; x++) {

		if (!visited[x] && a[x] != k) {

			res[fcnt] = a[x];
			k = res[fcnt];

			visited[x] = true;
			func(fcnt + 1);
			visited[x] = false;
		}
	
	}

}

int main() {

	cin >> n >> m;

	for (int x = 0; x < n; x++) {
		cin >> a[x];
		//numvisited[a[x]] = 0;
	}

	sort(a, a + n);

	func(0);
}