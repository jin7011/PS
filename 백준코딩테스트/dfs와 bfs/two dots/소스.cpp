#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <vector>
#include <stack>

using namespace std;

typedef struct D{
	int y, x, cnt, sy, sx;
	char col;

}D;

int h, w, res, go[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool visited[51][51];
char map[51][51];
int flag = 0;

stack <D> que;
queue <pair<int, int>> visite;

bool inrange(int y, int x) {
	return x > 0 && y > 0 && x <= w && y <= h;
}

void set() {

	//while (!visite.empty())
	//{
	//	int y = visite.front().first;
	//	int x = visite.front().second;

	//	visited[y][x] = 0;
	//	visite.pop();
	//}

	for (int y = 1; y <= h; y++)
		for (int x = 1; x <= w; x++)
			visited[y][x] = 0;

}

bool bfs(int y, int x) {// 처음좌표로 온전히 다시 돌아왔을 때 연동횟수가 4이상이면 return 1

	que.push({ y,x,1,y,x,map[y][x] }); //현재좌표 , 연동횟수 , 처음좌표
	visited[y][x] = 1;

	while (!que.empty()) {

		int tempy = que.top().y;
		int tempx = que.top().x;
		int cnt = que.top().cnt;
		int sy = que.top().sy;
		int sx = que.top().sx;
		char col = que.top().col;

		que.pop();

		for (int q = 0; q < 4; q++) {

			int dy = tempy + go[q][0];
			int dx = tempx + go[q][1];

			if (cnt >= 4 && dy == sy && dx == sx) {
				return 1;
			}

			if (inrange(dy, dx) && !visited[dy][dx] && map[dy][dx] == col) {

				visited[dy][dx] = 1;
				que.push({ dy,dx,cnt + 1,sy,sx,col });
				visite.push({ dy,dx });
				//break;
			}
		}
		

	}

	return 0;

}

void dfs(int y, int x, int cnt, int sy, int sx, char col) {

	if (cnt >= 4 && y == sy && x == sx) {
		flag = 1;
		return;
	}

	for (int q = 0; q < 4; q++) {

		int dy = y + go[q][0];
		int dx = x + go[q][1];

		if (inrange(dy, dx) && (!visited[dy][dx] || cnt >= 4 && dy == sy && dx == sx) && map[dy][dx] == col) {
			visited[dy][dx] = 1;
			dfs(dy, dx, cnt + 1, sy, sx, map[dy][dx]);
			visited[dy][dx] = 0;
		}

	}
	

	
}

int main() {

	cin >> h >> w;

	for (int y = 1; y <= h; y++)
		for (int x = 1; x <= w; x++)
			cin >> map[y][x];

	for (int y = 1; y <= h; y++) {
		if (flag == 1)
			break;
		for (int x = 1; x <= w; x++) {
			visited[y][x] = 1;
			dfs(y, x, 1, y, x, map[y][x]);
			if (flag == 1)
				break;
			set();
		}
	}

	if (flag != 0)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}