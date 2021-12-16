#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int h, w;
char map[51][51];
int num[51][51];
int res;
int go[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

queue <pair<int, int>> que;

void set() {
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			num[y][x] = -1;
}

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && x < w&& y < h;
}

int bfs(int y, int x) {
	set();
	int ans=0;

	que.push({ y,x });
	num[y][x] = 0;

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		ans = max(ans, num[tempy][tempx]);

		for (int i = 0; i < 4; i++)
		{
			int dy = tempy + go[i][0];
			int dx = tempx + go[i][1];

			if (inrange(dy, dx) && num[dy][dx] == -1 && map[dy][dx] == 'L') { // 범위안, 처음방문
				que.push({ dy,dx });
				num[dy][dx] = num[tempy][tempx] + 1;
			}
		}

		
	}

	return ans; // 
}

int main() {

	cin >> h >> w;

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			cin >> map[y][x];

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++) {
			if (map[y][x] == 'L') {
				res = max(res, bfs(y, x));
			}
		}

	cout << res;

	return 0;
}