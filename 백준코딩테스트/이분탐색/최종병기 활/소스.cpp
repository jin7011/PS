#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int len, home, k,q;
int baseidx;
int a[100001];
bool visited[1000001];

vector <int> homeindex;

int distance(int a, int b,int circlesz) { // a에서 b까지 가는 길이

	return (b - a + circlesz) % circlesz;

}

int check(int oribase, int lenth, int cnt) {

	int base = oribase;

	for (int x = (base + 1) % home; ; x = (x + 1) % home) {

		if (homeindex[x] == homeindex[oribase]) break;

		if (distance(homeindex[base], homeindex[x], len) >= lenth) { // base에서 다음 까지 길이가 mid보다 크면 다음이 base가 되고 자르는 횟수 ++
			cnt++;
			base = x;
		}

		if (cnt == k)
		{
			if (distance(homeindex[base], homeindex[oribase], len) >= lenth) // 다 자르고 나서 고무줄이 원모양이니까 남은 부분(마지막 base와 처음자른 곳(oribase))사이에 길이마저도 mid보다 크다면
				return 1;
			else
				return 0; // 남은 부분의 길이가 mid보다 작다면 모두 의미없는 짓이기때문에 실패반환
		}

	}

	return 0; // 전부 뒤져봤는데도 사이거리가 좁아서 자를 곳이 마땅치 않을때.
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
		int cnt = 1; // 처음거 잘랐다고 치고
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