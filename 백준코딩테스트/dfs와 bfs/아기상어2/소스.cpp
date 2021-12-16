#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int map[52][52];
int visited[52][52];
int go[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int goy[4] = { 1,-1,1,-1 };
int gox[4] = { 1,-1,-1,1 };

int h, w;
vector <int> res;
queue <pair<pair<int, int>,int> > que;

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && x < w&& y < h;
}

int bfs(int y, int x) {

	que.push({ { y,x }, 0 }); // 모든 0 의 좌표를 살펴볼것인데 0인좌표와 시작거리(제 자리)를 줬음
	visited[y][x] = 1;

	while (!que.empty()) {

		int tempy = que.front().first.first;
		int tempx = que.front().first.second;
		int cnt = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {

			int dy = tempy + go[i][0];
			int dx = tempx + go[i][1];

			if (inrange(dy, dx) && !visited[dy][dx]) {
				if (map[dy][dx]!=1) {
					que.push({ { dy,dx }, cnt + 1 });
					visited[dy][dx] = 1;
					
				}
				else if(map[dy][dx] == 1){
					//map == 1
					res.push_back(cnt + 1);
					return cnt+1;
				}
			}
		}

		for (int i = 0; i < 4; i++) {

			int dy = tempy + goy[i];
			int dx = tempx + gox[i];

			if (inrange(dy, dx) && !visited[dy][dx]) {
				if (map[dy][dx] != 1) {
					que.push({ { dy,dx }, cnt + 1 });
					visited[dy][dx] = 1;

				}
				else if(map[dy][dx] == 1){
					//map == 1
					res.push_back(cnt + 1);
					return cnt+1;
				}
			}
		}
	}
	return *min_element(res.begin(), res.end());
}

void set() {
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			if (visited[y][x] == 1)
				visited[y][x] = 0;

	while (!que.empty())
		que.pop();
}


int main() {
	vector <int> vec;

	cin >> h >>w;

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			cin >> map[y][x];

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++) {
			if (map[y][x] == 0) {
				vec.push_back(bfs(y, x));
				set();
			}
		}

	cout << *max_element(vec.begin(), vec.end());

	return 0;

}