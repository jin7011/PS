#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int V,v, e, k, u, w;
vector <pair<int, int>> vec[20001]; // vec[�����] <����ġ,������>

priority_queue <pair<int, int>> pq; // �ִܰŸ��� ������ minheap
int d[20001]; // �ִܰŸ� ���.

void dijkstra(int start) {

	d[start] = 0; // ���� ���±� 0
	pq.push(make_pair(0, start));

	while (!pq.empty()) {

		int distance = -1*pq.top().first; // pq�� ����ִ� ���� ª�� �Ÿ� distance�� -�� �����ؼ� ���߿� push�� �� ������ ���ھ�~
		int current = pq.top().second; // pq�� ����ִ� ���� ª�� �Ÿ��� index

		pq.pop(); // ������ ����.

		if (d[current] < distance) continue; // �ִܰŸ��� �ƴϹǷ� pass

		for(int x=0;x<vec[current].size(); x++){ //���õ�(current)�� �������� ���� �Ÿ��� ��� �񱳺м�.
		
			int next = vec[current][x].first; // ��������� �ּ�
			int nextdistance = distance + vec[current][x].second; // ���� ����� �Ÿ�.( ���ݰ��� �Ÿ� + �߰��Ÿ����)
			
			if (nextdistance < d[next]) { //���� ���ΰ��� �ܼ��Ÿ����� ������带 ���Ŀ� �Ÿ��� ª�ٸ�,
				d[next] = nextdistance;
				pq.push(make_pair(-nextdistance, next)); // �Լ� ó���� �Ÿ��� 0 �̶� ����������� �������� push�� �� ����ȭ ���Ѽ� pq�� �ּ������� ����� ����

			}
		
		}

	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> e >> k; // ������, ������, ���ۼ�

	for (int x = 1; x <= V; x++)
		d[x] = 100000000;

	while (e--) {

		cin >> u >> v >> w; // ������, ����, ����ġ
		vec[u].push_back(make_pair(v, w)); // [������].(����ġ,����) 
		//vec[v].push_back(make_pair(u, w));
	}

	dijkstra(k); // ������

	for (int x = 1; x <= V; x++) {
		if (d[x] == 100000000) {
			cout << "INF"<<'\n';
			continue;
		}
		cout << d[x] << '\n';
	}

	return 0;
}