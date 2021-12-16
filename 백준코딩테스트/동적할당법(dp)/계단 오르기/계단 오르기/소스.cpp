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
		dp[3] = a[1] + a[3];  //ù ��� ������ ��� ���� +1,+2 ��� ������ dp�� ������ ����

		for (int x = 4; x <= n;x++ ) {

			dp[x] = Max(dp[x - 3] + a[x - 1] + a[x], dp[x - 2] + a[x]); //���ۺ��� ���޾� ���� ���� ������ ��츦 ������ �� ū ���� ����.

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