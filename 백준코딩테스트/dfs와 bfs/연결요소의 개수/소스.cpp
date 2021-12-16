#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector <int> vec[1001];
bool visited[1001];
int a, b;
int cnt = 0;

void bfs(int v) {
	queue <int> que;
	que.push(v);

	while (!que.empty()) {
		int qf = que.front();
		cout << qf << ' ';
		que.pop();

		for (int x = 0; x < vec[qf].size(); x++) {
			if (!visited[vec[qf][x]]) {
				visited[vec[qf][x]] = true;
				que.push(vec[qf][x]);
			}
		}
	}
}

int main() {

	cin >> n >> m;

	while (m--) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int x = 1; x <= n; x++)
		sort(vec[x].begin(), vec[x].end());

	for (int x = 1; x <= n; x++) {
		if (!visited[x]) {
			bfs(x);
			cout << '\n';
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}