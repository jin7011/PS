#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

int n,k,L; // map and apple
int map[105][105];
int ans;
int go[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; //0 1 2 3 , 북동남서

deque <pair<int, int>> deq; // 뱀위 머리위치와 꼬리위치 저장소
queue <pair<int,char>> dir; //뱀이 방향을 바꿔야하는 시간과 방향.

bool inrange(int y, int x) {
	return y > 0 && x > 0 && x <= n && y <= n;
}

int dirfind(int side, char command) { // (원래방향 , 입력받을 방향) 없으면 0반환

	if (command == 'L') // 90도 왼쪽
		return side = (side + 3) % 4;
	
	if (command == 'D') //오른쪽
		return side = (side + 1) % 4;
}

void dfs(int y, int x, int side, int cnt) { // 좌표와 바라보는방향

	if (!inrange(y, x) || map[y][x] == 2) {
		ans = cnt;
		return;
	}

	if (map[y][x] == 0) {
		int prey = deq.back().first;
		int prex = deq.back().second;
		map[prey][prex] = 0;
		deq.pop_back();
	}

	map[y][x] = 2;
	deq.push_front({ y,x });

	if (!dir.empty()) {

		int i = dir.front().first;

		if (cnt == i) {
			char k = dir.front().second;
			side = dirfind(side, k);
			dir.pop();
		}
	}

	int dy = y + go[side][0];
	int dx = x + go[side][1];

	dfs(dy, dx, side, cnt + 1);
}

int main() {

	cin >> n >> k;
	
	for (int x = 0; x < k; x++) // 좌표 및 사과위치
	{
		int ay, ax;
		cin >> ay >> ax;
		map[ay][ax] = 1;
	}

	cin >> L; // 방향명령 갯수

	for (int x = 0; x < L; x++) { // 시행시간 및 방향
		int l;
		char direction;
		cin >> l>>direction;
		dir.push({ l,direction });
	}

	deq.push_back({ 1,1 }); // 가장 첫번째 1,1자리
	map[1][1] = 2;

	dfs(1+go[1][0], 1+go[1][1], 1,1);// 1,1 다음 동쪽부분에서 시작 ( +1초)

	cout << ans;

	return 0;
}