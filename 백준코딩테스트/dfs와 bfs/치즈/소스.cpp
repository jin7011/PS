#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>

using namespace std;

int map[101][101];
int visited[101][101];

queue <pair<int, int> > que;
vector <int> vec;

int go[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
int h, w;
int cnt=0;
int Dcnt = 0;
int flag = 0;

bool inrange(int y, int x) {
	return y >= 0 && y < h&& x >= 0 && x < w;
}

void bfs(int y, int x) { //바깥공기와 안쪽공기를 나누는 과정.

	que.push({ y,x });
	visited[y][x] = 1;

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {

			int dy = tempy + go[i][0];
			int dx = tempx + go[i][1];

			if (inrange(dy, dx) && map[dy][dx] == 0 || map[dy][dx] == -1 && visited[dy][dx] == 0) {
				if (map[dy][dx] == 0) {
					visited[dy][dx] = 1;
					map[dy][dx] = -1;
					que.push({ dy,dx });
				}
				else {
					que.push({ dy,dx });
					visited[dy][dx] = 1;
				}
			}

		}

	}

}

int cheese(int y, int x) { // 치즈 겉부분 분리 ( 바깥 공기인 -1과 치즈의 겉부분인 1로의 bfs)

	int flag = 0;

	que.push({ y,x });

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = tempy + go[i][0];
			int dx = tempx + go[i][1];

			if (inrange(dy, dx) && map[dy][dx] == 1 && map[tempy][tempx] == -1) {
				map[dy][dx] = 2;
				que.push({ dy, dx });
				flag = 1;
			}
		}

	}

	return flag;
}

void Delete() {

	cnt = 0;

	for(int y=0; y<h;y++)
		for (int x = 0; x < w; x++) {
			if (map[y][x] == 2) {
				map[y][x] = 0;
				cnt++;
			}
		}

	if(cnt!=0)
	vec.push_back(cnt);
	Dcnt++;

}

void show(){

	for (int y = 0; y < h; y++) {
		cout << '\n';
		for (int x = 0; x < w; x++)
			cout << map[y][x] << ' ';
	}
	cout << '\n';

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> w;

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			cin >> map[y][x];

	int res = 0;
	int k=0;

	do {

		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
				visited[y][x] = 0;

		flag = 0;


		bfs(0,0);
			

		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++) {
				if (map[y][x] == -1) {
					flag += cheese(y, x); //존재하면 1 끝낼때 0
				}
			}

		if(flag !=0)
		Delete();
		//show();
	
	} while (flag);

	cout << Dcnt << '\n' << *min_element(vec.begin(),vec.end()) ;

	return 0;
}