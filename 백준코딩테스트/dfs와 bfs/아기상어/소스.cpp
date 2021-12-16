#include <iostream>
#include <algorithm>
#include <math.h>
#include <functional>
#include <queue>
#include <vector>
#include <stdio.h>

using namespace std;

int map[21][21];
int num[21][21]; // 이동거리용
int visited[21][21];
int n;
int sharksz = 2;
int res;
int cnt;
int go[4][2] = { {-1,0}, {0,-1},{0,1},{1,0} };
int mini;
bool flag = 0;

queue <pair<int, int> > que;
pair<int, int> eatable;
pair<int, int> shark; // 초기에 상어위치 저장용.

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < n;
}

void bfs() {

	eatable =make_pair(n, n);
	mini = 1e5;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			visited[y][x] = 0;

	int sy = shark.first;
	int sx = shark.second;

	que.push({ sy,sx });
	num[sy][sx] = 0;
	visited[sy][sx] = 1;

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {// 위->왼쪽

			int dy = tempy + go[i][0];
			int dx = tempx + go[i][1];

			if(inrange(dy,dx) && !visited[dy][dx] && map[dy][dx] <= sharksz){
				num[dy][dx] = num[tempy][tempx] + 1;

				if (num[dy][dx] <= mini && map[dy][dx] < sharksz && map[dy][dx] != 0 && eatable.first>dy) {
					// 먹을 수 있고 가장 가까운 곳중에서 위쪽에 있는 좌표를 저장. ( 처음좌표는 무조건 저장하고 시작)
					mini = num[dy][dx]; // 가장 가까운 거리를 체크해서 시간단축
					eatable = make_pair(dy,dx);	
				}
				else if (num[dy][dx] <= mini && map[dy][dx] < sharksz && map[dy][dx] != 0 && eatable.first == dy) { // 같은 y선상에 위치할 때 
					if (eatable.second >= dx) { // 그중 왼쪽에 있는 좌표를 우선시해서 대체한다.
						mini = num[dy][dx];
						eatable = make_pair(dy, dx);						
					}
				}

				visited[dy][dx] = 1;
				que.push({ dy,dx });

			}
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for(int y=0; y<n; y++)
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9)
				shark = make_pair(y, x);
		}

	// 상어기준 4방조사로 최단거리물고기 체크 (위쪽->왼쪽 우선)
	do {

		bfs();

		pair<int, int> t = make_pair(n,n);

		if (eatable != t) { //상어가 곱게 이동할 수 있다면

			cnt++;
			map[shark.first][shark.second] = 0; //처음위치 0
			res += num[eatable.first][eatable.second]; //상어가 물고기로 이동할 거리 저장.
			map[eatable.first][eatable.second] = 9; // 자리교환.

			if (cnt == sharksz) { // 상어와 크기가 같은 물고기였다면 상어의 크기++ cnt =0
				sharksz++;
				cnt = 0;
			}

			shark = eatable; // 다음 bfs를 위해 상어 위치 물고기로 체인지.

		}
		else
			break;
		
	} while (1);

	cout << res;

	return 0;
}