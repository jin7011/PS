#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int map[1001][1001];
int visited[1001][1001][2];
int go[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool kicked;

queue < pair<pair<int, int>, int> >que;

bool inrange(int y, int x) {
	return y > 0 && x > 0 && y <= n && x <= m;
}

void bfs() {

	que.push({ {1,1},0 });
	visited[1][1][0] = 1;

	while (!que.empty()) {

		int tempy = que.front().first.first;
		int tempx = que.front().first.second;
		kicked = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {
			int dy = tempy + go[i][1];
			int dx = tempx + go[i][0];

			if (inrange(dy, dx)) {
				if (map[dy][dx] == 0 && !visited[dy][dx][kicked]) {
					que.push({ {dy,dx},kicked });
					visited[dy][dx][kicked] = visited[tempy][tempx][kicked] + 1;
				}
				if (map[dy][dx] == 1 && !visited[dy][dx][kicked] && kicked == 0) {
					que.push({ {dy,dx},kicked+1 });
					visited[dy][dx][kicked+1] = visited[tempy][tempx][kicked] + 1;
				}

			}
		}
	}

}

int main() {

	cin >> n >> m; //세로 가로

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= m; x++)
			scanf("%1d", &map[y][x]);

	bfs();

	if (visited[n][m][0] != 0 && visited[n][m][1] != 0)
		cout << min(visited[n][m][0], visited[n][m][1]);
	else if (visited[n][m][0] != 0)
		cout << visited[n][m][0];
	else if (visited[n][m][1] != 0)
		cout << visited[n][m][1];
	else
		cout << -1;

	return 0;
}