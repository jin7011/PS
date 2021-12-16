#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m, r, c, d, robotx, roboty;

int map[55][55];
//int visited[51][51];
int cnt = 1; //ó�� ��ġ�� �ڸ�++
int tries = 0;
int preD = 0;

queue < pair<pair<int, int>,int> > que;

void show() {
	for (int y = 0; y < n; y++) {
		cout << '\n';
		for (int x = 0; x < m; x++)
			cout << map[y][x] << ' ';
	}
	cout << cnt;
	cout << '\n';
}

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < m;
}

int dnum(int num) { //�ϼ����� ������ �ް�; �׷����ϸ� ���� �ִ°�쿡 direction + 1�� ���ָ� ������ �ٶ� �� �ֵ�.
	if (num == 1)
		return 3;
	if (num == 3)
		return 1;
	else
		return num;
}

void goback(int y, int x, int direction) { //4���� �� �۷��Ծ��� ��, ��������(d)�����ϰ� ����.

	if (direction == 0 && inrange(y+1,x) && map[y + 1][x] != 1)//��->��
	{
		if (map[y + 1][x] != 7) {
			map[y + 1][x] = 7;
			cnt++;
			que.push({ {y + 1,x},direction });
			return;
		}
		else {
			que.push({ {y + 1,x},direction });
			return;
		}
	}

	if (direction == 1 && inrange(y,x+1) && map[y][x + 1] != 1)//�� -> ��
	{
		if (map[y][x + 1] != 7) {
			map[y][x + 1] = 7;
			cnt++;
			que.push({ {y,x + 1},direction });
			return;
		}
		else {
			que.push({ {y,x + 1},direction });
			return;
		}
	}

	if (direction == 2 && inrange(y-1,x) && map[y - 1][x] != 1)//�� -> ��
	{
		if (map[y - 1][x] != 7) {
			map[y - 1][x] = 7;
			cnt++;
			que.push({ {y - 1,x},direction });
			return;
		}
		else {
			que.push({ {y - 1,x},direction });
			return;
		}
	}

	if (direction == 3 && inrange(y,x-1) && map[y][x - 1] != 1 )//�� -> ��
	{
		if (map[y][x - 1] != 7) {
			map[y][x - 1] = 7;
			cnt++;
			que.push({ {y ,x - 1},direction });
			return;
		}
		else {
			que.push({ {y ,x - 1},direction });
			return;
		}
	}

	return;
}

void left(int y, int x, int direction) { // ���ʹ����� Ž�������ϰ� "����"(ť�� ����)�ϴ� �Լ�. �����ִٸ� direction+1�� �ϰ� �����.
	     //������ǥ,�������
	for (int i = 1; i <= 4; i++) {
		int d = (direction + i) % 4; //�������ϴ� ���� (��������� ���ʼ����� Ž��)

		if (d == 0 && inrange(y-1,x)&& map[y-1][x] == 0 )//������ ����ʹ� (from ��(3))
		{
			map[y-1][x] = 7;
			cnt++;
			que.push({ {y-1,x},d });
			return;
		}

		if (d == 1 && inrange(y,x-1) && map[y][x-1] == 0 )//���� ����ʹ�
		{
			map[y][x-1] = 7;
			cnt++;
			que.push({ {y,x-1},d});
			return;
		}

		if (d == 2 && inrange(y+1,x) && map[y+1][x] == 0)//��
		{
			map[y+1][x] = 7;
			cnt++;
			que.push({ {y+1,x},d });
			return;
		}
	
		if (d == 3 && inrange(y,x+1) && map[y][x+1] == 0)//��
		{
			map[y][x+1] = 7;
			cnt++;
			que.push({ {y,x+1 },d });
			return;
		}

	}
	//4���� �� �۷��Ծ��� ��, �������⿡�� �����ϰ� �ٽ� 4���� üũ
	goback(y, x, direction);
	return;

}

void bfs(int y,int x,int d) {

	que.push({ { y,x },dnum(d)}); //ó����ġ
	map[y][x] = 7;

	while (!que.empty()) {

		int tempy = que.front().first.first;
		int tempx = que.front().first.second;
		int direction = que.front().second;
		
		left(tempy, tempx, direction);
		//show();
		que.pop();

	}

}

int main() {

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			cin >> map[y][x];

	bfs(r, c, d); // �κ��� ��ġ�� ���� ����
	
	//show();

	//cout << '\n';
	cout << cnt;

	return 0;
}
