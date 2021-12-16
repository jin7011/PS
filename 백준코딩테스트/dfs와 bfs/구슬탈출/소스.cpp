#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
char map[4][11];
int go[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; // 상하좌우 순서. 0123
int r, b;

queue <pair<pair<int, int>,int> > R; // 좌표,횟수
queue <pair<pair<int, int>,int> > B; // 좌표,횟수
int res; 

bool inrange(int y,int x) {
	return y >= 0 && x >= 0 && y < n && x < m;
}

bool Bdfs(int y, int x,int redy,int redx,int dist) { // blue,red,방향

	if(map[y][x] == 'R')

}

void Rdfs(int y, int x, int dist, int cnt) { // 좌표 , 방향(4방 조사후 # 또는 0을 만날때까지 계속 방향을 '유지'하면서 진행 **

	if (map[y][x] == 'B')
		Bdfs();

	if (!inrange(y, x) && map[y][x] == '#' && cnt > 10) 
		return; 

	int turn = 1; // 방향을 가졌던 횟수.

	while (turn != 4) { // 해당지점 4방향 모두 조사.

		switch (dist) // 구슬이 한턴에 가지는 방향성에 대해서 브루트포스 (by dfs)를 실행. (4방모두 막힐시에 dfs종료) red먼저 조사 -> blue조사
		{

		case 0: { // 위쪽방향 유지

			int dy = y + go[0][0];
			int dx = x + go[0][1];

			if (inrange(dy, dx)) {

				if (map[dy][dx] == '.') { // 막혀있는 곳이 아닐때
					if (turn == 1) {
						Rdfs(dy, dx, dist, cnt);// 좌표와 움직임 (움직인 횟수는 방향성이 바뀌었을 때만 ++)
					}
					else {
						Rdfs(dy, dx, dist, cnt + 1);
					}
				}
			}
			else if (map[dy][dx] == '0') { // red가 구멍으로 빨려들어갈 때, blue가 빨려들어가지 않으면 종료 blue가 같이 들어가면 -> 무효.

				if (Bdfs(dy, dx, dist)) { // 들어가면 1 반환
					return;
				}
				else
					res = max(res, cnt + 1);
			}
			else { // red가 벽을 만났을 때 -> 무효
				map[dy][dx] = 'R';
				map[y][x] = '.';
				Bdfs()
				turn++;
				break;
			}
		}

		default:
			break;
		}

		dist++;

	}
}

int main() {

	cin >> n >> m;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];

			if (map[y][x] == 'R')
				R.push({ { y,x },0 });
			if (map[y][x] == 'B')
				B.push({ {y,x},0 });
		
		}



	return 0;
}