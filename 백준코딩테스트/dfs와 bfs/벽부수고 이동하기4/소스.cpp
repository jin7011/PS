#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
#include <string>

using namespace std;

queue< pair<int, int> > que;
queue< pair<int, int> > zeroque;
queue<int> boolque;
queue < pair<int, int> > oneque;

int zeromap[1001][1001];
int map[1001][1001];
int visited[1001][1001];

int group[55555555];
bool groupbool[55555555];

int go[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int n,m;
int cnt = 1;

bool inrange(int y, int x) {
	return x > 0 && y > 0 && x <= m&& y <= n;
}

int bfs(int y, int x) {

	//setD();
	int zero_cnt = 1;

	que.push({ y,x });
	zeroque.push({ y,x });
	visited[y][x] = 1;

	while (!que.empty()) {

			int tempy = que.front().first;
			int tempx = que.front().second;

			que.pop();

			for (int x = 0; x < 4; x++)
			{
				int dy = tempy + go[x][1];
				int dx = tempx + go[x][0];

				if (inrange(dy, dx) && !visited[dy][dx] && map[dy][dx] == 0) {
					que.push({ dy,dx });
					zeroque.push({ dy,dx });
					zero_cnt++;
					visited[dy][dx] = 1;
					
				}
			}
	}

	return zero_cnt;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m; //세로 가로

	for (int y = 1; y <= n; y++) 
		for (int x = 1; x <= m; x++) {
			scanf_s("%1d", &map[y][x]);
		}

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= m; x++) {
			if (map[y][x] == 0 && !visited[y][x]) {
				group[cnt] = bfs(y, x); //0의 이동거리를 한묶음씩 저장.

				while (!zeroque.empty()) {
					int tempy = zeroque.front().first;
					int tempx = zeroque.front().second;

					zeromap[tempy][tempx] = cnt;

					zeroque.pop();
				}
				cnt++;
			}

			if (map[y][x] == 1) {
				oneque.push({ y,x });
			}
			
		}

	while (!oneque.empty()) {

		int tempy = oneque.front().first;
		int tempx = oneque.front().second;

		oneque.pop();

		while (!boolque.empty()) {
			groupbool[boolque.front()] = 0;
			boolque.pop();
		}

		for (int i = 0; i < 4; i++) {
			int ty = tempy + go[i][1];
			int tx = tempx + go[i][0];

			if (inrange(ty, tx) && map[ty][tx] != 1 && !groupbool[zeromap[ty][tx]]) {
				groupbool[zeromap[ty][tx]] = true; // 덧셈에 쓰였다이말이야
				map[tempy][tempx] = map[tempy][tempx] + group[zeromap[ty][tx]];
				boolque.push(zeromap[ty][tx]);
			}

		}
	}

	for (int y = 1; y <= n; y++) {
		cout << '\n';
		for (int x = 1; x <= m; x++)
			cout << map[y][x]%10;
	}

	return 0;
}
