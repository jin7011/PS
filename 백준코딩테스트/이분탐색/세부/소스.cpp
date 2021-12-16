#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int start, des;
vector <pair<int, int>> bridge[300001];
queue <int> que;
bool visited[100001];
int mini, maxi;
long long res;

bool bfs(int s, int d, int m) {

	que.push(s);
	visited[s] = 1;

	while (!que.empty()) {

		int qf = que.front();

		que.pop();

		if (qf == d)
			return 1;

		for (int x = 0; x < bridge[qf].size(); x++) {
			int next = bridge[qf][x].first;
			long long weigh = bridge[qf][x].second;

			if (!visited[next] && weigh >= m) {
				visited[next] = 1;
				que.push(next);
			}
		}
	}

	return 0;
	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; // 섬과 다리 수
	cin >> start >> des; // 출발지점 도착지점

	for (int x = 0; x < m; x++) {
		int a, b,c;
		cin >> a >> b >> c;
		bridge[a].push_back({ b,c });
		bridge[b].push_back({ a,c });
		maxi = max(maxi, c);
	}

	while (mini <= maxi) {

		memset(visited, 0, sizeof(visited));
		long long mid = (mini + maxi) / 2;
		
		if (bfs(start, des, mid)) // mid가 옮겨진다면
		{
			res = mid;
			mini = mid + 1;
		}
		else
			maxi = mid - 1;
	}
	
	cout << res;

	return 0;
}