#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int map[51][51];
int num[51][51];
int copynum[51][51];
bool visited[10001];
int* arr;
int* per;
int res;
int ans= 1e9;
int n;
int vnum;
int zeronum;
int zerocnt;
int go[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

queue <pair<int, int>> que;
vector <pair<int, int>> virus;

bool inrange(int y, int x) {
	return y > 0 && x > 0 && x <= n && y <= n;
}

void actvirus(int y, int x) {
	que.push({ y,x });
	num[y][x] = 1;
}

void set() {
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			num[y][x] = 0;
}

void chk() {
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			if (map[y][x] == 0 || map[y][x] == 2)
				zeronum++;

	zeronum = zeronum - vnum;
}

int bfs() {
	zerocnt = 0;
	res = 0;

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		for (int q = 0; q < 4; q++) {

			int dy = tempy + go[q][0];
			int dx = tempx + go[q][1];

			if (inrange(dy, dx) && num[dy][dx]==0 && map[dy][dx] != 1) {
				que.push({ dy,dx });
				num[dy][dx] = num[tempy][tempx] + 1;
				res = max(res,num[dy][dx]);
				zerocnt++;
			}
		}
	}

	if (zerocnt == zeronum)
		return res;
	else
		return 1e9;
}

void putvirus(int cnt) {

	int k;

	if (cnt == vnum) {

		for (int q = 0; q < vnum; q++) {
			int y = virus[per[q]].first;
			int x = virus[per[q]].second;
			actvirus(y, x);
		}
		ans = min(ans,bfs());
		set();

		return;
	}

	if (cnt == 0)
		k = 0;
	else
		k = per[cnt - 1];

	for (int q = k; q < virus.size(); q++) {
		if (!visited[q]) {
			per[cnt] = arr[q];
			visited[q] = 1;
			putvirus(cnt + 1);
			visited[q] = 0;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> vnum;

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++) {
			cin >> map[y][x];
			if (map[y][x] == 2)
				virus.push_back({ y,x });
		}

	chk();
	arr = new int[virus.size()];
	per = new int[vnum];

	for (int q = 0; q < virus.size(); q++)
		arr[q] = q;

	putvirus(0);

	if (ans != 1e9) {
		if (ans != 0)
			cout << ans-1;
		else if(ans == 0)
			cout << 0;
	}
	else
		cout << -1;

	return 0;
}