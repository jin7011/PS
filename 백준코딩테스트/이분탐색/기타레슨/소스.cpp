#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n,m;
int sum;
int minlen; // ���� ���� ���������
int maxlen; // ��� �������� �Ѱ��� �� �� �ִ� �ִ밪
int midlen; // ���� �ְ����ϴ� ����������� �ִ밪.
int res;

vector <int> vec; // �����ϳ��ϳ� ���� ��������.

int sumfunc(vector<int> vec) {

	int s = 0;

	for (int x = 0; x < vec.size(); x++)
		s += vec[x];

	return s;
}

bool check(int mid) {

	int cnt = 1;
	sum = 0;

	for (int x = 0; x < n; x++) {

		sum += vec[x];

		if (vec[x] > mid) // ���ϳ��� ���̰� mid(�����������)�� ���� �� ���ٰ�����.
			return 0;

		if (sum > midlen) {
			sum = vec[x];
			cnt++;
		}

	}
	return m >= cnt; // ��緹���� ������ ���ϴ� ������ ���ų� ������ ok

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n>> m;
	int a;
	for (int x = 0; x < n; x++) {
		cin >> a;
		vec.push_back(a);
	}

	minlen = 1;
	maxlen = sumfunc(vec);

	while (minlen <= maxlen) {

		midlen = (minlen + maxlen) / 2;

		if (check(midlen)) {

			res = midlen;
			maxlen = midlen - 1;

		}
		else
		minlen = midlen + 1;
	}

	cout << maxlen;

	return 0;
}