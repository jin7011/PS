#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
#define IFT 100000;

using namespace std;

int v, e, a, b, c;

int dp[401][401];

void show() {

	for (int y = 1; y <= v; y++) {
		//if (y != 1)
			cout << '\n';
		for (int x = 1; x <= v; x++) {
			cout << dp[y][x] << ' ';
		}
	}
}

void floyd() {

	for (int k = 1; k <= v; k++)
		for (int start = 1; start <= v; start++)
			for (int end = 1; end <= v; end++) {

				if (dp[start][k] != 0 && dp[k][end] != 0) { // 경유지가 있을때

					if (dp[start][k] + dp[k][end] < dp[start][end])
						dp[start][end] = dp[start][k] + dp[k][end];

				}else if(dp[start][end] == 0) //경유지만 있꼬 직진없을때
					dp[start][end] = dp[start][k] + dp[k][end];

			}

}

int main() {

	cin >> v >> e;

	for(int y=1;y<=v;y++)
		for (int x = 1; x <= v; x++) {
			if (y == x)
				dp[y][x] = IFT;
		}

	//show();

	while (e--) {
		cin >> a >> b >> c;

		if (dp[a][b] == 0 || dp[a][b] > c)
			dp[a][b] = c;
		
	}

	floyd();

	//show();

	int m = IFT;

	for (int y = 1; y <= v; y++)
		for (int x = 1; x <= v; x++)
			if (x == y)
				m = min(dp[y][x], m);

	if (m == 0 || m == 100000)
		cout << -1;
	else
	cout << m;

	return 0;
}