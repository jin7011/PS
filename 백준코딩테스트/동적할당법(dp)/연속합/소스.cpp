#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

int n;
int* a;
long long* dp;

void func() {

	int m = a[0];
	dp[0] = m;
	long long sum = m;

	for (int x = 1; x <= n; x++) {
		if (sum < 0) {
			dp[x] = a[x];
			sum = a[x];
		}
		else {
			sum += a[x];
			dp[x] = sum;
		}
	}

}

int main() {

	cin >> n;

	a = new int[n+5];
	dp = new long long[n+5];

	for (int x = 0; x < n; x++)
		cin >> a[x];

	func();

	cout << *max_element(dp, dp + n);

	return 0;
}