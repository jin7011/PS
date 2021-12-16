#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n,m;
int sum;
int minlen; // 제일 작은 동영상길이
int maxlen; // 모든 동영상이 한곳에 들어갈 수 있는 최대값
int midlen; // 실제 넣고자하는 동영상길이의 최대값.
int res;

vector <int> vec; // 레슨하나하나 여기 저장하자.

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

		if (vec[x] > mid) // 곡하나의 길이가 mid(최장저장길이)를 넘을 수 없다고하자.
			return 0;

		if (sum > midlen) {
			sum = vec[x];
			cnt++;
		}

	}
	return m >= cnt; // 블루레이의 갯수가 원하는 수보다 같거나 적으면 ok

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