#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int map[126][126];
int num[126][126];
int res= 1e9;
int ans;
int t;
int go[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

queue <pair<int, int>> que;

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && x < n&& y < n;
}

void set() {

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			num[y][x] = 0;

	while (!que.empty()) {
		que.pop();
	}

	res = 1e9;
}

int bfs(int y, int x) {

	que.push({ y,x });
	num[y][x] = map[y][x];

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		if (tempy == n - 1 && tempx == n - 1)
		{
			res = min(res,num[tempy][tempx]);
		}

		for (int q = 0; q < 4; q++) {

			int dy = tempy + go[q][0];
			int dx = tempx + go[q][1];

			if (inrange(dy, dx) && num[dy][dx] > num[tempy][tempx] + map[dy][dx]) {
				que.push({ dy,dx });
				num[dy][dx] = num[tempy][tempx] + map[dy][dx];
			}

		}

	}

	return res;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int o = 1;

	while (1) {

		cin >> n;
		if (n == 0)
			break;

		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++) {
				cin >> map[y][x];
				num[y][x] = 1e9;
			}

		cout << "Problem " << o << ": " << bfs(0, 0)<<'\n';
		o++;
		set();

	}


	return 0;
}