#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int h, w;
int starty, startx, endy, endx, startside, endside;
int map[101][101];
bool visited[101][101][5];
//int num[101][101]; // �ּ� ���Ƚ�� ��f��
int sidego[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

queue < pair< pair<int, int>, pair<int, int> > > que; // (������ǥ2��),(����,Ƚ��)

bool inrange(int y, int x) {
	return y > 0 && x > 0 && y <= h && x <= w;
}

pair<int, int> go(int side) {

	pair<int, int> p;

	if (side == 1) // ����
	{
		return p = make_pair(0, 1);
	}
	if (side == 2) // ����
	{
		return p = make_pair(0, -1);
	}
	if (side == 3) // ����
	{
		return p = make_pair(1, 0);
	}
	if (side == 4) // ����
	{
		return p = make_pair(-1, 0);
	}

}

int bfs() {

	que.push({ { starty,startx }, { startside,0} });
	visited[starty][startx][startside] = 1;

	while (!que.empty()) {

		int tempy = que.front().first.first;
		int tempx = que.front().first.second;
		int dir = que.front().second.first;
		int cnt = que.front().second.second;

		que.pop();

		//cout << tempy << " " << tempx << " " << dir << " " << cnt << "\n";

		if (tempy == endy && tempx == endx && dir == endside) {
			return cnt;
		}

		for (int q = 1; q <= 3; q++) { // ���°��� ���� �����ؾ� ������ �� ���⼺ ���縦
			// �ι��� �ʿ䰡 ����.

			pair<int, int> run = go(dir); // ���簡���� �ִ� ���⿡ ���ؼ� 3�������� cnt+1�� ��ȿ�ϰ� �Լ�����

			int dy = tempy + (run.first * q);
			int dx = tempx + (run.second * q);

			if (visited[dy][dx][dir]) // �湮�� ���̶�� ������������
				continue;

			if (inrange(dy, dx) && map[dy][dx] == 0) { // �湮�� ���߰� ���̾��ٸ�
				visited[dy][dx][dir] = 1;
				que.push({ {dy,dx},{dir,cnt + 1} });
			}
			else // �տ� ���� �ִٸ� ���� ���� �� �����ϱ� �� �ڰ� ����־ pass
				break;
		}

		for (int i = 1; i <= 4; i++) {

			if (!visited[tempy][tempx][i] && dir != i)
			{
				visited[tempy][tempx][i] = 1;

				if ((dir==1 && i ==2) || (dir == 2 && i == 1) || (dir==4 && i ==3) || (dir ==3 && i ==4)) 
					que.push({ { tempy,tempx }, { i,cnt + 2 } });
				else 
					que.push({ { tempy,tempx }, { i,cnt + 1 } });		
			
			}
		}

	}

	return -1;
}

int main() {

	cin >> h >> w;

	for (int y = 1; y <= h; y++)
		for (int x = 1; x <= w; x++)
			cin >> map[y][x];

		cin >> starty >> startx >> startside >> endy >> endx >> endside;

		cout << bfs();

	return 0;
}