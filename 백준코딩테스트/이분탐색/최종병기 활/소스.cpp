#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int len, home, k,q;
int baseidx;
int a[100001];
bool visited[1000001];

vector <int> homeindex;

int distance(int a, int b,int circlesz) { // a���� b���� ���� ����

	return (b - a + circlesz) % circlesz;

}

int check(int oribase, int lenth, int cnt) {

	int base = oribase;

	for (int x = (base + 1) % home; ; x = (x + 1) % home) {

		if (homeindex[x] == homeindex[oribase]) break;

		if (distance(homeindex[base], homeindex[x], len) >= lenth) { // base���� ���� ���� ���̰� mid���� ũ�� ������ base�� �ǰ� �ڸ��� Ƚ�� ++
			cnt++;
			base = x;
		}

		if (cnt == k)
		{
			if (distance(homeindex[base], homeindex[oribase], len) >= lenth) // �� �ڸ��� ���� ������ ������̴ϱ� ���� �κ�(������ base�� ó���ڸ� ��(oribase))���̿� ���̸����� mid���� ũ�ٸ�
				return 1;
			else
				return 0; // ���� �κ��� ���̰� mid���� �۴ٸ� ��� �ǹ̾��� ���̱⶧���� ���й�ȯ
		}

	}

	return 0; // ���� �����ôµ��� ���̰Ÿ��� ���Ƽ� �ڸ� ���� ����ġ ������.
}

int main() {

	cin >> len >> home >> k;

	for (int x = 0; x < home; x++)
	{
		cin >> q;
		homeindex.push_back(q);
	}

	int mini = 1;
	int maxi = len;
	int res = maxi;

	while (mini <= maxi) {

		int mid = (mini + maxi) / 2;
		int cnt = 1; // ó���� �߶��ٰ� ġ��
		bool chck = 0;

		for (int i = 0; i < home; i++) {

			if (check(i, mid, cnt)) {
				chck = 1;
				break;
			}

		}

		if (chck == 1) { // cnt >= k
			res = mid;
			mini = mid + 1;
		}
		else
			maxi = mid - 1;
	}

	cout << res;

	return 0;
}