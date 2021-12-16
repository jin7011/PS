#include <iostream>
#include <algorithm>

using namespace std;

int a[10000] = { 0 };
int dp[10000] = { 0 };
int n;


int func(int n){
	// 6 10 13 9 8 1
	dp[1] = a[1];
	dp[2] = a[1] + a[2];
	dp[3] = max(a[1] + a[3], a[2] + a[3]); // 1,3 or 2,3 큰값 저장후에   (16,23)   12,13,23 만 비교하면댐
	dp[3] = max(dp[3], dp[2]);  // 추가된 방정식 정리.   (16,23)

	for (int x = 4; x <= n; x++) {
		dp[x] = max(dp[x - 3] + a[x - 1] + a[x], dp[x - 2] + a[x]); // dp[x-2] 0 arr[x]  or   dp[x-3] 0 arr[x-1] arr[x]
		dp[x] = max(dp[x], dp[x - 1]);  //이전 dp와 계속해서 비교. (두 칸 연속뛰었을 때 경우를 생각하기위해)
	}

	return max(dp[n], dp[n - 1]);

}

int main() {

	cin >> n;

	for (int x = 1; x <= n; x++)
		cin >> a[x];

	//if (n > 1)
		cout << func(n);
//	else if (n == 1)
	//	cout << a[1];

	return 0;

}