#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#pragma warning(LNK2019)
#pragma warning(LNK1120)

using namespace std;
int lastnum;
int n;
int k;
int visited[555555];
int dp[555555];

queue <pair<int, int>> que; // ������ġ�� �ɸ��ð�

int res[555555];
int index;

int step(int x, int soo) {//�̵��ɼǰ� ����������ġ

	if (x == 1)
		return soo - 1;
	if (x == 2)
		return soo + 1;
	else
		return soo * 2;

}

int mincnt;

void bfs() {

	mincnt = 1000001;
	que.push({ n,0 });
	visited[n] = 0;

	while (!que.empty()) {

		int qf = que.front().first; // ������ġ
		int cnt = que.front().second; // ������

		if (qf == k) {
			mincnt = cnt;
			lastnum = qf;
			return;
		}
		
		que.pop();

		for (int x = 1; x <= 3; x++) { // 3���� ���·� �̵����� ��
			int nextstep = step(x, qf); //  ���� �̵���ġ

			if (nextstep >= 0 && nextstep < 100001) {

				if (visited[nextstep] == 0) {
					que.push({ nextstep,cnt + 1 });
					visited[nextstep] = qf;

				}
				
			}
		}
	}

}

int main() {

	cin >> n >> k;

	bfs();

	cout << mincnt<<'\n'<<n<<' ';

	stack <int> tracking;

	for (int x = 0; x < mincnt; x++) {
		tracking.push(lastnum);
		lastnum = visited[lastnum];
	}

	while(!tracking.empty()) {
		cout << tracking.top() << ' ';
		tracking.pop();
	}

	return 0;
}