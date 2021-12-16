#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, a, b, k;
int map[510][510];
int visited[510][510];
int starty, startx;
int endy, endx;
int go[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
queue <pair<int, int>> que;

bool inrange(int y, int x) {
	return y > 0 && x > 0 && y <= n && x <= m;
}

bool search(int dy, int dx) {

	for (int y = dy; y <= dy + a - 1; y++)
		for (int x = dx; x <= dx + b - 1; x++)
		{
			if (map[y][x] == 1 || !inrange(y, x))
				return 0;
		}

	return 1;
}

int bfs() {

	que.push({ starty,startx });
	visited[starty][startx] = 1;

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		if (tempy == endy && tempx == endx)
			return visited[tempy][tempx]-1;

		for (int i = 0; i < 4; i++) {

			int dy = tempy + go[i][0];
			int dx = tempx + go[i][1];

			if (inrange(dy, dx) && !visited[dy][dx] && map[dy][dx] == 0) {

				if (search(dy,dx)) {
					visited[dy][dx] = visited[tempy][tempx] + 1;
					que.push({ dy,dx });
				}
			}


		}
	}

	return -1;

}

int main() {

	cin >> n >> m >> a >> b >> k;

	for (int x = 0; x < k; x++) {
		int q, w;
		cin >> q >> w;
		map[q][w] = 1; //map을 1~n까지 쓰자 ㅎ
	}

	cin >> starty >> startx;
	cin >> endy >> endx;

	cout << bfs();


	return 0;
}