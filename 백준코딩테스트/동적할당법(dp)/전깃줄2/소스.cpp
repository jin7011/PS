#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

int LIS[100001] = { 0 };
bool visited[1000001];
int n;
int a, b;
int res = 0;

vector <pair<int, int>> vec; // pair<a전기줄번호,b전깃줄번호> vec
//vector <pair<int, int> > lis; // DP,b전깃줄번호
pair<int, int> lis[1000001];

void func() {

	LIS[0] = 1;
	lis[0].second = 1;
	lis[0].first = vec[0].second;

	for (int x = 1; x < n; x++) {
		LIS[x] = 1;
		lis[x].second = 1;
		lis[x].first = vec[x].second;

		for (int y = 0; y < x; y++) {
			if (vec[x].second > vec[y].second) { // 증가하는 수라면,

				LIS[x] = max(LIS[x], LIS[y] + 1); // 증가하는 수의 갯수
				lis[x].second = max(lis[x].second, lis[y].second + 1);

			}
		}
	}
}

int find(int v) {
	for (int x = 0; x < n; x++) {
		if (vec[x].second == v)
			return x;
	}
}

int find2(int v) {
	for (int x = 0; x < n; x++) {
		if (lis[x].second == v)
			return x;
	}
}

int main() {

	cin >> n;
	int o = n;

	while (o--) {

		cin >> a >> b;
		vec.push_back(make_pair(a, b));

	}

	sort(vec.begin(), vec.end()); //pair를 넣고 정렬하면 첫번째를 기준으로 정렬된다.

	func();

	int M = *max_element(LIS, LIS + n);

	res = max(res, M);

	cout << '\n';
	cout << n - res<<'\n';
	int k = n - res;

	sort(lis, lis + n);

	while (res) {
		int idx = find2(res);
		visited[idx] = 1;
		res--;
	}
	
	int cnt = 0;

	for (int x = 0; x < n; x++) {

		if (!visited[x]) {
			cout << find(lis[x].first)<< '\n';
			cnt++;
		}
		if (cnt == k) break;
	}

	return 0;
}