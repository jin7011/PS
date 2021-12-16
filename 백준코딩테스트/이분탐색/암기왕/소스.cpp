#include <iostream>
#include <algorithm>

using namespace std;

int n, m,t,k;
int a[1000001];
int b[1000001];
int res[1000001];
int mini = 0;
int maxi = n - 1;

int search(int a[], int v) { // v�� �ִ� �ε����� ��ȯ

	mini = 0;
	maxi = n - 1;

	while (mini <= maxi) {

		int mid = (mini + maxi + 1) / 2;

		if (a[mid] == v) {
			return 1;
		}

		if (a[mid] > v) { // ������Ұ� ã�� ������ Ŭ �� (�� ���� ����Ž�� ��)
			maxi = mid - 1;
		}
		else
			mini = mid + 1;

	}

	return 0;

}

int main() {
	cin >> t;

	while (t--) {

		cin >> n;
		for (int x = 0; x < n; x++)
			cin >> a[x];

		sort(a, a + n);

		cin >> m;
		for (int x = 0; x < m; x++) {
			cin >> b[x];
			res[x] = search(a, b[x]);
		}

		for (int x = 0; x < m; x++)
			cout << res[x] << '\n';

	}

	return 0;
}