#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1000004];
int n,temp1,temp2;

int func2(int x) {

	if (x == 1) return dp[x];

	if (x % 3 == 0) {
		if (dp[x / 3] != 1e9)
			dp[x] = dp[x / 3] + 1;
		else
			dp[x] = func2(x / 3)+1;
	}
	else if (x % 2 == 0){
		if (dp[x / 2] != 1e9)
			dp[x] = dp[x / 2] + 1;
		else
			dp[x] = func2(x / 2) + 1;

		if (dp[x - 1] != 1e9)
			dp[x] = min(dp[x - 1]+1, dp[x]);
		else
			dp[x] = min(func2(x - 1)+1, dp[x]);
	}
	else {
		if (dp[x - 1] != 1e9)
			dp[x] = dp[x - 1] + 1;
		else
			dp[x] = func2(x - 1) + 1;
	}

	return dp[x];
}

void func(int x) {

	for (int i = 1; i <= x; i++) {
		if ( i % 3 == 0 && dp[i/3] != -3 ) 
			dp[i] = min(dp[i / 3]+1, dp[i]);
		if ( i % 2 == 0 && dp[i/2] != -3 )
			dp[i] = min(dp[i / 2]+1, dp[i]);
		if( dp[x-1] != -3 )
			dp[i] = min(dp[i - 1]+1, dp[i]);
	}

}

void go(int x) {

	cout << x << ' ';
	if (x == 1) return;

	if (x%3 == 0 &&dp[x] == dp[x / 3] + 1)
		go(x / 3);
	else if (x%2 == 0 &&dp[x] == dp[x / 2] + 1)
		go(x / 2);
	else if (x-1 >0 &&dp[x] == dp[x - 1] + 1)
		go(x - 1);
}

int main() {

	cin >> n;

	fill(dp, dp + 1000004, 1e9);

	dp[1] = 0;
	cout << func2(n) << '\n';

	//func(n);
	//cout << dp[n] << '\n';
	go(n);

	return 0;
}