#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;  // 6�� ���ͽ�Ʈ�󵹷����� ��� v1 ���� v2 ���°Ŵ� �ѹ��� ����ؼ� ���ص� �Ǵµ� �������ϱ� �׳� �ߴµ� �¾���.

int V, v, e, k, u, w;
vector <pair<int, int>> vec[20001]; // vec[�����] <����ġ,������>

priority_queue <pair<int, int>> pq; // �ִܰŸ��� ������ minheap
int d[20001]; // �ִܰŸ� ���.
int v1, v2;

void setD() {
	for (int x = 1; x <= V; x++)
		d[x] = 100000000;
}

void dijkstra(int start) {

	setD();
	d[start] = 0; // ���� ���±� 0
	pq.push(make_pair(0, start));

	while (!pq.empty()) {

			int distance = -1 * pq.top().first; // pq�� ����ִ� ���� ª�� �Ÿ� distance�� -�� �����ؼ� ���߿� push�� �� ������ ���ھ�~
			int current = pq.top().second; // pq�� ����ִ� ���� ª�� �Ÿ��� index

			pq.pop(); // ������ ����.

			if (d[current] < distance) continue; // �ִܰŸ��� �ƴϹǷ� pass

			for (int x = 0; x < vec[current].size(); x++) { //���õ�(current)�� �������� ���� �Ÿ��� ��� �񱳺м�.

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

	cin >> V >> e; // ������, ������, ���ۼ�

	for (int x = 1; x <= V; x++)
		d[x] = 100000000;

	while (e--) { //2,3�� �� ����ģ�ٸ�?

		cin >> u >> v >> w; // ������, ����, ����ġ
		vec[u].push_back(make_pair(v, w)); // [������].(����ġ,����) 
		vec[v].push_back(make_pair(u, w)); // �����
	}

	cin >> v1 >> v2;

	int index;
	int temp = 0;
	int temp2 = 0;

	dijkstra(1); // ������

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