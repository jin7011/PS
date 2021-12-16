#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>

using namespace std;

int h,w;
int cnt;
int map[101][101];
bool visited[101][101];
queue <pair<int, int>> que;
int go[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && y < h && x < w;
}

//void show() {
//	for (int y = 0; y < h; y++) {
//		cout << '\n';
//		for (int x = 0; x < w; x++)
//			cout << map[y][x] << ' ';
//	}
//	cout << '\n';
//}

void bfs(int y,int x) {

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			visited[y][x] = 0;

	que.push({ y,x });
	visited[y][x] = 1;
	map[y][x] = -1;

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {

			int dy = tempy + go[i][0];
			int dx = tempx + go[i][1];

			if (inrange(dy, dx) && !visited[dy][dx]) {
				if (map[dy][dx] == -1) {
					visited[dy][dx] = 1;
					que.push({ dy,dx });
				}
				else if (map[dy][dx] == 0) {
					map[dy][dx] = -1;
					visited[dy][dx] = 1;
					que.push({ dy,dx });
				}
				
			}
		}
	}

}

void cheese() {

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{
			if (map[y][x] == 1) {
				int air = 0;
				for (int i = 0; i < 4; i++) {

					int dy = y + go[i][0];
					int dx = x + go[i][1];

					if (inrange(dy, dx) && map[dy][dx] == -1)
						air++;

					if (air >= 2) {
						map[y][x] = 2;
						break;
					}
				}
			}
		}
}

bool remove() {
	bool flag = 0;

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++) {
			if (map[y][x] == 2) {
				map[y][x] = 0;
				flag = 1; // 하나라도 썩을걸 없앴다면 on
			}
		}

	cnt = cnt + flag;

	return flag;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bool res;

	cin >> h >> w;
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++) //치즈 1 안쪽/그냥공기 0 바깥공기 -1 썩을치즈 2 치즈썩으면 0
			cin >> map[y][x];


	do {
		bfs(0, 0); // 공기분리 바깥공기 -1 안공기 0
		cheese();
		res = remove(); // 지웠으면 1 아니면 0
	} while (res);

	cout << cnt;

	return 0;
}