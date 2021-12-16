#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int n; //n x n
int cnt = 0;
int map[101][101];
int unsafe[101][101];
int maxi;
int mini = 1e5;
int res;
int go[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

queue <pair<int, int> > que;

void setV() {
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			unsafe[y][x] = 0;

	cnt = 0;
}

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < n;
}

void bfs(int y, int x) {

	que.push({ y,x });

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {
			int dy = tempy + go[i][0];
			int dx = tempx + go[i][1];

			if (inrange(dy, dx) && unsafe[dy][dx] == 0) {
				unsafe[dy][dx] = 1;
				que.push({ dy,dx });
			}
		}
		
	}
	
}

int main() {

	cin >> n;

	for (int y = 0 ;y < n; y++)
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
			maxi = max(map[y][x], maxi);
			mini = min(map[y][x], mini);
		}

	//mini ~ maxi 높이까지보자  // 완탐

	for (int h = mini; h <= maxi; h++) {
		if (h != mini) setV(); //safe cnt 0
		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++) { //우범지대체크
				if (map[y][x] < h)
					unsafe[y][x] = 1;
			}

		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				if (unsafe[y][x] == 0) {
					 bfs(y, x); //우범지대 체크후 안전지대체크
					 cnt++;
				}
		res = max(res, cnt);
	}

	cout << res;

	return 0;
}