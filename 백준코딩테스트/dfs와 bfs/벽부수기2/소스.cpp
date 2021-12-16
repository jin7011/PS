#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;\

typedef struct D {
	int y, x, cnt, num;
}D;

char map[1001][1001];
int num[1001][1001];
int visited[1001][1001][11];
int h, w;
int k;
int go[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

queue <pair<pair<int, int>, int>> que;
queue <D> quee;

int res = 1e9;

bool inrange(int y, int x) {
	return x > 0 && y > 0 && x <= w && y <= h;
}

int bfs() {
	bool flag = 0;

	que.push({ {1,1},0 });
	num[1][1] = 1;

	while (!que.empty()) {

		int tempy = que.front().first.first;
		int tempx = que.front().first.second;
		int cnt = que.front().second;

		que.pop();

		if (cnt > k)
			continue;

		for (int q = 0; q < 4; q++)
		{

			int dy = tempy + go[q][0];
			int dx = tempx + go[q][1];

			if (dy == h && dx == w && cnt<=k) {
				flag = 1;
				res = num[tempy][tempx]+1;
				return flag;
			}

			if (inrange(dy, dx && cnt <= k)) {
				if (map[dy][dx] == '1' && num[dy][dx] > num[tempy][tempx] + 1 && cnt+1 <= k) {
					num[dy][dx] = num[tempy][tempx]+1;
					que.push({ {dy,dx},cnt + 1 });
				}
				else if (map[dy][dx] != '1' && num[dy][dx] > num[tempy][tempx]+1) {
					num[dy][dx] = num[tempy][tempx]+1;
					que.push({ {dy,dx},cnt });
				}
			}
		}
	}

	return flag;

}

void dfs(int y, int x, int cnt) {

	if (y == h && x == w)
	{
		res = min(res, num[y][x]);
		return;
	}

	for (int q = 0; q < 4; q++) {
		
		int dy = y + go[q][0];
		int dx = x + go[q][1];

		if (inrange(dy, dx) && num[dy][dx] > num[y][x] + 1 && cnt<= k) {

			if (map[dy][dx] == '1' && (cnt+1) <= k) {
				num[dy][dx] = num[y][x] + 1;
				dfs(dy, dx, cnt + 1);
			}

			if(map[dy][dx] =='0')
			{
				num[dy][dx] = num[y][x] + 1;
				dfs(dy, dx, cnt);
			}

		}
	}

}



int func() {

	bool flag = 0;

	quee.push({ 1,1,0,1 }); // 좌표(1,1) , 벽부순횟수, 이동거리
	visited[1][1][0] = 1;

	while (!quee.empty())
	{
		
		int tempy = quee.front().y;
		int tempx = quee.front().x;
		int cnt = quee.front().cnt;
		int dis = quee.front().num;

		quee.pop();

		if (tempy == h && tempx == w)
		{
			flag = 1;
			res = min(res, dis);
		}

		for (int q = 0; q < 4; q++) {

			int dy = tempy + go[q][0];
			int dx = tempx + go[q][1];

			if (inrange(dy, dx)) {
				if (map[dy][dx] == '1') {
					if (!visited[dy][dx][cnt + 1] && cnt < k) {
						quee.push({ dy,dx,cnt + 1,dis + 1 });
						visited[dy][dx][cnt + 1] = 1;
					}
				}
				else {
					if (!visited[dy][dx][cnt]) {
						quee.push({ dy,dx,cnt,dis + 1 });
						visited[dy][dx][cnt] = 1;
					}
				}
			}
		}
	}

	return flag;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w >> k;

	for (int y = 1; y <= h; y++)
		for (int x = 1; x <= w; x++) {
			cin >> map[y][x];
			num[y][x] = 1e9;
		}

	/*num[1][1] = 1;
	dfs(1, 1, 0);

	if (res != 1e9)
		cout << res;
	else
		cout << -1;*/

	if (func() != 0)
		cout << res;
	else
		cout << -1;

	return 0;
}