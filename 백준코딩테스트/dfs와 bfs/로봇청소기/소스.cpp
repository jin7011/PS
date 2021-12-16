#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m, r, c, d, robotx, roboty;

int map[55][55];
//int visited[51][51];
int cnt = 1; //처음 위치한 자리++
int tries = 0;
int preD = 0;

queue < pair<pair<int, int>,int> > que;

void show() {
	for (int y = 0; y < n; y++) {
		cout << '\n';
		for (int x = 0; x < m; x++)
			cout << map[y][x] << ' ';
	}
	cout << cnt;
	cout << '\n';
}

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < m;
}

int dnum(int num) { //북서남동 순서로 받고싶어서 그렇게하면 벽이 있는경우에 direction + 1만 해주면 왼쪽을 바라볼 수 있따.
	if (num == 1)
		return 3;
	if (num == 3)
		return 1;
	else
		return num;
}

void goback(int y, int x, int direction) { //4방향 다 글러먹었을 때, 원래방향(d)유지하고 후진.

	if (direction == 0 && inrange(y+1,x) && map[y + 1][x] != 1)//북->남
	{
		if (map[y + 1][x] != 7) {
			map[y + 1][x] = 7;
			cnt++;
			que.push({ {y + 1,x},direction });
			return;
		}
		else {
			que.push({ {y + 1,x},direction });
			return;
		}
	}

	if (direction == 1 && inrange(y,x+1) && map[y][x + 1] != 1)//서 -> 동
	{
		if (map[y][x + 1] != 7) {
			map[y][x + 1] = 7;
			cnt++;
			que.push({ {y,x + 1},direction });
			return;
		}
		else {
			que.push({ {y,x + 1},direction });
			return;
		}
	}

	if (direction == 2 && inrange(y-1,x) && map[y - 1][x] != 1)//남 -> 북
	{
		if (map[y - 1][x] != 7) {
			map[y - 1][x] = 7;
			cnt++;
			que.push({ {y - 1,x},direction });
			return;
		}
		else {
			que.push({ {y - 1,x},direction });
			return;
		}
	}

	if (direction == 3 && inrange(y,x-1) && map[y][x - 1] != 1 )//동 -> 서
	{
		if (map[y][x - 1] != 7) {
			map[y][x - 1] = 7;
			cnt++;
			que.push({ {y ,x - 1},direction });
			return;
		}
		else {
			que.push({ {y ,x - 1},direction });
			return;
		}
	}

	return;
}

void left(int y, int x, int direction) { // 왼쪽방향을 탐색부터하고 "진행"(큐를 삽입)하는 함수. 막혀있다면 direction+1을 하고 써야함.
	     //현재좌표,현재방향
	for (int i = 1; i <= 4; i++) {
		int d = (direction + i) % 4; //가고자하는 방향 (현재방향의 왼쪽순으로 탐색)

		if (d == 0 && inrange(y-1,x)&& map[y-1][x] == 0 )//북으로 가고싶다 (from 동(3))
		{
			map[y-1][x] = 7;
			cnt++;
			que.push({ {y-1,x},d });
			return;
		}

		if (d == 1 && inrange(y,x-1) && map[y][x-1] == 0 )//서로 가고싶다
		{
			map[y][x-1] = 7;
			cnt++;
			que.push({ {y,x-1},d});
			return;
		}

		if (d == 2 && inrange(y+1,x) && map[y+1][x] == 0)//남
		{
			map[y+1][x] = 7;
			cnt++;
			que.push({ {y+1,x},d });
			return;
		}
	
		if (d == 3 && inrange(y,x+1) && map[y][x+1] == 0)//동
		{
			map[y][x+1] = 7;
			cnt++;
			que.push({ {y,x+1 },d });
			return;
		}

	}
	//4방향 다 글러먹었을 때, 원래방향에서 후진하고 다시 4방향 체크
	goback(y, x, direction);
	return;

}

void bfs(int y,int x,int d) {

	que.push({ { y,x },dnum(d)}); //처음위치
	map[y][x] = 7;

	while (!que.empty()) {

		int tempy = que.front().first.first;
		int tempx = que.front().first.second;
		int direction = que.front().second;
		
		left(tempy, tempx, direction);
		//show();
		que.pop();

	}

}

int main() {

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			cin >> map[y][x];

	bfs(r, c, d); // 로봇의 위치와 보는 방향
	
	//show();

	//cout << '\n';
	cout << cnt;

	return 0;
}
