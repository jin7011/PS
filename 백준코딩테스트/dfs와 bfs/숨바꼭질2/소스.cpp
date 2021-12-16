//숨박꼭질2
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n, k;
queue <pair<int, int> > que;
int visited[1000001];
//int depth[200001];
int cnt[1000001];//해당 경로까지 갈 수 있는 경우의 수

int step1(int x) {
	return x - 1;
}

int step2(int x) {
	return x + 1;
}

int step3(int x) {
	return 2 * x;
}

int choice(int x, int soo) { // 옵션번호와 수빈이의 현재위치

	if (x == 1)
		return step1(soo);
	if (x == 2)
		return step2(soo);
	if (x == 3)
		return step3(soo);

}
const int lim = 100000;

void bfs() {

	que.push({ n,0 });
	visited[n] = 1; //처음방문한 경우는 1로 (자신에게 가는 경우의 수 한 가지이기때문)
	cnt[n] = 0; // 최단거리 0으로

	while (!que.empty()) {

		int from = que.front().first;
		int time = que.front().second;

		if (from == k) { //push할쯔음에 결과값을 낸다는 것은 목적지k에 딱 도달하자마자 
			//그전까지 도착하는 경우의 수까지만 더했다는 소리 이후에 같은 level에 k값이 더 나와도 계산 x
			cout << cnt[k] << '\n' << visited[k];
			return;
		}

		que.pop();

		for (int i = 1; i <= 3; i++) {

			int go = choice(i, from);

			if (!visited[go] && go <= lim) {

				visited[go] = visited[from]; // 방문체크 및 출발지 - 도착지간의 이동경로 경우의 수
				cnt[go] = time + 1; // 도착지 기준으로 오는데 걸린 걸음걸이/초

				que.push({ go,time + 1 });
			}
			else if (time + 1 == cnt[go]) { //최단 걸음이고 이미 들렸던 곳이라면 경우의 수만 추가해준다.
				visited[go] += visited[from];
			}
		}

	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	bfs();

	return 0;

}