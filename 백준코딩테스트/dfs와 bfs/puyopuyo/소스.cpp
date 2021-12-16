#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int h, w;
char map[13][7]; // R,G,B,P,Y
bool visited[13][7];
bool base[13][7];
int res;
bool flag;
int cnt;
int go[4][2] = { {0,1},{-1,0},{1,0},{0,-1} };

queue <pair<int, int>> que;
queue <char> s;
queue <pair<int, int>> de;

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && y < 12&& x < 6;
}

void show() {

	for (int y = 0; y < 12; y++) {
		cout << '\n';
		for (int x = 0; x < 6; x++)
			cout << map[y][x] << ' ';
	}
	cout << '\n';
}

void del() {

	while (!de.empty()) {

		int y = de.front().first;
		int x = de.front().second;

		map[y][x] = '.';

		de.pop();
	}
}

void dfs(int y, int x, int cntt,char col) {

	if (map[y][x] != col)
		return;

	if (cntt == 4)
		flag = 1;

	base[y][x] = 1;
	de.push({ y,x });

	for (int q = 0; q < 4; q++) {

		int dy = y + go[q][0];
		int dx = x + go[q][1];

		if (inrange(dy, dx) && !visited[dy][dx]&& map[dy][dx] == col) {
			visited[dy][dx] = 1;
			cnt++;
			dfs(dy, dx, cnt, col);
			visited[dy][dx] = 0;
		}
	}

}

void set() {
	for (int y = 0; y < 12; y++)
		for (int x = 0; x < 6; x++)
			visited[y][x] = 0;
	flag = 0;
	cnt = 1;
}

int remove() {

	bool ch=0;

	for (int y = 0; y < 12; y++)
		for (int x = 0; x < 6; x++)
			base[y][x] = 0;

	for (int y = 0; y < 12; y++)
		for (int x = 0; x < 6; x++)
		{
			if (map[y][x] != '.' && !base[y][x]) {
				set();
				visited[y][x] = 1;
				dfs(y, x, 1, map[y][x]);
				if (flag == 1) {
					del();
					ch = 1;
				}
				else {
					while (!de.empty()) {
						de.pop();
					}
				}
			}
		}

	return ch;
}

void resort(int dy,int dx) {

	int idx=dy;

	for (int y = dy - 1; y >= 0; y--) {
		if (map[y][dx] != '.') {
			map[idx][dx] = map[y][dx];
			map[y][dx] = '.';
			idx--;
		}
	}
}

void gravitysort() {

		for (int x = 0; x < 7; x++) {
			for (int y = 11; y >= 0; y--) {
				if (map[y][x] == '.') {
					resort(y,x);
					break;
				}
			}
		}

}

int chk() {

	for (int x = 0; x < 6; x++)
		if (map[11][x] != '.')
			return 1;

	return 0;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int y = 0; y < 12; y++)
		for (int x = 0; x < 6; x++)
			cin >> map[y][x];

	bool s=1;

	while (s) {
		if (remove() == 0)
			break;
		gravitysort();
		res++;
		show();
		s = chk();
	}

	cout << res;

	return 0;
}