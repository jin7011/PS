#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

int map[26][26];
bool visited[26][26];
priority_queue <int> pq;

int housecnt = 0;
int danji = 0;

void dfs(int x, int y) {

	if (x < 0 || y < 0) return;
	if (map[x][y] == 0 || visited[x][y] == 1) return;
	
	else {
		visited[x][y] = 1;
		housecnt++;

	}

	dfs(x + 1, y);
	dfs(x, y + 1);
	dfs(x - 1, y);
	dfs(x, y - 1);
}

int main() {

	int n;
	cin >> n;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			scanf_s("%1d", &map[x][y]);

	for(int x=0; x<n;x++)
		for (int y = 0; y < n; y++) {
			if (map[x][y] == 1 && visited[x][y] == 0) {
				housecnt = 0;
				dfs(x, y);
				danji++;
				pq.push(-housecnt);
			}

		}

	cout << danji << '\n';
	while (!pq.empty()) {
		cout << pq.top() * -1 << '\n';
		pq.pop();
	}

	return 0;

}