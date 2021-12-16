#include <iostream>
#include<algorithm>
#include <queue>
#include <stack>
using namespace std;

//queue < pair<pair<int, int>,int> > que;
//stack < pair<pair<int, int>, int> > stk;

int n, m;
int r, c;
int candy = 0;

int map[1001][1001];
int gox[3] = { 1,0,1 };
int goy[3] = { 0,1,1 };

int box = 0;

bool inrange(int y, int x) {
	return y > 0 && y <= n && x > 0 && x <= m;
}

//void bfs()
//{
//	que.push({ {1,1},map[1][1] });
//	
//	while (!que.empty()) {
//
//		int tempy = que.front().first.first;
//		int tempx = que.front().first.second;
//		candy = que.front().second;
//
//		que.pop();
//
//		for (int x = 0; x < 3; x++) {
//			int dy = tempy + goy[x];
//			int dx = tempx + gox[x];
//
//			if (inrange(dy, dx)) {
//
//				box = max(box, map[dy][dx] + candy);
//				que.push({ {dy,dx},candy + map[dy][dx] });
//
//			}
//		}
//	}
//
//}

void dfs(int y, int x, int c) {

		int tempy = y;
		int tempx = x;

		for (int x = 0; x < 3; x++) {
			int dy = tempy + goy[x];
			int dx = tempx + gox[x];

			if (inrange(dy, dx)) {

				box = max(box, map[dy][dx] + c);
				dfs(dy, dx, c + map[dy][dx]);

			}
		}
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= m; x++)
			cin >> map[y][x];

	dfs(1,1,map[1][1]);

	cout << box;

	return 0;
}