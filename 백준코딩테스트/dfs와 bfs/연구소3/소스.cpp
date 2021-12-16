#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int map[51][51];
int num[51][51];
int copynum[51][51];
bool visited[11];
int n, vnum;
int* arr;
int* per;
int res,ans = 1e9;
int go[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int zerocnt;
int zeroval;

queue <pair<int, int>> que;
vector <pair<int, int>> virus;

void chk() { 

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			if (map[y][x] == 0)
				zerocnt++;
}

bool inrange(int y, int x) {
	return x > 0 && y > 0 && x <= n && y <= n;
}

void set() {

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			num[y][x] = copynum[y][x];

	while (!que.empty())
		que.pop();
}

void pushvirus(int y, int x) {

	que.push({ y,x });
	num[y][x] = 1;

}

int bfs(){
	zeroval = 0;
	res = 0;

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		for (int q = 0; q < 4; q++) {

			int dy = tempy + go[q][0];
			int dx = tempx + go[q][1];

			if (inrange(dy, dx) && !num[dy][dx] && map[dy][dx] != 1) {

				if (map[dy][dx] == 0) { // 빈공간은 시간+1 
					zeroval++;
					num[dy][dx] = num[tempy][tempx] + 1;
					res = max(res, num[dy][dx]);
					que.push({ dy,dx });
				}

				if (map[dy][dx] == 2) { // 비활성화 바이러스에 경우 시간 + 0
					num[dy][dx] = num[tempy][tempx]+1;
					que.push({ dy,dx });
				}

			}
		}
		
	}
	if (zeroval == zerocnt)
		return res; //  성공
	else
		return 1e9; //  실패
}

void permutation(int cnt) {

	int k;

	if (cnt == vnum) {
		int y, x;
		for (int q = 0; q < vnum; q++) {
			y = virus[per[q]].first;
			x = virus[per[q]].second;
			pushvirus(y, x);
		}
		ans = min(ans,bfs());
		set(); // que,num 초기화

		return;
	}

	if (cnt > 0)
		k = per[cnt - 1];
	else
		k = 0;

	for (int x = k; x < virus.size(); x++) {

		if (!visited[x]) {
			per[cnt] = arr[x];
			visited[x] = 1;
			permutation(cnt + 1);
			visited[x] = 0;
		}

	}
}

int main() {

	cin >> n >> vnum;

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++) {
			cin >> map[y][x];
			if (map[y][x] == 2)
				virus.push_back({ y, x }); // 비활성화 바이러스좌표를 저장.
			if (map[y][x] == 1) {
				copynum[y][x] = -1; // 벽체크
				num[y][x] = -1; // 초기입력
			}
			
		}

	chk(); // 빈칸체크
	arr = new int[virus.size()];
	per = new int[vnum];
	for (int q = 0; q < virus.size(); q++)
		arr[q] = q;

	permutation(0);
	
	if (ans != 1e9) {
		if(ans!=0)
		cout << ans - 1;
		if (ans == 0)
			cout << 0;
	}
	else
		cout << -1;
	
	return 0;
}