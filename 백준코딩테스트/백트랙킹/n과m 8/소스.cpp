#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int n, m;
int a[10001];
int res[100001];
int visited[100001];
int temp;
int k=0;

int find(int v) {
	
	for (int x = 0; x < n; x++) {
		if (a[x] == v)
			return x;
	}
}

void func(int cnt,int start) {
	if (cnt == m) {
		for (int x = 0; x < m; x++) {
			cout << res[x] << ' ';///
		}
		cout << '\n';
		return;
	}

	for (int x = start; x < n; x++) {	
			res[cnt] = a[x];
			func(cnt + 1,find(res[cnt]));
	
	}

}
int main() {

	cin >> n >> m;

	for (int x = 0; x < n; x++)
		cin >> a[x];

	sort(a, a + n);

	func(0,0);

	return 0;
}
