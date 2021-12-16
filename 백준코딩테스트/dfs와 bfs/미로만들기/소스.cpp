#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

char map[51][51];
int visited[51][51];
int num[51][51];
int res=1e9;
int n;
int go[4][2] = { {0,1},{1,0}, { -1,0},{ 0,-1} };

queue <pair<pair<int, int>,int>> que;

bool inrange(int y, int x) {
	return y > 0 && x > 0 && y <= n && x <= n;
}

void dfs(int y, int x, int cnt) {

	num[y][x] = cnt;

	if (y == n && x == n ) {
		//res = min(res, cnt);
		return;
	}

	for (int q = 0; q < 4; q++) {

		int dy = y + go[q][0];
		int dx = x + go[q][1];

		if (inrange(dy,dx) && !visited[dy][dx] && num[dy][dx] > num[y][x]) {
			visited[dy][dx] = 1;

			if (map[dy][dx] == '1') {
				dfs(dy, dx, cnt);
			}
			else {
				dfs(dy, dx, cnt + 1);
			}

			visited[dy][dx] = 0;
		}

	}
}

int main() {

	cin >>n;

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			cin >> map[y][x];

	int m = n * n + 100;

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			num[y][x] = m;

	dfs(1, 1, 0);

	cout << num[n][n];

	return 0;
}