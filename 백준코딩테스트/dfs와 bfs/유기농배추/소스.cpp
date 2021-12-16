#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;  

queue <pair<int, int>> que;
pair <int, int> temp;

int map[51][51];
bool visited[51][51];

int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int n, m, k,t;
int q, w;
int cnt = 0;

bool inrange(int a, int b) {
	return a >= 0 && a < m && b >= 0 && b < n;
}

void func(int a, int b) {

	que.push(make_pair(a, b));
	visited[a][b] = true;
	
	while (!que.empty()) {

		temp = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) { // 상하좌우 판별
			int dx = temp.first + d[i][0];
			int dy = temp.second + d[i][1];

			if (map[dx][dy] == 1 && inrange(dx, dy) && visited[dx][dy] == 0) {
				visited[dx][dy] = 1;
				que.push(make_pair(dx, dy));
			}
		}
	}
}

int main() {

	cin >> t;

	while (t--) {

		cin >> n >> m >> k;

		cnt = 0;

		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++) {
				visited[x][y] = 0;
				map[x][y] = 0;
			}

		while (k--) {
			cin >> q >> w;
			map[w][q] = 1;
		}

		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++) {
				if (map[x][y] == 1 && visited[x][y] == 0) {
					func(x, y);
					cnt++;
				}
			}

		cout << cnt <<'\n';
	}
	return 0;
}