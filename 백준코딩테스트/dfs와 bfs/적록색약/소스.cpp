#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
#include <string>

using namespace std;

queue< pair<int, int> > que;

char map[101][101];
int visited[101][101];
int normalvisited[101][101];

int go[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int n;
int cnt = 0;
int Bcnt = 0;
int normal = 0;

bool inrange(int y, int x) {
	return x >= 0 && y >= 0 && x < n && y < n;
}

void bfs(int y, int x, char col) {

	que.push({ y,x });
	normalvisited[y][x] = 1;

	while (!que.empty()) {

		for (int k = 0; k < que.size(); k++) {

			int tempy = que.front().first;
			int tempx = que.front().second;

			que.pop();

			for (int x = 0; x < 4; x++)
			{
				int dy = tempy + go[x][1];
				int dx = tempx + go[x][0];

				if (inrange(dy, dx) && !normalvisited[dy][dx] && map[dy][dx] == col) {
					que.push({ dy,dx });
					normalvisited[dy][dx] = 1;

				}
			}
		}
	}

}

void bfsRG(int y, int x) {

	que.push({ y,x });
	visited[y][x] = 1;

	while (!que.empty()) {

		for (int k = 0; k < que.size(); k++) {

			int tempy = que.front().first;
			int tempx = que.front().second;

			que.pop();

			for (int x = 0; x < 4; x++)
			{
				int dy = tempy + go[x][1];
				int dx = tempx + go[x][0];

				if (inrange(dy, dx) && !visited[dy][dx] && (map[dy][dx] == 'R' || map[dy][dx] == 'G') ) {	
						que.push( { dy,dx });
						visited[dy][dx] = 1;					

				}
			}
		}
	}

	//normal++;
}

void bfsB(int y, int x) {

	que.push( { y,x });
	visited[y][x] = 1;

	while (!que.empty()) {

		for (int k = 0; k < que.size(); k++) {

			int tempy = que.front().first;
			int tempx = que.front().second;

			que.pop();

			for (int x = 0; x < 4; x++) {

				int dy = tempy + go[x][1];
				int dx = tempx + go[x][0];

				if (inrange(dy, dx) && !visited[dy][dx] && map[dy][dx] == 'B') {
					que.push( { dy,dx });
					visited[dy][dx] = true;
				}
			}
		}
	}

	//cnt++;
}

void showV() {

	for (int y = 0; y < n; y++) {
		cout << '\n';
		for (int x = 0; x < n; x++) {
			cout << normalvisited[y][x] << ' ';
		}
	}
	cout << '\n';
}

int main() {

	cin >> n;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			cin >> map[y][x];

	// R or G 찾기 + B찾기
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++) {

			if ( (map[y][x] == 'G' || map[y][x] == 'R')) {

				if (!normalvisited[y][x]) {
					bfs(y, x, map[y][x]);
					normal++;
					//showV();
				}

				if (!visited[y][x]) {
					bfsRG(y, x);
					cnt++;
					//showV();
				}
			}

			if (map[y][x] == 'B' && !visited[y][x]) {
				bfsB(y, x);
				Bcnt++;
				//showV();
			}

		}

	cout << normal+Bcnt << ' '<< cnt+Bcnt;

	return 0;
}