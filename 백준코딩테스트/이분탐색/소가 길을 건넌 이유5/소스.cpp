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
	for(int x=1; x<=n;x++) // 1���� �迭����
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

		if (a[x - k] == 1) { // ������ ���������°� �պκ�(�ǳʿ� ��)�̱⶧��,
			cnt--;
		//	cout << x - k << '\n';
		}
		if (a[x] == 1) {// ������ �����߰��Ǵ°� �޺κ�(�ǳʾ��ϴ� ��)�̰�
			cnt++;
			//cout << x << '\n';
		}
		res = min(res, cnt);
	}

	cout << res;

	return 0;
}