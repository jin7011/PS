#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

//Escaped in x minute(s) x는 시간
//Trapped! 탈출 불가능할 때

int t, highest, h, w;
char map[31][31][31];
int num[31][31][31];
int res;
int go[6][3] = { {0,1,0},{0,-1,0},{1,0,0},{-1,0,0},{0,0,1},{0,0,-1} };


queue <pair<pair<int, int>,int>> que; // 현재위치
queue <pair<pair<int, int>, int>> visi; //초기화 저장위치
pair <pair<int, int>, int> s; // 상근위치
pair <pair<int, int>, int> e; // 탈출구위치

void set() {

	for (int z = highest; z >= 1; z--) // 최상층부터 입력
		for (int y = 1; y <= h; y++)
			for (int x = 1; x <= w; x++) {
				num[y][x][z] = 0;
				map[y][x][z] = 0;
			}
	while (!que.empty())
		que.pop();
}

bool inrange(int y, int x,int z) {
	return y > 0 && x > 0 && x <= w && y <= h && z>=1 && z<= highest;
}

bool bfs(int y, int x,int z) {

	que.push({ { y,x },z });
	num[y][x][z] = 1;

	while (!que.empty()) {

		int tempy = que.front().first.first;
		int tempx = que.front().first.second;
		int tempz = que.front().second;

		que.pop();

		if (map[tempy][tempx][tempz] == 'E') {
			return 1;
		}

		for (int q = 0; q < 6; q++) {

			int dy = tempy + go[q][0];
			int dx = tempx + go[q][1];
			int dz = tempz + go[q][2];

			if (inrange(dy, dx,dz) && !num[dy][dx][dz] && map[dy][dx][dz] != '#'){
				num[dy][dx][dz] = num[tempy][tempx][tempz] + 1;
				que.push({ {dy,dx},dz });
			}
		}

	}
	return 0;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		
		cin >> highest>> h >> w;

		if (highest == 0 && h == 0 && w == 0)
			break;
		
		for (int z = highest; z>=1 ; z--) // 최상층부터 입력
			for (int y = 1; y <= h; y++)
				for (int x = 1; x <= w; x++) {
					cin >> map[y][x][z];
					if (map[y][x][z] == 'S')
						s = make_pair(make_pair(y, x), z);
					if(map[y][x][z] == 'E')
						e = make_pair(make_pair(y, x), z);
				}

		if (bfs(s.first.first, s.first.second, s.second)) {
			cout << "Escaped in "<< num[e.first.first][e.first.second][e.second]-1<<" minute(s).\n";
		}
		else
		cout << "Trapped!\n";

		set();

	}

	return 0;
}