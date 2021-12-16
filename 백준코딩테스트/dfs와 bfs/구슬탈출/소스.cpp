#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
char map[4][11];
int go[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; // �����¿� ����. 0123
int r, b;

queue <pair<pair<int, int>,int> > R; // ��ǥ,Ƚ��
queue <pair<pair<int, int>,int> > B; // ��ǥ,Ƚ��
int res; 

bool inrange(int y,int x) {
	return y >= 0 && x >= 0 && y < n && x < m;
}

bool Bdfs(int y, int x,int redy,int redx,int dist) { // blue,red,����

	if(map[y][x] == 'R')

}

void Rdfs(int y, int x, int dist, int cnt) { // ��ǥ , ����(4�� ������ # �Ǵ� 0�� ���������� ��� ������ '����'�ϸ鼭 ���� **

	if (map[y][x] == 'B')
		Bdfs();

	if (!inrange(y, x) && map[y][x] == '#' && cnt > 10) 
		return; 

	int turn = 1; // ������ ������ Ƚ��.

	while (turn != 4) { // �ش����� 4���� ��� ����.

		switch (dist) // ������ ���Ͽ� ������ ���⼺�� ���ؼ� ���Ʈ���� (by dfs)�� ����. (4���� �����ÿ� dfs����) red���� ���� -> blue����
		{

		case 0: { // ���ʹ��� ����

			int dy = y + go[0][0];
			int dx = x + go[0][1];

			if (inrange(dy, dx)) {

				if (map[dy][dx] == '.') { // �����ִ� ���� �ƴҶ�
					if (turn == 1) {
						Rdfs(dy, dx, dist, cnt);// ��ǥ�� ������ (������ Ƚ���� ���⼺�� �ٲ���� ���� ++)
					}
					else {
						Rdfs(dy, dx, dist, cnt + 1);
					}
				}
			}
			else if (map[dy][dx] == '0') { // red�� �������� ������ ��, blue�� �������� ������ ���� blue�� ���� ���� -> ��ȿ.

				if (Bdfs(dy, dx, dist)) { // ���� 1 ��ȯ
					return;
				}
				else
					res = max(res, cnt + 1);
			}
			else { // red�� ���� ������ �� -> ��ȿ
				map[dy][dx] = 'R';
				map[y][x] = '.';
				Bdfs()
				turn++;
				break;
			}
		}

		default:
			break;
		}

		dist++;

	}
}

int main() {

	cin >> n >> m;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];

			if (map[y][x] == 'R')
				R.push({ { y,x },0 });
			if (map[y][x] == 'B')
				B.push({ {y,x},0 });
		
		}



	return 0;
}