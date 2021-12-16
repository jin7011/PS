#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

int f, s, g, u, d;
//int cnt;
int res;
int visited[1000001];

queue <pair<int, int>> que;

bool inrange(int k) {
	return k >= 1 && k <= f;
}

int bfs(int start) {

	que.push({ start,0 });
	visited[start] = 1;

	while (!que.empty()) {

		int floor = que.front().first;
		int cnt = que.front().second;

		if (floor == g)
			return cnt;

		que.pop();

		int uy = floor + u;
		int dy = floor - d;

		if (inrange(uy) && !visited[uy]) {
			visited[uy] = 1;
			que.push({ uy,cnt + 1 });
		}

		if (inrange(dy) && !visited[dy]) {
			visited[dy] = 1;
			que.push({dy, cnt + 1});
		}
		
	}

	return -1;
}

int main() {

	cin >> f >> s >> g >> u >> d;

	res = bfs(s);

	if (res != -1)
		cout << res;
	else
		cout << "use the stairs";

	return 0;
}