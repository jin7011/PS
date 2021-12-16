#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int h, w;
char map[101][101];
int num[101][101];
bool visited[101][101];
int res;
int ans = 1e9;

queue <pair<pair<int, int>,int>> que;
int go[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && x < w && y < h;
}

void dfs(int y, int x,int cnt) {

	num[y][x] = cnt;

	if (y == h - 1 && x == w - 1) {
		ans = min(ans, cnt);
		return;
	}

	for (int q = 0; q < 4; q++) {

		int dy = y + go[q][0];
		int dx = x + go[q][1];

		if (inrange(dy,dx) && !visited[dy][dx]) {
			visited[dy][dx] = 1;

			if (map[dy][dx] == '1' && num[dy][dx] > cnt + 1) {
				dfs(dy, dx, cnt + 1);
			}
			else if(map[dy][dx] == '0' && num[dy][dx] > cnt)
			{
				dfs(dy, dx, cnt);
			}

			visited[dy][dx] = 0;
		}
	}
		
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> w >> h;

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			cin >> map[y][x];

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			num[y][x] = 1e9;

	 dfs(0,0,0);

	 cout << ans;

	return 0;
}