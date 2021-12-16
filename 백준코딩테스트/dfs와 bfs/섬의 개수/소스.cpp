#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

queue <pair<int, int>> que;

int w,h;
int map[51][51];
bool visited[51][51];
int t;
int go[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
//int go2[4][2] = {{ -1,-1 }, { 1,1 }, { 1,-1 }, { -1,1 }};
int gox[4] = { -1,1,-1,1 };
int goy[4] = { -1,1,1,-1 };
bool flag=0;
int cnt = 0;

int inrange(int wide, int high) {
	return wide >= 0 && wide < w && high >= 0 && high < h;
}

void bfs() {	

	while (!que.empty()) {
		//int len = que.size();
			int dx, dy;
			int tempy = que.front().first;
			int tempx = que.front().second;

			que.pop();

			for (int x = 0; x < 4; x++) {
				dy = tempy + goy[x];
				dx = tempx + gox[x];

				if (inrange(dx, dy) && !visited[dy][dx] && map[dy][dx] == 1) {
					visited[dy][dx] = true;
					que.push({ dy,dx });
					//flag = true;
				}
			}

			for (int x = 0; x < 4; x++) {
				dy = tempy + go[x][1];
				dx = tempx + go[x][0];

				if (inrange(dx, dy) && !visited[dy][dx] && map[dy][dx] == 1) {
					visited[dy][dx] = true;
					que.push({ dy,dx });
					//flag = true;
				}
			}		

	}		

}

int main() {
	w = 1;
	h = 1;
	while (w!=0 && h!= 0) {
		cnt = 0;

		cin >> w >> h;

		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++) {
				cin >> map[y][x];
				visited[y][x] = 0;
			}

		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++) {
				if (map[y][x] == 1 && !visited[y][x]) {
					visited[y][x] = 1;
					que.push({ y,x });
					bfs();
					cnt++;
				}
			}

	/*	for (int y = 0; y < h; y++) {
			cout << '\n';
			for (int x = 0; x < w; x++)
				cout << visited[y][x] << ' ';
		}*/

		//cout << '\n';
		if(w!=0 && h!=0)
		cout << cnt<<'\n';

	}

	return 0;
}