#include <iostream>
#include <algorithm>
#include <math.h>
#include <functional>
#include <queue>
#include <vector>
#include <stdio.h>

using namespace std;

int map[21][21];
int num[21][21]; // �̵��Ÿ���
int visited[21][21];
int n;
int sharksz = 2;
int res;
int cnt;
int go[4][2] = { {-1,0}, {0,-1},{0,1},{1,0} };
int mini;
bool flag = 0;

queue <pair<int, int> > que;
pair<int, int> eatable;
pair<int, int> shark; // �ʱ⿡ �����ġ �����.

bool inrange(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < n;
}

void bfs() {

	eatable =make_pair(n, n);
	mini = 1e5;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			visited[y][x] = 0;

	int sy = shark.first;
	int sx = shark.second;

	que.push({ sy,sx });
	num[sy][sx] = 0;
	visited[sy][sx] = 1;

	while (!que.empty()) {

		int tempy = que.front().first;
		int tempx = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {// ��->����

			int dy = tempy + go[i][0];
			int dx = tempx + go[i][1];

			if(inrange(dy,dx) && !visited[dy][dx] && map[dy][dx] <= sharksz){
				num[dy][dx] = num[tempy][tempx] + 1;

				if (num[dy][dx] <= mini && map[dy][dx] < sharksz && map[dy][dx] != 0 && eatable.first>dy) {
					// ���� �� �ְ� ���� ����� ���߿��� ���ʿ� �ִ� ��ǥ�� ����. ( ó����ǥ�� ������ �����ϰ� ����)
					mini = num[dy][dx]; // ���� ����� �Ÿ��� üũ�ؼ� �ð�����
					eatable = make_pair(dy,dx);	
				}
				else if (num[dy][dx] <= mini && map[dy][dx] < sharksz && map[dy][dx] != 0 && eatable.first == dy) { // ���� y���� ��ġ�� �� 
					if (eatable.second >= dx) { // ���� ���ʿ� �ִ� ��ǥ�� �켱���ؼ� ��ü�Ѵ�.
						mini = num[dy][dx];
						eatable = make_pair(dy, dx);						
					}
				}

				visited[dy][dx] = 1;
				que.push({ dy,dx });

			}
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for(int y=0; y<n; y++)
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9)
				shark = make_pair(y, x);
		}

	// ������ 4������� �ִܰŸ������ üũ (����->���� �켱)
	do {

		bfs();

		pair<int, int> t = make_pair(n,n);

		if (eatable != t) { //�� ���� �̵��� �� �ִٸ�

			cnt++;
			map[shark.first][shark.second] = 0; //ó����ġ 0
			res += num[eatable.first][eatable.second]; //�� ������ �̵��� �Ÿ� ����.
			map[eatable.first][eatable.second] = 9; // �ڸ���ȯ.

			if (cnt == sharksz) { // ���� ũ�Ⱑ ���� ����⿴�ٸ� ����� ũ��++ cnt =0
				sharksz++;
				cnt = 0;
			}

			shark = eatable; // ���� bfs�� ���� ��� ��ġ ������ ü����.

		}
		else
			break;
		
	} while (1);

	cout << res;

	return 0;
}