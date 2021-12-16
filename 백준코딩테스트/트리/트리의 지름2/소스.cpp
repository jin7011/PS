#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector <pair<int, int> > vec[100001];
queue <int> que;

int n; // ����� ����
int start, des, d;
int maxD = 0;
int k = 0;

int bfs(int v) {

	int visited[100001] = { 0, };
	int res[100001] = { 0, };
	int maxpoint = 0;
	k = 0;

	que.push(v);
	visited[v] = 1;

	while (!que.empty()) {

		int root = que.front(); // ��Ʈ���

		que.pop();

		for (int x = 0; x < vec[root].size(); x++) { //��Ʈ����� �ڽĵ��� ��� ���ƺ���,

			int next = vec[root][x].first; //��Ʈ����� �ڽ�(�αٵ�����)
			int newD = vec[root][x].second; // ��Ʈ������ �Ÿ�

			if (!visited[next] && res[next] < newD + res[root]) { // �������� ���ٸ� && �Ÿ��� �� ��ٸ�

				visited[next] = true;
				res[next] = newD + res[root];
				que.push(next);

				if (k < res[next]) {
					k = res[next];
					maxpoint = next;
				}
			}

		}
	}
	maxD = k;
	return maxpoint;

}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int o = n;
	o--;
	while (o--) {
		cin >> start;
		cin >> des;
		cin >> d;

		vec[start].push_back({ des,d });
		vec[des].push_back({ start,d });
		
	}

	bfs(bfs(1));

	cout << maxD;

	return 0;

}