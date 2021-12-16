#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int n, k,w,v;
int W[101];
int V[100001]; 
int res = 0;
int dp[101][100001];

void func() { //    결과적으로 무게가 많이 주어질수록 많은 가치를 담아갈 수 있기떄문에 dp의 최종값이 최대값이 된다.

	for (int i = 1; i <= n; i++) {
		for (int w = 1; w <= k; w++) {

			dp[i][w] = dp[i - 1][w];   // 이번 물건을 넣지 않는다고 먼저 생각하고   (중요)

			if (w - W[i] >= 0) {  //무게를 보니 이번물건을 넣을 수 있다 생각했을 때 넣어보고 
				int n1 = dp[i - 1][w - W[i]] + V[i]; // 이전에 있던 물건을 전부빼고 이번물건을 넣었을 때, 남는 무게에서 가능한많이 다른 물건을 더 넣은 가치
				int n2 = dp[i - 1][w]; // 다시 생각해보니 이번 물건은 안넣는게 낫겠다 싶을때 가치

				dp[i][w] = max(n1,n2); // 더 큰것을 비교하여 저장한게 주어진 무게에서 최대가치값

			}
			else {
				continue;

			}
		}
	}


}

int main() {

	cin >> n >> k; // 갯수 4 , 무게 7

	for (int x = 1; x <= n; x++) {
		cin >> W[x] >> V[x];
	}

	func();

	for (int x = 1; x <= n; x++) {
		cout << '\n';
		for (int y = 0; y <= k; y++)
			cout << dp[x][y] << ' ';
	}
	cout <<'\n';

	cout << dp[n][k];

	return 0;
}