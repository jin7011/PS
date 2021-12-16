#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

int map[101][101];
bool visited[101][101];
int num[101][101];

priority_queue <int> pq;

queue <pair<int, int>> que;
pair <int, int> p;

int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int n, m;
int cnt = 0;
int sum = 0;

int inrange(int a, int b) {
	return a >= 0 && a <= n && b >= 0 && b <= m;
}

void bfs(int x,int y) {

	visited[x][y] = true;
	num[x][y]++;
	p = make_pair(x, y);
	que.push(p);

	while (!que.empty()) {

		pair <int, int> tmp = que.front();
		que.pop();
		x = tmp.first;
		y = tmp.second;


		for (int j = 0; j < 4; j++) {

			int dx = x + d[j][0];
			int dy = y + d[j][1];

			if (inrange(dx, dy) && visited[dx][dy] != 1 && map[dx][dy] != 0) {
				if (dx == n - 1 && dy == m - 1) {
					cout << num[x][y] + 1;
					return;
				}
				else {
					visited[dx][dy] = true;
					num[dx][dy] = num[x][y] + 1;
					p = make_pair(dx, dy);
					que.push(p);
				}
			}
		}

	}

}

int main() {

	cin >> n>>m;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			scanf_s("%1d", &map[x][y]);

	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			num[x][y] == 0;

	bfs(0, 0);

	return 0;

}