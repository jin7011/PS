//정수 x에 사용할 수 있는 연산은 다음과 같이 세가지이다.
//
//1. x가 3으로 나누어 떨어지면 3으로 나눈다.
//2. x가 2로 나누어 떨어지면 2로 나눈다.
//3. 1을 뺀다.
//
//정수 n이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하라.
//
//input:
//1~10^6 정수 n 
//output:
//1을 만드는 연산횟수의 최솟값.
//
//ex)
//input:
//2
//
//output:
//1
//
//input:
//	10
//	
//output:
//	3
// 10경우에 10 -> 9 -> 3 -> 1로 3번만에 만들 수 있다.

#include <iostream>
#include <algorithm>

using namespace std;

int n = 0;
int* dp = 0;

int func(int n) { // 이전에 구한 값을 저장하여 재활용해야 그것이 동적활용인듯 싶다.

	dp[1] = 0; // 1을 1로만드는 횟수는 당연히 0임. (초기값)

	for (int x = 2; x <= n; x++) {
		if (x % 3 == 0) { //3으로 나누어지는게 가장 best 
			dp[x] = dp[x / 3] + 1; // x를 3으로 나누었던 data를 활용해서 그것에 +1 (현재 3으로 한번 나눴으므로)
			continue;
		}
		else if (x % 2 == 0) {
			if (dp[x / 2] < dp[x - 1]) {
				dp[x] = dp[x / 2] + 1;
			}
			else {
				dp[x] = dp[x - 1] + 1;
			}
			continue;
		}
			dp[x] = dp[x - 1] + 1;
	}
	return dp[n];
}

int main() {

	cin >> n;
	dp = new int[n + 1];

	cout << func(n);


	return 0;
}



