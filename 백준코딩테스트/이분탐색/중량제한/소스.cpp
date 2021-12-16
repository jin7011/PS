#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;
const int MAX = 100000 + 1;

int n, m; // n���� �� m���� �ٸ�
int a, b, c; // a���� b���� c�ٸ�
int mini, maxi; // ���߷���
int res; //�Ӱ����
int finish,start;

vector <pair<int, int>> vec[MAX]; //�Ӽ���
bool visited[MAX]; //�Ӻ�˶�

bool bfs(int weigh) { // ���ٸ��� �ε�ܺ��µ�
	queue <int> que;

	que.push(start); //ó�������ϴ� ���弶
	visited[start] = 1; 

	while (!que.empty()) {

		int qf = que.front(); //��߼�
		que.pop(); //��

		if (qf == finish) //����(����)���� ��޿Ϸ�� true
			return 1;

		for (int x = 0; x < vec[qf].size(); x++) {

			int next = vec[qf][x].first; //��������ȣ
			int nextweigh = vec[qf][x].second; // ���������� ���ٸ� ������?

			if (!visited[next] && weigh <= nextweigh) { //���� �������� ���
				visited[next] = 1;
				que.push(next);
			}
		}
	}

	return 0; // ���ٰ� ���ٸ��ǻ����� false
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
		vec[a].push_back({ b,c }); // a�ٸ����� (b�ٸ�����,����)
		vec[b].push_back({ a,c }); // ��ٸ�
		maxi = max(maxi, c);

	}
	cin >> start >> finish;

	while (mini <= maxi) {

		memset(visited, false, sizeof(visited));
		int mid = (mini + maxi) / 2;

		if (bfs(mid)) { // �հ�? ����
			res = mid;
			mini = mid + 1;
		}
		else //���հ� -> �Ͼ�����ȭ
			maxi = mid - 1;
		
	}

	cout << res << '\n';

	return 0;
}