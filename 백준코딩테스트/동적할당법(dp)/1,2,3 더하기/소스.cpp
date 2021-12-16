#include <iostream>
#include <algorithm>

using namespace std;

int coin[3] = { 1,2,3 };
int dp[1000001];

int n;
int k;

int func(int q) {

	if (dp[q] != 0) return dp[q];

	return dp[q] = func(q - 1) + func(q - 2) + func(q - 3); // 개같은 3보나치

}

int main() {

	cin >> n; //x테스트 케이스

	while (n--) {
		cin >> k; // 원하는 금액

		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		if (k < 4)
			cout << dp[k] << '\n';
		else
		cout << func(k) << '\n';
	}


	return 0;
}