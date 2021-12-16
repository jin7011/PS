#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

char map[1001][1001];
int num[1001][1001];
int res,h,w,ans=1e9;
int go[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

queue <pair<int, int>> s;
queue <pair<int, int>> f;
queue <pair<pair<int, int>, char>> que;

void set() {

	for (int y = 1; y <= h; y++)
		for (int x = 1; x <= w; x++) {
			num[y][x] = 0;
			map[y][x] = 0;
		}

	while (!s.empty())
		s.pop();
	while (!f.empty())
		f.pop();
	while (!que.empty())
		que.pop();

	//ans = 1e9;
	res = 0;
}

void show() {

	for (int y = 1; y <= h; y++) {
		cout << '\n';
		for (int x = 1; x <= w; x++) {
			cout<< num[y][x] << ' ';
		}
	}
}

void showmap() {

	for (int y = 1; y <= h; y++) {
		cout << '\n';
		for (int x = 1; x <= w; x++) {
			cout << map[y][x] << ' ';
		}
	}
}

bool inrange(int y, int x) {
	return y > 0 && x > 0 && y <= h&& x <=w;
}

void fire() {

	while (!f.empty()) {

		int y = f.front().first;
		int x = f.front().second;

		f.pop();

		for (int q = 0; q < 4; q++) {

			int dy = y + go[q][0];
			int dx = x + go[q][1];

			if (inrange(dy, dx) && !num[dy][dx] && map[dy][dx] != '#' && map[dy][dx] != '*') {
				f.push({ dy,dx });
				num[dy][dx] = num[y][x] + 1;
			}
		}
	}
}

int bfs() {

	num[s.front().first][s.front().second] = 1;

	while (!s.empty()) {

		int y = s.front().first;
		int x = s.front().second;

		s.pop();

		for (int q = 0; q < 4; q++) {

			int dy = y + go[q][0];
			int dx = x + go[q][1];

			if (dy > h || dx > w || dy <= 0 || dx <= 0) {
				return num[y][x];
			}

			if (map[dy][dx] == '.' && num[dy][dx] > num[y][x] + 1) {

				s.push({ dy,dx });
				num[dy][dx] = num[y][x] + 1;
				
			}
		}
	}
		return -1;

}

int escape() {

	while (!f.empty()) {
		que.push({{ f.front().first,f.front().second }, 'f'	});
		f.pop();
	}
	while (!s.empty()) {
		que.push({ { s.front().first,s.front().second }, 's' });
		s.pop();
	}

	while (!que.empty()) {

		int y = que.front().first.first;
		int x = que.front().first.second;
		char t = que.front().second;

		que.pop();

		if (t == 'f') {

			for (int q = 0; q < 4; q++) {

				int dy = y + go[q][0];
				int dx = x + go[q][1];

				if (inrange(dy, dx) && map[dy][dx] != '#' && map[dy][dx] != '*') {
					map[dy][dx] = '*';
					que.push({ {dy,dx},t });
				}
			}
		}
	//	showmap();

		if (t == 's') {

			//num[y][x] = 1;

			for (int q = 0; q < 4; q++) {

				int dy = y + go[q][0];
				int dx = x + go[q][1];

				if (!inrange(dy, dx))
					return num[y][x];

				if (map[dy][dx] == '.' && !num[dy][dx]) {
					que.push({ {dy,dx},t});
					num[dy][dx] = num[y][x]+1;
				}
			}
		}
	}

	return -1;
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		cin >> w >>h ;

		for (int y = 1; y <= h; y++)
			for (int x = 1; x <= w; x++) {
				cin >> map[y][x];

				if (map[y][x] == '@') {
					s.push({ y,x });
					num[y][x] = 1;
					//que.push({ {y,x},'s' });
				}
				if (map[y][x] == '*') {
					f.push({ y,x });
					//que.push({ {y,x},'f' });
					//num[y][x] = 1;
				}
			}

		//fire();
		//show();

		res = escape();
		//showmap();

		if (res != -1)
			cout << res<<'\n';
		else
			cout << "IMPOSSIBLE"<<'\n';

		set();
	}

	return 0;
}
