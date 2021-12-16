#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int k;
int b;
int q;
int idx;
bool* a;
int res;
int cnt;

int main() {

	cin >> n >> k >> b;

	a = new bool[n + 1];
	for(int x=1; x<=n;x++) // 1부터 배열시작
		a[x] = 0;

	for (int x = 1; x <= b; x++) {
		cin >> q;
		a[q] = 1;
	}

	for (int x = 1; x <= k; x++) {
		if (a[x])
			cnt++;
	}

	res = cnt;

	for (int x = k+1; x <= n; x++) {

		if (a[x - k] == 1) { // 무조건 빠져나가는건 앞부분(건너온 길)이기때문,
			cnt--;
		//	cout << x - k << '\n';
		}
		if (a[x] == 1) {// 무조건 새로추가되는건 뒷부분(건너야하는 길)이고
			cnt++;
			//cout << x << '\n';
		}
		res = min(res, cnt);
	}

	cout << res;

	return 0;
}