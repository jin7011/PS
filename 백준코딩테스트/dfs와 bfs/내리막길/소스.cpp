#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int h,w;
int res;
int map[501][501];
int visited[501][501];

bool inrange(int y, int x) {
	return y >= 0 && y < h && x >= 0 && x < w;
}

int dfs(int y,int x,int high) { // 0 , 0 , 1e5
	//map[0][0] = 50 = high ���� ���� 
	  // 50 < 1e5
	if (high <= map[y][x]) return 0;  // ���밡 �� ���ٸ� �Ȱ�.
	if (!inrange(y, x)) return 0;
	

	if (visited[y][x] == -1) { // �鸰���� ���ٸ� 

		visited[y][x] = 0;

		if (y == h - 1 && x == w - 1) {
			res++;
			return 1;  // �����ϸ� 1�� ��ȯ����.
		}

		visited[y][x] += dfs(y + 1, x, map[y][x]); // ������ ��ǥ ,���� ���� �Ű�������
		visited[y][x] += dfs(y - 1, x, map[y][x]);
		visited[y][x] += dfs(y, x - 1, map[y][x]);
		visited[y][x] += dfs(y, x + 1, map[y][x]);
	}

	return visited[y][x];

}

int go(int y, int x) {

	int go[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

	if (visited[y][x] == -1) {

		visited[y][x] = 0;

		for (int i = 0; i < 4; i++) {

			int dy = y + go[i][0];
			int dx = x + go[i][1];

			if ( inrange(dy, dx) && (map[dy][dx] < map[y][x]) ) {
				visited[y][x] += go[dy][dx];
			}
		}

	}

	return visited[y][x];
}

int main() {

	cin >> h >> w;

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++) {
			cin >> map[y][x];
			visited[y][x] = -1;
		}

	visited[h - 1][w - 1] = 1;

	//cout << dfs(0, 0, 1e5);
	cout << go(0, 0);

	return 0;
}