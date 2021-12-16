//���ڲ���2
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
int cnt[1000001];//�ش� ��α��� �� �� �ִ� ����� ��

int step1(int x) {
	return x - 1;
}

int step2(int x) {
	return x + 1;
}

int step3(int x) {
	return 2 * x;
}

int choice(int x, int soo) { // �ɼǹ�ȣ�� �������� ������ġ

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
	visited[n] = 1; //ó���湮�� ���� 1�� (�ڽſ��� ���� ����� �� �� �����̱⶧��)
	cnt[n] = 0; // �ִܰŸ� 0����

	while (!que.empty()) {

		int from = que.front().first;
		int time = que.front().second;

		if (from == k) { //push�������� ������� ���ٴ� ���� ������k�� �� �������ڸ��� 
			//�������� �����ϴ� ����� �������� ���ߴٴ� �Ҹ� ���Ŀ� ���� level�� k���� �� ���͵� ��� x
			cout << cnt[k] << '\n' << visited[k];
			return;
		}

		que.pop();

		for (int i = 1; i <= 3; i++) {

			int go = choice(i, from);

			if (!visited[go] && go <= lim) {

				visited[go] = visited[from]; // �湮üũ �� ����� - ���������� �̵���� ����� ��
				cnt[go] = time + 1; // ������ �������� ���µ� �ɸ� ��������/��

				que.push({ go,time + 1 });
			}
			else if (time + 1 == cnt[go]) { //�ִ� �����̰� �̹� ��ȴ� ���̶�� ����� ���� �߰����ش�.
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