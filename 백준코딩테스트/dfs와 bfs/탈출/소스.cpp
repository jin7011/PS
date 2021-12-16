#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

char map[51][51];
int num[51][51];
int h, w;
int go[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int res;

queue <pair<int, int>> s;
queue <pair<int, int>> rain;

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && y < h&& x < w;
}

void flood() {
	
	while(!rain.empty()){ // 처음 저장된 rain의 위치정보까지만 

		int ry = rain.front().first;
		int rx = rain.front().second;

		rain.pop();

		for (int q = 0; q < 4; q++) {

			int dy = ry + go[q][0];
			int dx = rx + go[q][1];

			if (inrange(dy, dx) && num[dy][dx] == 0 && map[dy][dx] != 'X' && map[dy][dx] != 'D' && map[dy][dx] != 1) {
				num[dy][dx] = num[ry][rx] + 1;
				rain.push({ dy,dx });
			}
		}
	}
}

int move(int y, int x) {

	num[y][x] = 1;

	while (!s.empty()) {

		int sy = s.front().first;
		int sx = s.front().second;

		if (map[sy][sx] == 'D') {
			return num[sy][sx]-1;
		}

		//flood(); // 홍수먼저.
		s.pop();

		for (int w = 0; w < 4; w++) {
			
			int dy = sy + go[w][0];
			int dx = sx + go[w][1];

			if (inrange(dy, dx) && ( num[dy][dx] == 0 || num[dy][dx] > (num[sy][sx]+1) ) && map[dy][dx] != 1 && map[dy][dx] != 'X') {
				num[dy][dx] = num[sy][sx] + 1;
				s.push({ dy,dx });
			}
		}

		
	}

	return -1;
}

int main() {

	cin >> h >> w;

	for(int y = 0; y< h; y++)
		for (int x = 0; x < w; x++) {
			cin >> map[y][x];
			if (map[y][x] == 'S') {
				s.push({ y,x });
			}
			else if (map[y][x] == '*') {
				rain.push({ y,x });
				num[y][x] = 1;
			}
		}

	flood();

	res = move(s.front().first, s.front().second);

	if (res == -1)
		cout << "KAKTUS";
	else
		cout << res;

	return 0;
}