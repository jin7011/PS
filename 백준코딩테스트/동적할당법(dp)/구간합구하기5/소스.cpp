#include <iostream>
using namespace std;
int N, M;
int dp[2048][2048];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int input;
			cin >> input;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + input;
		}
	}
	while (M--) {
		int sy, sx, ey, ex;
		cin >> sy >> sx >> ey >> ex;
		cout << dp[ey][ex] - dp[sy - 1][ex] - dp[ey][sx - 1] + dp[sy - 1][sx - 1] << "\n";
	}
	return 0;
}
