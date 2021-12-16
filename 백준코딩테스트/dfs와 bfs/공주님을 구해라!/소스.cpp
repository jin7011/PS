#include<iostream>
#include<algorithm>
#include<queue>
#include <stack>

using namespace std;

int map[101][101];
int num[101][101];
int res,h,w,t;
int go[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };

typedef struct D {
	int y, x,status,cnt;
}D;

queue <D> stk;


bool inrange(int y, int x) {
	return y > 0 && x > 0 && y <= h && x <= w;
}
void dfs() {
	int k = 0;
	res = 1e9;

	if (map[1][1] == 2)
		k = 1;
	else
		k = 0;

	stk.push({ 1,1,k,0 });
	num[1][1] = 0;

	while (!stk.empty()) {

		int y = stk.front().y;
		int x = stk.front().x;
		int cnt = stk.front().cnt;
		int status = stk.front().status;

		stk.pop();

		if (y == h && x == w) {
			res = min(res, num[y][x]);
		}

		for (int q = 0; q < 4; q++) {

			int dy = y + go[q][0];
			int dx = x + go[q][1];

			if (inrange(dy, dx) && cnt < t && num[dy][dx] > num[y][x] + 1) {

				if (status == 0) { // 그람 x

					if (map[dy][dx] != 1) {

						if (map[dy][dx] == 2) { //칼을 주웠을 때

							int temp = h - dy + w - dx; //칼을 주운 좌표부터 목적지까지 거리 계산

							if (num[y][x]+1 + temp <= t) { //만약 주어진 시간 T안으로 들어오면 MIN값으로 반환
								res = min(res, num[y][x]+1 + temp);
							}

						}
						else if (map[dy][dx] == 0) { // 그냥 땅
							num[dy][dx] = num[y][x] + 1;
							stk.push({ dy,dx,0,cnt + 1 });
						}

					}

				}

			}
		}

	}
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w >> t;

	for (int y = 1; y <= h; y++)
		for (int x = 1; x <= w; x++) {
			cin >> map[y][x];
			num[y][x] = 1e9;
		}

	dfs();

	if (res != 1e9)
		cout << res;
	else
		cout << "Fail";

	return 0;
}