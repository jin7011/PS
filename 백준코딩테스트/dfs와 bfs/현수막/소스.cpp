#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int w, h;

int map[251][251];
int visited[251][251];

int dydx[4][2] = { {0,1},{1,0},{-1,0},{0,-1} }; // 동서남북

int goy[4] = { 1,1,-1,-1 }; // 대각선행렬
int gox[4] = { -1,1,1,-1 };
int cnt = 0;

bool inrange(int y, int x) {
	return y > 0 && x > 0 && y <= h && x <= w;
}

queue <pair<int, int> > que;

void bfs(int y, int x) {

	que.push({ y,x });
	visited[y][x] = true;

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {
			int dy = tempy + dydx[i][0];
			int dx = tempx + dydx[i][1];

			if (inrange(dy, dx) && !visited[dy][dx] && map[dy][dx] == 1) {
				visited[dy][dx] = true;
				que.push({ dy,dx });
			
			}
		}

		for (int i = 0; i < 4; i++) {

			int dy = tempy + goy[i];
			int dx = tempx + gox[i];

			if (inrange(dy, dx) && !visited[dy][dx]&& map[dy][dx] == 1) {
				visited[dy][dx] = true;
				que.push({ dy,dx });

			}
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> w;

	for (int y = 1; y <= h; y++)
		for (int x = 1; x <= w; x++)
			cin >> map[y][x];

	for (int y = 1; y <= h; y++)
		for (int x = 1; x <= w; x++) {
			if (map[y][x] == 1 && !visited[y][x]) {
				bfs(y, x);
				cnt++;
			}
		}

	cout << cnt;

	return 0;
}