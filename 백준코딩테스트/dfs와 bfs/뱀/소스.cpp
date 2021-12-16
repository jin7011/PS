#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

int n,k,L; // map and apple
int map[105][105];
int ans;
int go[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; //0 1 2 3 , �ϵ�����

deque <pair<int, int>> deq; // ���� �Ӹ���ġ�� ������ġ �����
queue <pair<int,char>> dir; //���� ������ �ٲ���ϴ� �ð��� ����.

bool inrange(int y, int x) {
	return y > 0 && x > 0 && x <= n && y <= n;
}

int dirfind(int side, char command) { // (�������� , �Է¹��� ����) ������ 0��ȯ

	if (command == 'L') // 90�� ����
		return side = (side + 3) % 4;
	
	if (command == 'D') //������
		return side = (side + 1) % 4;
}

void dfs(int y, int x, int side, int cnt) { // ��ǥ�� �ٶ󺸴¹���

	if (!inrange(y, x) || map[y][x] == 2) {
		ans = cnt;
		return;
	}

	if (map[y][x] == 0) {
		int prey = deq.back().first;
		int prex = deq.back().second;
		map[prey][prex] = 0;
		deq.pop_back();
	}

	map[y][x] = 2;
	deq.push_front({ y,x });

	if (!dir.empty()) {

		int i = dir.front().first;

		if (cnt == i) {
			char k = dir.front().second;
			side = dirfind(side, k);
			dir.pop();
		}
	}

	int dy = y + go[side][0];
	int dx = x + go[side][1];

	dfs(dy, dx, side, cnt + 1);
}

int main() {

	cin >> n >> k;
	
	for (int x = 0; x < k; x++) // ��ǥ �� �����ġ
	{
		int ay, ax;
		cin >> ay >> ax;
		map[ay][ax] = 1;
	}

	cin >> L; // ������ ����

	for (int x = 0; x < L; x++) { // ����ð� �� ����
		int l;
		char direction;
		cin >> l>>direction;
		dir.push({ l,direction });
	}

	deq.push_back({ 1,1 }); // ���� ù��° 1,1�ڸ�
	map[1][1] = 2;

	dfs(1+go[1][0], 1+go[1][1], 1,1);// 1,1 ���� ���ʺκп��� ���� ( +1��)

	cout << ans;

	return 0;
}