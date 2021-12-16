#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

typedef struct D {
	int q,w;
}D;

struct compare {
	bool operator() (const D& a, const D& b) {
		return a.q > b.q;
	}

};

int LIS[100001] = { 0 };
int n;
int a,b;
int res = 0;

vector <pair<int,int>> vec;
priority_queue<D, vector<D>, compare> pq;

void func() {

	LIS[0] = 1;

	for (int x = 1; x < n; x++) {
		LIS[x] = 1;
		for (int y = 0; y < x; y++) {
			if (vec[x].second > vec[y].second) {
				LIS[x] = max(LIS[x], LIS[y] + 1);

			}
		}
	}
}

int main() {

	cin >> n;
	int o = n;

	while(o--) {

		cin >> a >> b;
		vec.push_back(make_pair(a, b));

	}

	sort(vec.begin(), vec.end()); //pair를 넣고 정렬하면 첫번째를 기준으로 정렬된다.

	func();

	int M = *max_element(LIS, LIS + n);

	res = max(res,M);
	cout << n-res;

	return 0;
}