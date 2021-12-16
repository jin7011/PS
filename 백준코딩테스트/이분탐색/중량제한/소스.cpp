#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;
const int MAX = 100000 + 1;

int n, m; // n개의 섬 m개의 다리
int a, b, c; // a섬과 b섬의 c다리
int mini, maxi; // 앙중량띠
int res; //앙결과띠
int finish,start;

vector <pair<int, int>> vec[MAX]; //앙섬띠
bool visited[MAX]; //앙비싯띠

bool bfs(int weigh) { // 돌다리를 두들겨보는데
	queue <int> que;

	que.push(start); //처음시작하는 공장섬
	visited[start] = 1; 

	while (!que.empty()) {

		int qf = que.front(); //출발섬
		que.pop(); //ㅍ

		if (qf == finish) //끝섬(공장)까지 배달완료시 true
			return 1;

		for (int x = 0; x < vec[qf].size(); x++) {

			int next = vec[qf][x].first; //다음섬번호
			int nextweigh = vec[qf][x].second; // 다음섬가는 돌다리 ㅁㅌㅊ?

			if (!visited[next] && weigh <= nextweigh) { //무게 ㅅㅌㅊ면 통과
				visited[next] = 1;
				que.push(next);
			}
		}
	}

	return 0; // 가다가 돌다리뽀사지면 false
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	mini = 0;
	maxi = 0;

	for (int x = 0; x < m; x++)
	{
		cin >> a >> b >> c;
		vec[a].push_back({ b,c }); // a다리에서 (b다리까지,무게)
		vec[b].push_back({ a,c }); // 양다리
		maxi = max(maxi, c);

	}
	cin >> start >> finish;

	while (mini <= maxi) {

		memset(visited, false, sizeof(visited));
		int mid = (mini + maxi) / 2;

		if (bfs(mid)) { // 합격? ㅇㅇ
			res = mid;
			mini = mid + 1;
		}
		else //불합격 -> 하양평준화
			maxi = mid - 1;
		
	}

	cout << res << '\n';

	return 0;
}