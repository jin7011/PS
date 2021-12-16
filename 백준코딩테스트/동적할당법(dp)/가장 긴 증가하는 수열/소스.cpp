#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int n;
int a[1000001];
int dp[1000001];
int cnt = 0;


int main() {

	cin >> n;

	for (int x = 0; x < n; x++)
		cin >> a[x];

	dp[0] = 1; // 자기포함이므로 항상 1로 시작하는데 첫번째 기준점은 이전까지의 기록이 없으므로 1로 시작

	for (int x = 1; x < n; x++) {
		dp[x] = 1; //dp[기준] = 1 (자기포함) 으로 시작해서 이전까지의 숫자와 dp(계산기록)을 비교해본다.
		for (int y = 0; y < x; y++) {
			if (a[x] > a[y]) {
				dp[x] = max(dp[y] + 1, dp[x]); // 기준(j)보다 작은 수가 있다면 그 작은 수가 이전에 작은 수보다 작은 수에 대해 기록된 dp가 있는지 확인하고 
												// 그 dp+1이 큰지 현재 기준점(i)의 dp가 큰지 확인해서 새로 기록한다.
			}
		}
	}
	
	cout << *max_element(dp, dp + n);

	return 0;
}