#include <iostream>
#include <algorithm>
using namespace std;

int* a;
int* dp;
int n;

int Max(int a, int b) {

	if (a < b) return b;
	else return a;

}

int func2(int n) {
		
	reverse(&a[1], &a[n+1]);

		dp[1] = a[1];

		dp[2] = a[1] + a[2];
		dp[3] = a[1] + a[3];  //첫 계단 무조건 밟고 나서 +1,+2 계단 밟은거 dp에 모조리 저장

		for (int x = 4; x <= n;x++ ) {

			dp[x] = Max(dp[x - 3] + a[x - 1] + a[x], dp[x - 2] + a[x]); //시작부터 연달아 밟은 경우랑 띄어밟은 경우를 나눠서 더 큰 값을 저장.

	}
		return Max(dp[n],dp[n - 1]);
}

int main() {

	cin >> n;

	a = new int[n];
	dp = new int[n];

	a[0] = 0;
	for (int x = 1; x < n+1; x++)
		cin >> a[x];

	cout << func2(n);

	return 0;
}