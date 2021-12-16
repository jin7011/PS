#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int k;
int a[1000001];
int b[1000001];
int cnt = 0;

void Find(int k,int left,int right) {

	cnt = 0;

	for (int x = left; x <= right; x++) {
		if (a[x] == k) {
			cnt++;
		}
	}
	cout << cnt<<' ';

}

void func(int k,int left,int right) { //k,0,9

	int middle = (left + right) / 2;

	if (left > right) {
		cout << 0 << ' ';
		return;
	}

	else if (a[middle] == k) {
		Find(k, left, right);
		return;
	}
	else if (a[middle] < k) {
		func(k, middle+1, right);
	}
	else if (a[middle] > k) {
		func(k, left, middle-1);
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(NULL);
	cin >> n;

	for (int x = 0; x < n; x++)
		cin >> a[x];

	sort(a, a + n);

	cin >> m;

	for (int x = 0; x < m; x++)
		cin >> b[x];

	for (int x = 0; x < m; x++) {
		func(b[x],0,n-1);
	}

	return 0;
}