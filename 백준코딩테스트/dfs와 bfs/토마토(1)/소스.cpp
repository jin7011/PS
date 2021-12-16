#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

int map[1001][1001];
bool visited[1001][1001];
int date[1001][1001];

vector <int> vec;
queue <pair<int, int>> que;
pair <int, int> p;
pair <int, int> tmp;

int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
//int dz[2] = { -1,1 };
int n, m;
bool check = 0;
int cnt = 0;

bool inrange(int a, int b) {
	return a >= 0 && a < n && b >= 0 && b < m;
}

void bfs() {

	while (!que.empty()) {
		int len = que.size();
		check = 0;

		for (int Q = 0; Q <len; Q++) {  // 무한루프 돌지않게 while문에서 미리 익힌토마토에 대한 큐사이즈를 정의한다.
			tmp = que.front();
			que.pop();

			int x = tmp.first;
			int y = tmp.second;

			for (int i = 0; i < 4; i++) {
				int q = x + d[i][0];
				int w = y + d[i][1];

				if (inrange(q, w) && map[q][w] == 0 && visited[q][w] == 0) { // '0' 익지 않은 토마토  '-1' 비어있는 곳 '1' 익은토마토
					visited[q][w] = true;
					p = make_pair(q, w);
					que.push(p);
					if(check == 0)
					check = 1;
				}
			}
		}
		if (check == 1) {
			check = 0;
			cnt++;
		}
		else
			break;
	}

}

int main() {

	cin >> m >> n;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			cin >> map[x][y];


	for (int x = 0; x < n; x++)   //초기화
		for (int y = 0; y < m; y++) {
			visited[x][y] = 0;
		}

	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++) {
			if (map[x][y] == 1) {
				p = make_pair(x, y);
				que.push(p);
				visited[x][y] = true;
			}
		}

	bfs();

	bool ch=0;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++) {
			if (map[x][y] == 0 && visited[x][y] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			else if (map[x][y] == 0) {
				ch = 1;
			}
		}
	
	if (ch == 0)
		cout << 0;
	else
	cout << cnt;


	return 0;
}