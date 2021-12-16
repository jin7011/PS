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

	int left = a[0] - m; // 최소간격(가장 높은 나무의 가장 낮은기준점)
	int right = a[0]; //최대간격 ( 가장 높은 나무 기준a[n] 높은 기준점)

	while (left <= right) {

		cnt = 0;
		middle = (right + left) / 2;

		for (int x = 0; x < n && a[x] - middle > 0; x++)
			cnt += (a[x] - middle); // middle보다 큰 나무를 자르고 나온 길이

		if (cnt >= m) { //결과길이가 원하는 길이'm'보다 크거나 같으면 줄여서 자르자
			left = middle + 1;
			res = middle;
			//자르고 싶은 높이 최솟값
		}
		else
			right = middle - 1;

	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m; // 갯수와 원하는 높이

	for (int x = 0; x < n; x++) {
		cin >> q;
		a.push_back(q);
	}

	sort(a.begin(), a.end(), greater<int>());

	func();

	cout << res;

	return 0;

}