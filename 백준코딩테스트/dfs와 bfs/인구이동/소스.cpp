#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int n, mini, maxi;
int map[51][51];
int visited[51][51];
int res;
int cnt;
int sum;
int ans;
int go[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

queue <pair<int, int>> que;
queue <pair<int, int>> land;

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && x < n && y < n;
}

bool incal(int a, int b) {
	int dis = abs(a - b);
	return dis >= mini && dis <= maxi;
}

void moveunit() {

	int len = land.size();

	for (int q = 0; q < len; q++) {

		int y = land.front().first;
		int x = land.front().second;

		land.pop();

		map[y][x] = sum / len;

	}

}

int bfs(int y,int x) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bool flag = 0;

	que.push({ y,x });
	visited[y][x] = 1;
	land.push({ y,x });
	sum = map[y][x];

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		for (int q = 0; q < 4; q++) {

			int dy = tempy + go[q][0];
			int dx = tempx + go[q][1];

			if (inrange(dy, dx) && !visited[dy][dx] && incal(map[dy][dx], map[tempy][tempx])) { // 맵범위 안쪽이고 인구차의 범위도 안쪽에 속할때,

				flag = 1;
				visited[dy][dx] = 1;
				que.push({ dy,dx });
				land.push({ dy,dx });
				sum += map[dy][dx];

			}
		}
	}

	moveunit();

	return flag;

}

void set() {
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			visited[y][x] = 0;
}

void show() {

	for (int y = 0; y < n; y++) {
		cout << '\n';
		for (int x = 0; x < n; x++)
			cout << map[y][x] << ' ';
	}
	cout << '\n';
}

int main() {

	cin >> n >> mini >> maxi;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			cin >> map[y][x];

	int stop = 0;

	do {

		stop = 0;

		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++) {
				if (!visited[y][x])
					stop += bfs(y, x);
			}

		if (stop != 0) {
			cnt++;
			//show();
			set();
		}

	} while (stop != 0);

	cout << cnt;

	return 0;
}