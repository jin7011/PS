#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <deque>

using namespace std;

int h, w;
int map[301][301];
bool visited[301][301];
int go[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int res;

queue <pair<int, int>> que;
queue <pair<int, int>> melted;

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && x < w && y < h;
}

void set() {
	
	//while (!visi.empty())
	//{
	//	int tempy = visi.front().first;
	//	int tempx = visi.front().second;

	//	visi.pop_front();
	//	visited[tempy][tempx] = 0;
	//}

}

void meltedset() {

	while (!melted.empty()) {

		int tempy = melted.front().first;
		int tempx = melted.front().second;

		melted.pop();
		visited[tempy][tempx] = 0;
	}
}

void show() {

	for (int y = 0; y < h; y++) {
		cout << '\n';
		for (int x = 0; x < w; x++)
			cout << map[y][x] << ' ';
	}
}

void melting(int y, int x) { // 그리디서치
	
	for (int q = 0; q < 4; q++)
	{
		int dy = y + go[q][0];
		int dx = x + go[q][1];

		if (map[dy][dx] == 0) { // 4방에 0이 있다면 
			if(map[y][x] > 0 && !visited[dy][dx]) // 0이하로 녹지않고 0이 되어버린 얼음은 패스
			map[y][x] = map[y][x] - 1;
			if (map[y][x] == 0) {
				visited[y][x] = 1;
				melted.push({ y,x });
				break;
			}
		}
	}

}

void bfs(int y, int x) {

	que.push({ y,x });
	visited[y][x] = 1;

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		for (int q = 0; q < 4; q++) {

			int dy = tempy + go[q][0];
			int dx = tempx + go[q][1];

			if (inrange(dy, dx) && map[dy][dx] > 0 && !visited[dy][dx]) {
				que.push({ dy,dx });
				visited[dy][dx] = 1;
				//visi.push_back({ dy,dx });
			}
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w;

	for(int y=0; y< h; y++)
		for (int x = 0; x < w; x++) {
			int a;
			cin >> a;
			map[y][x] = a;
		}

	int cnt = 300;

	while (cnt != 0) {

		cnt = 0;
		res++; // 횟수
		memset(visited, 0, sizeof(visited));
		

		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++) {
				if (map[y][x] > 0)
					melting(y, x);
			}

		meltedset();

		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (map[y][x] > 0 && visited[y][x] == 0) {
					bfs(y, x);
					cnt++;
				}
			}
		}

		if (cnt >= 2) {
			cout << res;
			return 0;
		}

	}

	cout << 0;

	return 0;
}