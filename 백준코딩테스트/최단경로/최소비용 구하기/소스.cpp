#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int n, m;
vector <pair<int,int>> vec[100001];
int res;
int dp[1001];

void func(int s,int e) {

	stack <int> stk;

	for (int q = 1; q <= n; q++) { // ¼¶¿¡¼­ ¼¶À¸·Î °¡´Â °Å¸®dp
		dp[q] = 1e9;
	}

	dp[s] = 0;
	stk.push(s);

	while (!stk.empty()) {

		int st = stk.top();

		stk.pop();

		for (int q = 0; q < vec[st].size(); q++) {

			int next = vec[st][q].first;
			int nextdis = vec[st][q].second;
			int dis = dp[next];

			if (dis > dp[st]+nextdis) {
				dp[next] = dp[st]+nextdis;
				stk.push(next);
			}

		}
	}

}

void show() {
	for (int x = 1; x <= n; x++)
		cout << dp[x] << ' ';
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int q = 0; q < m; q++) {
		int a,b,c;
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
	}

	int start, des;
	cin >> start >> des;

	func(start, des);
	//show();
	cout << dp[des];

	return 0;
}