#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <functional>

using namespace std;

int dp[5001][5001];
bool visited[5001][5001];

vector <int> vec;

int sum[5001];
int n;
int m;
int a, b;

void show() {

	for (int start = 1; start <= n; start++) {
		cout << '\n';
		for (int end = 1; end <= n; end++)
			cout << dp[start][end] << ' ';
	}
	cout << '\n';
}

void floyd() {

	int d = 0;

	for(int k = 1; k<=n;k++)
		for(int start = 1; start <=n; start++)
			for (int end = 1; end <= n; end++) {
				if (start == end) {
					dp[start][end] = 0;
					continue;
				}
				if (dp[start][k] != 0 && dp[k][end] != 0) {// 교차로가 있을때
					if (dp[start][end] != 0 && dp[start][end] > dp[start][k] + dp[k][end]) {
						dp[start][end] = dp[start][k] + dp[k][end];
					}
					else if (dp[start][end] == 0) {
						dp[start][end] = dp[start][k] + dp[k][end];
					}
				}
			}

}

int main() {

	cin >> n >> m;

	while (m--) {
		cin >> a >> b;

		dp[a][b] = 1;
		dp[b][a] = 1;
	}

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			if (y == x)
				dp[y][x] == 0;

	floyd();
	//show();

	for (int y = 1; y <= n; y++) {
		sum[y] = 0;
		for (int x = 1; x <= n; x++) {
			sum[y] += dp[y][x];
		}
	}

	int index = 0;
	int min = *min_element(sum + 1, sum + n + 1);

	for (int x = 1; x <= n; x++)
	{
		if (min == sum[x]) {
			cout << x;
			return 0;
		}
	}

	return 0;
}