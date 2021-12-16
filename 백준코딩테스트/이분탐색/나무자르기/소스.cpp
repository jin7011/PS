#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int n,m,q;

vector <int> a;

int middle;
long long cnt;
int base;
long long res;

void func() {

	int left = a[0] - m; // �ּҰ���(���� ���� ������ ���� ����������)
	int right = a[0]; //�ִ밣�� ( ���� ���� ���� ����a[n] ���� ������)

	while (left <= right) {

		cnt = 0;
		middle = (right + left) / 2;

		for (int x = 0; x < n && a[x] - middle > 0; x++)
			cnt += (a[x] - middle); // middle���� ū ������ �ڸ��� ���� ����

		if (cnt >= m) { //������̰� ���ϴ� ����'m'���� ũ�ų� ������ �ٿ��� �ڸ���
			left = middle + 1;
			res = middle;
			//�ڸ��� ���� ���� �ּڰ�
		}
		else
			right = middle - 1;

	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m; // ������ ���ϴ� ����

	for (int x = 0; x < n; x++) {
		cin >> q;
		a.push_back(q);
	}

	sort(a.begin(), a.end(), greater<int>());

	func();

	cout << res;

	return 0;

}