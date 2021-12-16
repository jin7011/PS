#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;  // 6번 다익스트라돌렸지만 사실 v1 에서 v2 가는거는 한번만 계산해서 더해도 되는데 귀찮으니까 그냥 했는데 맞았음.

int V, v, e, k, u, w;
vector <pair<int, int>> vec[20001]; // vec[출발지] <가중치,도착지>

priority_queue <pair<int, int>> pq; // 최단거리를 맨위로 minheap
int d[20001]; // 최단거리 기록.
int v1, v2;

void setD() {
	for (int x = 1; x <= V; x++)
		d[x] = 100000000;
}

void dijkstra(int start) {

	setD();
	d[start] = 0; // 내게 오는길 0
	pq.push(make_pair(0, start));

	while (!pq.empty()) {

			int distance = -1 * pq.top().first; // pq에 들어있는 가장 짧은 거리 distance를 -로 저장해서 나중에 push할 때 음수로 넣자아~
			int current = pq.top().second; // pq에 들어있는 가장 짧은 거리의 index

			pq.pop(); // 저장후 삭제.

			if (d[current] < distance) continue; // 최단거리가 아니므로 pass

			for (int x = 0; x < vec[current].size(); x++) { //선택된(current)의 인접노드로 가는 거리를 모두 비교분석.

				int next = vec[current][x].first; // 다음노드의 주소
				int nextdistance = distance + vec[current][x].second; // 다음 노드의 거리.( 지금계산된 거리 + 추가거리비용)

				if (nextdistance < d[next]) { //다음 노드로가는 단순거리보다 인접노드를 거쳐온 거리가 짧다면,
					d[next] = nextdistance;
					pq.push(make_pair(-nextdistance, next)); // 함수 처음엔 거리가 0 이라 상관없었지만 마지막에 push할 때 음수화 시켜서 pq를 최소힙으로 만들기 시작

				}

			}
		}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> e; // 정점수, 간선수, 시작수

	for (int x = 1; x <= V; x++)
		d[x] = 100000000;

	while (e--) { //2,3을 꼭 지나친다면?

		cin >> u >> v >> w; // 시작점, 끝점, 가중치
		vec[u].push_back(make_pair(v, w)); // [시작점].(가중치,끝점) 
		vec[v].push_back(make_pair(u, w)); // 양방향
	}

	cin >> v1 >> v2;

	int index;
	int temp = 0;
	int temp2 = 0;

	dijkstra(1); // 시작점

	if (d[v1] != 100000000 && d[v2] != 100000000) {

		if (d[v2] != 100000000) //1~v2
			temp = d[v2];
		else {
			cout << -1;
			return 0;
		}

		dijkstra(v2);

		if (d[v1] != 100000000)  // v2~v1
			temp += d[v1];
		else {
			cout << -1;
			return 0;
		}

		dijkstra(v1);

		if (d[V] != 100000000) // v1~V
			temp += d[V];
		else {
			cout << -1;
			return 0;
		}

		dijkstra(1);

		if (d[v1] != 100000000)  //1~v1
			temp2 = d[v1];
		else {
			cout << -1;
			return 0;
		}

		dijkstra(v1);
		if (d[v2] != 100000000) //v1~v2
			temp2 += d[v2];
		else {
			cout << -1;
			return 0;
		}

		dijkstra(v2);
		if (d[V] != 100000000)  //v2~V
			temp2 += d[V];
		else {
			cout << -1;
			return 0;
		}
	}
	else
	{
		cout << -1;
		return 0;
	}



	cout << min(temp,temp2);

	
	
	return 0;
}