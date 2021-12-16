#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[10000];
int temp[100001];
int k;
bool visited[100001];

void func(int cnt) {

	if (cnt == m) {
		for (int x = 0; x < m; x++)
			cout << temp[x] << ' ';
		cout << '\n';
		return;
	}

	for (int x = 0; x < n; x++) {
		if (visited[x] == 0) {
			temp[cnt] = a[x];
			visited[x] = 1;
			func(cnt + 1);
			visited[x] = 0;
		}
	}

}

int main() {

	cin >> n>>m;

	for (int x = 0; x < n; x++) {
		cin >> a[x];
	}

	sort(a, a + n);

	func(0);

	return 0;
}